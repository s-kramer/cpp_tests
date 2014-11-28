#include <iostream>

template <class ActualClass> 
class Singleton
{
   public:
   static ActualClass& GetInstance()
   {
      if(p == 0)
         p = new ActualClass; // This won't compile
      return *p; 
   }

   protected:
   static ActualClass* p;
   private: // because this should be protected
   Singleton(){}
   Singleton(Singleton const &);
   Singleton& operator = (Singleton const &); 
};
template <class T>
T* Singleton<T>::p = 0;

class A: public Singleton<A>
{
   //Rest of functionality 
};


int main()
{
    A::GetInstance();
    return 0;
}
