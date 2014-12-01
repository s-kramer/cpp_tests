#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <boost/timer.hpp>
#include <omp.h>
int main(int argc, char* argv[]) {
	const int mySize = 1000000;
	//srand(time(NULL)); 
	srand(0); 
	std::vector<int> a(mySize), b(mySize);	
	std::vector<int> aver(mySize), diff(mySize);
	int averSum = 0, diffSum = 0;
	boost::timer myTimer;
	double finish;
	myTimer.restart();
	#pragma omp parallel num_threads(8) default(none) \
		shared(a,b) private(i)
	{
		#pragma omp for nowait
		for(int i = 0; i < mySize; ++i) 
			a[i] = rand() / 2;	
		#pragma omp for nowait
		for(int i = 0; i < mySize; ++i)
			b[i] = rand() / 2;
	}
	#pragma omp sections
	{
		#pragma omp section
		for(int i = 0; i < mySize; ++i)
			aver[i] = (a[i] + b[i]) / 2 ;
		#pragma omp section
		for(int i = 0; i < mySize; ++i)
			diff[i] = a[i] - b[i];
	}
	#pragma omp parallel for reduction(+:averSum) reduction(+:diffSum)
	for(int i = 0; i < mySize; ++i) {
		averSum += aver[i];
		diffSum += diff[i];
	}
	#pragma omp single
	{ // Oczywiscie na wyrost i niepotrzebne :)
		std::cout << "averSum = " << averSum 
			<< "\ndiffSum = " << diffSum << '\n';
	}
	finish = myTimer.elapsed();
	std::cout << "W czasie: " << finish << '\n';
	return 0;
}
