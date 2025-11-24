//le union

/*Una union è una struttura speciale che permette di 
conservare dati diversi nello stesso spazio di memoria.*/

#include <stdio.h>
#include <string.h>   // per strcpy

// --------------------------------------
// 1. ENUM: serve per ricordare quale dato è attivo
// --------------------------------------
typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_STRING
} TipoDato;


// --------------------------------------
// 2. UNION: contiene diversi tipi ma UNO solo alla volta
// --------------------------------------
union Dato {
    int i;            // può contenere un int
    float f;          // oppure un float
    char str[20];     // oppure una stringa (max 20)
};


// ----------------------------------------
// 3. STRUCT: combina l'enum + la union
//    -> così sappiamo cosa contiene la union
// ----------------------------------------
typedef struct {
    TipoDato tipo;    // indica quale membro della union è valido
    union Dato valore; // contiene il valore (uno solo)
} Variabile;


// ----------------------------------------
// 4. Funzione per stampare la Variabile
// ----------------------------------------
void stampaVariabile(Variabile v) {
    if (v.tipo == TIPO_INT) {
        printf("La variabile contiene un INT: %d\n", v.valore.i);

    }
    else if (v.tipo == TIPO_FLOAT) {
        printf("La variabile contiene un FLOAT: %.2f\n", v.valore.f);

    }
    else if (v.tipo == TIPO_STRING) {
        printf("La variabile contiene una STRINGA: %s\n", v.valore.str);
    }
}


// ----------------------------------------
// 5. MAIN: esempio completo di utilizzo
// ----------------------------------------
int main() {

    Variabile v;   // creo una variabile generica


    // ----------------------------------
    // Caso 1: metto un intero
    // ----------------------------------
    v.tipo = TIPO_INT;      // dico che la union contiene un intero
    v.valore.i = 42;        // metto un intero nella union
    stampaVariabile(v);     // stampa: INT


    // ----------------------------------
    // Caso 2: metto un float
    // (ATTENZIONE: sovrascrive l'intero precedente!)
    // ----------------------------------
    v.tipo = TIPO_FLOAT;    // dico che ora la union contiene un float
    v.valore.f = 3.14;      // scrivo un float
    stampaVariabile(v);     // stampa: FLOAT


    // ----------------------------------
    // Caso 3: metto una stringa
    // ----------------------------------
    v.tipo = TIPO_STRING;
    strcpy(v.valore.str, "Ciao mondo"); // salvo una stringa nella union
    stampaVariabile(v);                 // stampa: STRINGA


    return 0;
}
/*Perché qui vedi IL VERO USO REALE delle union:

✔ conservare tipi diversi
✔ risparmiare memoria
✔ avere un “contenitore flessibile”
✔ usare enum per sapere cosa c'è dentro*/