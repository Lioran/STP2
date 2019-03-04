#ifndef EDITOR_H
#define EDITOR_H
#include <QString>

class editor
{
public:
    editor();
    QString number = "";
    void AddDigit(int basis, int symbol);
    void AddDelim();
    void BS();
    void Clear();
};

#endif // EDITOR_H
