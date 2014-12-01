#include <complex>
#include <cstdio>
#include <iostream>
#include <boost/timer.hpp>

typedef std::complex<double> complex;

// Obliczanie ilości iteracji dla danego punktu.
int mandelbrotCalculate(complex, int);

// Prezentacja wyników.
void showMaldelbrot(int * iterationsTable, int screenwidth, int numberOfPoints);a

// Część główna programu.
int main(int /* argc */, char** /* argv */) {
	// Stałe
	const int screenWidth = 78, screenHeight = 50;	// Rozmiary wydruku.
	const int nPoints = screenWidth * screenHeight;	// Ilość punktów.
	// Doświadczalnie wybrany zakres.
	const complex center(-0.5, 0);			// Centrum wykresu.
	const complex span(3.2, -( 4 / 3.0) * 3.2 * screenHeight / screenWidth);
	const complex begin = center - span / 2.0;
	const complex end = center + span / 2.0;
	const int maxiter = 100000;			// Maksymalna ilośc iter.
	// Zmienne pomocnicze i algorytmu.
	int iPoints;					// Indeks punktów.
	int * maldelbrotTable;				// Tablica punktów
	maldelbrotTable  = new int[nPoints];		// i alokowanie.
	boost::timer myTimer;				// Pomiar czasu.
	double finish;					// Czas wykonania.

	// Start pomiaru czasu.
	myTimer.restart(); 
//	#pragma omp parallel for ordered schedule(dynamic)
	for(iPoints = 0; iPoints < nPoints; ++iPoints) {
		const int x = iPoints % screenWidth, y = iPoints / screenWidth;
		complex c = begin + complex(x * span.real() / (screenWidth + 1.0),
			y * span.imag() / (screenHeight + 1.0));
		int iters = mandelbrotCalculate(c, maxiter);
		maldelbrotTable[iPoints] = (iters == maxiter) ? 0 : iters;
	}
	showMaldelbrot(maldelbrotTable, screenWidth, nPoints);
	// Koniec pomiaru czasu.
	finish = myTimer.elapsed();
	std::cout << "Czas wykonania = " << finish << '\n';
	delete [] maldelbrotTable;
}
// Obliczanie ilości iteracji dla danego punktu.
int mandelbrotCalculate(complex c, int maxiter) {
	// Iteracja z = z * z + c, aż do |z| >= 2 lub gdy maksymalna
	// ilość iteracji zostanie osiągnięta.
	complex z = c;
	int n = 0;
	while(( n < maxiter) && (std::abs(z) < 2.0)) {
		z = z * z + c;
		++n;
	}
	return n;
}
// Prezentacja wyników.
void showMaldelbrot(int * tab, int sWidth, int nPoints) {
	static const char symbols[] = ".,c8M@jawrpogOQEPGJ";
	static const int symLen = sizeof(symbols) - 1;
	for(int i = 0; i < nPoints; ++i) {
		std::putchar(
			tab[i] ? symbols[tab[i] % symLen] : ' '
		);
		((i + 1) % sWidth) || (std::puts("|"));
	}
}
