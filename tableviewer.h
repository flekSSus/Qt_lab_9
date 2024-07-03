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

class TableViewer:public QWidget
{

    Q_OBJECT
public:
    TableViewer();
    ~TableViewer(){}

    QTableWidget *_pTable;
    QPushButton * _pLoadButton;
    QPushButton * _pSortUpButton;
    QStringList listStr;
    QGridLayout *_pGridLayout;
    QFile chosenFile;
    QLabel * _pLabelImage;
    QPixmap _pImage;
    QMenu *_pContMenu;

protected:

    void keyPressEvent(QKeyEvent* pKEO);
    void mousePressEvent(QMouseEvent* pMEO);
    void contextMenuEvent(QMenu *pContMenu);

public slots:
    void WriteTable();
    void CreateWindow();
    void SortUp();


};

#endif // TABLEVIEWER_H
