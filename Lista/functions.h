//
//  functions.h
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>

char ***tabela(char ***students);

void usun(char ***students);

void drukuj(char ***students);

void usun_element(char ***students, int index);

char ***dodaj_na_poczatku(char ***students);

void dodaj_do_pustej_listy(char ***students);

void dodajStudenta(char ***students, int pozycja);

char ***tymczasowa_tabela(char ***students);

void dodaj_na_koncu(char ***students);

void sortuj(char ***students, int metoda);

void zamien(char *pom, char *a, char *b);

void zwolnij(char ***students);

#endif /* functions_h */
