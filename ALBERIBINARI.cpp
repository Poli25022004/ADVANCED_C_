/*  ALBERI BINARI
✔ Un albero binario è una struttura di nodi collegati
✔ Ogni nodo ha un valore e fino a 2 figli
✔ Il primo nodo in alto si chiama radice
✔ Se un figlio non esiste → c’è NULL
✔ Si usa per organizzare i dati come in una "mappa"
✔ Si legge dall’alto verso il basso*/

//com'è costruito un nodo
/*   +--------------------+
   |      nodo          |
   +--------------------+
   | valore :   10      |
   | sinistro:   →      |
   | destro:     →      |
   +--------------------+
*/

/*+------------------------------------------+
| struct node {                            |
|     int val;         <-- il valore       |
|     struct node *left;  <-- figlio sx    |
|     struct node *right; <-- figlio dx    |
| };                                        |
+------------------------------------------+
*/
#include <stdio.h>
#include <stdlib.h>

// Definizione di un nodo dell'albero
typedef struct node {
    int val;                // Il valore del nodo
    struct node* left;      // Puntatore al figlio sinistro
    struct node* right;     // Puntatore al figlio destro
} node_t;
// Funzione per creare un nuovo nodo con un certo valore
node_t* create_node(int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t)); // Alloco memoria
    if (new_node == NULL) {
        printf("Errore memoria!\n");
        return NULL;
    }
    new_node->val = value;   // Imposto il valore del nodo
    new_node->left = NULL;    // All'inizio non ha figli
    new_node->right = NULL;   // All'inizio non ha figli
    return new_node;          // Ritorno il nodo creato
}

// Inserisce un nodo in modo che l albero di ricerca sia corretto
node_t* insert(node_t* root, int value) {
    if (root == NULL) {
        // Se l'albero è vuoto, creo la radice
        return create_node(value);
    }

    if (value < root->val) {
        // Se il valore è più piccolo della radice → vai a sinistra
        root->left = insert(root->left, value);
    }
    else {
        // Se il valore è più grande della radice → vai a destra
        root->right = insert(root->right, value);
    }

    return root; // Ritorno la radice aggiornata
}
//// Inserisce un nodo in modo che il BST sia corretto
node_t* insert(node_t* root, int value) {
    if (root == NULL) {
        // Se l'albero è vuoto, creo la radice
        return create_node(value);
    }

    if (value < root->val) {
        // Se il valore è più piccolo della radice → vai a sinistra
        root->left = insert(root->left, value);
    }
    else {
        // Se il valore è più grande della radice → vai a destra
        root->right = insert(root->right, value);
    }

    return root; // Ritorno la radice aggiornata
}
//Stampare l’albero in ordine crescente
// Visita in ordine: sinistra → radice → destra
void inorder(node_t* root) {
    if (root == NULL) return; // Se il nodo è vuoto, esco

    inorder(root->left);          // Visito il sottoalbero sinistro
    printf("%d ", root->val);     // Stampo il valore del nodo
    inorder(root->right);         // Visito il sottoalbero destro
}

// Libera tutta la memoria dell'albero
void free_tree(node_t* root) {
    if (root == NULL) return; // Se il nodo è vuoto, esco

    free_tree(root->left);     // Libero il sottoalbero sinistro
    free_tree(root->right);    // Libero il sottoalbero destro
    free(root);                // Libero il nodo stesso
}

int main() {
    node_t* root = NULL; // Inizio con un albero vuoto

    // Inserisco dei valori
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 15);

    printf("Albero in ordine crescente: ");
    inorder(root); // Stampa: 5 10 15 20
    printf("\n");

    // Liberiamo la memoria
    free_tree(root);
    return 0;
}
/*      10
       /  \
     5     20
          /
        15
*/