#include <Qt/QtGui>
#include <Qt/qdebug.h>
#include <iostream>
#include <boost/shared_ptr.hpp>


class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad (void);

private slots:
    void open();
    void save();
    void quit();

private:
    boost::shared_ptr<QTextEdit> textEdit;

    boost::shared_ptr<QAction> openAction;
    boost::shared_ptr<QAction> saveAction;
    boost::shared_ptr<QAction> quitAction;

    boost::shared_ptr<QMenu> filemenu;
};

