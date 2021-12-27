//
//  functions.h
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>

char ***pusta_tabela(char ***students);
char ***tymczasowa_tabela(char ***students);

char ***dodaj_do_pustej_listy(char ***students);
char ***dodaj_na_poczatku(char ***students);
char ***dodaj_na_koncu(char ***students);

char ***usun_studenta(char ***students);
char ***usun_element(char ***students, int index);

int sprawdz_id(void);

void dodajStudenta(char ***students, int pozycja);
void drukuj(char ***students);
void sortuj(char ***students, int metoda);
void zwolnij_pamiec(char ***students);

#endif /* functions_h */
