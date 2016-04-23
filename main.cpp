#include "ecgdisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication ECGDisplayApp(argc, argv);
    ECGdisplay MainDisplayWindow;
    MainDisplayWindow.show();
    return ECGDisplayApp.exec();
}
