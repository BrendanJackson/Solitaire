#include "Hand.h"

Hand::Hand(vector<int> visitingCards)
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
