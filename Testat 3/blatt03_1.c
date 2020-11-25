/*
1.1  Maschinengenauigkeit(2 Punkte)
Schreiben Sie ein Programm, 
welches mithilfe von do-while-Schleifen jeweils die Maschinenge-nauigkeitv ε >0
der Gleitkommazahlen im float oder double-Format bestimmt. 
Ein mögliches Vorgehen ist solange für ε kleiner werdende Zweierpotenzen auszuprobieren, 
bis 1 + (ε/2) > 1
nicht mehr gilt, also ε / 2 
nicht mehr im Signifikaten von gespeichert werden kann.
Gilt für diese Maschinengenauigkeit auch 2 + ε ≥ 2 ? 
Was sagt dies über ε aus? 
Wie viele binäre oder dezimale Nachkommastellen können die Datentypen float und double darstellen?
*/
#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {

int Vorgabe;
printf("\nx + epsilon >= x\n\n soll x mit 1 oder mit 2 besetzt werden?");
scanf("%d",&Vorgabe);
printf("\n\nAusgewählt:%d\n\n", Vorgabe);

int Exponent = 1;
float epsilon_f = 1;
float Signifikanz_f = 1+(epsilon_f/2);

double epsilon_d = 1;
double Signifikanz_d = 1+(epsilon_d/2);


printf("Das folgende zeigt die Zweierpotenzen absteigend bis zur vom Typ float niedrigsten erkannten Potenz.\n \n");
do {

  Exponent = Exponent -1;

  float power = pow(2, Exponent);
  printf("2 hoch %d:      ",Exponent);
  epsilon_f= 1*power;

  Signifikanz_f = Vorgabe+Vorgabe*(epsilon_f/2);

  printf("%.23f\n",epsilon_f );

} while(Signifikanz_f>Vorgabe);

printf("\n Die niederigste Zweierpotenz von, die erreicht werden kann im Datentyp Float ohne \n unbeachtet zu bleiben, ist %.23f\n", epsilon_f );


printf("\n\n_______________________________________________________________\n\n");


Exponent = 1;





printf("Das folgende zeigt die Zweierpotenzen absteigend bis zur vom Typ double niedrigsten erkannten Potenz.\n \n");
do {

  Exponent = Exponent -1;

  double power = pow(2, Exponent);
  printf("2 hoch %d:      ",Exponent);
  epsilon_d= 1*power;

  Signifikanz_d = Vorgabe+Vorgabe*(epsilon_d/2);

  printf("%.33f\n",epsilon_d );

} while(Signifikanz_d>Vorgabe);

printf("\n Die niederigste Zweierpotenz, die erreicht werden kann im Datentyp Double ohne \n unbeachtet zu bleiben, ist %.32f\n", epsilon_d );

system("pause");

return 0;

}