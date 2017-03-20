#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QWidget>
#include <QString>
#include <QTimer>

namespace Ui {
class GradeCalculator;
}

class GradeCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit GradeCalculator(QWidget *parent = 0);
    void reset();
    ~GradeCalculator();

private:
    Ui::GradeCalculator *ui;
    int midterm_1_value = 0;
    int midterm_2_value = 0;
    double final_grade = 0;
    int course_type = 0;
    bool schema_a = true;
    bool schema_b = false;
    int hw1 = 0;
    int hw2 = 0;
    int hw3 = 0;
    int hw4 = 0;
    int hw5 =0;
    int hw6 =0;
    int hw7 =0;
    int hw8 =0;

protected slots:
    void on_midterm1_slider_valueChanged(int value);
    void on_midterm2_slider_valueChanged(int value);
    void on_final_slider_valueChanged(int value);
    void on_midterm1_spin_valueChanged(int value);
    void on_midterm2_spin_valueChanged(int value);
    void on_final_spin_valueChanged(int value);
    void on_schema_a_toggled(bool checked);
    void on_schema_b_toggled(bool checked);
    void on_course_name_box_currentIndexChanged(int index);
    void calculateGrades();
    void on_slide1_valueChanged(int value);
    void on_spin1_valueChanged(int value);
    void on_slide2_valueChanged(int value);
    void on_spin2_valueChanged(int value);
    void on_slide3_valueChanged(int value);
    void on_spin3_valueChanged(int value);
    void on_slide4_valueChanged(int value);
    void on_spin4_valueChanged(int value);
    void on_slide5_valueChanged(int value);
    void on_spin5_valueChanged(int value);
    void on_slide6_valueChanged(int value);
    void on_spin6_valueChanged(int value);
    void on_slide7_valueChanged(int value);
    void on_spin7_valueChanged(int value);
    void on_slide8_valueChanged(int value);
    void on_spin8_valueChanged(int value);
};

#endif // GRADECALCULATOR_H
