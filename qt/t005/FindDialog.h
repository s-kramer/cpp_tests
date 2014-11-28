#ifndef FINDDIALOG_H
#define FINDDIALOG_H 

#include <Qt/qdialog.h>
#include <Qt/QtGui>

class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog (QWidget *parent = 0);
    QString getFindText();

public slots:
    void findClickedSlot();

private:
    QPushButton *findButton;
    QLineEdit *queryBox;
    QString queryText;
    QLabel *findLabel;
    
};
#endif
