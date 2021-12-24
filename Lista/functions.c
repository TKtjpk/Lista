//
//  functions.c
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>


int iloscStudentow = 0;

char ***tabela(char ***students)
{
        students = malloc(sizeof(char**) * 1);
        
        students[0] = malloc(sizeof(char*) * 3);
        
        for (int y = 0; y < 3; y++)
        {
                students[0][y] = malloc(sizeof(char) * 21);
        }
        return students;
}

void usun(char ***students)
{
        if (iloscStudentow > 0)
        {
                int index, pozycja = -1;
                drukuj(students);
                printf("Podaj index do usuniecia: ");
                scanf(" %d", &index);
                for (int x = 0; x < iloscStudentow; x++)
                {
                        if (atoi(students[x][0]) == index)
                        {
                                pozycja = x;
                                usun_element(students, pozycja);
                                break;
                        }
                }
                if (pozycja == -1) {
                        printf("\n   ---   Nie ma takiego indexu   ---\n");
                }
        }
        else
        {
                students = NULL;
        }
}

void drukuj(char ***students)
{
        if (iloscStudentow > 0)
        {
                printf("\n index / NAZWISKO / IMIE\n");
                
                for (int x = 0; x < iloscStudentow; x++)
                {
                        
                        printf("%s  %s  %s", students[x][0] , students[x][2], students[x][1]);
                        printf("\n      -       -       -       -       -\n");
                }
        }
        else
        {
                printf("\n   ---   Tablica jest pusta   ---\n\n");
        }
}

void usun_element(char ***students, int index)
{
        for (int i = index; i < iloscStudentow + 1; i++)
        {
                students[i] = students[i+1];
        }
        
        iloscStudentow--;
        
        char ***temp = realloc(students, sizeof(***temp) * iloscStudentow);
        
        students = temp;
}

char ***dodaj_na_poczatku(char ***students)
{
        char ***temp;
        
        iloscStudentow++;
        
        temp = tymczasowa_tabela(students);
        
        for (int x = iloscStudentow - 1; x > 0; x--)
        {
                for (int i = 0; i < 3; i ++)
                {
                        strcpy(temp[x][i],temp[x-1][i]);
                }
        }

        students = temp;
        
        dodajStudenta(students, 0);

        return students;
}

void dodaj_na_koncu(char ***students)
{
        iloscStudentow++;
        
        char ***temp = tymczasowa_tabela(students);
        
        students = temp;
        dodajStudenta(students, iloscStudentow-1);
}

void dodaj_do_pustej_listy(char ***students)
{
        dodajStudenta(students, 0);
        
        iloscStudentow++;
}

void dodajStudenta(char ***students, int pozycja)
{
        char id[20], imie[20], nazwisko[20];
        
        printf("Podaj id: ");
        scanf(" %s", id);
        
        printf("Podaj imie: ");
        scanf(" %s", imie);
        
        printf("Podaj nazwisko: ");
        scanf(" %s", nazwisko);
        
        for (int y = 0; y < 3; y++)
        {
                strcpy(students[pozycja][y], (y !=0 ? (y == 1 ? imie : nazwisko): id));
        }
}

char ***tymczasowa_tabela(char ***students)
{
        char ***temp = realloc(students, sizeof(***temp) * iloscStudentow);
        
        temp[iloscStudentow-1] = malloc(sizeof(*temp) * 3);
        
        for (int i = 0; i < 3; i++)
        {
                temp[iloscStudentow-1][i] = malloc(sizeof(char) * 21);
        }
        
        return temp;
}

void sortuj(char ***students, int metoda)
{
        int znacznik;
        
        char *zamiennik;
        
        for (int x = 0; x < iloscStudentow - 1; x++)
        {
                znacznik = 0;
                
                for (int y = 0; y < iloscStudentow - 1; y++)
                {
                        if (metoda == 2 ? (strcmp(students[y+1][metoda],students[y][metoda]) < 0) : (atoi(students[y+1][metoda]) < atoi(students[y][metoda])))
                        {
                                for (int i = 0; i < 3; i++)
                                {
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

void zwolnij(char ***students) {
        for (int z = 0; z < iloscStudentow; z++)
        {
                for (int x = 0; x < 3; x++)
                {
                        free(students[z][x]);
                }
                free(students[z]);
        }
        free(students);
}
