#include "gradecalculator.h"
#include "ui_gradecalculator.h"

GradeCalculator::GradeCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);

    connect(ui->final_spin, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->midterm1_slider, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->midterm2_slider, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide1, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide2, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide3, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide4, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide5, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide6, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide7, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->slide8, SIGNAL(valueChanged(int)), this, SLOT(calculateGrades()));
    connect(ui->schema_a, SIGNAL(toggled(bool)), this, SLOT(calculateGrades()));
    connect(ui->schema_b, SIGNAL(toggled(bool)), this, SLOT(calculateGrades()));
    connect(ui->course_name_box, SIGNAL(currentIndexChanged(int)), this, SLOT(calculateGrades()));
  //  int numAssign = 8;
   // int hw_col = 3;
  /*  QVector<QString> name;

   QLabel* gradeBoard[8];
   QSlider* gradeSlider[8];
   QSpinBox* gradeSpin[8];

   for (int i = 1; i <= numAssign; ++i)
   {
      QString temp = QString::number(i);
      name[i] = "slide" + temp;
   }
    for(int row=0; row<numAssign; row++)
     {
        for (int col = 0; col < hw_col; col++)
        {
            if (col == 0)
           {
            gradeBoard[row] = new QLabel(this);
            gradeBoard[row]->setText(tr("Hw %1").arg(row+1));

            ui->hw_layout->addWidget(gradeBoard[row], row, col);
            }
            else if (col == 1)
            {
                gradeSlider[row] = new QSlider(this);
                gradeSlider[row]->setRange(0, 100);
                gradeSlider[row]->setOrientation(Qt::Horizontal);
                gradeSlider[row]->setObjectName(name[row]);
                ui->hw_layout->addWidget(gradeSlider[row], row, col);
            }
            else if (col == 2)
            {
                gradeSpin[row] = new QSpinBox(this);
                gradeSpin[row]->setRange(0, 100);

                ui->hw_layout->addWidget(gradeSpin[row], row, col);
            }
        }

        connect(gradeSpin[row], SIGNAL(valueChanged(int)),gradeSlider[row],SLOT(setValue(int)) );
        connect(gradeSlider[row],SIGNAL(valueChanged(int)),gradeSpin[row],SLOT(setValue(int)) );

      }


    //connect(midterm1_spin, SIGNAL(valueChanged(int)),midterm1_slider,SLOT(setValue(int)) );
    //connect(midterm1_slider,SIGNAL(valueChanged(int)),midterm1_spin,SLOT(setValue(int)) );

    //connect(midterm2_spin, SIGNAL(valueChanged(int)),midterm2_slider,SLOT(setValue(int)) );
    //connect(midterm2_slider,SIGNAL(valueChanged(int)),midterm2_spin,SLOT(setValue(int)) );

    //connect(final_spin, SIGNAL(valueChanged(int)),final_slider,SLOT(setValue(int)) );
    //connect(final_slider,SIGNAL(valueChanged(int)),final_spin,SLOT(setValue(int)) );
*/

}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}
void GradeCalculator::on_midterm1_slider_valueChanged(int value)
{
    midterm_1_value = value;
    ui->midterm1_spin->setValue(midterm_1_value);
}

void GradeCalculator::on_midterm2_slider_valueChanged(int value)
{
    midterm_2_value = value;
    ui->midterm2_spin->setValue(midterm_2_value);
}
void GradeCalculator::on_final_slider_valueChanged(int value){
    final_value = value;
    ui->final_spin->setValue(final_value);
}
void GradeCalculator::on_midterm1_spin_valueChanged(int value){

    midterm_1_value = value;
    ui->midterm1_slider->setValue(midterm_1_value);

}
void GradeCalculator::on_midterm2_spin_valueChanged(int value){
    midterm_2_value = value;
    ui->midterm2_slider->setValue(midterm_2_value);
}
void GradeCalculator::on_final_spin_valueChanged(int value){
    final_value = value;
    ui->final_slider->setValue(final_value);
}

void GradeCalculator::on_course_name_box_currentIndexChanged(int index)
{
    if (index == 0)
    {
        course_type = 0;
    }
    else if (index == 1)
    {
        course_type = 1;
    }
}


void GradeCalculator::on_schema_a_toggled(bool checked)
{
    if(checked)
    {
        schema_a = true;
        schema_b = false;
    }
    reset();
}

void GradeCalculator::on_schema_b_toggled(bool checked)
{
    if(checked)
    {
        schema_b = true;
        schema_a = false;
    }
    reset();
}

void GradeCalculator::calculateGrades(){

    if (schema_a == true && course_type == 0)
    {
        final_grade = 0.25 * (hw1+ hw2+hw3+hw4+hw5+hw6+hw7+hw8)/8 + .20 * midterm_1_value + .20 * midterm_2_value + 0.35 * final_value;
    }
    else if (schema_b == true && course_type == 0)
    {
        int high_midterm = 0;
        if (midterm_2_value <= midterm_1_value){
            high_midterm = midterm_1_value;
        }
        else{
            high_midterm = midterm_2_value;
        }
        final_grade = 0.25 * (hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)/8 + 0.3 * high_midterm + 0.45* final_value;
    }
    if (schema_a == true && course_type == 1)
    {
        final_grade = 0.35 * (hw1+ hw2+hw3+hw4+hw5+hw6+hw7+hw8)/8 + .10 * midterm_1_value + .20 * midterm_2_value + 0.35 * final_value;
    }
    else if (schema_b == true && course_type == 1)
    {
        int high_midterm = 0;
        if (midterm_2_value <= midterm_1_value){
            high_midterm = midterm_1_value;
        }
        else{
            high_midterm = midterm_2_value;
        }
        final_grade = 0.35 * (hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)/8 + 0.2 * high_midterm + 0.45* final_value;
    }
    QString final = QString::number(final_grade);
    ui->final_score_label->setText(final);
}

/*void GradeCalculator::get_hw_grade(int i){
 hw_grades[i] = gradeSpin[i]->value();
}*/

void GradeCalculator::on_slide1_valueChanged(int value)
{
    hw1 = value;
    ui->spin1->setValue(value);
}

void GradeCalculator::on_spin1_valueChanged(int value)
{
    hw1 = value;
    ui->slide1->setValue(value);
}

void GradeCalculator::on_slide2_valueChanged(int value)
{
    hw2 = value;
    ui->spin2->setValue(value);
}

void GradeCalculator::on_spin2_valueChanged(int value)
{
    hw2 = value;
    ui->slide2->setValue(value);
}

void GradeCalculator::on_slide3_valueChanged(int value)
{
    hw3 = value;
    ui->spin3->setValue(value);
}

void GradeCalculator::on_spin3_valueChanged(int value)
{
    hw3 = value;
    ui->slide3->setValue(value);
}

void GradeCalculator::on_slide4_valueChanged(int value)
{
    hw4 = value;
    ui->spin4->setValue(value);
}

void GradeCalculator::on_spin4_valueChanged(int value)
{
    hw4 = value;
    ui->slide4->setValue(value);
}
void GradeCalculator::on_slide5_valueChanged(int value)
{
    hw5 = value;
    ui->spin5->setValue(value);
}

void GradeCalculator::on_spin5_valueChanged(int value)
{
    hw5 = value;
    ui->slide5->setValue(value);
}
void GradeCalculator::on_slide6_valueChanged(int value)
{
    hw6 = value;
    ui->spin6->setValue(value);
}

void GradeCalculator::on_spin6_valueChanged(int value)
{
    hw6 = value;
    ui->slide6->setValue(value);
}
void GradeCalculator::on_slide7_valueChanged(int value)
{
    hw7 = value;
    ui->spin7->setValue(value);
}

void GradeCalculator::on_spin7_valueChanged(int value)
{
    hw7 = value;
    ui->slide7->setValue(value);
}
void GradeCalculator::on_slide8_valueChanged(int value)
{
    hw8 = value;
    ui->spin8->setValue(value);
}

void GradeCalculator::on_spin8_valueChanged(int value)
{
    hw8 = value;
    ui->slide8->setValue(value);
}

void GradeCalculator::reset(){
    midterm_1_value = 0;
    midterm_2_value = 0;
    final_grade = 0;
    schema_a = true;
    schema_b = false;
    hw1 = 0;
    hw2 = 0;
    hw3 = 0;
    hw4 = 0;
    hw5 = 0;
    hw6 = 0;
    hw7 = 0;
    hw8 = 0;
    ui->midterm1_slider->setValue(0);
    ui->midterm2_slider->setValue(0);
    ui->final_slider->setValue(0);
    ui->schema_a(true);
    ui->hw1->setValue(0);
    ui->hw2->setValue(0);
    ui->hw3->setValue(0);
    ui->hw4->setValue(0);
    ui->hw5->setValue(0);
    ui->hw6->setValue(0);
    ui->hw7->setValue(0);
    ui->hw8->setValue(0);
}
