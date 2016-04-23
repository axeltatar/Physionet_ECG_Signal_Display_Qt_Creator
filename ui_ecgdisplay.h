/********************************************************************************
** Form generated from reading UI file 'ecgdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECGDISPLAY_H
#define UI_ECGDISPLAY_H

#include "qcustomplot.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ECGdisplay
{
public:
    QWidget *centralWidget;
    QCustomPlot *plot;
    QScrollBar *horizontalScrollBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ECGdisplay)
    {
        if (ECGdisplay->objectName().isEmpty())
            ECGdisplay->setObjectName(QStringLiteral("ECGdisplay"));
        ECGdisplay->resize(723, 403);
        centralWidget = new QWidget(ECGdisplay);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(80, 8, 581, 296));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(80, 310, 581, 17));
        horizontalScrollBar->setTracking(true);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalScrollBar->setInvertedAppearance(false);
        horizontalScrollBar->setInvertedControls(false);
        ECGdisplay->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ECGdisplay);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 723, 21));
        ECGdisplay->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ECGdisplay);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ECGdisplay->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ECGdisplay);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ECGdisplay->setStatusBar(statusBar);

        retranslateUi(ECGdisplay);

        QMetaObject::connectSlotsByName(ECGdisplay);
    } // setupUi

    void retranslateUi(QMainWindow *ECGdisplay)
    {
        ECGdisplay->setWindowTitle(QApplication::translate("ECGdisplay", "ECGdisplay", 0));
    } // retranslateUi

};

namespace Ui {
    class ECGdisplay: public Ui_ECGdisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECGDISPLAY_H
