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

//MARK: Tworzenie tabeli (jeśli wcześniej nie było)
char ***pusta_tabela(char ***students)
{
        students = calloc(1, sizeof(char**));
        
        if (students == NULL)
        {
                perror("malloc failed");
                exit(-1);
        }
        
        students[0] = calloc(3, sizeof(char*));
        
        if (students[0] == NULL)
        {
                perror("malloc failed");
                exit(-1);
        }
        
        for (int y = 0; y < 3; y++)
        {
                students[0][y] = calloc(21, sizeof(char));
                
                if (students[0][y] == NULL)
                {
                        perror("malloc failed");
                        exit(-1);
                }
        }
        return students;
}

//MARK: Usuwanie z tabeli
char ***usun_studenta(char ***students)
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
                                students = usun_element(students, pozycja);
                                char ***temp = iloscStudentow ==0 ? students : realloc(students, sizeof(***temp) * iloscStudentow);
                                
                                if (temp == NULL)
                                {
                                        perror("malloc failed");
                                        exit(-1);
                                }
                                
                                students = temp;
                                break;
                        }
                }
                if (pozycja == -1) {
                        printf("\n   ---   Nie ma takiego indexu   ---\n");
                }
        }
        return students;
}

//MARK: Wyświetlanie tabeli
void drukuj(char ***students)
{
        if (iloscStudentow > 0)
        {
                printf("\n index / NAZWISKO / IMIE\n");
                
                for (int x = 0; x < iloscStudentow; x++)
                {
                        printf("%3s     %s     %s", students[x][0] , students[x][2], students[x][1]);
                        printf("\n................................................................\n");
                }
        }
        else
        {
                printf("\n   ---   Tablica jest pusta   ---\n\n");
        }
}

//MARK: Usuwanie elemntu (usuwanie elementu poprzez kopiowanie w to miejsce wyzej polozonych zwalnianie miejsca na ostatnim miejscu w celu eliminacji memory leaks)
char ***usun_element(char ***students, int index)
{
        for (int i = index; i < iloscStudentow - 1; i++)
        {
                for (int x = 0; x < 3; x++) {
                        strcpy(students[i][x], students[i+1][x]);
                }
        }
        
        iloscStudentow--;
        
        if (iloscStudentow > 0) {
                for (int x = 0; x < 3; x++) {
                        free(students[iloscStudentow][x]);
                }
                free(students[iloscStudentow]);
        }
        return students;
}

//MARK: Dodaj na początku
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

//MARK: Dodaj na końcu
char ***dodaj_na_koncu(char ***students)
{
        iloscStudentow++;
        char ***temp = tymczasowa_tabela(students);
        students = temp;
        dodajStudenta(students, iloscStudentow-1);
        return students;
}

//MARK: Dodawanie do tabeli pustej
char ***dodaj_do_pustej_listy(char ***students)
{
        students = pusta_tabela(students);
        dodajStudenta(students, 0);
        iloscStudentow++;
        return students;
}

//MARK: Dodawanie studenta (interakcja z uzytkownikiem)
void dodajStudenta(char ***students, int pozycja)
{
        char id[20], imie[20], nazwisko[20];
        int i;
        
        printf("Podaj id (akceptuje tylko cyfry): ");
        i = sprawdz_id();
        
        sprintf(id, "%d", i);
        
        printf("Podaj imie: ");
        scanf(" %s", imie);
        
        printf("Podaj nazwisko: ");
        scanf(" %s", nazwisko);
        
        for (int y = 0; y < 3; y++)
        {
                strcpy(students[pozycja][y], (y !=0 ? (y == 1 ? imie : nazwisko): id));
        }
}

//MARK: Realokacja tabeli i alokacja pamieci dla nowo utworzonego sektora
char ***tymczasowa_tabela(char ***students)
{
        char ***temp = realloc(students, sizeof(*students) * iloscStudentow);
        
        if (temp == NULL)
        {
                perror("malloc failed");
                exit(-1);
        }
        
        temp[iloscStudentow-1] = calloc(3, sizeof(**temp));
        
        if (temp[iloscStudentow-1] == NULL)
        {
                perror("malloc failed");
                exit(-1);
        }
        
        for (int i = 0; i < 3; i++)
        {
                temp[iloscStudentow-1][i] = calloc(21, sizeof(char));
                
                if (temp[iloscStudentow-1][i] == NULL)
                {
                        perror("malloc failed");
                        exit(-1);
                }
        }
        
        return temp;
}

//MARK: Sortowanie
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

//MARK: Zwalnianie tabeli
void zwolnij_pamiec(char ***students)
{
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

//MARK: Sprawdzanie czy ID to tylko cyfry
int sprawdz_id(void)
{
        int i = 0, ch, calosc = 0, cyfry = 0;
        
        do
        {
                ch = getchar();
                calosc++;
                
                if (ch >= 48 && ch <= 57)
                {
                        i = i * 10 + (ch - 48);
                        cyfry++;
                }
        } while (ch != 10 && ch != 13);
        
        if (calosc == cyfry + 1)
        {
                return i;
        }
        else
        {
                printf("\nPodaj id (akceptuje tylko cyfry): ");
                return sprawdz_id();
        }
}
