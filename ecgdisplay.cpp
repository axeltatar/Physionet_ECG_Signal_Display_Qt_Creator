#include "ecgdisplay.h"
#include "ui_ecgdisplay.h"
#include <iostream>
ECGdisplay::ECGdisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ECGdisplay)
{
    ui->setupUi(this);
    setupPlot();
    // configure scroll bars:
    // Since scroll bars only support integer values, we'll set a high default range of 0..30*60+5
    // which is equivalent to (30 minutes and 5 seconds)
    // and divide scroll bar position values by 10 to provide a scroll range 0..1806 s in floating point
    // axis coordinates expressed in seconds. if you want to dynamically grow the range accessible with the scroll bar,
    // just increase the the minimum/maximum values of the scroll bars as needed.
    ui->horizontalScrollBar->setRange(0,(30*60+5)*10);

    // create connection between axes and scroll bars:
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    // initialize axis range (and scroll bar positions via signals we just connected):
    ui->plot->xAxis->setRange(0, 5, Qt::AlignLeading); // display range is 5 seconds
    ui->plot->yAxis->setRange(300, 1000, Qt::AlignLeading);
    //ui->plot->yAxis->setRange(2, 4, Qt::AlignLeading);
}

ECGdisplay::~ECGdisplay()
{
    delete ui;
}

void ECGdisplay::setupPlot()
{
    FILE *pFile;
    uchar *buffer;
    long lSize;
    size_t result;
    int fs = 360;
    QVector<double> t(650000), s1(650000), s2(650000);

    // The following plot setup is mostly taken from the plot demos:
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::blue));
    ui->plot->addGraph();

    pFile = fopen("100.dat","rb");
    if(pFile == NULL)
    {
        std::cout << "cannot open file " << strerror(errno) <<std::endl;
    }

    for (int i = 0; i < 650000; ++i)
    {
        s1[i] = 0.0;
        s2[i] = 0.0;
        t[i] = i/(1.0*fs);
    }

  // obtain file size:
   fseek (pFile , 0 , SEEK_END);
   lSize = ftell (pFile);
   rewind (pFile);

   // allocate memory to contain the whole file:
   buffer = (uchar*) malloc (sizeof(uchar)*lSize);
   if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

   // copy the file into the buffer:
   result = fread (buffer, 1, lSize, pFile);
   if ((long)result != lSize) {fputs ("Reading error",stderr); exit (3);}

   fclose(pFile);

   int k = 0;
   for(int i = 0; i <650000; i++ )
   {
       //212->12bits.

       s1[i] = (buffer[k+1] & 15) * pow(2,8) + buffer[k];
       s2[i] = (buffer[k+1] & 240) * pow(2,4) + buffer[k+2] ;
       k = k + 3;

       //Signed.
       if ( s1[i] >= 2048 )
         s1[i] = ( 4096 - s1[i] ) * ( -1 );

       if ( s2[i] >= 2048 )
           s2[i] = ( 4096 - s2[i] ) * ( -1 );
    }
    std::cout << "Signal 1 first Point Value :\t " << s1[0] << std::endl;
    std::cout << "Signal 2 first Point Value :\t " << s2[0] << std::endl;

    //add offset to the second signal to visually seperate both signals
    for (int i = 0; i< 650000; i++)
    {
        s2[i] -= 500;
    }

    //plot data from .dat file
    ui->plot->graph(0)->setData(t,s1);
    ui->plot->graph(1)->setData(t, s2);

    ui->plot->axisRect()->setupFullAxesBox(true);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->plot->xAxis->setLabel("Time (s)");
    ui->plot->yAxis->setLabel("Amplitude");

    //insert plot title
    QCPPlotTitle *title = new QCPPlotTitle(ui->plot);
    title->setText("Patient 100.dat ECG Record");
    ui->plot->plotLayout()->insertRow(0); // insert an empty row above the axis rect
    ui->plot->plotLayout()->addElement(0, 0, title); // place the title in the empty cell we've just created
}

 void ECGdisplay::horzScrollBarChanged(int value)
{
    if (qAbs(ui->plot->xAxis->range().center()-value/10.0) > 0.1) // if user is dragging plot, we don't want to replot twice
    {
        ui->plot->xAxis->setRange(value/10.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
        ui->plot->replot();
    }
}

void ECGdisplay::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*10.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*10.0)); // adjust size of scroll bar slider
}

