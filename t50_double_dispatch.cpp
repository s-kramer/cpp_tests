#include <iostream>

/* Note: visitor pattern implementation 
 * (skramer, Wed 04 Jun 2014 12:23:26 AM CEST) 
 */

class SpaceShip;
class ApolloSpacecraft;

class Asteroid {
public:
  virtual void CollideWith(SpaceShip&) {
    std::cout << "Asteroid hit a SpaceShip" << std::endl;
  }
  virtual void CollideWith(ApolloSpacecraft&) {
    std::cout << "Asteroid hit an ApolloSpacecraft" << std::endl;
  }
};
 
class ExplodingAsteroid : public Asteroid {
public:
  virtual void CollideWith(SpaceShip&) {
    std::cout << "ExplodingAsteroid hit a SpaceShip" << std::endl;
  }
  virtual void CollideWith(ApolloSpacecraft&) {
    std::cout << "ExplodingAsteroid hit an ApolloSpacecraft" << std::endl;
  }
};

class SpaceShip 
{
    public:
        /* first dispatch */
        virtual void CollideWith(Asteroid& inAsteroid)
        {
            /* second dispatch */
            inAsteroid.CollideWith(*this);
        }
};
class ApolloSpacecraft : public SpaceShip 
{
    public:
        virtual void CollideWith(Asteroid& inAsteroid)
        {
            inAsteroid.CollideWith(*this);
        }
};
 


int main()
{
    Asteroid theAsteroid;
    SpaceShip theSpaceShip;
    ApolloSpacecraft theApolloSpacecraft;
    ExplodingAsteroid theExplodingAsteroid;

    Asteroid& theAsteroidReference = theExplodingAsteroid;
    theAsteroidReference.CollideWith(theSpaceShip); 
    theAsteroidReference.CollideWith(theApolloSpacecraft);

    /* This doesn't act as expected. theSpaceShipReference
     * is binded statically - the SpaceShip versions
     * of the messages are printed.
     * While virtual functions are dispatched dynamically in C++, 
     * function overloading is done statically.
     */
    SpaceShip& theSpaceShipReference = theApolloSpacecraft;
    //note the type of the pointer and the type of the object.
    theAsteroid.CollideWith(theSpaceShipReference);

    /* Here, the virtual function was activated invoking the
     * method of ExplodingAsteroid instead of Asteroid. 
     * The argument was however statically binded resulting
     * in not taking dynamic type of theSpaceShipReference 
     * into account. */
    theAsteroidReference.CollideWith(theSpaceShipReference);

    /* This uses double dispatch. */
    /*
     * At run time:
     * 
     *      theSpaceShipReference is a reference, so C++ looks up the correct method in the vtable. 
     *      In this case, it will call ApolloSpacecraft::CollideWith(Asteroid&).
     *      Within ApolloSpacecraft::CollideWith(Asteroid&), inAsteroid is a reference, 
     *      so inAsteroid.CollideWith(*this) will result in another vtable lookup. 
     *      In this case, inAsteroid is a reference to an ExplodingAsteroid so 
     *      ExplodingAsteroid::CollideWith(ApolloSpacecraft&) will be called...
     */
    theSpaceShipReference.CollideWith(theAsteroid);
    theSpaceShipReference.CollideWith(theAsteroidReference);

    return 0;
}

