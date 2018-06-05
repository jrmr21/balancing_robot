#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebugStateSaver>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtNetwork>
#include <QLabel>
#include <QMessageBox>
#include <QByteArray>
#include <QLabel>
#include <QTimer>

#include "myudp.h"

class MaFenetre : public QWidget
{
    Q_OBJECT
    QPushButton *BoutonHaut, *BoutonBas, *BoutonGauche, *BoutonDroit, *BoutonArret;

public:
    MaFenetre(QWidget *parent = 0);

private:

    QLabel *label;
    bool erreurTrouvee;
    QNetworkAccessManager *m;
    QTimer *timer;
    MyUDP client;

public slots:
    void chargement();
    void afficher();
    void messageErreur(QNetworkReply::NetworkError);

private slots:
//declaration des boutons qu'on vas utiliser
    void boutonHaut();
    void boutonBas();
    void boutonDroit();
    void boutonGauche();
    void boutonArret();
};

#endif // WIDGET_H
