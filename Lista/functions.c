//
//  functions.c
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#include "functions.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int iloscStudentow = 0;

void usun(char ***students) {
        if (iloscStudentow > 0) {
                int index, pozycja = -1;
                drukuj(students);
                printf("Podaj index do usuniecia: ");
                scanf(" %d", &index);
                for (int x = 0; x < iloscStudentow; x++) {
                        if (atoi(students[x][0]) == index) {
                                pozycja = x;
                                usun_element(students, pozycja);
                                break;
                        }
                }
                if (pozycja == -1) {
                        printf("\n   ---   Nie ma takiego indexu   ---\n");
                }
        } else {
                students = NULL;
        }
}

void drukuj(char ***students) {
        if (iloscStudentow > 0) {
                printf("\n");
                printf("index                  IMIE                    NAZWISKO\n");
                for (int x = 0; x < iloscStudentow; x++) {
                        
                        for (int y = 0; y < 3; y++) {
                                y == 0 ? printf("%6s - ", students[x][y]) : printf("  |   %20s", students[x][y]);
                        }
                        printf("\n-------------------------------------------------------------");
                        printf("\n");
                }
        } else {
                printf("\n   ---   Tablica jest pusta   ---\n\n");
        }
}

void usun_element(char ***students, int index) {
        for (int i = index; i < iloscStudentow + 1; i++) {
                students[i] = students[i+1];
        }
        iloscStudentow--;
        char ***temp = tymczasowa_tabela(students);
        students = temp;
}

char ***dodaj_na_poczatku(char ***students) {
        switch (iloscStudentow) {
                case 0: iloscStudentow++;
                        students = dodaj_do_pustej_listy(students);
                        break;
                default:
                        iloscStudentow++;
                        char ***temp = tymczasowa_tabela(students);
                        
                        for (int x = iloscStudentow - 1; x > 0; x--) {
                                for (int i = 0; i < 3; i ++) {
                                        temp[x][i] = students[x-1][i];
                                }
                        }
                        students = temp;
                        
                        dodajStudenta(students[0][0], students[0][1], students[0][2]);
        }
        return students;
}

char ***dodaj_na_koncu(char ***students) {
        switch (iloscStudentow) {
                case 0: iloscStudentow++;
                        students = dodaj_do_pustej_listy(students);
                        break;
                default:
                        iloscStudentow++;
                        char ***temp = tymczasowa_tabela(students);
                        for (int x = 0; x < iloscStudentow -1; x++) {
                                for (int i = 0; i < 3; i ++) {
                                        temp[x][i] = students[x][i];
                                }
                        }
                        students = temp;
                        dodajStudenta(students[iloscStudentow-1][0], students[iloscStudentow-1][1], students[iloscStudentow-1][2]);
                        break;
        }
        return students;
}

char ***dodaj_do_pustej_listy(char ***students) {
        
        char imie[20], nazwisko[20], id[20];
        dodajStudenta(id, imie, nazwisko);
        students = tymczasowa_tabela(students);
        
        for (int y = 0; y < 3; y++) {
                
                strcpy(students[0][y], (y !=0 ? (y == 1 ? imie : nazwisko): id));
        }
        return students;
}

void dodajStudenta(char *id, char *imie, char *nazwisko) {
        
        printf("Podaj id: ");
        scanf(" %s", id);
        
        printf("Podaj imie: ");
        scanf(" %s", imie);
        
        printf("Podaj nazwisko: ");
        scanf(" %s", nazwisko);
}

char ***tymczasowa_tabela(char ***students) {
        char ***temp = malloc(sizeof(char**) * iloscStudentow);
        assert(temp);
        for (int x= 0; x < iloscStudentow; x++) {
                temp[x] = malloc(sizeof(char*));
                //assert(students[0]);
                
                for (int y = 0; y < 3; y++) {
                        
                        temp[x][y] = malloc(sizeof(char) * 20);
                        assert(temp[x][y]);
                }
        }
        return temp;
}

void sortuj(char ***students, int metoda) {
        int znacznik;
        char *zamiennik;
        for (int x = 0; x < iloscStudentow - 1; x++) {
                znacznik = 0;
                for (int y = 0; y < iloscStudentow - 1; y++) {
                        if (metoda == 2 ? (strcmp(students[y+1][metoda],students[y][metoda]) < 0) : (atoi(students[y+1][metoda]) < atoi(students[y][metoda]))) {
                                for (int i = 0; i < 3; i++) {
                                        zamiennik = students[y][i];
                                        students[y][i] = students[y + 1][i];
                                        students[y + 1][i] = zamiennik;
                                }
                                znacznik = 1;
                        }
                }
                if (!znacznik) break;
        }
}
