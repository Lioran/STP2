#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include "test_editor.h"
#include "test_convert.h"
#include "test_history.h"

int main(int argc, char *argv[])
{
    freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    QTest::qExec(new test_editor, argc, argv);
    QTest::qExec(new test_convert, argc, argv);
    //QTest::qExec(new test_history, argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
