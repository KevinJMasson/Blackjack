#include <deck.h>
#include <vector>
#include <iostream>
//#include <algorithm>
//#include <random>
#include<cstdlib>
#include<time.h>

using namespace std;

void Card::display() {
  switch (num) {
    case 1:
      cout << "Ace of ";
      break;
    case 11:
      cout << "Jack of ";
      break;
    case 12:
      cout << "Queen of ";
      break;
    case 13:
      cout << "King of ";
      break;
    default:
      cout << num << " of ";
    }
  cout << suit << endl;
}

Deck::Deck() {
  Fill();
  Shuffle();
}

void Deck::Fill() {
  for (int i = 0; i < 4; i++) {
    char suit;
    switch (i) {
      case 0:
        suit = 'S';
        break;
      case 1:
        suit = 'C';
        break;
      case 2:
        suit = 'H';
        break;
      case 3:
        suit = 'D';
        break;
      default:
      cout << "Error";
    }
    for (int j = 1; j<14; j++) {
      if (j == 1 || j == 13) {
      }
      Card c(suit,j);
      library.push_back(c);
    }
  }
}

void Deck::Shuffle() {
    // Initialize seed randomly
    srand(time(0));

    for (int i=0; i<library.size(); i++) {
        // Random for remaining positions.
        int r = i + (rand() % (library.size() -i));

        swap(library[i], library[r]);
    }
}

Card Deck::Draw() {

  if (!library.empty()) {
    Card top = library[library.size()-1];
    library.pop_back();
    return top;
  } else {
      cout << "Out of cards. Shuffling..." << endl;
      Fill();
      Shuffle();
      return Draw();
    }
}
