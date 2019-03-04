#include "convert.h"
#include <QString>
#include <QDebug>
#include <QtCore/qmath.h>
#include <string.h>

convert::convert(QString number, int basis, int percision, int new_basis)
{
    this->number = number;
    this->basis = basis;
    this->percision = percision;
    this->new_basis = new_basis;
}
void convert::to10(){
    int token = this->number.indexOf(".");
    if(token == -1){
        int num = this->number.toInt(0, this->basis);
        this->number = QString::number(num, 10);
    }
    else{
        QString doo = this->number.left(token);
        std::string posle = this->number.right(this->number.length()-token-1).toStdString();
        int len = posle.length();
        int num = doo.toInt(nullptr, this->basis);
        double num_pos = 0.0;
        double step = 0.0;
        step = (double)1/this->basis;
        for(int i = 0; i < len; i++){
            if((int)posle[i]%65 < 6 && (int)posle[i]%65 >=0){
                num_pos += ((int)posle[i]%65 + 10) * step;
            }else{
                num_pos += ((int)posle[i]%48) * step;
            }
            step /= this->basis;
        }
        num_pos += (double)num;
        this->number = QString::number(num_pos, 'f', this->number.length());
        qDebug() << this->number<< endl;
    }
}

QString convert::from10(){
    this->to10();
    int token = this->number.indexOf(".");
    if(token == -1){
        return  QString::number(this->number.toInt(), this->new_basis);
    }
    else{
        QString doo = this->number.left(token);
        std::string posle = this->number.right(this->number.length()-token-1).toStdString();
        int len = posle.length();
        int num = doo.toInt();
        int num_n = 0;
        int k = 1;
        while(num > 0){
            num_n += (num%this->new_basis)*k;
            num /= this->new_basis;
            k *= 10;
        }
        double num_pos = 0.0;
        double step = 10.0;
        for(int i = 0; i < len; i++){
            num_pos += (double)(posle[i]%48)/step;
            step *= 10;
        }
        int count = this->percision;
        step = 10;
        double num_pos_n = 0.0;
        int temp = 0;
        while(num_pos > 0.00000001 && count != 0){
            num_pos *= this->new_basis;
            temp = (int)num_pos;
            num_pos -= (double)temp;
            num_pos_n += (double)temp/step;
            step *= 10;
        }
        num_pos_n += (double)num_n;
        QString result = QString::number(num_pos_n, 'f', this->number.length());
        qDebug() << result<< endl;
        return  result;
    }
}
