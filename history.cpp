#include "history.h"
#include <QString>
#include <QStandardItem>
#include <QStandardItem>

history::history(QTableView* parent):QTableView (parent)
{   
    QStringList horizontalHeader;
    horizontalHeader.append("Из");
    horizontalHeader.append("Этого");
    horizontalHeader.append("Вот в");
    horizontalHeader.append("Это");
    QStandardItemModel *model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(horizontalHeader);
    this->setModel(model);
}
void history::record(int p1, int p2, QString num1, QString num2){
    this->rec.p1 = p1;
    this->rec.p2 = p2;
    this->rec.number1 = num1;
    this->rec.number2 = num2;
    this->list.push_back(rec);
    QStandardItem *item;
    int row = this->model()->rowCount();
    QStandardItemModel *model = new QStandardItemModel;
    model = (QStandardItemModel*)this->model();
    item = new QStandardItem(QString::number(this->rec.p1));
    model->setItem(row, 0, item);
    item = new QStandardItem(this->rec.number1);
    model->setItem(row, 1, item);
    item = new QStandardItem(QString::number(this->rec.p2));
    model->setItem(row, 2, item);
    item = new QStandardItem(this->rec.number2);
    model->setItem(row, 3, item);
    this->setModel(model);
}
void history::clear(){
    this->list.clear();
    delete this->model();
}
int history::count(){
    return this->list.count();
}
