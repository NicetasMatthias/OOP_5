#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);


    ui->comboBox_mode->addItem("Rational");
    ui->comboBox_mode->addItem("Integer");
}

Interface::~Interface()
{
    delete ui;
}

void Interface::form_request(int t)
{
    QString msg;

    switch (ui->comboBox_mode->currentIndex())
    {
    case MODE_RATIONAL:
        msg << QString().setNum(MODE_RATIONAL);
        msg << ui->spinBox_a_t->text() << ui->spinBox_a_b->text();
        msg << ui->spinBox_b_t->text() << ui->spinBox_b_b->text();
        msg << ui->spinBox_c_t->text() << ui->spinBox_c_b->text();
        msg << QString().setNum(t);
        if (t==VALUE_REQUEST)
        {
            msg << ui->spinBox_x_t->text() << ui->spinBox_x_b->text();
        }
        break;
    case MODE_INT:
        msg << QString().setNum(MODE_INT);
        msg << ui->spinBox_a_t->text();
        msg << ui->spinBox_b_t->text();
        msg << ui->spinBox_c_t->text();
        msg << QString().setNum(t);
        if (t==VALUE_REQUEST)
        {
            msg << ui->spinBox_x_t->text();
        }
        break;
    default: return;;
    }
    emit request(msg);
}

void Interface::answer(QByteArray ans)
{
    QString s;
    int t,pos;
    pos = ans.indexOf(separator.toLatin1());
    t = ans.left(pos).toInt();
    ans = ans.right(ans.length()-pos-1);
    switch (t)
    {
    case VALUE_ANSWER:
        s="Значение в заданой точке: ";
        break;
    case STANDART_ANSWER:
        s="Стандартная форма: ";
        break;
    case CANON_ANSWER:
        s="Каноническая форма: ";

        break;
    case ROOTS_ANSWER:
        s="Корни: ";
        break;
    }

    pos = ans.indexOf(separator.toLatin1());
    s += ans.left(pos);
    ui->lineEdit_result->setText(s);
}

void Interface::on_pushButton_roots_clicked()
{
    form_request(ROOTS_REQUEST);
}

void Interface::on_pushButton_value_clicked()
{
    form_request(VALUE_REQUEST);
}

void Interface::on_pushButton_standart_clicked()
{
    form_request(STANDART_REQUEST);
}

void Interface::on_pushButton_canon_clicked()
{
    form_request(CANON_REQUEST);
}


void Interface::on_comboBox_mode_currentIndexChanged(int index)
{
    switch (index)
    {
    case MODE_INT:
        ui->spinBox_a_b->setEnabled(false);
        ui->spinBox_b_b->setEnabled(false);
        ui->spinBox_c_b->setEnabled(false);
        ui->spinBox_x_b->setEnabled(false);
        break;
    case MODE_RATIONAL:
        ui->spinBox_a_b->setEnabled(true);
        ui->spinBox_b_b->setEnabled(true);
        ui->spinBox_c_b->setEnabled(true);
        ui->spinBox_x_b->setEnabled(true);
        break;

    default:break;
    }
}
