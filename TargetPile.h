/*
|--------------------------------------------------------------------------
| TargetPile
|--------------------------------------------------------------------------
| Handles the stacks needed to complete the game
| Displays ongoing & updated game data
|
|
|
*/
// class Pile
// class DrawPile : public Pile
// class Hand : public Pile

// prevents duplication
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
  stack<int> spades; // stack accepting only numbers 1-13

  // 14-26 == "♣️"
  string club = "♣️";
  stack<int> clubs; // stack accepting only numbers 14-26

  // 27-39 == "♦️"
  string diamond = "♦️";
  stack<int> diamonds; // stack accepting only numbers 27-39

  // 40-52 == "♥️"
  string heart = "♥️";
  stack<int> hearts; // stack accepting only numbers 40-52

  // cards that will be temporarily hidden
  vector <bool> hidden1 = {0}; //last
  vector <bool> hidden2 = {1}; //last
  vector <bool> hidden3 = {1,1}; //last 2
  vector <bool> hidden4 = {1,1,1}; //last 3
  vector <bool> hidden5 = {1,1,1,1}; //last 4
  vector <bool> hidden6 = {1,1,1,1,1}; //last 5
  vector <bool> hidden7 = {1,1,1,1,1,1}; //last 6

  vector < vector <bool> > hidden;

public:
  // displays the cards as the game progresses
  void displayGame( DrawPile drawPile );
  void displayHand( vector< deque<int> > hands );
  void displayStacks();

  // validates incoming data to stacks
  bool moveToTarget(int card);

  vector < vector <bool> > & getHidden(); // gets updated hidden card info

  // stack getters
  stack <int> getSpades();
  stack <int> getClubs();
  stack <int> getDiamonds();
  stack <int> getHearts();


  // int gameOver();
};

#endif
