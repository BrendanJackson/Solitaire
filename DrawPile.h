/*
|--------------------------------------------------------------------------
|
|--------------------------------------------------------------------------
|
|
|
|
|
*/
// class Pile
// class TargetPile : public Pile
// class Hand : public Pile




#ifndef DRAWPILE_H
#define DRAWPILE_H

#include "Pile.h"
#include "Hand.h"

class DrawPile : public Pile
{
protected:
  queue<int> cards;
public:
  DrawPile( vector<int> visitingCards );
  void drawCard();

  int getCardValue( Hand handObject, int handNumber );
  deque<int> getHand( Hand handObject, int handNumber );
  void moveCard( deque<int> hand );

  // getters
  queue<int> getCards();
};

#endif
