#ifndef TABLEVIEWER_H
#define TABLEVIEWER_H
#include<QWidget>
#include<QTableWidget>
#include <QFile>
#include<QTextStream>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include<QKeyEvent>
#include<QGridLayout>
#include<iostream>

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

protected:

    void keyPressEvent(QKeyEvent* pKEO);

public slots:
    void WriteTable();
    void CreateWindow();
    void SortUp();

};

#endif // TABLEVIEWER_H
