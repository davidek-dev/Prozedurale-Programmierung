/**
 * Prozedurale Programmierung
 *
 * Sudoku Loeser
 */

#include <stdio.h>

/* Loesung:
int SUDOKU[9][9] = {
  {4,1,3,8,6,5,2,9,7},
  {9,5,6,2,3,7,4,8,1},
  {2,8,7,4,9,1,5,3,6},
  {8,6,2,9,7,3,1,5,4},
  {3,4,1,5,8,6,9,7,2},
  {7,9,5,1,4,2,3,6,8},
  {1,3,8,6,5,4,7,2,9},
  {5,2,9,7,1,8,6,4,3},
  {6,7,4,3,2,9,8,1,5}
};
*/

const int SUDOKU[9][9] = {
  {4,1,0,0,6,5,0,0,7},
  {0,0,6,0,0,7,4,8,0},
  {2,0,7,4,9,0,0,0,6},
  {0,6,0,0,7,0,1,0,0},
  {3,0,1,5,0,0,0,7,2},
  {0,9,0,0,4,2,3,0,8},
  {1,0,8,6,0,0,0,2,9},
  {0,2,0,0,1,8,6,4,0},
  {6,0,0,3,0,0,0,1,0}
};

int BOARD[9][9];  // Spielfeld

/**
 * Prueft, ob alle drei Sudoku-Regeln auf dem Spielfeld eingehalten wurden.
 * Stoppt beim erster erkannter Regelverletzung.
 *
 * show_hints - Wenn ungleich 0, Ausgabe von Fehlermeldungen.
 *
 * Rueckgabe 1, wenn alle Regeln eingehalten, sonst 0.
 */
int check_board(int show_hints) {
  for (int val = 1; val <= 9; val++) {
    int col_count[9] = {0,0,0,0,0,0,0,0,0};
    int square_count[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    for (int row = 0; row < 9; row++) {
      int row_count = 0;
      for (int col = 0; col < 9; col++) {
        if (BOARD[row][col] == val) {
          if (++row_count > 1) {
            if (show_hints) {
              printf("\n  --> Fehler in (%d/%d): ", row + 1, col + 1);
              printf("die %d kommt mehrfach in der Zeile vor!\n", val);
            }
            return 0;
          }
          if (++col_count[col] > 1) {
            if (show_hints) {
              printf("\n  --> Fehler in (%d/%d): ", row + 1, col + 1);
              printf("die %d kommt mehrfach in der Spalte vor!\n", val);
            }
            return 0;
          }
          if (++square_count[row / 3][col / 3] > 1) {
            if (show_hints) {
              printf("\n  --> Fehler in (%d/%d): ", row + 1, col + 1);
              printf("die %d kommt mehrfach im Quadrat vor!\n", val);
            }
            return 0;
          }
        }
      }
    }
  }
  return 1;
}


/**
 * Gibt das gesamte Spielfeld auf dem Bildschirm aus.
 */
void print_board() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Steuerung:\n");
  printf("  Beenden:  1337              + ENTER\n");
  printf("  Loesen:   42                + ENTER\n");
  printf("  Spielzug: ZeileSpalteZiffer + ENTER\n\n");
  printf("     1  2  3   4  5  6   7  8  9\n");
  printf("   +---------+---------+---------+\n");
  for (int row = 0; row < 9; row++) {
    printf(" %d |", row + 1);
    for (int col = 0; col < 9; col++) {
      if (BOARD[row][col] == 0) {
        printf("   ");
      } else {
        printf(" %d ", BOARD[row][col]);
      }
      if ((col + 1) % 3 == 0) {
        printf("|");
      }
    }
    printf("\n");
    if ((row + 1) % 3 == 0) {
      printf("   +---------+---------+---------+\n");
    }
  }
}

/**
 * Rekursiver Sudoku Loeser.  Das Spielfeld wird mit Loesung ueberschrieben.
 *
 * Rueckgabe 1, wenn Sudoku loesbar ist, sonst 0.
 */
int solve_sudoku() {
  int r = -1;  // -1 == Ungueltiger Index
  int c = -1;
  // 1. Finde freies Feld
  for (int row = 0; ((row < 9) && (r == -1)); row++) {
    for (int col = 0; ((col < 9) && (c == -1)); col++) {
      if (BOARD[row][col] == 0) {
        r = row;
        c = col;
      }
    }
  }
  // Kein freies Feld mehr gefunden --> Entweder Loesung oder nicht.
  if ((r == -1) && (c == -1)) {
    return check_board(0);
  }

  // 2. Probiere alle moeglichen Kombinationen
  for (int val = 1; val <= 9; val++) {
    BOARD[r][c] = val;
    // Teste 1. ob val in Ordnung ist, dann rekursiver Aufruf.
    if (check_board(0) && solve_sudoku()) {
      // Rekursiver Aufruf hat Loesbarkeit ermittelt
      // --> Verbreite die gute Nachricht an uebergeordnete Rekursion!
      return 1;
    }
  }
  // Kein rekursiver Aufruf hat Loesbarkeit ermittelt
  // --> Gebe Feld wieder frei
  BOARD[r][c] = 0;
  // --> Verbreite die schlechte Nachricht an uebergeordnete Rekursion!
  return 0;
}

/**
 * Hauptfunktion
 */
int main() {
  // Kopiere das original SUDOKU ins Spielfeld.
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      BOARD[row][col] = SUDOKU[row][col];
    }
  }

  // Erste Ausgabe
  print_board();
  printf("\n\n\nEingabe:  ");

  // Spielhauptschleife
  int input = 0; // Gerade verarbeitete Eingabe
  char buf[100]; // Eingabepuffer
  while (1) {
    fgets(buf, 100, stdin);    // Lese in Eingabepuffer ein
    sscanf(buf, "%d", &input); // scanf("%d", &input);
    if (input == 1337) {
      break;  // Verlasse Endlosschleife --> Spielende
    } else if (input == 42) {
      // Kopiere das original SUDOKU ins Spielfeld.
      for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
          BOARD[row][col] = SUDOKU[row][col];
        }
      }
      if (solve_sudoku()) {
        print_board();
        printf("\n  --> Loesung gefunden!!\n");
        break;  // Verlasse Endlosschleife --> Spielende
      } else {
        print_board();
        printf("\n  --> Sudoku unloesbar!!\n");
        break;  // Verlasse Endlosschleife --> Spielende
      }
    }

    // Pruefe auf gueltige Eingaben
    int row = (input % 1000) / 100; // Zeile  [1..9]
    int col = (input %  100) /  10; // Spalte [1..9]
    int val = (input %   10);       // Ziffer [0..9]
    if ((input > 999) || (input < 100) || (row == 0) || (col == 0)) {
      print_board();
      printf("\n  --> Falsche Eingabe!!\n");
      printf("\nEingabe:  ");
      continue;
    }

    // Gueltige Werte fuer row, col, val erhalten.
    // Pruefe, ob Feld spielbar ist.
    if (SUDOKU[row - 1][col - 1] != 0) {
      print_board();
      printf("\n  Das Setzen von Feld (%d/%d) ist verboten!\n", row, col);
      printf("\nEingabe:  ");
      continue;
    }

    // Spielzug erlaubt
    BOARD[row - 1][col - 1] = val;
    print_board();
    if (check_board(1)) {
      printf("\n\n");  // Gebe Leerzeilen statt Fehlermeldung aus.
    }
    printf("\nEingabe:  ");
  }

  printf("\n  --> Spiel beendet.\n\n\n");

  return 0;
}
