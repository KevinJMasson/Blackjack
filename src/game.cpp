#include<deck.h>
#include<player.h>
#include<iostream>
#include<vector>

using namespace std;

int main() {
  char loop, hit;
  int turn = 0;
  Card curr;
  Player Dealer, User;
  Deck d;

  while(User.getPoints() > 0) {
    cout << "Current balance is: " << User.getPoints() << endl;
    cout << endl;
    cout << "Player's Turn!\n";
    while (turn == 0) {
      cout << endl;
      curr = d.Draw();
      if (User.Add(curr)) {
        if (User.getTotal() == 21) {
            turn = 1;
            cout << endl;
            cout << "Dealer's Turn!\n";
            break;
        }
        cout << "Hit or Stay?\n";
        cin >> hit;
        if (hit == 's') {
          turn = 1;
          cout << endl;
          cout << "Dealer's Turn!\n";
        }
      } else {
        cout << "Bust!" << endl;
        cout << endl;
        User.PChange(-100);
        system("pause");
        break;
      }
    }
    while (turn == 1) {
      cout << endl;
      curr = d.Draw();
      if (Dealer.Add(curr)) {
        if (Dealer.getTotal() >= User.getTotal() && Dealer.getTotal() < 22) {
          cout << "Dealer wins!\n";
          cout << endl;
          User.PChange(-100);
          User.Fold();
          Dealer.Fold();
          system("pause");
          break;
        }
      } else {
        cout << "You win!\n";
        cout << endl;
        User.Fold();
        User.PChange(100);
        system("pause");
        break;
      }
    }
    turn = 0;
  }
  cout << "You are out of points! Thanks for playing!\n";
  system("pause");
  return 0;
}
