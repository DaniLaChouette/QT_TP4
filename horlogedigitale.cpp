#include "horlogedigitale.h"
#include <QString>
#include <QDebug>
HorlogeDigitale::HorlogeDigitale(QWidget *parent) : QLCDNumber(parent)
{
    // initialise la valeur du compteur de tic d’horloge
    m_valeur = 0;
    // instancie le timer (base de temps) de l’horloge
    m_timer = new QTimer(this);
    // connecte le signal d’expiration (timeout) d’une période (top d’horloge) au slot tic()
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tic()));
    // personnalise l’afficheur
    //setStyleSheet("background-color: black; color: green;");
    setDigitCount(8);
    setSegmentStyle(QLCDNumber::Filled);
    setFixedSize(this->width()*1.5, this->height()*1.5); // agrandit sa taille
}
HorlogeDigitale::~HorlogeDigitale()
{
    qDebug() << "~HorlogeDigitale()";
}
long HorlogeDigitale::getMinute()
{
    return (m_valeur%36000)/600;
}
long HorlogeDigitale::getHeure()
{
    return m_valeur/36000;
}
long HorlogeDigitale::getSeconde()
{
    return (m_valeur % 600) / 10;
}

void HorlogeDigitale::fixer(int h, int m,int s)
{
    m_valeur = h*36000 + m*600 + s*10;
}
void HorlogeDigitale::update()
{
    QString heure, minute,seconde;
    // met à jour l’affichage de l’horloge
    if (getHeure() < 10)
        heure = "0" + QString::number(getHeure());
    else heure = QString::number(getHeure());
    if (getMinute() < 10)
        minute = "0" + QString::number(getMinute());
    else minute = QString::number(getMinute());
    if (getSeconde() < 10)
        seconde = "0" + QString::number(getSeconde());
    else seconde = QString::number(getSeconde());
    QString text = heure + ":" + minute + ":" + seconde;

    display(text);
}
void HorlogeDigitale::tic()
{
    // incrémente le compteur de top d’horloge
    m_valeur++;
    // demande la mise à jour l’affichage de l’horloge
    update();
}
void HorlogeDigitale::demarrer(int top/*=PERIODE*/)
{
    qDebug() << "HorlogeDigitale::demarrer()";
    m_timer->start(top);
}
void HorlogeDigitale::arreter()
{
    m_timer->stop();
    qDebug() << "HorlogeDigitale::arreter()";
}
