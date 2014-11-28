#include <iostream>
#include <vector>
#include <algorithm>

class AAnimal
{
public:
    explicit AAnimal (){};
    virtual ~AAnimal (){};

    virtual void Speak(void) = 0;
};

class Dog : public AAnimal
{
public:
    explicit Dog (void){};
    virtual ~Dog (){};

    void Speak (void) 
    {
        std::cout << "Dog barking..." << '\n';
    }
};

class Cat : public AAnimal
{
public:
    explicit Cat (void){};
    virtual ~Cat (){};

    void Speak (void)
    {
        std::cout << "Cat meowing..." << '\n';
    }

};

class Bird : public AAnimal
{
public:
    explicit Bird (){};
    virtual ~Bird (){};

    void Speak (void)
    {
        std::cout << "Bird birding... " << '\n';
    }
};

void Speak (AAnimal *a)
{
    a->Speak();
}

int main()
{
    Dog dog_1, dog_2, dog_3;
    Cat cat_1, cat_2, cat_3;
    Bird Bird_1, Bird_2, Bird_3;

    std::vector<AAnimal*> animal_vector = {&dog_1, &dog_2, &dog_3, &cat_1, &cat_2, &cat_3, &Bird_1, &Bird_2, &Bird_3};
    std::for_each( animal_vector.begin(), animal_vector.end(), Speak);

    return 0;
}
