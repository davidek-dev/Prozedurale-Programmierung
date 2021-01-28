#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int i,n;
  char str[101];
  char **S=NULL;

  // Anzahl der Strings einlesen
  printf(" n = ");
  scanf("%d",&n);

  // Speicher für String-Array der Länge n dynamisch reservieren
  S=(char**)malloc(n*sizeof(char*));
  if(S==NULL) {
    printf("Fehler malloc() S");
    exit(1);
  }
  printf("\n");

  // Strings nacheinander einlesen
  for(i=0; i<n; i++) {
    printf(" String_%d : ",i+1);
    scanf("%2048s",str);
    S[i]=(char*)malloc((strlen(str)+1)*sizeof(
                         char)); // Speicher for i-ten String dynamisch reservieren.
    if(S[i]==NULL) {
      printf("Fehler malloc() S_%d",i);
      exit(1);
    }
    strcpy(S[i],str); // eingelesenen String str nach S[i] kopieren
  }
  printf("\n");

  // Ausgabe zur Kontrolle
  for(i=0; i<n; i++) printf("\n String_%d : %s",i+1,S[i]);

  // Speicher freigeben
  for(i=0; i<n; i++) free(S[i]);
  free(S);
  return 0;
}
