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

int main() {
  float  temp_f, eps_f = 1.0f; // Das "f" am Ende sorgt fuer float Konstante.
  double eps_d = 1.0;  
  int count = 0;

  do {
    eps_f = eps_f / 2;
    temp_f= 1.0 + (eps_f / 2);
    count--;
  } while ( temp_f> 1.0);

  printf("\nEs wird angefangen bei der Potenz 2^0. Dort beträgt der Wert für eps_f = 1\nNach der iteration der do-while Schleife\nIst bei der 2^%d ten Potenz der kleinste mögliche Wert für epsilon erreicht, dies ist somit das Ende der Mantisse\nEs werden entsprechend %.23f = %d Nachkommastellen angezeigt\n\n", count+1, eps_f, count);
  printf("Die nächste Stufe wäre %.23f\nMit %.23e \t==> %.7e + %.7e = %.7e\n", 1.0f, eps_f / 2, 1.0f + (eps_f / 2));
  printf("\t==> %.7e + %.7e = %.7e\n", 2.0f, eps_f, 2.0f + eps_f);


  printf("\t==> %.7e + %.7e = %.7e\n", 1.0f, eps_f, 1.0f + eps_f);
  printf("\t==> %.7e + %.7e = %.7e\n", 1.0f, eps_f / 2, 1.0f + (eps_f / 2));
  printf("\t==> %.7e + %.7e = %.7e\n", 2.0f, eps_f, 2.0f + eps_f);

  /** double:
   *
   * eps_d = 2^-52 ~ 2.22*10^{-16} also Genauigkeit von 15 - 16 Dezimalstellen.
   *
   * Die Maschinengenauigkeit eps_d ist ebenfalls eine relative Groesse.
   */
  count = 0;
  do {
    eps_d = eps_d / 2;
    count = count - 1;
  } while (1.0 + (eps_d / 2) > 1.0);
  printf("\neps_double = 2^%d = %.16e = %.16e\n\n", count, eps_d, DBL_EPSILON);
  printf("\t==> %.16e + %.16e = %.16e\n", 1.0, eps_d, 1.0 + eps_d);
  printf("\t==> %.16e + %.16e = %.16e\n", 1.0, eps_d / 2, 1.0 + (eps_d / 2));
  printf("\t==> %.16e + %.16e = %.16e\n", 2.0, eps_d, 2.0 + eps_d);

  return 0;
}
