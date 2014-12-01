#include <QString>
#include <iostream>

int main()
{
    QString s("%1, %1");
    std::cout << s.arg(2).data() << '\n';
    return 0;
}
