#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <Qt/QtGui>

class AddressBook: public QWidget
{
    Q_OBJECT

public:
    explicit AddressBook (QWidget* parent = 0);

public slots:
    void addContactSlot(void);
    void submitContactSlot(void);
    void editContactSlot(void);
    void removeContactSlot(void);
    void cancelSlot(void);
    void nextEntrySlot(void);
    void prevEntrySlot(void);

private:
    enum Mode {ViewMode, AddMode, EditMode} currentMode;

    QTextEdit *addressText;
    QLineEdit *nameText;
    QLabel *nameLabel, *addressLabel;
    QPushButton *addButton, *submitButton, *cancelButton, *editButton, *removeButton;
    QPushButton *nextEntryButton, *prevEntryButton;

    QMap<QString, QString> contacts;
    QString oldName, oldAddress;

    void prepareWidgetsToAddition(void);
    void cleanupWidgetsAfterAddtition(void);
    void prepareWidgetsDefaultState(void);

    void updateMode(Mode mode);
};
#endif
