/********************************************************************************
** Form generated from reading UI file 'clientside.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSIDE_H
#define UI_CLIENTSIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientSide
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientSide)
    {
        if (ClientSide->objectName().isEmpty())
            ClientSide->setObjectName(QStringLiteral("ClientSide"));
        ClientSide->resize(400, 300);
        centralWidget = new QWidget(ClientSide);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 190, 161, 21));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(243, 243, 243);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 151, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        ClientSide->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientSide);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        ClientSide->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientSide);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ClientSide->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientSide);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ClientSide->setStatusBar(statusBar);

        retranslateUi(ClientSide);

        QMetaObject::connectSlotsByName(ClientSide);
    } // setupUi

    void retranslateUi(QMainWindow *ClientSide)
    {
        ClientSide->setWindowTitle(QApplication::translate("ClientSide", "ClientSide", Q_NULLPTR));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("ClientSide", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientSide: public Ui_ClientSide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSIDE_H
