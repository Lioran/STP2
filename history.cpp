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
    QStandardItem *item;
    int row = this->model()->rowCount();
    QStandardItemModel *model = new QStandardItemModel;
    model = (QStandardItemModel*)this->model();
    item = new QStandardItem(QString::number(p1));
    model->setItem(row, 0, item);
    item = new QStandardItem(num1);
    model->setItem(row, 1, item);
    item = new QStandardItem(QString::number(.p2));
    model->setItem(row, 2, item);
    item = new QStandardItem(num2);
    model->setItem(row, 3, item);
    this->setModel(model);
}
void history::clear(){
    delete this->model();
}
int history::count(){
    return this->model()->rowCount();
}
