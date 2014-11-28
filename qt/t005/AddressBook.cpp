#include "AddressBook.h"

AddressBook::AddressBook(QWidget *parent) :
    addressText (new QTextEdit(this)),
    nameText (new QLineEdit(this)),
    nameLabel (new QLabel(tr("Name"), this)),
    addressLabel (new QLabel(tr("Address"), this)),
    addButton (new QPushButton(tr("&Add"), this)),
    submitButton (new QPushButton(tr("&Submit"), this)),
    cancelButton (new QPushButton(tr("&Cancel"), this)),
    editButton (new QPushButton(tr("&Edit"), this)),
    removeButton (new QPushButton(tr("&Remove"), this)),
    nextEntryButton (new QPushButton(tr("&Next"), this)),
    prevEntryButton (new QPushButton(tr("&Previous"), this))
{

    connect(addButton, SIGNAL(clicked()), this, SLOT(addContactSlot()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitContactSlot()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelSlot()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(editContactSlot()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeContactSlot()));
    connect(prevEntryButton, SIGNAL(clicked()), this, SLOT(prevEntrySlot()));
    connect(nextEntryButton, SIGNAL(clicked()), this, SLOT(nextEntrySlot()));

    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(submitButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addStretch();

    QHBoxLayout *navigationLayout = new QHBoxLayout();
    navigationLayout->addWidget(prevEntryButton);
    navigationLayout->addWidget(nextEntryButton);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameText, 0, 1);
    layout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    layout->addWidget(addressText, 1, 1);
    layout->addLayout(buttonLayout, 1 , 2, Qt::AlignTop);
    layout->addLayout(navigationLayout, 2, 1);

    setLayout(layout);
    setWindowTitle("Address book");

    prepareWidgetsDefaultState();
    editButton->setEnabled(false);
    removeButton->setEnabled(false);
}

void AddressBook::addContactSlot(void)
{
    oldAddress = addressText->toPlainText();
    oldName = nameText->text();

    nameText->clear();
    addressText->clear();

    updateMode(AddMode);
    nameText->setFocus(Qt::OtherFocusReason);
}

void AddressBook::submitContactSlot(void)
{
    QString nameCandidate = nameText->text();
    QString addressCandidate = addressText->toPlainText();

    if (currentMode == AddMode) {

        if (nameCandidate.isEmpty() | addressCandidate.isEmpty()) {
            QMessageBox::warning(this, tr("Empty fields"), tr("You have provided empty name or address")); 
            return;
        } 

        if (!contacts.contains(nameCandidate)) {
            contacts.insert(nameCandidate, addressCandidate);
            QMessageBox::information(this, tr("Contact added successfully"), tr("Contact %1 added successfully").arg(nameCandidate));
        } else {
            QMessageBox::warning(this, tr("Contact already in the base"), tr("Contact %1 is already present in the base.").arg(nameCandidate));
            return;
        }
    } else if (currentMode == EditMode) {
        if (oldName != nameCandidate) {
            if (!contacts.contains(nameCandidate)) {
                contacts.remove(oldName);
                contacts.insert(nameCandidate, addressCandidate);
                QMessageBox::information(this, tr("Contact modified"), tr("Contact modified successfully"));
            } else {
                QMessageBox::warning(this, tr("Modification error"), tr("Could not modify contatc. It's already present in the database"));
                return;
            }
        } else if (oldAddress != addressCandidate) {
            contacts[nameCandidate] = addressCandidate;
            QMessageBox::information(this, tr("Contact modified"), tr("Contact modified successfully"));
        }
    }
}

void AddressBook::prepareWidgetsDefaultState(void)
{
    nextEntryButton->setEnabled(false);
    prevEntryButton->setEnabled(false);
    cleanupWidgetsAfterAddtition();
}

void AddressBook::prepareWidgetsToAddition(void)
{
    addButton->setEnabled(false);
    submitButton->show();
    cancelButton->show();

    addressText->setReadOnly(false);
    nameText->setReadOnly(false);

    nextEntryButton->setEnabled(false);
    prevEntryButton->setEnabled(false);
}

void AddressBook::cleanupWidgetsAfterAddtition(void)
{
    if (contacts.isEmpty()) {
        nameText->clear();
        addressText->clear();
    }

    addButton->setEnabled(true);
    submitButton->hide();
    cancelButton->hide();

    addressText->setReadOnly(true);
    nameText->setReadOnly(true);

    if (contacts.size()) {
        prevEntryButton->setEnabled(true);
        nextEntryButton->setEnabled(true);
    }
}

void AddressBook::cancelSlot(void)
{
    nameText->setText(oldName);
    addressText->setText(oldAddress);
    cleanupWidgetsAfterAddtition();
}

void AddressBook::prevEntrySlot(void)
{
    QString name = nameText->text();
    QMap<QString, QString>::iterator i = contacts.find(name);

    // if (i == contacts.end()) {
        // i = contacts.begin();
    // } 

    if (i == contacts.begin()) {
        i = contacts.end();
    }

    i--;
    
    nameText->setText(i.key());
    addressText->setText(i.value());
}

void AddressBook::nextEntrySlot(void)
{
    QString name = nameText->text();
    QMap<QString, QString>::iterator i = contacts.find(name);

    if (i != contacts.end()) {
        i++;
    } 
    if (i == contacts.end()) {
        i = contacts.begin();
    }
    
    nameText->setText(i.key());
    addressText->setText(i.value());
}

void AddressBook::editContactSlot(void)
{
    oldName = nameText->text();
    oldAddress = addressText->toPlainText();

    currentMode = EditMode;
}

void AddressBook::removeContactSlot(void)
{
    
}

void AddressBook::updateMode(Mode mode)
{
    currentMode = mode;

    if (mode == AddMode) {
        prepareWidgetsToAddition();
    } else if (mode == EditMode) {
        cleanupWidgetsAfterAddtition();
    } else {
        /* code */
    }

}
