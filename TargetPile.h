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
// class Hand : public Pile


#ifndef TARGETPILE_H
#define TARGETPILE_H

#include "Pile.h"
#include "DrawPile.h"
#include "Hand.h"

class TargetPile : public Pile
{
protected:
  // 01-13 == "♠️"
  string spade = "♠️";
  stack<int> spades;

  // 14-26 == "♣️"
  string club = "♣️";
  stack<int> clubs;

  // 27-39 == "♦️"
  string diamond = "♦️";
  stack<int> diamonds;

  // 40-52 == "♥️"
  string heart = "♥️";
  stack<int> hearts;

  bool hand2Visibility[1] = {1}; //last
  bool hand3Visibility[2] = {1,1}; //last 2
  bool hand4Visibility[3] = {1,1,1}; //last 3
  bool hand5Visibility[4] = {1,1,1,1}; //last 4
  bool hand6Visibility[5] = {1,1,1,1,1}; //last 5
  bool hand7Visibility[6] = {1,1,1,1,1,1}; //last 6

public:
  // TargetPile();
  void displayGame( DrawPile drawPile );

  void displayHand( vector< deque<int> > hands );

  bool moveToTarget(int card);

  string getCardValue(int cardNumber);


  stack <int> getSpades();
  stack <int> getClubs();
  stack <int> getDiamonds();
  stack <int> getHearts();

  void displayStacks();

  int gameOver();
};

#endif
