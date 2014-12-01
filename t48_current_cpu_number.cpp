#include <iostream>
#include <sstream>
#include <omp.h>
#include <utmpx.h>
#include <random>
int main(){
#pragma omp parallel
    {
        std::default_random_engine rand;
        int num = 0;
#pragma omp for
        auto cpu = sched_getcpu();
        std::ostringstream os;
        os<<"\nThread "<<omp_get_thread_num()<<" on cpu "<<sched_getcpu()<<std::endl;
        std::cout<<os.str()<<std::flush;
        std::cout<<num;
    }
}


