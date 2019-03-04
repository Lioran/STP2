#include "test_editor.h"
#include <QTest>
#include "editor.h"

test_editor::test_editor(QObject *parent) :
    QObject(parent)
{
}

void test_editor::AddDigit(){
    editor ed;
    QString num = "0";
    ed.AddDigit(10, 0);
    QCOMPARE(ed.number, num);
    ed.BS();
    num = "";
    QCOMPARE(ed.number, num);
    ed.AddDigit(16, 15);
    ed.AddDigit(16, 14);
    ed.AddDigit(16, 13);
    ed.AddDigit(16, 12);
    ed.AddDigit(16, 11);
    ed.AddDigit(16, 10);
    num = "FEDCBA";
    QCOMPARE(ed.number, num);
}

void test_editor::AddDelim(){
    editor ed;
    QString num = "0.";
    ed.AddDigit(10,0);
    ed.AddDelim();
    QCOMPARE(ed.number, num);
}
void test_editor::Clear(){
    editor ed;
    QString num = "";
    ed.AddDigit(10,1);
    ed.Clear();
    QCOMPARE(ed.number, num);
}
void test_editor::BS(){
    editor ed;
    QString num = "1";
    ed.AddDigit(10,1);
    ed.AddDigit(10,2);
    ed.BS();
    QCOMPARE(ed.number, num);
}
//QTEST_APPLESS_MAIN(test_editor)
