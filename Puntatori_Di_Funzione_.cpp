
/*I PUNTATORI A FUNZIONE

Un puntatore a funzione è una variabile che contiene l’indirizzo di una funzione.
Serve quando vuoi:

passare una funzione come argomento ad un’altra funzione

scegliere dinamicamente quale funzione chiamare

creare callback

simulare “metodi” in C (tipico nella programmazione a eventi)
si dischiara così:
ritorno (*nome)(parametri)
*/

#include <stdio.h>

// Funzioni normali
int somma(int a, int b) {
    return a + b;
}

int prodotto(int a, int b) {
    return a * b;
}

int main() {

    // 1) Dichiaro un puntatore a funzione
    int (*op)(int, int);

    // 2) Lo faccio puntare alla funzione somma
    op = somma;

    printf("Somma: %d\n", op(4, 6));  // chiama somma(4, 6)

    // 3) Ora lo faccio puntare alla funzione prodotto
    op = prodotto;

    printf("Prodotto: %d\n", op(4, 6));  // chiama prodotto(4, 6)

    return 0;
}
/*Concetto	Significato
int (*p)(int,int)	puntatore a funzione che prende due int
p = nome_funzione;	associo il puntatore
p(x,y)	chiamo la funzione tramite il puntatore
fun(p)	passo una funzione come parametro*/