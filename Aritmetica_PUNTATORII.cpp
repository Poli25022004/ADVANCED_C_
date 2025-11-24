/*È la possibilità di fare operazioni matematiche sui puntatori:

aggiungere un numero

sottrarre un numero

confrontare puntatori

trovare la distanza tra due puntatori

Serve soprattutto quando lavori con array,
perché gli array si attraversano con i puntatori.*/
#include <stdio.h>

int main() {

    int a[5] = { 10, 20, 30, 40, 50 };

    // p parte dal primo elemento dell’array
    int* p = a;

    printf("Valore iniziale *p = %d\n", *p); // stampa 10

    // p + 1 → passa al secondo elemento
    p++;
    printf("Dopo p++, *p = %d\n", *p); // stampa 20

    // p + 2 → salta di due elementi
    p = p + 2;
    printf("Dopo p = p + 2, *p = %d\n", *p); // stampa 40

    // p - 1 → torna indietro di un elemento
    p--;
    printf("Dopo p--, *p = %d\n", *p); // stampa 30

    // differenza tra puntatori
    int* start = &a[0];   // punta al primo elemento
    int distanza = p - start;

    printf("p - start = %d (numero di elementi di distanza)\n", distanza);

    return 0;
}


/*Se p è un int* e un int occupa 4 byte:
p + 1  →  p + 4 byte
p + 2  →  p + 8 byte
*/

/*Per un char* (1 byte):
p + 1 → p + 1 byte

NON aggiungi byte, aggiungi elementi.

Esempio base
int a[5] = {10, 20, 30, 40, 50};
int *p = a;  // p punta a a[0];

visivamente

INDICI:    0     1     2     3     4
          +----+----+----+----+----+
ARRAY:    | 10 | 20 | 30 | 40 | 50 |
          +----+----+----+----+----+
p →        ^

p + 1 (si sposta al prossimo elemento)

p →               ^
INDICI:    0     1     2     3     4
ARRAY:    [10] [20] [30] [40] [50]
*/

/*Differenza tra due puntatori
int* p = &a[3];  // punta a 40
int* q = &a[0];  // punta a 10

int dist = p - q; 
*/

/*Operazione	 Significato
p + 1	         vai al prossimo elemento
p - 1   	     vai all’elemento precedente
p++	             come p = p + 1
p--              come p = p - 1
p - q	         distanza in elementi, non byte
*(p + n)	     elemento n dopo p*/
