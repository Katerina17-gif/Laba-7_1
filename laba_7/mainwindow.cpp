#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
m_firstLineEdit = new QLineEdit;
m_firstLineEdit_2 = new QLineEdit;
m_secondLineEdit = new QLineEdit;
m_secondLineEdit_2 = new QLineEdit;
m_thirdLineEdit = new QLineEdit;
m_thirdLineEdit_2=new QLineEdit;

m_firstLineEdit->setValidator(new QIntValidator(m_firstLineEdit));
m_firstLineEdit_2->setValidator(new QIntValidator(m_firstLineEdit));
m_secondLineEdit->setValidator(new QIntValidator(m_secondLineEdit));
m_secondLineEdit_2->setValidator(new QIntValidator(m_secondLineEdit));
m_thirdLineEdit->setValidator(new QIntValidator(m_thirdLineEdit));
m_thirdLineEdit_2->setValidator(new QIntValidator(m_thirdLineEdit));

button1 = new QRadioButton("+");
button2 = new QRadioButton("-");
button3 = new QRadioButton("*");
button4 = new QRadioButton("/");

QHBoxLayout* hBox1 = new QHBoxLayout;
hBox1->addWidget(m_firstLineEdit);
hBox1->addWidget(m_secondLineEdit);
hBox1->addWidget(m_thirdLineEdit);

QHBoxLayout* hBox2 =new QHBoxLayout;
hBox2->addWidget(m_firstLineEdit_2);
hBox2->addWidget(m_secondLineEdit_2);
hBox2->addWidget(m_thirdLineEdit_2);

QHBoxLayout* hBox3 = new QHBoxLayout;
hBox3->addWidget(button1);
hBox3->addWidget(button2);
hBox3->addWidget(button3);
hBox3->addWidget(button4);

QVBoxLayout* vBox = new QVBoxLayout;
vBox->addLayout(hBox1);
vBox->addLayout(hBox2);
vBox->addLayout(hBox3);

this->setLayout(vBox);

connect(button1, SIGNAL(clicked()), SLOT(makePlus()));
connect(button2, SIGNAL(clicked()), SLOT(makeUnPlus()));
connect(button3, SIGNAL(clicked()), SLOT(makeDiv()));
connect(button4, SIGNAL(clicked()), SLOT(makeRem()));
}

void MainWindow::makePlus(){
bool isFirstOk = false;

int firstValue=m_firstLineEdit->text().toInt(&isFirstOk);
int secondValue = m_firstLineEdit_2->text().toInt(&isFirstOk);

int firstValue_2 = m_secondLineEdit->text().toInt(&isFirstOk);
int secondValue_2 = m_secondLineEdit_2->text().toInt(&isFirstOk);


int m = firstValue * secondValue_2 + firstValue_2 * secondValue;
int n = secondValue * secondValue_2;

for (int i=2;i<=n;i++) {

while(m%i==0 && n%i==0) {
m/=i;
n/=i;
}
}


m_thirdLineEdit->setText(QString::number(m));
m_thirdLineEdit_2->setText(QString::number(n));

}


void MainWindow::makeUnPlus(){
bool isFirstOk = false;

int firstValue=m_firstLineEdit->text().toInt(&isFirstOk);
int secondValue = m_firstLineEdit_2->text().toInt(&isFirstOk);

int firstValue_2 = m_secondLineEdit->text().toInt(&isFirstOk);
int secondValue_2 = m_secondLineEdit_2->text().toInt(&isFirstOk);


int m = firstValue * secondValue_2 - firstValue_2 * secondValue;
int n = secondValue * secondValue_2;

for (int i=2;i<=n;i++) {

while(m%i==0 && n%i==0) {
m/=i;
n/=i;
}
}

m_thirdLineEdit->setText(QString::number(m));
m_thirdLineEdit_2->setText(QString::number(n));


}

void MainWindow::makeDiv(){
bool isFirstOk = false;

int firstValue=m_firstLineEdit->text().toInt(&isFirstOk);
int secondValue = m_firstLineEdit_2->text().toInt(&isFirstOk);

int firstValue_2 = m_secondLineEdit->text().toInt(&isFirstOk);
int secondValue_2 = m_secondLineEdit_2->text().toInt(&isFirstOk);

int m = firstValue * firstValue_2;
int n = secondValue * secondValue_2;

for (int i=2;i<=n;i++) {

while(m%i==0 && n%i==0) {
m/=i;
n/=i;
}
}

m_thirdLineEdit->setText(QString::number(m));
m_thirdLineEdit_2->setText(QString::number(n));

}

void MainWindow::makeRem(){
bool isFirstOk = false;

int firstValue=m_firstLineEdit->text().toInt(&isFirstOk);
int secondValue = m_firstLineEdit_2->text().toInt(&isFirstOk);

int firstValue_2 = m_secondLineEdit->text().toInt(&isFirstOk);
int secondValue_2 = m_secondLineEdit_2->text().toInt(&isFirstOk);

int m = firstValue * secondValue_2;
int n = secondValue *firstValue_2 ;

for (int i=2;i<=n;i++) {

while(m%i==0 && n%i==0) {
m/=i;
n/=i;
}
}

m_thirdLineEdit->setText(QString::number(m));
m_thirdLineEdit_2->setText(QString::number(n));
}
