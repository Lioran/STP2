#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "convert.h"
#include "editor.h"
#include "history.h"
#include <QMessageBox>
#include <QDebug>
#include <QStandardItem>
#include <QStandardItemModel>

QStandardItemModel *model = new QStandardItemModel;
QStandardItem *item;
history *hiss;
editor *ed;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT (AddDigit()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT (AddDelim()));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT (BS()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT (Clear()));
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)),this,SLOT(OnDoubleClicked(QModelIndex)));
    hiss = new history;
    ed = new editor;
    ui->tableView->setModel(hiss->model());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddDigit(){
    int num_n =  0;
    std::string symbol = qobject_cast<QPushButton*>(sender())->text().toStdString();
    if((int)symbol[0]%65 < 6 && (int)symbol[0]%65 >=0){
        num_n = (int)symbol[0]%65 + 10;
    }else {
        num_n = qobject_cast<QPushButton*>(sender())->text().toInt();
    }
    int len = ed->number.length();
    ed->AddDigit(ui->comboBox->currentIndex()+2, num_n);
    if(ed->number.length() != len) ui->lineEdit->setText(ed->number);
}
void MainWindow::AddDelim(){
    ed->AddDelim();
    ui->lineEdit->setText(ed->number);
}
void MainWindow::BS(){
    ed->BS();
    ui->lineEdit->setText(ed->number);
}
void MainWindow::Clear(){
    ed->Clear();
    ui->lineEdit->setText(ed->number);
    ui->lineEdit_2->clear();
}
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ed->Clear();
    ui->lineEdit->setText("");
    ui->label->setText("Из "+QString::number(index+2));
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    ui->lineEdit_2->setText("");
    ui->label_2->setText("В "+QString::number(index+2));
}

void MainWindow::on_pushButton_20_clicked()
{
    convert c(ui->lineEdit->text(), ui->comboBox->currentIndex()+2, 10, ui->comboBox_2->currentIndex()+2);
    QString result = c.from10();
    ui->lineEdit_2->setText(result);
    hiss->record(ui->comboBox->currentIndex()+2, ui->comboBox_2->currentIndex()+2, ui->lineEdit->text(), ui->lineEdit_2->text());
    ui->tableView->setModel(hiss->model());
}
void MainWindow::on_action_triggered()
{
    this->close();
}
void MainWindow::OnDoubleClicked(const QModelIndex &index){
    ui->comboBox->setCurrentIndex(index.model()->data(index.model()->index(index.row(), 0)).toInt()-2);
    ui->comboBox_2->setCurrentIndex(index.model()->data(index.model()->index(index.row(), 2)).toInt()-2);
    ui->lineEdit->setText(index.model()->data(index.model()->index(index.row(), 1)).toString());
    ui->lineEdit_2->setText(index.model()->data(index.model()->index(index.row(), 3)).toString());
}

void MainWindow::on_pushButton_21_clicked()
{
    hiss->clear();
    hiss = new history;
    ui->tableView->setModel(hiss->model());
}
