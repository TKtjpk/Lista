//
//  functions.h
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>

void usun(char ***students);
void drukuj(char ***students);
void usun_element(char ***students, int index);
char ***dodaj_na_poczatku(char ***students);
char ***dodaj_do_pustej_listy(char ***students);
void dodajStudenta(char *id, char *imie, char *nazwisko);
char ***tymczasowa_tabela(char ***students);
char ***dodaj_na_koncu(char ***students);
void sortuj(char ***students, int metoda);
void zamien(char *pom, char *a, char *b);

#endif /* functions_h */
