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

    bool okx, oky, okAng;

    QString x = ui.xTextInput->toPlainText();
    QString y = ui.yTextInput->toPlainText();
    int intx = x.toInt(&okx);
    int inty = y.toInt(&oky);


    QString angle = ui.angleTextInput->toPlainText();
    int intAng = angle.toInt(&okAng);

    if (!(okx && oky && okAng))
        ui.statusBar->showMessage(tr("Введены нечисловые символы или поля пусты"));
    else{
        ui.statusBar->showMessage(tr("Обновлено"));
        ui.renderArea->updateReferencePoint(intx, inty);
        ui.renderArea->updateAngle(intAng);
        ui.renderArea->update();
    }

}
