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

int main (){
   unsigned int a;
   unsigned int b;
   printf("\nHallo und willkommen zum ggT Rechner!\nEs gibt zwei Möglichkeiten den ggT zu berechnen\n\n");
   printf("\t1. klassischer euklidischer Algorithmus\n");
   printf("\t2. effizienteren, modifizierten Euklidischen Algorithmus");
   printf("gib die erste Zahl ein:  ");
   scanf("%d\n", &a);
   printf("gib die zweite Zahl ein: \n");
   scanf("%d\n", &b);





 unsigned int A = 81;
  unsigned int B = 36;
  unsigned int a, b, temp; // Arbeitskopien

  if ((A == 0) && (B == 0)) {
    printf("Der ggT ist fuer a == b == 0 nicht definiert!\n");
    return -1;
  }

  printf("Klassischer Euklidischer Algorithmus:\n\n");
  a = A;
  b = B;

  if (a == 0) { // ggt(A,B) = b
    a = b;
    b = 0; // Damit bricht nachfolgender Algorithmus ab
  }

  while (b != 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  printf("\tggT(%u, %u) = %u\n\n", A, B, a);

  printf("Modifizierter Euklidischer Algorithmus:\n\n");
  a = A;
  b = B;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  printf("\tggT(%u, %u) = %u\n\n", A, B, a);

  puts("Modifizierter Euklidischer Algorithmus (ohne \045):\n"); // \045 == %
  a = A;
  b = B;

  while (b != 0) {
    temp = a - (a / b) * b; // Integer-Division!
    a = b;
    b = temp;
  }
  printf("\tggT(%u, %u) = %u\n\n", A, B, a);

  return 0;
}
