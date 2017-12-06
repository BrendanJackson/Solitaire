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
// class DrawPile : public Pile
// class TargetPile : public Pile

#ifndef HAND_H
#define HAND_H

#include "Pile.h"
// #include "TargetPile.h"

class Hand : public Pile
{
protected:
  deque<int> hand1;
  deque<int> hand2;
  deque<int> hand3;
  deque<int> hand4;
  deque<int> hand5;
  deque<int> hand6;
  deque<int> hand7;

public:
  void fillHand(vector<int> visitingCards);

  // getters
  deque<int> getHand1();
  deque<int> getHand2();
  deque<int> getHand3();
  deque<int> getHand4();
  deque<int> getHand5();
  deque<int> getHand6();
  deque<int> getHand7();


  // moves cards
  void moveCards( int handNumber );

  vector<int> checkHand( int handNumber );
  vector<int> selectCards( vector<int> pseudoStack );
  bool checkTargetHand( int targetHandNumber, vector<int> pseudoStack );
  void moveHands( int targetHandNumber, vector<int> pseudoStack);
  void popCards( int handNumber, int popAmount); // removes cards that have been successfully passed

  deque <int> getHand( int handNumber);
  vector< deque<int> > getHands();
};

#endif
