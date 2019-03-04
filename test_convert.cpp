#include "test_convert.h"
#include <QTest>
#include "convert.h"

test_convert::test_convert(QObject *parent) :
    QObject(parent)
{
}
void test_convert::to10(){
    convert con("101", 2, 10, 10);
    QCOMPARE(con.from10(), "5");
}
void test_convert::from10(){
    convert con("5", 10, 10, 2);
    QCOMPARE(con.from10(), "101");
}
