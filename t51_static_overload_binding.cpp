#include <iostream>

class ClientBase
{
};

class ClientDerived : public ClientBase
{
};

class OperationBase
{
    public:
        virtual void printMessage(ClientBase& clientBase) const
        {
            std::cout << "OperationBase::printMessage(ClientBase)" << '\n';
        }

        virtual void printMessage(ClientDerived& clientDerived) const
        {
            std::cout << "OperationBase::printMessage(ClientDerived)" << '\n';
        }

        virtual ~OperationBase() = default;
};

class OperationDerived : public OperationBase
{
    public:
        virtual void printMessage(ClientBase& clientBase) const
        {
            std::cout << "OperationDerived::printMessage(ClientBase)" << '\n';
        }

        virtual void printMessage(ClientDerived& clientDerived) const
        {
            std::cout << "OperationDerived::printMessage(ClientDerived)" << '\n';
        }
};

int main()
{
    OperationBase operationBase;
    OperationDerived operationDerived;
    OperationBase& operationBaseReference = operationDerived;

    ClientBase clientBase;
    ClientDerived clientDerived;
    ClientBase& clientBaseReference = clientDerived;

    operationBase.printMessage(clientBase);
    /* Function overloads are statically-binded. This won't do what you
     * expect it to do - it will call operationBase::printMessage(ClientBase).
     * You need to get rid of the overload to get dynamic binding!
     */
    operationBase.printMessage(clientBaseReference);

    operationBaseReference.printMessage(clientBase);
    operationBaseReference.printMessage(clientBaseReference);
    
    return 0;
}
