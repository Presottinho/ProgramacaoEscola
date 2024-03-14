#include <stdio.h>
#include <stdlib.h>

#define TSTR 10

void juntaStr (char strDest[], char strOrig[])
{

    char strSomadas[20];
    int tmn = 0;
    for(int i = 0; strDest[i] != '\0'; i++){
        strSomadas[i] = strDest[i];
        tmn++;
    }
    tmn++
    strSomadas[tmn] = ' ';
    tmn++
    for(int i = 0; strOrig[i] != '\0'; i++){
        strSomadas[tmn] = strOrig[i];
        tmn++
    }

    printf("%s", strSomadas);

}

int main()
{
    char adjetivo[TSTR]=" azulado" ;
    char substantivo[TSTR]="Orbe";

    printf("%s\n",substantivo);
    printf("%s\n",adjetivo);

=  juntaStr(substantivo,adjetivo);

   printf("%s\n",substantivo);
   printf("%s\n",adjetivo);


    return 0;
}