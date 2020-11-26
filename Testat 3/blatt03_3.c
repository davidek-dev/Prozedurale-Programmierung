/*
1.3  
Größter gemeinsamer Teiler   (6 Punkte)
Schreiben Sie ein Programm, welches für zwei gegebene nicht-negative ganze Zahlen a
und b den größten gemeinsamen Teiler (ggT) bestimmt und auf dem Bildschirm ausgibt.

a) Implementieren Sie dafür den klassischen Euklidischen Algorithmus:
1. Berechnen Sie die absolute Differenz |a−b| der beiden gegebenen Zahlen.
2. Ersetzen Sie die größere der Zahlena, durch die in Schritt 1. berechnete Differenz.
3. Wiederholen Sie Schritt 1. und 2. solange, bis eine der Zahlen gleich Null ist. 
Die von Null verschiedene Zahl ist der ggT.

b) Implementieren Sie den effizienteren, modifizierten Euklidischen Algorithmus:
1. Bestimmen Sie den Rest bei der Integer-Division von a und b,
2. Ersetzen Sie a durch b und b durch den in 1. berechneten Rest,
3. Wiederholen Sie die Schritte 1. und 2. solange b ungleich Null ist.
Zur Berechnung des Restes der Integer-Division kann der Modulo-Operator % verwendet werden, 
z.B.13 % 4 = 1.

c) Nicht alle Architekturen und Programmiersprachen unterstützen die Modulo-Operation.
Wie kann unter Ausnutzung der Integer-Division der Divisionrest trotzdem noch effizient berechnet werden? 
Wie verändert sich das Programm aus b)?
*/
#include <stdio.h>
#include <math.h>


int std_euklid_ggT(unsigned int a, unsigned int b){
  if (a == 0) { // ggt(A,B) = b
    a = b;
    b = 0; // Damit bricht nachfolgender Algorithmus ab
  }

  while (b != 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;//sdasdh
    }
  }
  return a;
}

int advanced_euklid_ggT(unsigned int a, unsigned int b){
  unsigned int temp=0;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int advanced_euklid_ggT_no_modulo(unsigned int a, unsigned int b){
  unsigned int temp=0;

  while (b != 0) {
    temp = a - (a / b) * b; 
    a = b;
    b = temp;
  }
  return a;
}

int main (){

   int Modus =0;
   unsigned int a, b;
   printf("\nHallo und willkommen zum ggT Rechner!\nEs gibt zwei M%cglichkeiten den ggT zu berechnen\n\n", 148);
   printf("\t1. klassischer euklidischer Algorithmus\n");
   printf("\t2. effizienteren, modifizierten Euklidischen Algorithmus\n");
   printf("\t3. effizienteren, modifizierten Euklidischen Algorithmus ohne den Modulo Operator\n\n");
   //while((!(Modus==1))||(!(Modus==2))||(!(Modus==3))){
       printf("Welchen Modus willst du verwenden? 1, 2 oder 3?\n");
       scanf("%d",&Modus);
   //}
   
   printf("\n\nGeb die erste Zahl ein:\t\n");
   scanf("%d", &a);
   printf("\nGeb die zweite Zahl ein:\t\n");
   scanf("%d", &b);

  if ((a == 0) && (b == 0)) {
    printf("Der ggT ist fuer a == b == 0 nicht definiert!\n");
    return -1;
  }

  switch (Modus)
  {
  case 1:
      printf("Klassischer Euklidischer Algorithmus:\n\n");
      printf("\tggT(%d, %d) = %d\n\n", a, b, std_euklid_ggT(a, b));
      break;
  case 2:
      printf("Modifizierter Euklidischer Algorithmus:\n\n");
        printf("\tggT(%d, %d) = %d\n\n", a, b, advanced_euklid_ggT(a, b));  
      break;
  default:
      printf("Modifizierter Euklidischer Algorithmus (ohne \045):\n");
      printf("\tggT(%d, %d) = %d\n\n", a, b, advanced_euklid_ggT_no_modulo(a, b));
      break;
  }



  return 0;
}
