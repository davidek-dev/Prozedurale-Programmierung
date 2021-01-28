#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mitarbeiter {
  char vorname[51];
  char nachname[51];
  short personalnummer;
};

struct aufgabe {
  int id;
  char kurzbeschreibung[51];
  short prioritaet;
  struct mitarbeiter* mitarbeiter;
  struct aufgabe* next;
};

/**
 * Erstellt einen Datensatz von 3 Aufgaben mit 2 Mitarbeitern.
 *
 * @return Beispieldatensatz.
 */
struct aufgabe* erstelle_daten() {
  struct mitarbeiter* mitarbeiter1;
  struct mitarbeiter* mitarbeiter2;
  struct aufgabe* liste;

  /* Erstelle Mitarbeiter */
  mitarbeiter1 = (struct mitarbeiter*) malloc (sizeof(struct mitarbeiter));
  strcpy (mitarbeiter1->vorname, "Vorname1");
  strcpy (mitarbeiter1->nachname, "Nachname1");
  mitarbeiter1->personalnummer = 1;
  mitarbeiter2 = (struct mitarbeiter*) malloc (sizeof(struct mitarbeiter));
  strcpy (mitarbeiter2->vorname, "Vorname2");
  strcpy (mitarbeiter2->nachname, "Nachname2");
  mitarbeiter2->personalnummer = 2;

  /* Erstelle Aufgabenliste */
  liste = (struct aufgabe*) malloc (sizeof(struct aufgabe));
  liste->id = 1;
  strcpy (liste->kurzbeschreibung, "Text1");
  liste->prioritaet = 2;
  liste->mitarbeiter = mitarbeiter1;
  liste->next = (struct aufgabe*) malloc (sizeof(struct aufgabe));
  liste->next->id = 2;
  strcpy (liste->next->kurzbeschreibung, "Text2");
  liste->next->prioritaet = 3;
  liste->next->mitarbeiter = NULL;
  liste->next->next = (struct aufgabe*) malloc (sizeof(struct aufgabe));
  liste->next->next->id = 3;
  strcpy (liste->next->next->kurzbeschreibung, "Text3");
  liste->next->next->prioritaet = 1;
  liste->next->next->mitarbeiter = mitarbeiter2;
  liste->next->next->next = NULL;

  return liste;
}

/**
 * Funktion zur Ausgabe der Aufgabenliste, inklusive assoziierten Mitarbeiter.
 *
 * @param fd File descriptor zur Ausgabe (stdout) oder geöffnete Datei.
 * @param liste Aufgabenliste.
 * @param limit Anzahl der auszugebenden Datensätze. Ist limit < 0, werden alle
 *              verfügbaren Datensätze ausgegeben.
 */
void datenausgabe(FILE* fd, struct aufgabe* liste, int limit) {
  while ((liste != NULL) && (limit != 0)) {
    fprintf(fd, "Aufgabe %d\n", liste->id);
    fprintf(fd, "\tBeschreibung: %s\n", liste->kurzbeschreibung);
    fprintf(fd, "\tPrioritaet: %hd\n", liste->prioritaet);
    if (liste->mitarbeiter != NULL) {
      fprintf(fd, "\tZugewiesen an: %s %s (%hd)\n",
              liste->mitarbeiter->vorname,
              liste->mitarbeiter->nachname,
              liste->mitarbeiter->personalnummer);
    } else {
      fprintf(fd, "\tNicht zugewiesen.\n");
    }
    liste = liste->next;
    limit--;
  }
}

/**
 * Fügt eine neue Aufgabe an den Anfang der Liste hinzu.
 *
 * @param liste Aufgabenliste.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste
 */
struct aufgabe* hinzufuegen_anfang(struct aufgabe* liste) {
  struct aufgabe* neues_element = NULL;
  neues_element = (struct aufgabe*) malloc (sizeof(struct aufgabe));
  neues_element->id = 4;
  strcpy (neues_element->kurzbeschreibung, "Text4");
  neues_element->prioritaet = 3;
  neues_element->mitarbeiter = NULL;
  neues_element->next = liste;
  return neues_element;
}

/**
 * Fügt eine neue Aufgabe an das Ende der Liste hinzu.
 *
 * @param anfang Aufgabenliste.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste.
 */
struct aufgabe* hinzufuegen_ende(struct aufgabe* anfang) {
  struct aufgabe* ptr = anfang;
  struct aufgabe* neues_element = NULL;

  /* Erstelle neues Element */
  neues_element = (struct aufgabe*) malloc (sizeof(struct aufgabe));
  neues_element->id = 5;
  strcpy (neues_element->kurzbeschreibung, "Text5");
  neues_element->prioritaet = 4;
  neues_element->mitarbeiter = NULL;
  neues_element->next = NULL;

  /*
   * Wenn Liste bisher leer war, neuer Listenanfang, ansonsten zum Listenende
   * gehen und Element einfügen.
   */
  if (anfang == NULL) {
    return neues_element;
  } else {
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = neues_element;
    return anfang;
  }
}

/**
 * Fügt eine neue Aufgabe an die n-te Position der Liste hinzu.
 *
 * @param anfang Aufgabenliste
 * @param n Position, wo das Element hinzugefügt werden soll. Wenn n größer ist,
 *          als die Liste, wird das Element an das Ende der Liste geschrieben.
 *          n == 0 schreibt an den Listenanfang.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste.
 */
struct aufgabe* hinzufuegen_n(struct aufgabe* anfang, unsigned int n) {
  struct aufgabe* ptr = anfang;
  struct aufgabe* neues_element = NULL;

  /* Erstelle neues Element */
  neues_element = (struct aufgabe*) malloc (sizeof(struct aufgabe));
  neues_element->id = 6;
  strcpy (neues_element->kurzbeschreibung, "Text6");
  neues_element->prioritaet = 2;
  neues_element->mitarbeiter = NULL;
  neues_element->next = NULL;

  if (anfang == NULL) {
    /* Wenn Liste bisher leer war, neuer Listenanfang */
    return neues_element;
  } else if (n == 0) {
    /* Neuer Anfang der Liste */
    neues_element->next = anfang;
    return neues_element;
  } else {
    n--;
    while ((ptr->next != NULL) && (n > 0)) {
      ptr = ptr->next;
      n--;
    }
    neues_element->next = ptr->next;
    ptr->next = neues_element;
    return anfang;
  }
}

/**
 * Funktion zum Vertauschen von zwei aufeinanderfolgenden Aufgaben in einer
 * verketteten Aufgabenliste. Es gilt a->next == b.
 *
 * @param liste Anfang der Aufgabenliste.
 * @param a Aufgabe zum Vertauschen.
 * @param b Aufgabe zum Vertauschen.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste.
 */
struct aufgabe* swap_aufgaben(struct aufgabe* liste, struct aufgabe* a,
                              struct aufgabe* b) {
  struct aufgabe* iter = liste;

  /* Sonderfall Listenanfang */
  if (liste == a) {
    a->next = b->next;
    b->next = a;
    return b;
  }

  while (iter->next != a) {
    iter = iter->next;
  }

  iter->next = b;
  a->next = b->next;
  b->next = a;

  return liste;
}

/**
 * Sortiert eine verkette Liste von Aufgaben absteigend nach Prioritäten.
 *
 * @param anfang Anfang der Aufgabenliste.
 *
 * @return Zeiger auf den Anfang der sortierten Aufgabenliste.
 */
struct aufgabe* sortiere_prioritaeten(struct aufgabe* anfang) {
  int tausch = 1;
  struct aufgabe* iter = NULL;

  while (tausch) {
    tausch = 0;
    iter = anfang;
    while (iter->next != NULL) {
      if ((iter->prioritaet) < (iter->next->prioritaet)) {
        tausch = 1;
        anfang = swap_aufgaben(anfang, iter, iter->next);
        break;
      }
      iter = iter->next;
    }
  }

  return anfang;
}

/**
 * Sortiert eine verkette Liste von Aufgaben alphabetisch aufsteigend nach
 * Kurzbeschreibungen.
 *
 * @param anfang Anfang der Aufgabenliste.
 *
 * @return Zeiger auf den Anfang der sortierten Aufgabenliste.
 */
struct aufgabe* sortiere_kurzbeschreibung(struct aufgabe* anfang) {
  int tausch = 1;
  struct aufgabe* iter = NULL;

  while (tausch) {
    tausch = 0;
    iter = anfang;
    while (iter->next != NULL) {
      if (strcmp(iter->kurzbeschreibung, iter->next->kurzbeschreibung) > 0) {
        tausch = 1;
        anfang = swap_aufgaben(anfang, iter, iter->next);
        break;
      }
      iter = iter->next;
    }
  }

  return anfang;
}

/**
 * Gibt die Aufgabe mit der höchsten Priorität aus.
 *
 * @param liste Anfang der Aufgabenliste.
 */
void datenausgabe_max_prioritaet(struct aufgabe* liste) {
  struct aufgabe* max = liste;
  while (liste != NULL) {
    if((max->prioritaet) < (liste->prioritaet)) {
      max = liste;
    }
    liste = liste->next;
  }
  datenausgabe(stdout, max, 1);
}

/**
 * Gibt alle Datensätze von mitarbeiter1 (ID = 1) aus.
 *
 * @param liste Anfang der Aufgabenliste.
 */
void datenausgabe_mitarbeiter1(struct aufgabe* liste) {
  while (liste != NULL) {
    if((liste->mitarbeiter != NULL)
        && (liste->mitarbeiter->personalnummer == 1)) {
      datenausgabe(stdout, liste, 1);
    }
    liste = liste->next;
  }
}

/**
 * Entferne eine Aufgabe am Anfang der Liste.
 *
 * @param liste Aufgabenliste.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste
 */
struct aufgabe* entfernen_anfang(struct aufgabe* liste) {
  struct aufgabe* liste_neu = NULL;

  if(liste == NULL) {
    return NULL;
  }
  liste_neu = liste->next;
  if (liste->mitarbeiter != NULL) {
    free(liste->mitarbeiter);
  }
  free(liste);

  return liste_neu;
}

/**
 * Entfernt eine Aufgabe am Ende der Liste.
 *
 * @param liste Aufgabenliste.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste.
 */
struct aufgabe* entfernen_ende(struct aufgabe* liste) {
  struct aufgabe* iter = liste;

  if(liste == NULL) {
    return NULL;
  }
  if (liste->next == NULL) {
    if (liste->mitarbeiter != NULL) {
      free(liste->mitarbeiter);
    }
    free(liste);
    return NULL;
  } else {
    while (iter->next->next != NULL) {
      iter = iter->next;
    }
    if (iter->next->mitarbeiter != NULL) {
      free(iter->next->mitarbeiter);
    }
    free(iter->next);
    iter->next = NULL;
  }

  return liste;
}

/**
 * Entfernt eine Aufgabe an die n-te Position der Liste.
 *
 * @param liste Aufgabenliste
 * @param n Position, wo das Element gelöscht werden soll. Wenn n größer ist,
 *          als die Liste, wird das Element am Ende der Liste gelöscht.
 *          n == 0 löscht das erste Listenelement.
 *
 * @return Zeiger auf den Anfang der neuen Aufgabenliste.
 */
struct aufgabe* entfernen_n(struct aufgabe* liste, unsigned int n) {
  struct aufgabe* iter = NULL;
  struct aufgabe* iter2 = NULL;

  if(liste == NULL) {
    return NULL;
  }

  if (liste->next == NULL) {
    if (liste->mitarbeiter != NULL) {
      free(liste->mitarbeiter);
    }
    free(liste);
    return NULL;
  } else if (n == 0) {
    iter = liste->next;
    if (liste->mitarbeiter != NULL) {
      free(liste->mitarbeiter);
    }
    free(liste);
    return iter;
  } else {
    iter = liste;
    while ((iter->next->next != NULL) && (n > 1)) {
      iter = iter->next;
      n--;
    }
    iter2 = iter->next->next;
    if (iter->next->mitarbeiter != NULL) {
      free(iter->next->mitarbeiter);
    }
    free(iter->next);
    iter->next = iter2;
  }

  return liste;
}

/**
 * Schreibt die Aufgabenliste in eine Datei. Der Dateiname wird durch
 * Benutzereingabe ermittelt.
 *
 * @param liste Aufgabenliste
 */
void schreibe_in_datei (struct aufgabe* liste) {
  FILE* fd = NULL;
  char buffer[51];
  char* ptr = buffer;

  printf("Geben Sie einen Dateinamen ein: ");
  fgets(buffer, sizeof buffer, stdin);
  /* Sichere das String Ende */
  buffer[50] = '\0';
  while ((*ptr != '\n') && (*ptr != '\0')) ptr++;
  *ptr = '\0';

  fd = fopen(buffer, "w");
  if(fd == NULL) {
    printf("Cannot open file!");
    exit(-1);
  }
  datenausgabe(fd, liste, -1);
  fclose(fd);
}

/**
 * Liest die Aufgabenliste aus einer Datei.
 *
 * @param fname Dateiname aus der gelesen werden soll. Wenn fname == NULL, wird
 *              der Dateiname durch Benutzereingabe ermittelt.
 */
struct aufgabe* lese_aus_datei (char* fname) {
  FILE* fd = NULL;
  char buffer[51];
  char* ptr = buffer;
  struct aufgabe* liste = NULL;
  struct aufgabe* lastitem = NULL;
  struct aufgabe* newitem = NULL;

  if (fname == NULL) {
    printf("Geben Sie einen Dateinamen ein: ");
    fgets(buffer, sizeof buffer, stdin);
  } else {
    strncpy(buffer, fname, sizeof buffer);
  }
  /* Sichere das String Ende */
  buffer[50] = '\0';
  while ((*ptr != '\n') && (*ptr != '\0')) ptr++;
  *ptr = '\0';

  fd = fopen(buffer, "r");
  if (fd == NULL) {
    fprintf(stderr, "Cannot open file %s.", buffer);
    exit(-1);
  }

  while (!feof(fd)) {
    newitem = (struct aufgabe*) malloc(sizeof(struct aufgabe));

    fscanf(fd, "Aufgabe %d\n", &(newitem->id));
    fscanf(fd, "\tBeschreibung: %s\n", newitem->kurzbeschreibung);
    fscanf(fd, "\tPrioritaet: %hd\n", &(newitem->prioritaet));
    if (fgetc(fd) == 'N') {
      newitem->mitarbeiter = NULL;
      fscanf(fd, "icht zugewiesen.\n");
    } else {
      newitem->mitarbeiter = (struct mitarbeiter*) malloc(sizeof(struct mitarbeiter));
      fscanf(fd, "ugewiesen an: %s %s (%hd)\n",
             newitem->mitarbeiter->vorname,
             newitem->mitarbeiter->nachname,
             &(newitem->mitarbeiter->personalnummer));
    }
    newitem->next = NULL;

    if (liste == NULL) {
      liste = newitem;
      lastitem = newitem;
    } else {
      lastitem->next = newitem;
      lastitem = lastitem->next;
    }
  }

  fclose(fd);

  return liste;
}

/**
 * MAIN
 */
int main(int argc, char* argv[]) {
  struct aufgabe* liste = NULL;

  /* Aufgabe 4 */
  liste = erstelle_daten();

  /* Aufgabe 5 */
  datenausgabe(stdout, liste, -1);

  /* Aufgabe 6 */
  liste = hinzufuegen_anfang(liste);

  /* Aufgabe 7 */
  liste = hinzufuegen_ende(liste);

  /* Aufgabe 8 */
  liste = hinzufuegen_n(liste, 2);

  /* Aufgabe 10 */
  liste = sortiere_prioritaeten(liste);

  /* Aufgabe 11 */
  liste = sortiere_kurzbeschreibung(liste);

  /* Aufgabe 12 */
  datenausgabe_max_prioritaet(liste);

  /* Aufgabe 13 */
  datenausgabe_mitarbeiter1(liste);

  /* Aufgabe 14 */
  liste = entfernen_anfang(liste);

  /* Aufgabe 15 */
  liste = entfernen_ende(liste);

  /* Aufgabe 16 */
  liste = entfernen_n(liste, 2);

  /* Aufgabe 17 */
  schreibe_in_datei(liste);

  /* Aufgabe 18 */
  liste = lese_aus_datei(NULL);

  /* Aufgabe 19 */
  if (argc > 1) {
    liste = lese_aus_datei(argv[1]);
  }

  return 0;
}
