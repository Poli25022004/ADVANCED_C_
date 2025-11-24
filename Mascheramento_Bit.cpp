/*Il mascheramento di bit (bit masking) in C è una tecnica 
per leggere, modificare o isolare bit specifici all’interno 
di un numero usando operatori bitwise
AND (&) → usato per isolare bit

OR (|) → usato per impostare bit

XOR (^) → usato per invertire bit

NOT (~) → inverte tutti i bit

SHIFT (<<, >>) → sposta i bit

controllo di un registro di 8 bit
Immaginiamo di avere un registro di 8 bit che controlla delle funzioni:

Bit	Significato
0	LED acceso/spento
1	Allarme attivo
2	Motore ON/OFF

*/
#include <stdio.h>

int main() {
    unsigned char reg = 0b00000000;   // registro iniziale (tutti i bit a 0)

    printf("Valore iniziale: 0x%02X\n", reg);

    // ---------------------------
    // 1) IMPOSTARE UN BIT A 1
    // ---------------------------
    // Voglio accendere il LED (bit 0)
    reg |= (1 << 0);
    printf("Accendo il LED (bit 0): 0x%02X\n", reg);

    // ---------------------------
    // 2) LEGGERE UN BIT
    // ---------------------------
    // Controllo se l'allarme (bit 1) è attivo
    if (reg & (1 << 1))
        printf("Allarme attivo\n");
    else
        printf("Allarme NON attivo\n");

    // ---------------------------
    // 3) IMPOSTARE UN BIT A 1
    // ---------------------------
    // Attivo il motore (bit 2)
    reg |= (1 << 2);
    printf("Attivo il motore (bit 2): 0x%02X\n", reg);

    // ---------------------------
    // 4) AZZERARE UN BIT (mettere a 0)
    // ---------------------------
    // Spengo il LED (bit 0)
    reg &= ~(1 << 0);
    printf("Spengo il LED (bit 0): 0x%02X\n", reg);

    // ---------------------------
    // 5) TOGGLE (invertire) un bit
    // ---------------------------
    // Inversione del bit allarme (bit 1)
    reg ^= (1 << 1);
    printf("Inverto allarme (bit 1): 0x%02X\n", reg);

    return 0;
}
/*Cosa succede passo per passo

1️⃣ reg = 0b00000000
Tutti i bit a 0.

2️⃣ reg |= (1 << 0)
Imposta il bit 0 → LED ON
→ 00000001

3️⃣ Lettura bit 1
→ vale 0 → "allarme NON attivo"

4️⃣ reg |= (1 << 2)
Imposta bit 2 → motore ON
→ 00000101

5️⃣ reg &= ~(1 << 0)
Pulisce bit 0 → LED OFF
→ 00000100

6️⃣ reg ^= (1 << 1)
Inverte bit 1 (da 0 a 1)
→ 00000110

Risultato finale stampato
Valore iniziale: 0x00
Accendo il LED (bit 0): 0x01
Allarme NON attivo
Attivo il motore (bit 2): 0x05
Spengo il LED (bit 0): 0x04
Inverto allarme (bit 1): 0x06
*/