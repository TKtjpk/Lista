//
//  main.c
//  Lista
//
//  Created by MacBook Pro (Tomasz) on 19/12/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

char menu1[] = "(a) - dodaj element  |  (d) - kasuj element  |  (p) - wyswietl liste  |  (x) - zamknij program: \n";
char menu2[] = "(f) - poczatek listy  |  (e) - koniec listy  |  (a) - sortuj alfabetycznie  |  (n) - sortuj wg ID\n";

int main(int argc, const char * argv[]) {
        char ***lista = NULL;
        char komenda = '\0';
        
        while(1) {
                
                printf("%s", menu1);
                scanf(" %c", &komenda);
                
                switch (komenda) {
                        case 'a':
                                printf("%s", menu2);
                                scanf(" %c", &komenda);
                                switch (komenda) {
                                        case 'f':
                                                lista = dodaj_na_poczatku(lista);
                                                break;
                                        case 'e':
                                                lista = dodaj_na_koncu(lista);
                                                break;
                                        case 'a':
                                                sortuj(lista, 2);
                                                break;
                                        case 'n':
                                                sortuj(lista, 0);
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        case 'd':
                                usun(lista);
                                break;
                        case 'p':
                                drukuj(lista);
                                break;
                        case 'x':
                                free(lista);
                                printf("Koniec programu\n");
                                return 0;
                        default:
                                printf("OK");
                                break;
                }
                //drukuj(lista);
        }
        return 0;
}
