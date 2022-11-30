#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineCore/QWebEngineSettings>
#include <QTextEdit>
#include <QFile>
#include "widgetsplittingrenderer.h"

//int main(int argc, char **argv)
//{
//    QApplication app(argc, argv);

//    QWebEngineView *myWidget = new QWebEngineView;
//    myWidget->setUrl(QUrl("https://doc.qt.io/qt-6/qgraphicsproxywidget.html"));

//    QWidget* w = new QWidget;
//    QVBoxLayout* vLayout = new QVBoxLayout;

//    QLineEdit* urlLineEdit = new QLineEdit;
//    QObject::connect(urlLineEdit, &QLineEdit::editingFinished, [=]() {
//        myWidget->setUrl(QUrl(urlLineEdit->text()));
//    });
//    vLayout->addWidget(urlLineEdit);
//    vLayout->addWidget(new WidgetSplittingRenderer(myWidget));

//    w->setLayout(vLayout);
//    w->show();

//    return app.exec();
//}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTextEdit *myWidget = new QTextEdit;
    myWidget->setLineWrapMode(QTextEdit::LineWrapMode::FixedPixelWidth);
    myWidget->setLineWrapColumnOrWidth(300);
    QFile file(":/lorem.txt");
    file.open(QIODevice::ReadOnly);
    myWidget->setText(file.readAll());

    QWidget* w = new QWidget;
    QVBoxLayout* vLayout = new QVBoxLayout;

    auto splittingWidget = new WidgetSplittingRenderer(myWidget, 5);
    vLayout->addWidget(splittingWidget);

    w->setLayout(vLayout);
    w->show();

    myWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    myWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QObject::connect(myWidget->horizontalScrollBar(), &QScrollBar::rangeChanged, splittingWidget->horizontalScrollBar(), &QScrollBar::setRange);
    QObject::connect(myWidget->verticalScrollBar(), &QScrollBar::rangeChanged, splittingWidget->verticalScrollBar(), &QScrollBar::setRange);
    QObject::connect(myWidget->horizontalScrollBar(), &QScrollBar::valueChanged, splittingWidget->horizontalScrollBar(), &QScrollBar::setValue);
    QObject::connect(myWidget->verticalScrollBar(), &QScrollBar::valueChanged, splittingWidget->verticalScrollBar(), &QScrollBar::setValue);
    QObject::connect(splittingWidget->horizontalScrollBar(), &QScrollBar::valueChanged, myWidget->horizontalScrollBar(), &QScrollBar::setValue);
    QObject::connect(splittingWidget->verticalScrollBar(), &QScrollBar::valueChanged, myWidget->verticalScrollBar(), &QScrollBar::setValue);

    splittingWidget->horizontalScrollBar()->setRange(myWidget->horizontalScrollBar()->minimum(), myWidget->horizontalScrollBar()->maximum());
    splittingWidget->horizontalScrollBar()->setValue(myWidget->horizontalScrollBar()->value());
    splittingWidget->verticalScrollBar()->setRange(myWidget->verticalScrollBar()->minimum(), myWidget->verticalScrollBar()->maximum());
    splittingWidget->verticalScrollBar()->setValue(myWidget->verticalScrollBar()->value());

    return app.exec();
}
