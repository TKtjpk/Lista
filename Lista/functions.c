//
//  functions.c
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#include "functions.h"
#include <string.h>
#include <stdlib.h>

void costam(void) {
    printf("Hej Jestem \n");
}

char ***dodaj(char ***list) {
    char student[1][3][20] = {};
    char src0p[6];
    char nazwisko[20];
    char imie[20];
    int id = 1;
    printf("Podaj imię studenta: ");
    scanf("%s", imie);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", nazwisko);
    sprintf(src0p, "%03d", id);
    //sscanf(src0p, "%i", &id);
    //printf("%i", id);
    student[0][0][0] = *src0p;
    student[0][1][0] = *imie;
    student[0][2][0] = *nazwisko;
    //list = (char***)malloc((10 * 3 * 20) * sizeof(char));
    for (int z  = 0; z < 3; z++) {
        printf("%s ", student[0][z]);
        //strcpy(list[0][z], student[0][z]);
    }
    printf("\n");
    //list = (char*)malloc((10 * 3 * 20) * sizeof(char));
    return list;
}
