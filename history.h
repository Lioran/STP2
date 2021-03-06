#ifndef HISTORY_H
#define HISTORY_H
#include <QString>
#include <QList>
#include <QTableView>
#include <QStandardItemModel>

class history: public QTableView
{
    Q_OBJECT
public:
    history(QTableView* parent = nullptr);
    void record(int p1, int p2, QString num1, QString num2);
    void clear();
    int count();
};

#endif // HISTORY_H
