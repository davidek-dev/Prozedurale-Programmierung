/*
1.2  
Eulersche Zahl (2 Punkte)
Schreiben Sie ein Programm, 
welches eine Maschinengenauedouble-Approximation der Euler-schen Zahlebestimmt:
e=∞∑i=01i!= 2,71828182845904523536028747135266249775724709369995. . .
Stellen Sie zu jedem Schritt die Zwischenergebnisse der Reihenentwicklung übersichtlich 
in einer Tabelle auf dem Bildschirm dar. 
Wie viele Schritte werden benötigt?
*/
#include <stdio.h>

int main() {

printf("Folgendes ist eine Maschienengenaue Ausgabe der Eulerschen Zahl\n \n");

double eulerOld=1;
int count=0;
double euler=1;
double multiplier=1;
double toAdd=1;

do {


  eulerOld=euler                   ;                    //eulerOld=euler
  count=count+1                   ;                    //count= count + 1



  multiplier=multiplier*count    ;                      //multiplier = multiplier*count
  toAdd=1/multiplier            ;                           //toAdd=1/(multiplier)
  euler=euler+toAdd         ;
                             //euler=eulerOld+toAdd
if (eulerOld!=euler) {
    printf("     %d .Schritt:\t",count);
    printf("%.16f\n",euler );
}


} while(eulerOld!=euler);                //während sich noch das alte euler vom neuen euler unterscheidet soll er die klammer ausführen

printf("\n Die maschienengenauste Approximation an die Eulersche Zahl lautet \n \n \t %.16f\n \n ", eulerOld);

  return 0;
}
