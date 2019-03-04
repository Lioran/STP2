#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_20_clicked();

    void AddDigit();

    void AddDelim();

    void BS();

    void Clear();

    void on_action_triggered();

    void OnDoubleClicked(const QModelIndex &index);
    void on_pushButton_21_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
