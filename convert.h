#ifndef CONVERT_H
#define CONVERT_H
#include <QString>

class convert
{
public:
    convert(QString number, int basis, int percision, int new_basis);
    QString from10();
private:
    QString number;
    int basis;
    int percision;
    int new_basis;
    void to10();
};

#endif // CONVERT_H
