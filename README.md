UtilsRTClibTimerEthernet
========================

Ma librairie UtilsRTClibTimerEthernet, surcouche de ma librairie Utils qui implémente une fonction d'analyse des chaînes en réception via le réseau Ethernet pour gérer les timers RTC créé avec ma lib RTClibTimer.

Cette librairie dispose des fonctions suivantes : 
* void analyseChaine(EthernetClient clientIn,String chaineReceptionIn, RTClibTimer timerRTCIn[], int nombreTimersIn) : cette fonction est le coeur de la librairie et assure l'analyse de la chaîne reçue en provenance du client et renvoie les messages (réponse Ajax) d'analyse vers le client Ethernet. 
* void envoiEnteteHTTP(EthernetClient clientIn); : fonction utilitaire qui renvoie l'entete http 200 OK vers le client

Les chaînes reconnues par cette librairie sont : 
* start(index, intervalle) 
* start(index, intervalle, max)
* startAll(intervalle)
* startAll(intervalle, max)
* stop(index) 
* stopAll()
* restart(index)
* info(index) 


Cette librairie est utilisée notamment dans mon projet "The Open Datalogger Project" : https://github.com/sensor56/TheOpenDataloggerProject
