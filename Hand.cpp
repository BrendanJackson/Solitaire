#include "Hand.h"

void Hand::fillHand(vector<int> visitingCards)
{
  // refactor
  // hand1{24}, hand2{25,26}, hand3{27, 28, 29}, hand4{30, 31, 32, 33},
  // hand5{34, 35, 36, 37, 38}, hand6{39, 40, 41, 42, 43, 44},
  // hand7{45, 46, 47, 48, 49, 50, 51}
  hand1.push_back( visitingCards[24] );

  hand2.push_back( visitingCards[25] );
  hand2.push_back( visitingCards[26] );

  hand3.push_back( visitingCards[27] );
  hand3.push_back( visitingCards[28] );
  hand3.push_back( visitingCards[29] );

  hand4.push_back( visitingCards[30] );
  hand4.push_back( visitingCards[31] );
  hand4.push_back( visitingCards[32] );
  hand4.push_back( visitingCards[33] );

  hand5.push_back( visitingCards[34] );
  hand5.push_back( visitingCards[35] );
  hand5.push_back( visitingCards[36] );
  hand5.push_back( visitingCards[37] );
  hand5.push_back( visitingCards[38] );

  hand6.push_back( visitingCards[39] );
  hand6.push_back( visitingCards[40] );
  hand6.push_back( visitingCards[41] );
  hand6.push_back( visitingCards[42] );
  hand6.push_back( visitingCards[43] );
  hand6.push_back( visitingCards[44] );

  hand7.push_back( visitingCards[45] );
  hand7.push_back( visitingCards[46] );
  hand7.push_back( visitingCards[47] );
  hand7.push_back( visitingCards[48] );
  hand7.push_back( visitingCards[49] );
  hand7.push_back( visitingCards[50] );
  hand7.push_back( visitingCards[51] );

}

deque<int> Hand::getHand1()
{
  return hand1;
}

deque<int> Hand::getHand2()
{
  return hand2;
}

deque<int> Hand::getHand3()
{
  return hand3;
}

deque<int> Hand::getHand4()
{
  return hand4;
}

deque<int> Hand::getHand5()
{
  return hand5;
}

deque<int> Hand::getHand6()
{
  return hand6;
}

deque<int> Hand::getHand7()
{
  return hand7;
}

deque <int> & Hand::getHand( int handNumber )
{

  switch( handNumber )
  {

    case 1:
    return hand1;
    break;

    case 2:
    return hand2;
    break;

    case 3:
    return hand3;
    break;

    case 4:
    return hand4;
    break;

    case 5:
    return hand5;
    break;

    case 6:
    return hand6;
    break;

    case 7:
    return hand7;
    break;

    default: cout << "\nNo hand returned!?!";
    exit(0);
    break;
  }

}

void Hand::popCards( int handNumber, int popAmount)
{


  for (int i = 0; i < popAmount; i++){
    // hand1.pop_back();
    getHand( handNumber ).pop_back();
  }


}

vector< deque<int> >  Hand::getHands()
{

  vector< deque<int> > hands;  //vector of type deque<int>

  hands.clear();

  hands.push_back( getHand1() );
  hands.push_back( getHand2() );
  hands.push_back( getHand3() );
  hands.push_back( getHand4() );
  hands.push_back( getHand5() );
  hands.push_back( getHand6() );
  hands.push_back( getHand7() );

  return hands;

}



// checks hand given for amount of possible cards to move
vector<int> Hand::checkHand(int handNumber)
{

  vector < deque<int> > hands = getHands();
  vector<int> pseudoStack;
  pseudoStack.clear();

  if (hands.at(handNumber - 1).size() == 0)
    return pseudoStack;

  cout << "\nhandNumber-1: " << handNumber-1;
  cout << "\nhands[handNumber-1].size()" << hands[handNumber-1].size();
  cout << "\nhands[handNumber-1].back() is: " << hands[handNumber-1].back();

  //creates a temporary vector that will adhere to the rules of moving hands in solitaire

  // puts last element in hands vector into pseudostack
  pseudoStack.push_back( hands[handNumber-1].back() );
  for (int i = hands[handNumber-1].size() - 1; i >= 0; i--) {
    if ( getFace( pseudoStack.front() ) == getFace( hands[handNumber-1].at(i) - 1 ) )
      pseudoStack.push_back( hands[handNumber-1].at(i) );

    cout << "\ni= " << i;
    cout << "\nhands[handNumber-1][i]: " << hands[handNumber-1][i]
         << " getFace(hands[handNumber-1][i]): " << getFace(hands[handNumber-1][i]);

  }

  cout << "\nYou can move these cards to another hand: ";
  for( int i = 0; i < pseudoStack.size(); i++ ){
    checkFace( getFace( pseudoStack.at(i) ) );
    cout << getSuit( pseudoStack.at(i) );
  }



  return pseudoStack;

}

vector<int> Hand::selectCards( vector<int> pseudoStack )
{

  int selectedCards;
  int answer;
  vector<int> tempStack;

  do {

    cout << "\n\nHow many cards would you like to select, out of " << pseudoStack.size()
         << "? \nThe cards will be chosen in the order they appear." << endl;
    for( int i = 0; i < pseudoStack.size(); i++ ){
      checkFace( getFace( pseudoStack.at(i) ) );
      cout << getSuit( pseudoStack.at(i) );
    }

    cout << endl;
    cin >> selectedCards;
    while (selectedCards > pseudoStack.size() || selectedCards < 1){
      cout << "\nYou have selected an improper amount of cards, please be sure you select an amount between 1 and "
           << pseudoStack.size() << endl;
       cin >> selectedCards;
    }

    cout << "\nYou have selected these cards ";

    for (int i = 0; i < selectedCards;i++ )
      cout << pseudoStack.at(i) << " ";

    cout << "\nIs this correct? 1 for yes, 0 for no" << endl;
     cin >> answer;
 }while( answer == 0 );

reverse( pseudoStack.begin(), pseudoStack.end() );

 for (int i = 0; i < selectedCards;i++ )
   tempStack.push_back( pseudoStack.at(i) );

  pseudoStack = tempStack;

  return pseudoStack;

}

bool Hand::checkTargetHand( deque<int> currentHand, vector<int> pseudoStack )
{

  int bottomCard;
  bool move;
  move = false;

  if (currentHand.empty() == 1)
    bottomCard = 0;
  else
    bottomCard =  currentHand.back();


  if( ( getFace( getFace( bottomCard ) ) == 0) && ( getFace( pseudoStack.back() == 13) ) ){
    cout << "\nTargetHand is empty, moving kings ontop! ";
    move = true;

  } else if (getFace( bottomCard ) == 0 && getFace( pseudoStack.back() ) != 13){
      cout << "\nYou cannot move a card that is not a king to an empty pile";

  } else if (
       (( bottomCard <= 26 ) && ( pseudoStack.back() <= 26) )
    || (( bottomCard >= 27 ) && ( pseudoStack.back() >= 27) )
  ){
    cout << "\nCannot place 2 cards of the same color ontop of one another";

  } else if( getFace( bottomCard ) == getFace( pseudoStack.back() ) + 1){
    cout << "\nPseudoStack will fit ontop of targetpile";
    move = true;

  } else
    cout << "\nCannot place PseudoStack ontop of targetpile"
         << "\nbottomCard: " << bottomCard << " pseudoStack.back(): " << getFace( pseudoStack.back() );


  
  cout << endl;
  return move;

}

void Hand::moveHands( int targetHandNumber, vector<int> pseudoStack)
{

  cout << "\nin moveHands, pseudoStack.size(): " << pseudoStack.size();
  for(int i = 0;i < pseudoStack.size();i++){

    getHand( targetHandNumber ).push_back( pseudoStack.at(i) );

    cout << "\npseudoStack.at(i): " << pseudoStack.at(i);

  }

}
