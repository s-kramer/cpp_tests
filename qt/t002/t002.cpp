#include <Qt/QtGui>
#include <boost/smart_ptr.hpp>


int main(int argc, char *argv[])
{
    QApplication app (argc, argv);

    boost::shared_ptr<QTextEdit> qTextEdit(new QTextEdit);
    boost::shared_ptr<QPushButton> qPushButton(new QPushButton("&Quit"));

    QObject::connect(qPushButton.get(), SIGNAL(clicked()), qApp, SLOT(quit()));

    boost::shared_ptr<QVBoxLayout> qVBoxLayout(new QVBoxLayout);
    qVBoxLayout->addWidget(qTextEdit.get());
    qVBoxLayout->addWidget(qPushButton.get());

    QWidget window;
    window.setLayout(qVBoxLayout.get());
    window.show();

    return app.exec();
}
