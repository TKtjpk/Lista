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

enum Menu {a, d, p, x};

int main(int argc, const char * argv[]) {
    costam();
    char ***lista = NULL, komenda;
    lista = (char***)malloc((10 * 3 * 20) * sizeof(char));
    lista = dodaj(lista);
    int i = 1;
    do {
//        for (int z = 0; i < 3; i++) {
//            printf("%s", lista[0][z]);
//        }
        printf("(a) - dodaj element  |  ");
        printf("(d) - kasuj element  |  ");
        printf("(p) - zmien element  |  ");
        printf("(x) - zamknij program\n");
        komenda = getc(stdin);
        //scanf("%c", &komenda);
        if (komenda == 'a') {
            printf("(f) - poczatek listy  |  ");
            printf("(e) - koniec listy  |  ");
            printf("(a) - sortuj alfabetycznie  |  ");
            printf("(n) - sortuj wg ID\n");
        } else if (komenda == 'd') {
            printf("d");
        } else if (komenda == 'p') {
            printf("p");
        } else if (komenda == 'x') {
            printf("Koniec programu\n");
        }
    } while (komenda != 'x');
    free(lista);
    return 0;
}
