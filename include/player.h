#ifndef PLAYER_H
#define PLAYER_H

#include<deck.h>

using namespace std;

class Card;

class Player {
  public:
    Player() {
      total = 0;
      ATotal = 0;
      points = 1000;
    }
    void Show();
    bool Add(Card);
    void AceCheck(Card);
    int getTotal() {
      if (ATotal > total)
        return ATotal;
      else
        return total;
    }
    int getPoints() {
      return points;
    }
    void PChange(int);
    void Fold();
  private:
    int total;
    int ATotal;
    int points;
    vector<Card> Hand;

};

#endif
