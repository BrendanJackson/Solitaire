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

// prevents duplication
#ifndef HAND_H
#define HAND_H

#include "Pile.h"


class Hand : public Pile
{
protected:
  // The 7 hands
  deque<int> hand1;
  deque<int> hand2;
  deque<int> hand3;
  deque<int> hand4;
  deque<int> hand5;
  deque<int> hand6;
  deque<int> hand7;

public:
  void fillHand(vector<int> visitingCards); // gets initial data for hands

  // getters
  deque<int> getHand1();
  deque<int> getHand2();
  deque<int> getHand3();
  deque<int> getHand4();
  deque<int> getHand5();
  deque<int> getHand6();
  deque<int> getHand7();

  /**
  * Data validation, and procedures to move cards to and from different containers
  */
  vector<int> checkHand( int handNumber );
  vector<int> selectCards( vector<int> pseudoStack );
  bool checkTargetHand( deque<int> currentHand, vector<int> pseudoStack );
  void moveHands( int targetHandNumber, vector<int> pseudoStack);
  void popCards( int handNumber, int popAmount); // removes cards that have been successfully passed

  /**
  * Gets the hand the user selected
  */
  deque<int> & getHand( int handNumber);
  /**
  * recollects hands in a 2D vector
  */
  vector< deque<int> > getHands();
};

#endif
