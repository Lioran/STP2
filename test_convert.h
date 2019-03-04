#ifndef TEST_CONVERT_H
#define TEST_CONVERT_H

#include <QObject>

class test_convert: public QObject
{
    Q_OBJECT
public:
    explicit test_convert(QObject *parent = nullptr);
private slots:
    void to10();
    void from10();
};

#endif // TEST_CONVERT_H
