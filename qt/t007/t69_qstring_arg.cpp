#include <QtCore/QString>
#include <iostream>

int main()
{
    QString s("%1, %1");
    std::cout << s.arg(2).toStdString() << '\n';
    return 0;
}
