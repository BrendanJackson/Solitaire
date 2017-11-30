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

public:
  // TargetPile();
  void displayGame( Pile pile, DrawPile drawPile, Hand hand );

  void displayHand( Hand hand );

  string getCardValue(int cardNumber);
};

#endif
