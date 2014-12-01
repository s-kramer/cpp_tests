#include <QtCore/QString>
#include <QtCore/QDir>
#include <iostream>

int main()
{
    QString path("/home/skramer/c_test/qt/test_file.x");
    QDir test(path);

    std::cout << test.absolutePath().toStdString() << '\n';

    return 0;
}
