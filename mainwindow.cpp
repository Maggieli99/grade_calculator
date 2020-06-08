#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hw_num(0)
{
    ui->setupUi(this);
    setWindowTitle("Grade Calculator");
    QObject::connect(ui->spinHW1, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_HW1, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));

    QObject::connect(ui->spinHW2, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_HW2, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));

    QObject::connect(ui->spinHW3, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_HW3, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));

    QObject::connect(ui->spinHW4, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_HW4, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));



    QObject::connect(ui->spinHW5, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_HW5, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));


    QObject::connect(ui->spinFP, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_FP, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));



    QObject::connect(ui->spinMid, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_Mid, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));


    QObject::connect(ui->spinFinal, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));
    QObject::connect(ui->Slider_Final, SIGNAL(valueChanged(int)),
                     this,SLOT(calculateScore()));


    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(showGrade()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateScore(){
    if ((ui->comboBox->itemText(ui->comboBox->currentIndex()) == "PIC 10C")) {
        hw_num = 3;
    }
    else if ((ui->comboBox->itemText(ui->comboBox->currentIndex()) == "PIC 10B"))
    {
        hw_num = 5;
    }

    hw_sum = ui->spinHW1->value()
            + ui->spinHW2->value()
            + ui->spinHW3->value()
            + ui->spinHW4->value()
            + ui->spinHW5->value();



    final_proj = ui->spinFP->value();
    mid = ui->spinMid->value();
    final = ui->spinFinal->value();
    hw_total = hw_num * 20;

    calculateScheme1();
    calculateScheme2();

    showDetail();
}

void MainWindow::calculateScheme1(){
    if ((ui->comboBox->itemText(ui->comboBox->currentIndex()) == "PIC 10C")) {
        final_grade1 = (hw_sum / hw_total  * 0.15 + final_proj / 20 * 0.35 + mid / 37 * 0.25 + final / 100 * 0.3) * 100;
    }
    else {
        final_grade1 = (hw_sum / hw_total * 0.3 + mid / 37 * 0.3 + final / 100 * 0.4) * 100;
    }
}

void MainWindow::calculateScheme2(){
    if ((ui->comboBox->itemText(ui->comboBox->currentIndex()) == "PIC 10C")) {
        final_grade2 = (hw_sum / hw_total  * 0.15 + final_proj / 20 * 0.35 + final / 100 * 0.5) * 100;
    }
    else {
        return;
    }
}

void MainWindow::showGrade() {
    QString temp;
    if (final_grade1 > final_grade2) {
        final_grade = final_grade1;
    }
    else {
        final_grade = final_grade2;
    }

    if (final_grade >= 93) {
        temp = QString::number(final_grade, 'f', 2) + "  A";
    }
    else if (final_grade >= 90) {
        temp = QString::number(final_grade,'f', 2) + "  A-";
    }
    else if (final_grade >= 87) {
        temp = QString::number(final_grade,'f', 2) + "  B+";
    }
    else if (final_grade >= 83) {
        temp = QString::number(final_grade,'f', 2) + "  B";
    }
    else if (final_grade >= 80) {
        temp = QString::number(final_grade,'f', 2) + "  B-";
    }
    else if (final_grade >= 77) {
        temp = QString::number(final_grade,'f', 2) + "  C+";
    }
    else if (final_grade >= 73) {
        temp = QString::number(final_grade,'f', 2) + "  C";
    }
    else if (final_grade >= 70) {
        temp = QString::number(final_grade,'f', 2) + "  C-";
    }
    else if (final_grade < 70) {
        temp = QString::number(final_grade,'f', 2) + "  Fail";
    }


    ui->grade->setText(temp);
    ui->grade->repaint();
}

void MainWindow::showDetail() {
    if ((ui->comboBox->itemText(ui->comboBox->currentIndex()) == "PIC 10C")) {
        ui->label_11->setText(QString::number(hw_sum) + " / " + QString::number(hw_total) + " *0.15 + "
                              + QString::number(final_proj) + " / 20 * 0.35 + "
                              + QString::number(mid) + " / 37 * 0.25 + "
                              + QString::number(final) + " / 100 * 0.3"
                              + " = " + QString::number(final_grade1,'f', 2));


        ui->label_12->setText(QString::number(hw_sum) + " / " + QString::number(hw_total) + " *0.15 + "
                              + QString::number(final_proj) + " / 20 * 0.35 + "
                              + QString::number(final) + " / 100 * 0.5"
                              + " = " + QString::number(final_grade2, 'f',2));
    }
    else {
        ui->label_11->setText(QString::number(hw_sum) + " / " + QString::number(hw_total) + " *0.3 + "
                              + QString::number(mid) + " / 37 * 0.3 + "
                              + QString::number(final) + " / 100 * 0.4"
                              + " = " + QString::number(final_grade1, 'f', 2));
        ui->label_12->setText("NA (This course only have one grading scheme.)");
    }
}

