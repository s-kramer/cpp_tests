#include "FindDialog.h"

FindDialog::FindDialog(QWidget *parent):
    QDialog(parent),
    findButton (new QPushButton(tr("&Find"), this)),
    queryBox (new QLineEdit(this)),
    findLabel (new QLabel(tr("Enter the text for the search"))),
    
{
    
}

QString FindDialog::getFindText(void)
{
    
}
