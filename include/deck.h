#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>

using namespace std;

class Card
{
public:
  Card(char c = ' ', int n = 0) : suit(c), num(n) {}
  Card(const Card& c) {
    suit = c.suit;
    num = c.num;
  }
  void display();
  char getSuit() {
    return suit;
  }
  int getNum() {
    return num;
    }
private:
  char suit;
  int num;
};

class Deck
{
public:
  Deck();
  void Fill();
  void Shuffle();
  Card Draw();

private:
  vector<Card> library;
  //vector<Card> discard;
};


#endif
