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
};

struct student Lisa = {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8, NULL};
struct student Hans = {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2, &Lisa};
struct student Anna = {"Anna", "Musterfrau", 22222, "Am Schwarzenberg-Campus 3", 4, &Hans};

void printList(struct student* root)
{
	if (root == NULL) return;
	for (; root != NULL; root = root->next)
		printf("%s\t%s\t%d\t%s\t%d\n", root->vorname, root->nachname, root->matrikelnummer, root->adresse, root->anzahl);
	printf("\n");
}

void printListReverse(struct student* curr)
{
   if (curr==NULL) return;
   struct student* first = curr;
   struct student* second = curr->next;
   for ( ; curr->next != NULL ; curr = curr->next) ;
   	printf("%s\t%s\t%d\t%s\t%d\n", curr->vorname, curr->nachname, curr->matrikelnummer, curr->adresse, curr->anzahl);
	

    for (; second->next != NULL; second = second->next)
		printf("%s\t%s\t%d\t%s\t%d\n", second->vorname, second->nachname, second->matrikelnummer, second->adresse, second->anzahl);
	
    printf("%s\t%s\t%d\t%s\t%d\n", first->vorname, first->nachname, first->matrikelnummer, first->adresse, first->anzahl);
    printf("\n");
}


int main(){

    printList(&Anna);
    printf("\n");
    printListReverse(&Anna);
    return 0;
}