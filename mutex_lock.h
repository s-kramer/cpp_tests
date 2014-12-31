#ifndef MUTEX_LOCK
#define MUTEX_LOCK 

#include <cyg/kernel/kapi.h>

class Mutex_lock
{
public:
    explicit Mutex_lock (cyg_mutex_t& mutex) : mutex(mutex) { cyg_mutex_lock(&mutex); };
    ~Mutex_lock () { cyg_mutex_unlock(&mutex); };
private:
    cyg_mutex_t& mutex;
};

#endif
