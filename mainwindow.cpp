#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString vString = ui->lineEdit->text();
    int j=0;
    vString.append('$');
    for(int i=0 ; i<vString.size();++i)
    {
        if(vString[i]=='*'||vString[i]=='$')
        {
            vInputString.push_back(vString.mid(j,i-j));
            j=i+1;
            vInputString.push_back(vString.mid(i,1));
        }
    }


    Parse vParse;
    vParse.check(vInputString);

    std::vector<QString> temp= vParse.getOutput();
    for(std::vector<QString>::size_type i=0; i<temp.size(); ++i)
    {

        ui->textEdit->append(temp[i]);

    }
    //        ui->textEdit->append(vInputString[i]+"\n");

}
