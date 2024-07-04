#ifndef TABLEVIEWER_H
#define TABLEVIEWER_H
#include<QWidget>
#include<QTableWidget>
#include <QFile>
#include <QString>
#include<QTextStream>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include<QMenu>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QGridLayout>
#include<iostream>
#include<QLabel>
#include<QPixmap>
#include<QCheckBox>
#include<QPalette>
#include<QStringList>

class TableViewer:public QWidget
{

    Q_OBJECT
public:
    TableViewer();
    ~TableViewer(){}

    QTableWidget *_pTable;
    QPushButton * _pLoadButton;
    QPushButton * _pSortUpButton;
    QPushButton * _pBubbleSortButton;
    QStringList listStr;
    QGridLayout *_pGridLayout;
    QFile chosenFile;
    QLabel * _pLabelImage;
    QPixmap _pImage;
    QMenu *_pContMenu;
    QCheckBox *_pChBoxBackGround;

protected:

    void keyPressEvent(QKeyEvent* pKEO);
    void mousePressEvent(QMouseEvent* pMEO);

public slots:
    void WriteTable();
    void CreateWindow();
    void SortUp();
    void ChangeBackground();
    void BubbleSort();

};

#endif // TABLEVIEWER_H
