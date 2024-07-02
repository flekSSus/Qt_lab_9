#include<QApplication>
#include"tableviewer.h"

int main(int argv,char **args)
{

    QApplication app1(argv,args);

    TableViewer table1;

    table1.show();

    app1.exec();
}
