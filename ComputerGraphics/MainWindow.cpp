#include "MainWindow.h"
#include "qtextcodec.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

MainWindow::~MainWindow()
{}

void MainWindow::updateButtonClicked()
{

    bool okx, oky;

    QString x = ui.xTextInput->toPlainText();
    QString y = ui.yTextInput->toPlainText();
    int intx = x.toInt(&okx);
    int inty = y.toInt(&oky);
    ui.renderArea->updateReferencePoint(intx, inty);

    if (!(okx && oky)) 
        ui.statusBar->showMessage("Введены нечисловые символы или поля пусты");
    else 
        ui.statusBar->showMessage("Обновлено");
}
