#include <stdio.h>
#include <stdlib.h>

/*
1.1 Datenstruktur
Erstellen Sie ein globales, zweidimensionales und statisches Array zur Speicherung 
des 9×9Sudoku-Spielfelds. 
Ein leeres Feld kann z.B. durch die „0“ repräsentiert werden
*/

const int Base_Feld[9][9] = {{4, 1, 0, 0, 6, 5, 0, 0, 7},
                             {0, 0, 6, 0, 0, 7, 4, 8, 0},
                             {2, 0, 7, 4, 9, 0, 0, 0, 6},
                             {0, 6, 0, 0, 7, 0, 1, 0, 0},
                             {3, 0, 1, 5, 0, 0, 0, 7, 2},
                             {0, 9, 0, 0, 4, 2, 3, 0, 8},
                             {1, 0, 8, 6, 0, 0, 0, 2, 9},
                             {0, 2, 0, 0, 1, 8, 6, 4, 0},
                             {6, 0, 0, 3, 0, 0, 0, 1, 0}};

int Feld[9][9]; //spielfeld

/*
1.2 Bildschirmausgabe
Schreiben Sie eine Funktion, 
welche das Sudoku-Spielfeld ähnlich 
wie in oberer Abbildungübersichtlich auf dem Bildschirm ausgibt
*/

void drucken(int (*ptr)[9])
{  
    printf("\n\nFolgendes sind die 4 Sudokuregeln:\n\n");
    printf("\t1.\tDie Werte m\x81ssen im Bereich von 1 bis 9 sein\n");
    printf("\t2.\tIn einer Reihe darf keine Zahl mehr als ein mal auftreten\n");
    printf("\t3.\tIn einer Spalte darf keine Zahl mehr als ein mal auftreten\n");
    printf("\t4.\tIn einem Block darf keine Zahl mehr als ein mal auftreten\n\n\n");


    printf("      1  2  3     4  5  6     7  8  9\n");
    printf("   +-----------+-----------+-----------+\n");

    for (int i = 1; i <= 9; i++)
    {
        printf("%d  |  ", i);

        for (int j = 1; j <= 9; j++)
        {
            if (ptr[i - 1][j - 1] == 0)
            {
                printf("   ");
            }
            else
            {
                printf("%d  ", ptr[i - 1][j - 1]);
            }

            if (j % 3 == 0)
            {
                printf("|  ");
            }
        }

        printf("\n");
        if (i % 3 == 0)
        {
            printf("   +-----------+-----------+-----------+\n");
        }
    }
}

int main()
{




    
    
    
    // Kopiere das original SUDOKU ins Spielfeld.
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            Feld[row][col] = Base_Feld[row][col];
        }
    }

    /*
1.3
Dateneingabe
Erweitern Sie ihre main-Funktion, sodass der Benutzer Werte in ihrem Spielfeld ändern kann,
bis das Sudoku vollständig ausgefüllt ist. 
Überlegen Sie sich, welche Eingaben Sie vom Benutzer benötigen, 
wie Sie die Benutzer eingaben auf Gültigkeit überprüfen 
und wie der Benutzer „falsche Entscheidungen“ Rückgängig machen kann. 
Nutzen Sie dazu die scanf-Funktion oder für zeichenweises Einlesen die getchar-Funktion.
*/
    //Abbruch bedingung erzeugen
    int empty_fields = 0;
    int row_select;
    int column_select;
    int new_value;
    int startBoxRow;
    int startBoxCol;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (Base_Feld[i][j] == 0)
            {
                empty_fields++;
            }
        }
    }

    //..............................
    //Main Game Loop
    //Aufgabe 1.4 - Spiel spielbar machen
    //..............................



    while (empty_fields != 0) //solange nicht jedes feld ausgefüllt ist
    {
        //printf("\e[1;1H\e[2J"); //Regex führt hier zum clear des Bildschirms und zum
        //positionieren des eingabefeldes in der Konsole am unteren Rand
        //unabhängig von der Fenstergröße. Vorteil gegenüber system("clear") ist
        //die viel höhere effizienz
        //Fehl Eingabe Managment
        
        drucken(Feld);
        //Wert eingabe
        new : printf("\n\n\nF\x81lle das Sudoku aus!\n\n"); //goto anweisung. bei Fehler wird hier nochmal gestartet
        printf("\tZeile:");
        scanf("%d", &row_select); //reihe einlesen

        if (row_select > 9 || row_select < 1) //row ausserhalb ddes Bereiches eingegeben
        {
            printf("\nFehler:\tDeine Eingabe ist%d. Die Reihe darf jedoch nur im Bereich von 1 bis 9 sein\n", row_select);
            goto new;
        }

        printf("\tSpalte:");
        scanf("%d", &column_select); //spalte einlesen

        if (Base_Feld[row_select - 1][column_select - 1] != 0) //das ausgewählte Feld gehört zur vorlage und soll nicht geändert werden
        {
            printf("\nFehler:\tDas ausgew\x84hlte Feld geh\x94rt zu den vorgegebenen Feldern und kann deswegen nicht ver\x84ndert werden.\n");
            goto new;
        }

        if (column_select > 9 || column_select < 1) //spalte ist ausserhalb des Bereiches
        {
            printf("\nFehler:\tDeine Eingabe ist%d. Die Spalte darf jedoch nur im Bereich von 1 bis 9 sein\n", column_select);
            goto new;
        }

        printf("\tWelcher Wert soll eingegeben werden?:");
        scanf("%d", &new_value); //Wert für das Kästchen eingeben

        //regel 1: Bereich beachten
        if (new_value > 9 || new_value < 1) //spalte ist ausserhalb des Bereiches
        {
            printf("\nFehler:\tDeine Eingabe ist %d. Der Wert darf jedoch nur im Bereich von 1 bis 9 sein\n", new_value);
            goto new;
        }

        //------------------------------------------------------
        //alle Gültigkeiten abgearbeitet, jetzt nur noch logik fehler möglich.
        //Verbesserung durch das üebrschreiben von Feldern.
        //------------------------------------------------------
        column_select--;
        row_select--;
        
        

        //spalten&reihen Regel
        Feld[row_select][column_select] = new_value;
       for (int row = 0; row < 9; row++)
       {
           for (int col = 0; col < 9; col++)
           {
               if(Feld[row_select][column_select]==Base_Feld[row_select][col]){
                   system("cls");
                   printf("\n\nIn der Spalte %d und Reihe %d gibt es bereits den Eintrag %d\n\n", col+1, row_select+1, new_value);
                   goto set;
               }
               if(Feld[row_select][column_select]==Base_Feld[row][column_select]){
                   system("cls");
                   printf("\n\nIn der Reihe %d und Spalte %d gibt es bereits den Eintrag %d\n\n", row+1, column_select+1, new_value);
                   goto set;
               }
           }
       }

        //TODO: Box regel
       startBoxRow = (row_select+1) - row_select % 3;
       startBoxCol = (column_select+1) - column_select % 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Feld[i+startBoxRow][j+startBoxCol]==Feld[row_select][column_select])
                {
                    printf("\n\nIm der gleichen Box in der %d ten Spalte und der %d ten Reihe der Box gibt es bereits den Eintrag %d\n\n", startBoxRow+i+1, j+startBoxCol+1, new_value);
                    goto set;
                }
            }
        }
        

       set:
    empty_fields--;
    }

    return 0;
}