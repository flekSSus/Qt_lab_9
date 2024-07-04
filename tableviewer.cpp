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

    _pTable=new QTableWidget(this);
    _pLoadButton=new QPushButton("Load",this);
    _pSortUpButton=new QPushButton("Sort Up",this);
    _pGridLayout=new QGridLayout(this);
    _pLabelImage=new QLabel(this);
    _pContMenu=new QMenu(this);
    _pChBoxBackGround=new QCheckBox("Random Background Color",this);

    //CheckBox

    _pChBoxBackGround->setCheckState(Qt::Unchecked);


    //ContextMenu

    _pContMenu->addAction("Close");

    //Pixmap

    _pImage.load("Qt_Image_PNG.png");

    //Label Image

    _pLabelImage->setPixmap(_pImage);

    //Layout

    _pGridLayout->addWidget(_pLoadButton,1,0);
    _pGridLayout->addWidget(_pSortUpButton,2,0);
    _pGridLayout->addWidget(_pTable,1,1,3,3);
    _pGridLayout->addWidget(_pLabelImage,3,0);
    _pGridLayout->addWidget(_pChBoxBackGround,4,0);

    connect(_pLoadButton,SIGNAL(clicked()),this,SLOT(WriteTable()));
    connect(_pSortUpButton,SIGNAL(clicked()),this,SLOT(SortUp()));
    connect(_pContMenu,SIGNAL(triggered(QAction*)),this,SLOT(close()));
    connect(_pChBoxBackGround,&QCheckBox::toggled,this,&TableViewer::ChangeBackground);

    //this
    setFocusPolicy(Qt::StrongFocus);
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
    switch (pKEO->key())
        {
    case Qt::Key_L:
        WriteTable();
        break;
        }

}
void TableViewer::mousePressEvent(QMouseEvent *pMEO)
{
    if(pMEO->button()==Qt::RightButton)
    {
        _pContMenu->setGeometry(pMEO->globalX(),pMEO->globalY(),100,30);
        _pContMenu->show();
    }

}

void TableViewer::ChangeBackground()
{
    if(_pChBoxBackGround->isChecked())
    {
        switch (rand()%4)
        {
        case 0:
        {
            QPalette pal1;
            pal1.setColor(QPalette::Window,Qt::green);
            this->setPalette(pal1);
        }
            break;
        case 1:
        {
            QPalette pal1;
            pal1.setColor(QPalette::Window,Qt::red);
            this->setPalette(pal1);
        }
            break;
        case 2:
        {
            QPalette pal2;
            pal2.setColor(QPalette::Window,Qt::blue);
            this->setPalette(pal2);
        }
            break;
        case 3:
        {
            QPalette pal3;
            pal3.setColor(QPalette::Window,Qt::yellow);
            this->setPalette(pal3);
        }
            break;
        }
    }
    else
    {
        QPalette pal2;
        pal2.setColor(QPalette::Window,Qt::white);
        this->setPalette(pal2);
    }
}

