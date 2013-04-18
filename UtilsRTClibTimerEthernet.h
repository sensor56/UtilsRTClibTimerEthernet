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

#ifndef UtilsRTClibTimerEthernet_h
#define UtilsRTClibTimerEthernet_h

#include "Arduino.h"
#include "Utils.h"
#include "Ethernet.h"
#include "RTClibTimerEthernet.h"

//#include "RTClib.h"


class UtilsRTClibTimerEthernet { 

  private : // variables internes
  
  public : // variables publiques de la classe 

  Utils _utils; // objet utils donnant accès aux fonctions de la lib
  
  public : // fonctions publiques 
  // toutes les fonctions publiques de la librairie doivent être pré-déclarées ici 
  
  	UtilsRTClibTimerEthernet(); // constructeur
  	
  	void analyseChaine(EthernetClient clientIn, String chaineReceptionIn, RTClibTimerEthernet timerRTCIn[], int nombreTimersIn); 
  
	void envoiEnteteHTTP(EthernetClient clientIn);

  private : // fonctions internes
  // toutes les fonctions internes (ou privées) de la librairie doivent être pré-déclarées ici 
  

}; // fin classe 


#endif
