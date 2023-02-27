#ifndef DECK_H
#define DECK_H

#include <vector>

using namespace std;

class Card
{
public:
  Card(char c, int n) : suit(c), num(n) {}
  getSuit() {
    return suit;
  }
  getNum() {
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
  Shuffle();
  Draw();

private:
  vector<Card> library;
  vector<Card> discard;
};


#endif
