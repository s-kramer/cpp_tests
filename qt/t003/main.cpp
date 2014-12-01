#include <Qt/QtGui>
#include "Notepad.h"

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    Notepad notepad;
    notepad.show();
    return app.exec();
}

