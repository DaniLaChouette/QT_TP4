#ifndef IHMHORLOGE_H
#define IHMHORLOGE_H
#include "horlogedigitale.h"
class HorlogeDigitale;


class IHMHorloge : public QWidget
{
    Q_OBJECT
private:
    // les widgets
    QPushButton *boutonReglage;
    HorlogeDigitale *horloge;
    QTimeEdit *editionHeure;
public:
    IHMHorloge(QWidget *parent=0);
    ~IHMHorloge();
private slots:
    void regler();
    void quitter();
signals:
    void depart(int);
    void arret();
};
#endif // IHMHORLOGE_H
