# balancing_robot

programme complet V1 du robot gyropode.

arduino balancing -> gere l'equilibre et la gestion des mouvement du robot
( liaison UART, I2C)

atmega328p -> arduino de transfer d information SPI ou UART (ESP ou HC06)
fonctionne tres bien, liaison UART avec arduino balancing

ESP12F -> serveur UDP, reception des paquets et transfert en SPI
(SPI ok, UDP reception a voir...)
