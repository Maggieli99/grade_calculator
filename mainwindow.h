#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QPushButton>


namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void compute_overall();
    //void valueChanged(int value);

public slots:
    void calculateScore();
    void showDetail();
    void showGrade();

private:
    Ui::MainWindow *ui;
    double hw_sum;
    double final_proj;
    double mid;
    double final;
    double final_grade1;
    double final_grade2;
    double final_grade;

    double hw_total;
    double hw_num;

    void calculateScheme1();
    void calculateScheme2();
    //void showGrade();

};


#endif // MAINWINDOW_H
