#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
#include <QMessageBox>
#include <QColorDialog>
#include <qmath.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void RGB_to_XYZ_and_LAB();
    void XYZ_to_RGB_and_LAB();
    void LAB_to_RGB_and_XYZ();
    QColorDialog *colordialog;

private slots:
    void on_color_button_clicked();
    void setNames(){
        cmodel_setNames_1();
        cmodel_setNames_2();
        cmodel_setNames_3();
    }
    void cmodel_setNames_1();
    void cmodel_setNames_2();
    void cmodel_setNames_3();
    void setValues(){
        cmodel_setValues_1();
        cmodel_setValues_2();
        cmodel_setValues_3();
    }
    void cmodel_setValues_1();
    void cmodel_setValues_2();
    void cmodel_setValues_3();

    void on_cmodel_1_currentTextChanged(const QString &arg1);

    void on_cmodel_2_currentTextChanged(const QString &arg1);

    void on_cmodel_3_currentTextChanged(const QString &arg1);

    void on_line11_editingFinished();

    void on_line21_editingFinished();

    void on_line31_editingFinished();

    void on_line12_editingFinished();

    void on_line22_editingFinished();

    void on_line32_editingFinished();

    void on_line13_editingFinished();

    void on_line23_editingFinished();

    void on_line33_editingFinished();

    void on_line14_editingFinished();

    void on_line24_editingFinished();

    void on_line34_editingFinished();

    void on_slider_1_valueChanged(int value);

    void on_slider_2_valueChanged(int value);

    void on_slider_3_valueChanged(int value);

    void setSliderValue();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
