#ifndef HORLOGEDIGITALE_H
#define HORLOGEDIGITALE_H
#include <QtWidgets>
#include <QtGui> /* tous les widgets de Qt4 */
#include <QLCDNumber>
#include <QTimer>

// réglage au dixième de secondes
#define PERIODE 100
class HorlogeDigitale : public QLCDNumber
{
    Q_OBJECT
public:
    HorlogeDigitale(QWidget *parent=0);
    ~HorlogeDigitale();
    long getMinute();
    long getHeure();
    long getSeconde();
    void fixer(int h, int m,int s);
private:
    QTimer *m_timer;
    long m_valeur;
    void update();
private slots:
    void tic();
public slots:
    void demarrer(int top=PERIODE);
    void arreter();
};
#endif // HORLOGEDIGITALE_H
