/***
 * You are given a deck of cards (initially 52). We can perform two operations using the deck now.
 * 1. Remove a card from the given deck.
   2. Calculate the probability of Drawing out a card from the given deck (multiplied by 1000 and return the integer value.).

 * Perform the following steps :
   1. Create a class deck to manage the no. of elements left in the deck and the cards left in the deck.
   2. Create a function Probability in class deck(return type int).
 ***/
#include <iostream>
using namespace std;

class Deck {
    int cards;
    int* arr;
    
    public:
    Deck() {
        cards = 52;
        arr = new int[14];
        for(int i=0; i<14; i++)
            arr[i] = 4;
    }   
    void remove(int n, char c) {
        arr[n]--;
        cards--;
    }  
    int probability(int n) {
        int num = arr[n];
        int p = num * 1000 / cards;
        return p;
    }
};