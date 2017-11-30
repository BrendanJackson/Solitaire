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

  int hand2Visibility = 1; //last
  int hand3Visibility = 2; //last 2
  int hand4Visibility = 3; //last 3
  int hand5Visibility = 4; //last 4
  int hand6Visibility = 5; //last 5
  int hand7Visibility = 6; //last 6

public:
  Hand(vector<int> visitingCards);

  // getters
  deque<int> getHand1();
  deque<int> getHand2();
  deque<int> getHand3();
  deque<int> getHand4();
  deque<int> getHand5();
  deque<int> getHand6();
  deque<int> getHand7();
};

#endif
