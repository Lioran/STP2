#ifndef TEST_HISTORY_H
#define TEST_HISTORY_H

#include <QObject>

class test_history : public QObject
{
    Q_OBJECT
public:
    explicit test_history(QObject *parent = nullptr);
private slots:
    void record();
    void clear();
    void count();
};

#endif // TEST_HISTORY_H
