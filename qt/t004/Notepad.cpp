#include "Notepad.h"

Notepad::Notepad(void) :
    textEdit(new QTextEdit),
    openAction(new QAction(tr("&Open"), this)),
    saveAction(new QAction(tr("&Save"), this)),
    quitAction(new QAction(tr("&Quit"), this)),
    filemenu(new QMenu)
{
    connect(openAction.get(), SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAction.get(), SIGNAL(triggered()), this, SLOT(save()));
    connect(quitAction.get(), SIGNAL(triggered()), qApp, SLOT(quit()));

    filemenu.reset(menuBar()->addMenu(tr("&File")));
    filemenu->addAction(openAction.get());
    filemenu->addAction(saveAction.get());
    filemenu->addSeparator();
    filemenu->addAction(quitAction.get());

    setCentralWidget(textEdit.get());

    setWindowTitle(tr("Notepad"));
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
void Notepad::open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h);;All Files (*)"));

    if (filename != "") {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }

}

void Notepad::save()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "",  tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("File save Error"), tr("The file could not be saved"));
    }
    else {
        QTextStream stream(&file);
        stream << textEdit->toPlainText();
        stream.flush();
        file.close();
    }
}
