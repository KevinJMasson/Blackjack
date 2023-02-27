#include <deck.h>
#include <vector>
#include <iostream>

Deck() {
  for (int i = 0; i < 4; i++) {
    char suit;
    switch (i) {
      case 0:
        suit = S;
        break;
      case 1:
        suit = C;
        break;
      case 2:
        suit = H;
        break;
      case 3:
        suit = D;
        break;
      default:
        cout << "Error in suit creation";
    }
    for (int j = 1; i<14; i++) {
      Card c(suit,j);
      library.push_back() c;
    }
  }
  cout << "The Size of the library is " << library.size() << endl;
}
