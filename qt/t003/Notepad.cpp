#include "Notepad.h"

Notepad::Notepad(void) :
    textEdit(new QTextEdit),
    quitButton(new QPushButton(tr("Quit"))),
    layout(new QVBoxLayout)
{
    QObject::connect(quitButton.get(), SIGNAL(clicked()), this, SLOT(quit()));
    layout->addWidget(textEdit.get());
    layout->addWidget(quitButton.get());

    setLayout(layout.get());
    setWindowTitle(tr("Notepad"));
}

Notepad::~Notepad()
{
    
}

void Notepad::quit(void)
{
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("Notepad exit"));
    messageBox.setText(tr("Are you sure you want to quit?"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if (messageBox.exec() == QMessageBox::Yes) {
        qApp->quit();
    }

}
