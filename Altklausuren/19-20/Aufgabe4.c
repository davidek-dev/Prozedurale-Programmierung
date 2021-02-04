#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc<4)         //"Ihr Programm hat zu prüfen, ob ausreichend viele Kommandozeilenargumente übergeben wurden"
    {                   //argc muss 4 sein da argv 4 einträge haben muss
                        //wenn argc größer als 0 ist, so ist in argv[0] standardmäßig der Name des programmes 
        return EXIT_FAILURE;//argv[1] = Eingabedateiname  argv[2] = M   argv[3] = N
    }
    
    char* Eingabedatei=NULL;
    int M=0;//zeilen
    int N=0; //anzahl ganze zahlen pro zeile
    sscanf(argv[1], Eingabedatei);//
    sscanf(argv[2], "%d", &M);
    sscanf(argv[3], "%d", &N);

    int* array = (int*) malloc(N* sizeof(int));//die eingelesenen Datenzeilen sollen in einem dynamisch allozierten Array gespeichert werden.

    FILE* Eingabedatei_pointer = fopen(Eingabedatei, "r");
    if ((array==NULL)||(Eingabedatei_pointer ==NULL))//, ob die eingabedatei auslesbar ist und ob die dynamischen speicherallokationen erfolgreich waren
    {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf( Eingabedatei_pointer, "%d", array[j]);
        }
        for (int k = 0; k < N; k++)
        {
            printf("%d ", array[k]);
        }
        
    }
        

//gcc Aufgabe4.c "Eingabedatei.txt" "4" "3"

    fclose(Eingabedatei_pointer); //nicht explizit gefordert aber muss trotzdem vorhanden sein sonst speicherleck
    free(array);            //nicht explizit gefordert aber muss trotzdem vorhanden sein sonst speicherleck
    

}