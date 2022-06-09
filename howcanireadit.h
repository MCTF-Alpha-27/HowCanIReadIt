#ifndef HOWCANIREADIT_H
#define HOWCANIREADIT_H

#include <Python.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HowCanIReadIt; }
QT_END_NAMESPACE

class HowCanIReadIt : public QMainWindow
{
    Q_OBJECT

public:
    HowCanIReadIt(QWidget *parent = nullptr);
    ~HowCanIReadIt();

private slots:
    void on_textEdit_textChanged();

private:
    Ui::HowCanIReadIt *ui;
};
#endif // HOWCANIREADIT_H
