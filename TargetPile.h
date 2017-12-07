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

  vector <bool> hidden1 = {0}; //last
  vector <bool> hidden2 = {1}; //last
  vector <bool> hidden3 = {1,1}; //last 2
  vector <bool> hidden4 = {1,1,1}; //last 3
  vector <bool> hidden5 = {1,1,1,1}; //last 4
  vector <bool> hidden6 = {1,1,1,1,1}; //last 5
  vector <bool> hidden7 = {1,1,1,1,1,1}; //last 6

  vector < vector <bool> > hidden;

public:

  void displayGame( DrawPile drawPile );

  void displayHand( vector< deque<int> > hands );

  bool moveToTarget(int card);

  string getCardValue(int cardNumber);

  vector < vector <bool> > & getHidden();

  stack <int> getSpades();
  stack <int> getClubs();
  stack <int> getDiamonds();
  stack <int> getHearts();

  void displayStacks();

  int gameOver();
};

#endif
