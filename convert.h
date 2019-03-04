#ifndef CONVERT_H
#define CONVERT_H
#include <QString>

class convert
{
public:
    QString number;
    int basis;
    int percision;
    int new_basis;
    convert(QString number, int basis, int percision, int new_basis);
    void to10();
    QString from10();

};

#endif // CONVERT_H
