#include "widget.h"
#include "ui_widget.h"

MaFenetre::MaFenetre(QWidget *parent)
    : QWidget(parent),  m(new QNetworkAccessManager())
{
    m->setParent(this);
    erreurTrouvee = false;

    label=new QLabel(this);//création du label qui contiendra l'image
    label->move(60, 50);//on le déplace

    timer = new QTimer(this);//création du timer qui en appellent le slot créera une vidéo
    timer->start(60);
    connect(timer, SIGNAL(timeout()), this, SLOT(chargement()));//on le connecte

    BoutonHaut = new QPushButton("bouton haut", this);//creation du bouton haut
    BoutonHaut->setGeometry(890, 240, 80, 70); // Dimensions du bouton.     //  x , y , size ? , size ?
    connect(BoutonHaut, SIGNAL(clicked()), this, SLOT(boutonHaut()));

    BoutonBas = new QPushButton("bouton bas", this);//creation du bouton haut
    BoutonBas->setGeometry(890, 380, 80, 70); // Dimensions du bouton.
    connect(BoutonBas, SIGNAL(clicked()), this, SLOT(boutonBas()));

    BoutonDroit = new QPushButton("bouton droit", this);//creation du bouton droit
    BoutonDroit->setGeometry(970, 310, 80, 70); // Dimensions du bouton.
    connect(BoutonDroit, SIGNAL(clicked()), this, SLOT(boutonDroit()));

    BoutonGauche = new QPushButton("bouton gauche", this);//creation du bouton gauche
    BoutonGauche->setGeometry(810, 310, 80, 70); // Dimensions du bouton.
    connect(BoutonGauche, SIGNAL(clicked()), this, SLOT(boutonGauche()));

    BoutonArret = new QPushButton("Arret", this);//creation du bouton quitter
    BoutonArret->setGeometry(890, 310, 80, 70); // Dimensions du bouton.
    connect(BoutonArret, SIGNAL(clicked()), this, SLOT(boutonArret()));  // Connecter les signaux et les slots
}

void MaFenetre::chargement()//slot qui charge l'image tout les 60 millièmes de seconde
{

    //const QUrl url = QUrl("http://root:root@192.168.0.90/axis-cgi/jpg/image.cgi"); //URL de l'IMAGE et nom de la page web qui affiche l'image
    const QUrl url = QUrl("http://192.168.0.22:8080/shot.jpg"); //URL de l'IMAGE et nom de la page web qui affiche l'image

    //Adresse de la came du lycée 192.168.0.90

    const QNetworkRequest requete(url); //On crée notre requête

    QNetworkReply *r = m->get(requete);

    QObject::connect(r, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),this,&MaFenetre::messageErreur);//connection au message d'erreur si il y en à une
    QObject::connect(r, SIGNAL(finished()), this, SLOT(afficher()));    //Dès que l'image est chargé on l'affiche en mettant à jour le QLabel
}

void MaFenetre::afficher()
{    
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());//on recupère l'image

    QByteArray data = r->readAll();//on la met dans un QByteArray

    QImage image;
    image.loadFromData(data);//on la charge car on ne peut pas l'afficher directement ( format de compression comme jpg...)

    label->setFixedSize(image.size());
    label->setPixmap(QPixmap::fromImage(image));//On rafraichi le QLabel avec la nouvel image
}

void MaFenetre::messageErreur(QNetworkReply::NetworkError)
{
        // On réccupère la reply
        QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());

        // Si une erreur a déjà été trouvée, on delete la reply et on ne fait rien d'autre
        if ( erreurTrouvee ) {
            r->deleteLater();
            return; // Return pour ne pas traiter l'erreur
        }

        // On indique qu'il y a eu une erreur
        erreurTrouvee = true;

        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement de l'image. Vérifiez votre connexion ou vérifiez que votre caméra est branché.<br /><br /> Code de l'erreur : <br /><em>" + r->errorString() + "</em>");
        close();

        r->deleteLater();
}

//fonction des boutons
void MaFenetre::boutonHaut()
{
    qDebug() << "Bouton Haut";
    client.HelloUDP('1');
}

void MaFenetre::boutonBas()
{
   qDebug() << "Bouton bas";
   client.HelloUDP('2');
}

void MaFenetre::boutonGauche()
{
   qDebug() << "Bouton gauche";
   client.HelloUDP('3');
}

void MaFenetre::boutonDroit()
{
   qDebug() << "Bouton droit";
   client.HelloUDP('4');
}

void MaFenetre::boutonArret()
{
   qDebug() << "Arreter";
   client.HelloUDP('5');
}
