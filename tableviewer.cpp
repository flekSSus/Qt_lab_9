#include "tableviewer.h"

void TableViewer::WriteTable()
{
    QFileInfo fileInfo1(QFileDialog::getOpenFileName(nullptr,"Open file","","*.txt"));
    chosenFile.setFileName(fileInfo1.fileName());
    chosenFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream fileTextStream1(&chosenFile);

    QString tmpStr1,tmpStr2;
    fileTextStream1>>tmpStr1>>tmpStr2;


    delete _pTable;
    _pTable=nullptr;

    _pTable=new QTableWidget(this);
    _pGridLayout->addWidget(_pTable,1,1,3,3);

    _pTable->show();
    _pTable->setRowCount(tmpStr1.toInt());
    _pTable->setColumnCount(tmpStr2.toInt());
    _pTable->setHorizontalHeaderLabels(QStringList()<<"Name"<<"Path"<<"Size");

    listStr.clear();

    fileTextStream1.readLine();
    for(int i=0; i<_pTable->rowCount();++i)
    {
        listStr.insert(i,fileTextStream1.readLine());
        for(int j=0;j<_pTable->columnCount();++j)
            _pTable->setItem(i,j,new QTableWidgetItem(listStr[i].split(" ").at(j)));
    }

    chosenFile.close();

}
TableViewer::TableViewer()
{

    CreateWindow();

}

void TableViewer::CreateWindow()
{
    setFocusPolicy(Qt::StrongFocus);
    _pTable=new QTableWidget(this);
    _pLoadButton=new QPushButton("Load",this);
    _pSortUpButton=new QPushButton("Sort Up",this);
    _pGridLayout=new QGridLayout(this);

    //Load Button


    //Table


    //SortUp Button


    //Layout

    _pGridLayout->addWidget(_pLoadButton,1,0);
    _pGridLayout->addWidget(_pSortUpButton,2,0);
    _pGridLayout->addWidget(_pTable,1,1,3,3);

    connect(_pLoadButton,SIGNAL(clicked()),this,SLOT(WriteTable()));
    connect(_pSortUpButton,SIGNAL(clicked()),this,SLOT(SortUp()));

    //this
    resize(600,300);
    setLayout(_pGridLayout);
}
void TableViewer::SortUp()
{
    chosenFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream fileTextStream1(&chosenFile);

     listStr.sort();

    fileTextStream1<<_pTable->rowCount();
    fileTextStream1<<"\n";
    fileTextStream1<<_pTable->columnCount();
    fileTextStream1<<"\n";
    for(int i=0;i<_pTable->columnCount();++i)
        fileTextStream1<<listStr.at(i)<<'\n';

    chosenFile.close();
}
void TableViewer::keyPressEvent(QKeyEvent *pKEO)
{
    std::cout<<"OK";
    if(pKEO->key()==Qt::Key_L/*&&pKEO->modifiers()==Qt::NoModifier*/)
    {
        WriteTable();
    }

}
