#ifndef TEST_EDITOR_H
#define TEST_EDITOR_H

#include <QObject>

class test_editor : public QObject
{
    Q_OBJECT
public:
    explicit test_editor(QObject *parent = nullptr);
private slots:
    void AddDigit();
    void AddDelim();
    void BS();
    void Clear();
};

#endif // TEST_EDITOR_H
