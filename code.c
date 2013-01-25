//
//  main.c
//  Craps- gioco d'azzarzo
//
//  Created by Luciano Gavoni on 23/01/13.
//  Copyright (c) 2013 Luciano Gavoni. All rights reserved.
//
/* regole:
Un giocatore lancia due dadi. Ogni dado ha sei facce. Queste facce contengono 1,2,3,4,5,6 puntini. Dopo i dadi si saranno fermati, si calcolerà la somma dei puntini sulle due facce rivolte verso l'alto. Nel caso la somma fosse 7 o 11 al primo tiro, il giocatore avrebbe vinto. Nel caso fosse 2,3 o 12al primo tiro, il giocatore avrebbe perso. Nel caso la somma fosse 4,5,6,8,9 o 19 al primo tiro, allora quella somma diventerebbe il "punteggio" del giocatore. Per vincere, si deve continuare a lanciare i dadi fino a "ottenere il vostro punteggio". Il giocatore perderebbe qualora realizzasse un 7 prima di ottenere il proprio punteggio */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Status{ CONTINUA, VINCI, PERDI }; //costanti di enumerazioni
 
int rollDice( void );
 
int main( void )
{
    int somma; // somma punteggio lancio dadi
    int myPoint;
    enum Status gameStatus; // può contenere CONTINUA, VINCI, PERDI
    srand(time (NULL));
    somma = rollDice();
   
    // determino lo stato del gioco in base al punteggo dei dati
    switch (somma)
    {   //vinci al primo lancio;
           
        case 7:
        case 11:
            gameStatus = VINCI;
            break;
        // perde al primo lancio
           
        case 2:
        case 3:
        case 12:
            gameStatus = PERDI;
            break;
        //altrimenti continua a giocare --> Memorizza il punteggio
       
        default:
            gameStatus = CONTINUA;
            myPoint = somma;
            printf("Il punteggio è %d\n", myPoint);
            break;
    }
    while (gameStatus == CONTINUA) {
        somma = rollDice();
        //determino lo stato del gioco
        if (somma == myPoint) {
            gameStatus = VINCI; // il giocatore ha vinto
        }
        else if ( somma==7)
        {
            gameStatus = PERDI; // il gioco è finito , il giocatore ha perso;
        }
    }
    if (gameStatus == VINCI)
        printf("\n\tHai vinto! ritira i tuoi soldi\n");
    else
        printf("\n\tHai perso, ritenta");
   
    return 0;
}
 
// lancia i dadi, calcola la somma e visualizza i risultati
int rollDice( void )
{
    int morto1; // punteggio 1 dado
    int morto2; // punteggio 2 dado
    int sommaLavoro; //somma dei dadi
    morto1 = 1 + ( rand () % 6); // genera il punteggio del dado 1
    morto2 = 1 + ( rand () % 6); // genera il punteggio del dado 2
    sommaLavoro = morto1 + morto2;
    // visualizzo i risultati del lancio
    printf("I numeri usciti sono %d + %d = %d\n ", morto1, morto2, sommaLavoro );
    return sommaLavoro; //restituisce la somma dei dadi
}
