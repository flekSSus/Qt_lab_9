#include "tableviewer.h"

void TableViewer::WriteTable()
{
    QFileInfo fileInfo1(QFileDialog::getOpenFileName(nullptr,"Open file","","*.txt"));
    QFile file1(fileInfo1.fileName());
    file1.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream fileTextStream1(&file1);

    QString tmpStr1,tmpStr2;
    fileTextStream1>>tmpStr1>>tmpStr2;

    delete _pTable;
    _pTable=nullptr;

    _pTable=new QTableWidget(this);
    _pTable->show();
    _pTable->setGeometry(150,50,500,200);

    _pTable->setRowCount(tmpStr1.toInt());
    _pTable->setColumnCount(tmpStr2.toInt());
    _pTable->setHorizontalHeaderLabels(QStringList()<<"Name"<<"Path"<<"Size");

    QString str;

    for(int i=0; i<_pTable->rowCount();++i)
    {
        for(int j=0;j<_pTable->columnCount();++j)
        {
            fileTextStream1>>str;
            _pTable->setItem(i,j,new QTableWidgetItem(str));
        }
    }
   // _pTable->show();
    file1.close();

}
TableViewer::TableViewer()
{

    CreateWindow();

}

void TableViewer::CreateWindow()
{

    _pTable=new QTableWidget(this);
    _pLoadButton=new QPushButton("Load",this);

    //Load Button
    _pLoadButton->setGeometry(50,50,50,25);


    //Table
    _pTable->setGeometry(150,50,500,200);

    connect(_pLoadButton,SIGNAL(clicked()),this,SLOT(WriteTable()));

}

