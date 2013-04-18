/*
 * Copyright (c) 2013 by Xavier HINAULT - support@mon-club-elec.fr
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 3
 * or the GNU Lesser General Public License version 3, both as
 * published by the Free Software Foundation.
 */

/* Cette librairie implémente fonction analyse de chaîne en réception sur le réseau Ethernet
* pour la gestion des timers RTC avec ma lib RTClibTimer
*/

#include "Arduino.h"
//#include "RTClib.h"
#include "Ethernet.h"
#include "RTClibTimerEthernet.h"
#include "Utils.h"
#include "UtilsRTClibTimerEthernet.h"


  UtilsRTClibTimerEthernet::UtilsRTClibTimerEthernet(){ // constructeur par défaut
  
  }
  
//////////// fonctions membre de la classe //////////////

//------------ analyseChaine ---------------
void UtilsRTClibTimerEthernet::analyseChaine(EthernetClient clientIn, String chaineReception, RTClibTimerEthernet timerRTC[], int nombreTimersIn) { // fonction d'analyse de la chaine recue

 String paramString=""; // chaine locale - initialiser à "" !
 long params[6]; // tableau de paramètres pour instructions à paramètres multiples - taille du tableau fixée par le nombre max de paramètres utilisés 

  // ---- analyse de la chaine recue sur le port Série ---- 
  chaineReception.trim(); // enlève les espaces - version 1.0

         //================================= start(index, intervalle) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"start(",2,params)==true) { // si chaine FONCTION(valeur,valeur) bien reçue 

        int indexTimer=params[0]; 
        int intervalTimer=params[1];
        
        // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client

        clientIn.println("index : " + (String)indexTimer);
        clientIn.println("intervalle : " + (String)intervalTimer);
        
        if (indexTimer<nombreTimersIn) {
 
          timerRTC[indexTimer].start(intervalTimer); // équiv - initialise timer RTC sans fin
          
        } // fin if params < nombreTimers
        
        //return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= startAll(intervalle) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"startAll(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int intervalTimer=params[0];

        // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client
        
       clientIn.println("intervalle : " + (String)intervalTimer);

          for (int i=0; i<nombreTimersIn; i++) { // défile les timer 
             timerRTC[i].start(intervalTimer); // initialise timer RTC sans fin

          } // fin for 
                  
        //return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= start(index, intervalle, max) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"start(",3,params)==true) { // si chaine FONCTION(valeur,valeur,valeur) bien reçue 

        int indexTimer=params[0]; 
        int intervalTimer=params[1];
        int maxTimer=params[2];
        
        // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client

        clientIn.println("index : " + (String)indexTimer);
        clientIn.println("intervalle : " + (String)intervalTimer);
        clientIn.println("limite : " + (String)maxTimer);
        
        if (indexTimer<nombreTimersIn) {
			
           timerRTC[indexTimer].start(intervalTimer,maxTimer); // initialise timer RTC avec limite
          
        } // fin if params < nombreTimers
        
        
    	} // fin si testInstructionLong==true

        //================================= startAll(intervalle, max) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"startAll(",2,params)==true) { // si chaine FONCTION(valeur,valeur) bien reçue 

        int intervalTimer=params[1];
        int maxTimer=params[2];
        
        // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client
        
        clientIn.println("intervalle : " + (String)intervalTimer);
        clientIn.println("limite : " + (String)maxTimer);
        
          for (int i=0; i<nombreTimersIn; i++) { // défile les timer 
            timerRTC[i].start(intervalTimer,maxTimer); // initialise timer RTC avec limite

          } // fin for 
          
                  
        //return; // loop suivant
        
    	} // fin si testInstructionLong==true
    
        //================================= restart(index) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"restart(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int indexTimer=params[0]; 
        
        // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client

        clientIn.println("index : " + (String)indexTimer);
        
        if (indexTimer<nombreTimersIn) {
          
         timerRTC[indexTimer].start(); // initialise timer RTC avec limite
                   
          clientIn.print("Timer " + (String)indexTimer);
          clientIn.println(F(" actif."));
        
        } // fin if params < nombreTimers
        
        //return; // loop suivant
        
    	} // fin si testInstructionLong==true
    

        //================================= stop(index) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"stop(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int indexTimer=params[0]; 

       // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client

        clientIn.println("index : " + (String)indexTimer);
        
        if (indexTimer<nombreTimersIn) {
          timerRTC[indexTimer].stop();// stoppe le Timer 
          clientIn.print("Timer " + (String)indexTimer);
          clientIn.println(F(" inactif."));

        } // fin if params < nombreTimers
        
        //return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= info(index) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"info(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int indexTimer=params[0]; 

        // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client

        clientIn.println("index : " + (String)indexTimer);
        
        if (indexTimer<nombreTimersIn) {
          
          timerRTC[indexTimer].status(clientIn); // affiche les infos sur le port série 
          
         
        } // fin if params < nombreTimers
        
        //return; // loop suivant
        
    	} // fin si testInstructionLong==true
    
        //================================= stopAll() ===================================== 
        if (chaineReception.startsWith("stopAll()")==true) {

          for (int i=0; i<nombreTimersIn; i++) { // défile les timer 
 
             timerRTC[i].stop(); // stoppe le timer RTC
            
          } // fin for 

       // envoi reponse à la requete Ajax
        envoiEnteteHTTP(clientIn); // envoi entete HTTP OK 200 vers le client
          
          clientIn.println(F("Tous les timers inactifs."));
        
        
    	} // fin si chaineReception == 
  


} // fin analyse chaine 


//------ fonction utile envoi entete http ---------------- 
void UtilsRTClibTimerEthernet::envoiEnteteHTTP(EthernetClient clientIn){
 
 if (clientIn) {

   //-- envoi de la réponse HTTP --- 
           clientIn.println(F("HTTP/1.1 200 OK")); // entete de la réponse : protocole HTTP 1.1 et exécution requete réussie
           clientIn.println(F("Content-Type: text/html")); // précise le type de contenu de la réponse qui suit 
           clientIn.println(F("Connnection: close")); // précise que la connexion se ferme après la réponse
           clientIn.println(); // ligne blanche 
           
           //--- envoi en copie de la réponse http sur le port série 
           Serial.println(F("La reponse HTTP suivante est envoyee au client distant :")); 
           Serial.println(F("HTTP/1.1 200 OK"));
           Serial.println(F("Content-Type: text/html"));
           Serial.println(F("Connnection: close"));

 } // fin si client
 
} // fin envoiEnteteHTTP





