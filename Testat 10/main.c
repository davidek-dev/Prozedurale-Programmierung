#include <stdio.h>
#include <stdlib.h>

struct student
{
    char* vorname;
    char* nachname;
    int matrikelnummer;
    char* adresse;
    int anzahl;
    struct student* next;
    struct student* prev;
};


void printList(struct student* root)
{
	if (root == NULL) return;
	for (; root != NULL; root = root->next)
		printf("%s\t%s\t%d\t%s\t%d\n", root->vorname, root->nachname, root->matrikelnummer, root->adresse, root->anzahl);
	printf("\n");
    return;
}

void printListReverse(struct student* curr)
{
   if (curr==NULL) return;
   struct student* first = curr;
   
   for ( ; curr->next != NULL ; curr = curr->next) ; //curr ist tail
   struct student* second = curr;
   curr->next = first->next;
   curr->prev = first->prev;
   first->next = second->next;
   first->prev = second->next;  
   
   printList(curr);
   return;
   	// printf("%s\t%s\t%d\t%s\t%d\n", curr->vorname, curr->nachname, curr->matrikelnummer, curr->adresse, curr->anzahl);
	

    // for (; second->next != NULL; second = second->next)
	// 	printf("%s\t%s\t%d\t%s\t%d\n", second->vorname, second->nachname, second->matrikelnummer, second->adresse, second->anzahl);
	
    // printf("%s\t%s\t%d\t%s\t%d\n", first->vorname, first->nachname, first->matrikelnummer, first->adresse, first->anzahl);
    // printf("\n");
}


struct student* revert(struct student *root){
    struct student *tmp=NULL;
    struct student *curr = root;

    while (curr != NULL)
    {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;//also das alte curr->next
    }

    if(tmp != NULL ) root = tmp->prev; 

    for (; root->prev != NULL; root = root->prev);
    
    return root;
}


int main(){

    struct student* Lisa = malloc(sizeof(struct student));
    struct student* Hans = malloc(sizeof(struct student));
    struct student* Anna = malloc(sizeof(struct student));

    Lisa->adresse = "Denickestrasse 15";
    Lisa->anzahl = 8;
    Lisa->matrikelnummer = 66666;
    Lisa->nachname ="Lustig";
    Lisa->next = Hans;
    Lisa->vorname="Lisa";
    Lisa->prev = NULL;
    
    Hans->adresse = "Kasernenstrasse 12";
    Hans->anzahl = 2;
    Hans->matrikelnummer = 44444;
    Hans->nachname ="Peter";
    Hans->next = Anna;
    Hans->vorname="Hans";
    Hans->prev = Lisa;

    Anna->adresse = "Am Schwarzenberg-Campus 3";
    Anna->anzahl = 4;
    Anna->matrikelnummer = 22222;
    Anna->nachname ="Musterfrau";
    Anna->next = NULL;
    Anna->vorname="Anna";
    Anna->prev = Hans;
//------------------------------------------------
//zwei weitere einfügen und eins löschen
    struct student* David = malloc(sizeof(struct student));
    struct student* Marvin = malloc(sizeof(struct student));

    Anna->next = David;

    David->adresse = "Koppelring";
    David->anzahl = 3;
    David->matrikelnummer = 52497;
    David->nachname ="Zeplin";
    David->next = Marvin;
    David->vorname="David";
    David->prev = Anna;
    
    Marvin->adresse = "Am Golfplatz";
    Marvin->anzahl = 2;
    Marvin->matrikelnummer = 51488;
    Marvin->nachname ="Heydorn";
    Marvin->next = NULL;
    Marvin->vorname="Marvin";
    Marvin->prev = David;
//Lösche das dritte Listenelement

    struct student* prev = Lisa;
    struct student* third = Lisa->next;
    for (int i = 3; i < 4; i++) {third = third->next; prev = prev->next;}
    prev->next = third->next;
    third->next->prev = prev;
    free(third);


    printList(Lisa);
    printf("\n");
    printList(revert(Lisa));
    printf("\n");
 
    //printListReverse(Lisa);
    return 0;
}