# balancing_robot

programme complet V1 du robot gyropode.

arduino balancing -> gere l'equilibre et la gestion des mouvement du robot
( liaison UART, I2C)

atmega328p -> arduino de transfer d information SPI ou UART (ESP ou HC06)
fonctionne tres bien, liaison UART avec arduino balancing

ESP12F -> serveur UDP, reception des paquets et transfert en SPI
(SPI ok, UDP reception a voir...)


/******************************************************************************************************
 *                                                                                                    *
 *      BBBBBB      TTTTTTTTT      SSSSS             SSSSS     NN    N     II    RRRRR                *
 *      BB    B        TT        SS                SS          N N   N           RR   RR              *
 *      BBBBBB         TT          SSS               SSS       N  N  N     II    RRRRR                *
 *      BB    B        TT             SS                SS     N   N N     II    RR   RR              * 
 *      BBBBBB         TT         SSSS              SSSS       n    NN     II    RR     RR            *
 *                                                                                                    * 
******************************************************************************************************/


the IHM was build by sofiane (SOSO, the best driver of THE SOSO MOBILE) in C++ with QT Creator.
Thank's to https://openclassrooms.com forum to build a IP stream on the interface.

This program send in UDP differents control to the ESP12F (see balancing robot, "espisready").

have a nice day or night... a looong night...
