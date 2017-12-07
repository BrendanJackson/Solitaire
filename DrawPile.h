/*
|--------------------------------------------------------------------------
| DrawPile
|--------------------------------------------------------------------------
| Cycles draw cards through
| sends draw cards to various parts of the game
|
|
|
*/
// class Pile
// class TargetPile : public Pile
// class Hand : public Pile



// prevents duplication
#ifndef DRAWPILE_H
#define DRAWPILE_H

#include "Pile.h"
#include "Hand.h"

class DrawPile : public Pile
{
protected:
  queue<int> cards; //gets an initial 24 cards

public:
  DrawPile( vector<int> visitingCards ); // sets initial 24 cards
  void drawCard(); // shifts cards from front to back

  deque<int> getHand( Hand handObject, int handNumber ); // gets hand number from hand object
  void moveCard( deque<int> hand ); // moves a card to a new hand, removes card from drawpile

  // getters
  queue<int> & getCards();

  void popCard(); // pops card off cards queue
};

#endif
