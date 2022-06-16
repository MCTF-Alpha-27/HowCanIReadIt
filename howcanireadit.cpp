#include "howcanireadit.h"
#include "ui_howcanireadit.h"

#include <Python.h>

#include <iostream>

using namespace std;

HowCanIReadIt::HowCanIReadIt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HowCanIReadIt)
{
    ui->setupUi(this);
}

HowCanIReadIt::~HowCanIReadIt()
{
    delete ui;
}


void HowCanIReadIt::on_textEdit_textChanged()
{
    QString qwords = ui->textEdit->toPlainText();
    qDebug() << qwords;
    Py_Initialize();
    PyObject* pypinyin = PyImport_ImportModule("pypinyin");
    if (ui->checkBox->isChecked()) {
        PyObject* lazy_pinyin = PyObject_GetAttrString(pypinyin, "lazy_pinyin");
        PyObject* result = PyObject_CallFunction(lazy_pinyin, "s", qwords.toStdString().c_str());
        PyObject* repr = PyObject_Repr(result);
        PyObject* unicode = PyUnicode_AsEncodedString(repr, "utf-8", "strict");
        string str = PyBytes_AsString(unicode);
        ui->textEdit_2->setText(str.c_str());
    } else {
        PyObject* pinyin = PyObject_GetAttrString(pypinyin, "pinyin");
        PyObject* result = PyObject_CallFunction(pinyin, "s", qwords.toStdString().c_str());
        PyObject* repr = PyObject_Repr(result);
        PyObject* unicode = PyUnicode_AsEncodedString(repr, "utf-8", "strict");
        string str = PyBytes_AsString(unicode);
        ui->textEdit_2->setText(str.substr(1, str.length() - 2).c_str());
    }
    Py_Finalize();
}


void HowCanIReadIt::on_checkBox_stateChanged(int arg1)
{
    this->on_textEdit_textChanged();
}

