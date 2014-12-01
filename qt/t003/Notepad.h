#include <Qt/QtGui>
#include <boost/shared_ptr.hpp>


class Notepad : public QWidget
{
    Q_OBJECT

public:
    Notepad (void);
    ~Notepad();

private slots:
    void quit();

private:
    boost::shared_ptr<QTextEdit> textEdit;
    boost::shared_ptr<QPushButton> quitButton;
    boost::shared_ptr<QVBoxLayout> layout;
};

