#include <QApplication>
#include "ihmhorloge.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Choix de l’encodage des caractères
    IHMHorloge w;
    w.show();
    return a.exec();
}
