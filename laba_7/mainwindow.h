#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

class MainWindow: public QWidget
{
Q_OBJECT

public:
MainWindow(QWidget* parent = 0);
public slots:
void makePlus();
void makeUnPlus();
void makeDiv();
void makeRem();
private:
QLineEdit* m_firstLineEdit;
QLineEdit* m_firstLineEdit_2;
QLineEdit* m_secondLineEdit;
QLineEdit* m_secondLineEdit_2;
QLineEdit* m_thirdLineEdit;
QLineEdit* m_thirdLineEdit_2;

QRadioButton *button1 = new QRadioButton();
QRadioButton *button2 = new QRadioButton();
QRadioButton *button3 = new QRadioButton();
QRadioButton *button4 = new QRadioButton();
};
