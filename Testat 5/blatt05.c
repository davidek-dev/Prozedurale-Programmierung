#include <stdio.h>


/*
1.2 Bildschirmausgabe
Schreiben Sie eine Funktion, 
welche das Sudoku-Spielfeld ähnlich 
wie in oberer Abbildungübersichtlich auf dem Bildschirm ausgibt
*/


void drucken(int (*ptr)[9]){
    printf("      1  2  3     4  5  6     7  8  9\n");
    printf("   +-----------+-----------+-----------+\n");

    for (int i = 1; i <= 9; i++)
    {
        printf("%d  |  ", i);

        for (int j = 1; j <= 9; j++)
        {   
            if (ptr[i-1][j-1]==0)
            {
                printf("   ");
            }else
            {
                printf("%d  ", ptr[i-1][j-1]);
            } 

            if (j%3==0)
            {
                printf("|  ");
            }           
        }

        printf("\n");
        if (i%3==0)
        {
            printf("   +-----------+-----------+-----------+\n");
        }
    }
}





int main(){

/*
1.1 Datenstruktur
Erstellen Sie ein globales, zweidimensionales und statisches Array zur Speicherung 
des 9×9Sudoku-Spielfelds. 
Ein leeres Feld kann z.B. durch die „0“ repräsentiert werden
*/

int Feld[9][9] = {  {4,1,0,0,6,5,0,0,7},
                    {0,0,6,0,0,7,4,8,0},
                    {2,0,7,4,9,0,0,0,6},
                    {0,6,0,0,7,0,1,0,0},
                    {3,0,1,5,0,0,0,7,2},
                    {0,9,0,0,4,2,3,0,8},
                    {1,0,8,6,0,0,0,2,9},
                    {0,2,0,0,1,8,6,4,0},
                    {6,0,0,3,0,0,0,1,0}
                };
drucken(Feld);


    return 0;
}