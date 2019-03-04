#include "editor.h"
#include <QString>
editor::editor(){
    this->number = "";
}

void editor::AddDigit(int basis, int symbol){
    if(symbol >= basis) return;
    else if (symbol >= 10) {
        char str = 'A';
        this->number += char(int(str)+(symbol-10));
    }
    else this->number += char(int('0')+symbol);
}
void editor::AddDelim(){
    if(this->number.indexOf(".") != -1 || this->number.length() == 0) return;
    else this->number += ".";
}
void editor::BS(){
    if(this->number.length() != 0)
        this->number = this->number.left(this->number.length()-1);
}
void editor::Clear(){
    this->number = "";
}
