#ifndef ECGDISPLAY_H
#define ECGDISPLAY_H

#include <QMainWindow>
#include "qcustomplot.h"


namespace Ui {
class ECGdisplay;
}

class ECGdisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit ECGdisplay(QWidget *parent = 0);
    ~ECGdisplay();

    void setupPlot();

private slots:
    void horzScrollBarChanged(int value);
    void xAxisChanged(QCPRange range);

private:
    Ui::ECGdisplay *ui;
};

#endif // ECGDISPLAY_H
