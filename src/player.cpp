#include<player.h>
#include<iostream>

using namespace std;

void Player::Show() {
  cout << "Current hand is: " << endl;
  for (int i = 0; i < Hand.size(); i++) {
    Hand[i].display();
  }
  cout << "Total is: " << total;
  if (ATotal > 0) {
    cout << "(" << ATotal << ")";
  }
  cout << endl;
}

bool Player::Add(Card c) {
  total += c.getNum();
  Hand.push_back(c);
  AceCheck(c);
  Show();
  if (total < 22) {
    return true;
  } else {
    Fold();
    return false;
  }
}

void Player::AceCheck(Card c) {
  if (c.getNum() == 1) {
    if (total + 10 < 21) {
      ATotal = (total + 10);
    }
  }
  if (ATotal > 0) {
    if (ATotal + c.getNum() > 21) {
      ATotal = 0;
    } else {
      ATotal += c.getNum();
    }
  }
}

void Player::PChange(int n) {
  points += n;
}

void Player::Fold() {
  total = 0;
  ATotal = 0;
  Hand.clear();
}
