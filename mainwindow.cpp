#include "mainwindow.h"
#include "ui_mainwindow.h"

QColor color;
double X, Y, Z;
double L, a, b;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cmodel_1->addItem("");
    ui->cmodel_1->addItem("RGB");
    ui->cmodel_1->addItem("CMYK");
    ui->cmodel_1->addItem("HSV");
    ui->cmodel_1->addItem("HLS");
    ui->cmodel_1->addItem("XYZ");
    ui->cmodel_1->addItem("LAB");

    ui->cmodel_2->addItem("");
    ui->cmodel_2->addItem("RGB");
    ui->cmodel_2->addItem("CMYK");
    ui->cmodel_2->addItem("HSV");
    ui->cmodel_2->addItem("HLS");
    ui->cmodel_2->addItem("XYZ");
    ui->cmodel_2->addItem("LAB");

    ui->cmodel_3->addItem("");
    ui->cmodel_3->addItem("RGB");
    ui->cmodel_3->addItem("CMYK");
    ui->cmodel_3->addItem("HSV");
    ui->cmodel_3->addItem("HLS");
    ui->cmodel_3->addItem("XYZ");
    ui->cmodel_3->addItem("LAB");

    color.setRgb(255,255,255);

    RGB_to_XYZ_and_LAB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cmodel_setNames_1()
{
    ui->line14->hide();
    ui->label11->clear();
    ui->label12->clear();
    ui->label13->clear();
    ui->label14->clear();
    ui->label14->hide();
    if (ui->cmodel_1->currentText() == "RGB"){
        ui->label11->setText("R:");
        ui->label12->setText("G:");
        ui->label13->setText("B:");
    }
    else if (ui->cmodel_1->currentText() == "CMYK"){
        ui->line14->show();
        ui->label14->show();
        ui->label11->setText("C:");
        ui->label12->setText("M:");
        ui->label13->setText("Y:");
        ui->label14->setText("K:");
    }
    else if (ui->cmodel_1->currentText() == "HSV"){
        ui->label11->setText("H:");
        ui->label12->setText("S:");
        ui->label13->setText("V:");
    }
    else if (ui->cmodel_1->currentText() == "HLS"){
        ui->label11->setText("H:");
        ui->label12->setText("L:");
        ui->label13->setText("S:");
    }
    else if (ui->cmodel_1->currentText() == "XYZ"){
        ui->label11->setText("X:");
        ui->label12->setText("Y:");
        ui->label13->setText("Z:");
    }
    else if (ui->cmodel_1->currentText() == "LAB"){
        ui->label11->setText("L:");
        ui->label12->setText("A:");
        ui->label13->setText("B:");
    }

    cmodel_setValues_1();
}

void MainWindow::cmodel_setNames_2()
{
    ui->line24->hide();
    ui->label21->clear();
    ui->label22->clear();
    ui->label23->clear();
    ui->label24->clear();
    ui->label24->hide();
    if (ui->cmodel_2->currentText() == "RGB"){
        ui->label21->setText("R:");
        ui->label22->setText("G:");
        ui->label23->setText("B:");
    }
    else if (ui->cmodel_2->currentText() == "CMYK"){
        ui->line24->show();
        ui->label24->show();
        ui->label21->setText("C:");
        ui->label22->setText("M:");
        ui->label23->setText("Y:");
        ui->label24->setText("K:");
    }
    else if (ui->cmodel_2->currentText() == "HSV"){
        ui->label21->setText("H:");
        ui->label22->setText("S:");
        ui->label23->setText("V:");
    }
    else if (ui->cmodel_2->currentText() == "HLS"){
        ui->label21->setText("H:");
        ui->label22->setText("L:");
        ui->label23->setText("S:");
    }
    else if (ui->cmodel_2->currentText() == "XYZ"){
        ui->label21->setText("X:");
        ui->label22->setText("Y:");
        ui->label23->setText("Z:");
    }
    else if (ui->cmodel_2->currentText() == "LAB"){
        ui->label21->setText("L:");
        ui->label22->setText("A:");
        ui->label23->setText("B:");
    }

    cmodel_setValues_2();
}

void MainWindow::cmodel_setNames_3()
{
    ui->line34->hide();
    ui->label31->clear();
    ui->label32->clear();
    ui->label33->clear();
    ui->label34->clear();
    ui->label34->hide();
    if (ui->cmodel_3->currentText() == "RGB"){
        ui->label31->setText("R:");
        ui->label32->setText("G:");
        ui->label33->setText("B:");
    }
    else if (ui->cmodel_3->currentText() == "CMYK"){
        ui->line34->show();
        ui->label34->show();
        ui->label31->setText("C:");
        ui->label32->setText("M:");
        ui->label33->setText("Y:");
        ui->label34->setText("K:");
    }
    else if (ui->cmodel_3->currentText() == "HSV"){
        ui->label31->setText("H:");
        ui->label32->setText("S:");
        ui->label33->setText("V:");
    }
    else if (ui->cmodel_3->currentText() == "HLS"){
        ui->label31->setText("H:");
        ui->label32->setText("L:");
        ui->label33->setText("S:");
    }
    else if (ui->cmodel_3->currentText() == "XYZ"){
        ui->label31->setText("X:");
        ui->label32->setText("Y:");
        ui->label33->setText("Z:");
    }
    else if (ui->cmodel_3->currentText() == "LAB"){
        ui->label31->setText("L:");
        ui->label32->setText("A:");
        ui->label33->setText("B:");
    }

    cmodel_setValues_3();
}

void MainWindow::cmodel_setValues_1()
{
    if (ui->cmodel_1->currentText() == "RGB"){
        ui->line11->setText(QString::number(color.red()));
        ui->line12->setText(QString::number(color.green()));
        ui->line13->setText(QString::number(color.blue()));
    }

    if (ui->cmodel_1->currentText() == "CMYK"){
        ui->line11->setText(QString::number(color.cyan()));
        ui->line12->setText(QString::number(color.magenta()));
        ui->line13->setText(QString::number(color.yellow()));
        ui->line14->setText(QString::number(color.black()));
    }

    if (ui->cmodel_1->currentText() == "HSV"){
        ui->line11->setText(QString::number(color.hue()));
        ui->line12->setText(QString::number(color.saturationF()));
        ui->line13->setText(QString::number(color.valueF()));
    }

    if (ui->cmodel_1->currentText() == "HLS"){
        ui->line11->setText(QString::number(color.hslHue()));
        ui->line12->setText(QString::number(color.lightness()));
        ui->line13->setText(QString::number(color.hslSaturation()));
    }

    if (ui->cmodel_1->currentText() == "XYZ"){
        ui->line11->setText(QString::number(X));
        ui->line12->setText(QString::number(Y));
        ui->line13->setText(QString::number(Z));
    }

    if (ui->cmodel_1->currentText() == "LAB"){
        ui->line11->setText(QString::number(L));
        ui->line12->setText(QString::number(a));
        ui->line13->setText(QString::number(b));
    }

}

void MainWindow::cmodel_setValues_2()
{
    if (ui->cmodel_2->currentText() == "RGB"){
        ui->line21->setText(QString::number(color.red()));
        ui->line22->setText(QString::number(color.green()));
        ui->line23->setText(QString::number(color.blue()));
    }

    if (ui->cmodel_2->currentText() == "CMYK"){
        ui->line21->setText(QString::number(color.cyan()));
        ui->line22->setText(QString::number(color.magenta()));
        ui->line23->setText(QString::number(color.yellow()));
        ui->line24->setText(QString::number(color.black()));
    }

    if (ui->cmodel_2->currentText() == "HSV"){
        ui->line21->setText(QString::number(color.hue()));
        ui->line22->setText(QString::number(color.saturationF()));
        ui->line23->setText(QString::number(color.valueF()));
    }

    if (ui->cmodel_2->currentText() == "HLS"){
        ui->line21->setText(QString::number(color.hslHue()));
        ui->line22->setText(QString::number(color.lightness()));
        ui->line23->setText(QString::number(color.hslSaturation()));
    }

    if (ui->cmodel_2->currentText() == "XYZ"){
        ui->line21->setText(QString::number(X));
        ui->line22->setText(QString::number(Y));
        ui->line23->setText(QString::number(Z));
    }

    if (ui->cmodel_2->currentText() == "LAB"){
        ui->line21->setText(QString::number(L));
        ui->line22->setText(QString::number(a));
        ui->line23->setText(QString::number(b));
    }
}

void MainWindow::cmodel_setValues_3()
{
    if (ui->cmodel_3->currentText() == "RGB"){
        ui->line31->setText(QString::number(color.red()));
        ui->line32->setText(QString::number(color.green()));
        ui->line33->setText(QString::number(color.blue()));
    }

    if (ui->cmodel_3->currentText() == "CMYK"){
        ui->line31->setText(QString::number(color.cyan()));
        ui->line32->setText(QString::number(color.magenta()));
        ui->line33->setText(QString::number(color.yellow()));
        ui->line34->setText(QString::number(color.black()));
    }

    if (ui->cmodel_3->currentText() == "HSV"){
        ui->line31->setText(QString::number(color.hue()));
        ui->line32->setText(QString::number(color.saturationF()));
        ui->line33->setText(QString::number(color.valueF()));
    }

    if (ui->cmodel_3->currentText() == "HLS"){
        ui->line31->setText(QString::number(color.hslHue()));
        ui->line32->setText(QString::number(color.lightness()));
        ui->line33->setText(QString::number(color.hslSaturation()));
    }

    if (ui->cmodel_3->currentText() == "XYZ"){
        ui->line31->setText(QString::number(X));
        ui->line32->setText(QString::number(Y));
        ui->line33->setText(QString::number(Z));
    }

    if (ui->cmodel_3->currentText() == "LAB"){
        ui->line31->setText(QString::number(L));
        ui->line32->setText(QString::number(a));
        ui->line33->setText(QString::number(b));
    }
}

void MainWindow::on_color_button_clicked()
{
    color = colordialog->getColor();
    repaint();
    RGB_to_XYZ_and_LAB();
    setNames();
    setSliderValue();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPixmap currentColor(ui->label->width(), ui->label->height());
    QPainter painter(&currentColor);
    painter.setBrush(color);
    painter.drawRect(0,0,ui->label->width()-1,ui->label->height()-1);
    ui->label->setPixmap(currentColor);
}

double Fx(double x)
{
    if (x >= 0.04045) {
        return qPow((x+0.055) / 1.055, 2.4);
    }
    else return x / 12.92;
}

double Fl(double l)
{
    if (l >= 0.008856){
        return qPow(l, 1.0/3.0);
    }
    else {
        return 7.787 * l + 16 / 116.0;
    }
}

double FxReverse(double x) {
    if (abs(x)<0.0031308) {
        return 12.92 * x;
    }

    return 1.055 * pow(x, 0.41666) - 0.055;
}

double FlRevese(double l) {
    if (pow(l,3)>=0.008856) {
        return pow(l,3);
    }
    return (l-16.0/116.0)/7.878;
}

void MainWindow::RGB_to_XYZ_and_LAB()
{
    X = 0.412453 * Fx(color.red()/255.0) * 100 + 0.357580 * Fx(color.green()/255.0) * 100 + 0.180423 * Fx(color.blue()/255.0) * 100;
    Y = 0.212671 * Fx(color.red()/255.0) * 100 + 0.715160 * Fx(color.green()/255.0) * 100 + 0.072169 * Fx(color.blue()/255.0) * 100;
    Z = 0.019334 * Fx(color.red()/255.0) * 100 + 0.119193 * Fx(color.green()/255.0) * 100 + 0.950227 * Fx(color.blue()/255.0) * 100;
    L = 116 * Fl(Y /100.0) - 16;
    a = 500 * (Fl(X / 95.047) - Fl(Y /100.0));
    b = 200 * (Fl(Y /100.0) - Fl(Z / 108.883));
}

void MainWindow::XYZ_to_RGB_and_LAB() {
    double R = 3.240454 * X / 100.0 - 1.537138 * Y/ 100.0  - 0.498531 * Z/ 100.0;
    double G = -0.969266 * X / 100.0 + 1.876010 * Y/ 100.0  + 0.041556 * Z/ 100.0;
    double B = 0.055643 * X / 100.0 - 0.204025 * Y/ 100.0  + 1.057225 * Z/ 100.0;

    color.setRed(round(FxReverse(R)*255));
    color.setGreen(round(FxReverse(G)*255));
    color.setBlue(round(FxReverse(B)*255));

    L = 116 * Fl(Y /100.0) - 16;
    a = 500 * (Fl(X / 95.047) - Fl(Y /100.0));
    b = 200 * (Fl(Y /100.0) - Fl(Z / 108.883));
}

void MainWindow::LAB_to_RGB_and_XYZ() {
    X = FlRevese(a/500.0 + (L+16.0)/116.0) * 95.047;
    Y = FlRevese((L+16.0)/116.0) * 100.0;
    Z = FlRevese((L+16.0)/116.0- b/200.0) * 108.883;

    double R = 3.2406 * X / 100.0 - 1.5372 * Y / 100.0 - 0.4986 * Z / 100.0;
    double G = -0.9689 * X / 100.0 + 1.8758 * Y / 100.0 + 0.0415 * Z / 100.0;
    double B = 0.0557 * X / 100.0 - 0.2040 * Y / 100.0 + 1.0570 * Z / 100.0;

    color.setRed(round(FxReverse(R)*255));
    color.setGreen(round(FxReverse(G)*255));
    color.setBlue(round(FxReverse(B)*255));
}

void MainWindow::on_cmodel_1_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    cmodel_setNames_1();
}

void MainWindow::on_cmodel_2_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    cmodel_setNames_2();
}

void MainWindow::on_cmodel_3_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    cmodel_setNames_3();
}

void MainWindow::on_line11_editingFinished()
{
    if (ui->cmodel_1->currentText() == "RGB"){
        color.setRed(ui->line11->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "CMYK"){
        color.setCmyk(ui->line11->text().toInt(), color.magenta(), color.yellow(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "HSV"){
        color.setHsv(ui->line11->text().toInt(), color.saturation(), color.value());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "HLS"){
        color.setHsl(ui->line11->text().toInt(), color.hslSaturation(), color.lightness());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "XYZ"){
        X = ui->line11->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "LAB"){
        L = ui->line11->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line21_editingFinished()
{
    if (ui->cmodel_2->currentText() == "RGB"){
        color.setRed(ui->line21->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "CMYK"){
        color.setCmyk(ui->line21->text().toInt(), color.magenta(), color.yellow(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "HSV"){
        color.setHsv(ui->line21->text().toInt(), color.saturation(), color.value());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "HLS"){
        color.setHsl(ui->line21->text().toInt(), color.hslSaturation(), color.lightness());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "XYZ"){
        X = ui->line21->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "LAB"){
        L = ui->line21->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line31_editingFinished()
{
    if (ui->cmodel_3->currentText() == "RGB"){
        color.setRed(ui->line31->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "CMYK"){
        color.setCmyk(ui->line31->text().toInt(), color.magenta(), color.yellow(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "HSV"){
        color.setHsv(ui->line31->text().toInt(), color.saturation(), color.value());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "HLS"){
        color.setHsl(ui->line31->text().toInt(), color.hslSaturation(), color.lightness());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "XYZ"){
        X = ui->line31->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "LAB"){
        L = ui->line31->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line12_editingFinished()
{
    if (ui->cmodel_1->currentText() == "RGB"){
        color.setGreen(ui->line12->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "CMYK"){
        color.setCmyk(color.cyan(), ui->line12->text().toInt(), color.yellow(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "HSV"){
        color.setHsv(color.hue(), ui->line12->text().toInt(), color.value());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "HLS"){
        color.setHsl(color.hslHue(), color.hslSaturation(), ui->line12->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "XYZ"){
        Y = ui->line12->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "LAB"){
        a = ui->line12->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line22_editingFinished()
{
    if (ui->cmodel_2->currentText() == "RGB"){
        color.setGreen(ui->line22->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "CMYK"){
        color.setCmyk(color.cyan(), ui->line22->text().toInt(), color.yellow(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "HSV"){
        color.setHsv(color.hue(), ui->line22->text().toInt(), color.value());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "HLS"){
        color.setHsl(color.hslHue(), color.hslSaturation(), ui->line22->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "XYZ"){
        Y = ui->line22->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "LAB"){
        a = ui->line22->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line32_editingFinished()
{
    if (ui->cmodel_3->currentText() == "RGB"){
        color.setGreen(ui->line32->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "CMYK"){
        color.setCmyk(color.cyan(), ui->line32->text().toInt(), color.yellow(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "HSV"){
        color.setHsv(color.hue(), ui->line32->text().toInt(), color.value());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "HLS"){
        color.setHsl(color.hslHue(), color.hslSaturation(), ui->line32->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "XYZ"){
        Y = ui->line32->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "LAB"){
        a = ui->line32->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line13_editingFinished()
{
    if (ui->cmodel_1->currentText() == "RGB"){
        color.setBlue(ui->line13->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "CMYK"){
        color.setCmyk(color.cyan(), color.magenta(), ui->line13->text().toInt(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "HSV"){
        color.setHsv(color.hue(), color.saturation(), ui->line13->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "HLS"){
        color.setHsl(color.hslHue(), ui->line13->text().toInt(), color.lightness());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "XYZ"){
        Z = ui->line13->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_1->currentText() == "LAB"){
        b = ui->line13->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line23_editingFinished()
{
    if (ui->cmodel_2->currentText() == "RGB"){
        color.setBlue(ui->line23->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "CMYK"){
        color.setCmyk(color.cyan(), color.magenta(), ui->line23->text().toInt(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "HSV"){
        color.setHsv(color.hue(), color.saturation(), ui->line23->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "HLS"){
        color.setHsl(color.hslHue(), ui->line23->text().toInt(), color.lightness());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "XYZ"){
        Z = ui->line23->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_2->currentText() == "LAB"){
        b = ui->line23->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line33_editingFinished()
{
    if (ui->cmodel_3->currentText() == "RGB"){
        color.setBlue(ui->line33->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "CMYK"){
        color.setCmyk(color.cyan(), color.magenta(), ui->line33->text().toInt(), color.black());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "HSV"){
        color.setHsv(color.hue(), color.saturation(), ui->line33->text().toInt());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "HLS"){
        color.setHsl(color.hslHue(), ui->line33->text().toInt(), color.lightness());
        RGB_to_XYZ_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "XYZ"){
        Z = ui->line33->text().toDouble();
        XYZ_to_RGB_and_LAB();
    }
    if (ui->cmodel_3->currentText() == "LAB"){
        b = ui->line33->text().toDouble();
        LAB_to_RGB_and_XYZ();
    }
    setSliderValue();
    setValues();
}

void MainWindow::on_line14_editingFinished()
{
    color.setCmyk(color.cyan(), color.magenta(), color.yellow(), ui->line14->text().toInt());
    RGB_to_XYZ_and_LAB();
    setSliderValue();
    setValues();
}

void MainWindow::on_line24_editingFinished()
{
    color.setCmyk(color.cyan(), color.magenta(), color.yellow(), ui->line24->text().toInt());
    RGB_to_XYZ_and_LAB();
    setSliderValue();
    setValues();
}

void MainWindow::on_line34_editingFinished()
{
    color.setCmyk(color.cyan(), color.magenta(), color.yellow(), ui->line34->text().toInt());
    RGB_to_XYZ_and_LAB();
    setSliderValue();
    setValues();
}

void MainWindow::on_slider_1_valueChanged(int value)
{
    color.setRed(value);
    RGB_to_XYZ_and_LAB();
    setValues();
}

void MainWindow::on_slider_2_valueChanged(int value)
{
    color.setGreen(value);
    RGB_to_XYZ_and_LAB();
    setValues();
}

void MainWindow::on_slider_3_valueChanged(int value)
{
    color.setBlue(value);
    RGB_to_XYZ_and_LAB();
    setValues();
}

void MainWindow::setSliderValue()
{
    ui->slider_1->setValue(color.red());
    ui->slider_2->setValue(color.green());
    ui->slider_3->setValue(color.blue());
}
