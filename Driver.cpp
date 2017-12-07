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
#include "Pile.h"
#include "DrawPile.h"
#include "Hand.h"
#include "TargetPile.h"


int main()
{
  system("clear");
  // main loop control variable
  int selection;
  int drawCard;
  int targetHand;

  vector<int> pseudoStack;
  deque<int> currentHand;


  // Initial game setup.
  // !TODO: Set constructors as virtual, there are 3 instances of the game running

  Pile solitaire;
  solitaire.createDeck();
  DrawPile drawPile( solitaire.getCards() );
  Hand hand;
  hand.fillHand( solitaire.getCards() );
  TargetPile targetPile;

  // Welcome message
  cout << "\nWelcome to Klondike's solitaire!";


  // I want to loop back until the user selection is equal to 5
  do{
    targetPile.displayGame(drawPile);
    targetPile.displayHand( hand.getHands() );
    // Start the game
    selection = solitaire.bootstrap();



    switch (selection){
      // 1: To Draw a card
      case 1 :
        drawPile.drawCard();
        break;
      // 2: To move the draw card
      case 2 :
        solitaire.displayDrawMenu();


        cin >> targetHand;


        // sends you back to the menu
        if (targetHand == 8)
          break;

        // initial validation
        while (targetHand < 0 || targetHand > 8){
          cout << "\ninvalid input, enter a number 0-8.\n";
          cin >> targetHand;
        }

        // cout << "\nDraw card is: " << drawPile.getFace( drawPile.getCards().front() );

        drawCard = drawPile.getCards().front(); //
        cout << "\ndrawCard set as " << drawCard;


        // sends draw card to targetPiles
        if(targetHand == 0){
          bool pop = false;
          pop = targetPile.moveToTarget( drawCard );

          if (pop == true){
            drawPile.popCard();
          }

          break;
        }



        // supposed to push a the drawCard to the targetHand
        if( ( hand.getHand( targetHand ).empty() ) && ( drawPile.getFace( drawCard ) == 13 ) ){
          hand.getHand( targetHand ).push_back( drawCard );
          drawPile.getCards().pop();

        } else if( ( hand.getHand( targetHand ).empty() ) && ( drawPile.getFace( drawCard ) != 13 ) ){
          cout << "\nYou cannot place a card that is not a king on an empty hand";

        } else if (
             (( drawCard <= 26 ) && ( hand.getHand( targetHand ).back() <= 26) )
          || (( drawCard >= 27 ) && ( hand.getHand( targetHand ).back() >= 27) )
        ){
          cout << "\nCannot place 2 cards of the same color ontop of one another";

        } else if( hand.getFace( hand.getHand( targetHand ).back() ) == hand.getFace( drawCard ) + 1 ){
          hand.getHand( targetHand ).push_back( drawCard );
          drawPile.getCards().pop();

        }  else
          cout << "\nYour Card Can only go ontop of card 1 higher than its value";


        break;

      // 3: To select one of the hand cards
      case 3 :
        hand.displayHandMenu();
        int handNumber;
        int targetHandNumber; //clears old result
        int popAmount; // amount to be removed from vector after move is completed
        bool moveable;

        pseudoStack.clear();


        cin >> handNumber;

        // initial validation
        while (handNumber < 1 || handNumber > 8){
          cout << "\ninvalid input, enter a number 1-8.\n";
          system("clear");
          cin >> handNumber;
        }

        // sends  card to targetPiles
        if(handNumber == 8)
          break;



        pseudoStack = hand.checkHand( handNumber );
        if (pseudoStack.size() == 0){
          cout << "\nThis hand is empty, try something else";
          break;
        }

        cout << "\nHow many cards would you like to move?";
        pseudoStack = hand.selectCards( pseudoStack );
        popAmount = pseudoStack.size();


        targetPile.displayHand( hand.getHands() );

        cout << "\nYou need to choose a hand for your cards to be sent to.";
        // Get Target Hand
        hand.displayTargetHandMenu();

        cin >> targetHandNumber;

        // initial validation
        while (
          (targetHandNumber < 0 || targetHandNumber > 8)
          || (targetHandNumber == handNumber)
        ){

          if (targetHandNumber < 0 || targetHandNumber > 8){
            cout << "\ninvalid input, enter a number 1-8.\n";
            hand.displayHandMenu();
            cin >> targetHandNumber;
          }

          if (targetHandNumber == handNumber){
            cout << "\nYou cannot move your hand to the same hand, please select another hand.\n";
            hand.displayHandMenu();
            cin >> targetHandNumber;
          }

        }

        // sends  card to targetPiles
        if( targetHandNumber == 8 ){
          cout << "\nTargetHand is 8, breaking";
          break;
        }


        // Start TargetPile migration
        if(targetHandNumber == 0){
          cout << "\nTargetHand is 0, should break?";

          if(popAmount > 1){
            cout << "\ncannot move more than 1 card at a time to the target pile";
            break;
          }


          bool pop = false;
          pop = targetPile.moveToTarget( pseudoStack.back() );

          if (pop == true){
            // cout << "\npop is true!Heres the break!";
            hand.popCards( handNumber, popAmount);
          }
          // cout << "\nHeres the break!";
          break;
        } // End TargetPile migration


        currentHand = hand.getHand( targetHandNumber );

        moveable = hand.checkTargetHand( currentHand, pseudoStack );

        // moves pseudoStack ontop of TargetHand
        if (moveable == true){
          hand.moveHands( targetHandNumber, pseudoStack );
          hand.popCards( handNumber, popAmount );
          cout << "\nHands moveds";
        }

        // use popAmount here

        pseudoStack.clear();

        break;
      // 4: to quit
      case 4 :
        break;


    }

    // if all piles == 13 , selection = 4, You win Message!
    // selection = targetPile.gameOver();
  }while(selection != 4);

  // Exit Message
  cout << "\nThanks for playing!";
  system("clear");
} // End main


/*
  // Deck Order: foreach cards as card (sorta)
  for( int card : solitaire.getCards() )
    cout << "\ncard: " << card;
deque<int> getHand7();
  // Draw Pile
  cout << "\ndrawPile.size " << drawPile.getCards().size();

  // Hand Piles
  cout << "\nhand1.size " << hand.getHand1().size();
  cout << "\nhand2.size " << hand.getHand2().size();
  cout << "\nhand3.size " << hand.getHand3().size();
  cout << "\nhand4.size " << hand.getHand4().size();
  cout << "\nhand5.size " << hand.getHand5().size();
  cout << "\nhand6.size " << hand.getHand6().size();
  cout << "\nhand7.size " << hand.getHand7().size();
*/

/*
cout << "\nDeque Test";
cout << "\nhand.getHand1().size(): " << hand.getHand7().size();
cout << "\nindex 0: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size()];
cout << "\nindex 1: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 1];
cout << "\nindex 2: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 2];
cout << "\nindex 3: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 3];
cout << "\nindex 4: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 4];
cout << "\nindex 5: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 5];
cout << "\nindex 6: " << hand.getHand7()[hand.getHand7().size() - hand.getHand7().size() + 6];
cout << endl;
exit(0);
*/
