#include "test_history.h"
#include <QTest>
#include "history.h"

test_history::test_history(QObject *parent) :
    QObject(parent)
{
}
void test_history::record(){
    history his;
    his.record(10, 4, "65", "1001");
    QCOMPARE(his.rec.p1, 10);
    QCOMPARE(his.rec.p2, 4);
    QCOMPARE(his.rec.number1, "65");
    QCOMPARE(his.rec.number2, "1001");
    QCOMPARE(his.list.front().p1, 10);
    QCOMPARE(his.list.front().p2, 4);
    QCOMPARE(his.list.front().number1, "65");
    QCOMPARE(his.list.front().number2, "1001");
}
void test_history::clear(){
    history his;
    his.record(10, 4, "65", "1001");
    his.clear();
    QCOMPARE(his.count(), 0);
}
void test_history::count(){
    history his;
    his.record(10, 4, "65", "1001");
    QCOMPARE(his.count(), 1);
}
