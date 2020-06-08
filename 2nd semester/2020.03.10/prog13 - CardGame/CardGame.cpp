//  CardGame.cpp
//  Created by Zarina Maksudova
#include <iostream>
#include <iterator>
#include <map>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "CardGame.h"

CardGame::CardGame() {
    //Reset();
    CardEffect();
    EnchantmentEffect();
}
/*int CardGame::GetCurrentTurn() const {
    return CardGame::MyCurrentTurn;

}*/
/*void CardGame::Reset() {
   MyCurrentTurn = 1;
   return;
}*/
void CardGame::CardEffect() {
    CardEffectM.insert(make_pair("red_attack", -4));
    CardEffectM.insert(make_pair("green_attack", -3));
    CardEffectM.insert(make_pair("write_attack", -1));
    CardEffectM.insert(make_pair("black_attack", -10));
    // CardEffectM.insert(make_pair("enchantment", 5));
    CardEffectM.insert(make_pair("heal", 2));

}
void CardGame::EnchantmentEffect() {
    EnchantmentEffectM.insert(make_pair("enchantment", 5));
}
/*void CardGame::ResetTurnNumber() {
    MyCurrentTurn = 1;

}*/

Player::Player(map<string, int> deck, int hpcount) {
    Deck = deck;
    HPCount = hpcount;
}


void Player::DisplayDeck() {
    for(map<string, int>::const_iterator it = Deck.begin();
        it != Deck.end(); ++it) {
        cout << it->second << " of " << it->first << "\n";

    }
}

bool Player::PlayCard(string Card) {

    //Check if exists:
    if (Deck.count(Card) == 0)
    {
        cout << "UPS! You don't have such card - enter a valid card name!" << endl;
        return false;
    }

    Deck[Card]--;
    if (Deck[Card] <= 0)
    {
        Deck.erase(Card);
    }
    return true;

}

void Player::AddMoreCards(map<string, int> newdeck) {
    // Create a map iterator and point to beginning of map
    map<string, int>::iterator it = newdeck.begin();

    // Iterate over the map using Iterator till end.
    while (it != newdeck.end())
    {
        // Accessing KEY from element pointed by it.
        string card = it->first;

        // Accessing VALUE from element pointed by it.
        int count = it->second;
        //Check if exists
        if (Deck.count(card) == 0)
        {
            Deck.insert(make_pair(card, count));
        } else {
            Deck[card] += count;
        }
        //cout << card << endl;
        // Increment the Iterator to point to next entry
        it++;
    }
}

int Player::ChangeHPCount(int effect){
    HPCount += effect;
    return HPCount;
}

int Player::GetHPCount() {
    return HPCount;
}

int CardGame::GetCardEffect(string Command) {

    //Check if exists
    if (CardEffectM.count(Command) == 0)
    {
        return 0;
    }
    return CardEffectM[Command];

}
/*int CardGame::GetEnchantmentEffect(string Command) {

  //Check if exists
  if (EnchantmentEffectM.count(Command) == 0)
	{
	    return 0;
	}
	return EnchantmentEffectM[Command];

}*/

string CardGame::GetRandomCard() {

    auto it = CardEffectM.begin();
    advance(it, rand() % CardEffectM.size());
    string random_key = it->first;
    return random_key;
}


map<string, int> CardGame::CreateDisplayDeck() {
    /*
   int j;
   cout << endl;
   Card Deck_1Player [ 5 ];
   Card Deck_2Player [ 5 ];

   // create 2 Decks
   for ( j = 0; j < 5; j++ )
   {
       int num = ( j % 7 ) + 2;
       Suit su = Suit ( j / 7 );
       Deck_1Player [ j ].set ( num, su );
       Deck_2Player [ j ].set ( num, su );
   }

   // displaying 2 started Decks
   srand ( time ( NULL ) );

   //----Player 1----//
   cout << "1st Player started Deck:\n";
   for ( j = 0; j < 5; j++ )
   {
       Deck_1Player [ j ].display ( );
       cout < "  ";

       // start new line after Player1 5-Card-Deck
       if ( !( ( j + 1 ) % 5 ) )
           cout << endl;
   }

   for ( j = 0; j < 5; j++ )
   {
       int k = rand ( ) % 5;     // take random Card
       Card temp1 = Deck_1Player [ j ];    // swap it with the current
       Deck_1Player [ j ] = Deck_1Player [ k ];
       Deck_1Player [ k ] = temp1;
   }
   // displaying mixed Deck
   cout << "\nMixed 1st Player's Deck:\n";
   for ( j = 0; j < 5; j++ )
   {
       Deck_1Player [ j ].display ( );
       cout << "  ";
       if ( !( ( j + 1 ) % 5 ) ) // start new line after each 5 Card
           cout << endl;
   }

   //--------------//


   //----Player 2----//
   cout << "2nd Player started Deck:\n";
   for ( j = 0; j < 5; j++ )
   {
       Deck_2Player [ j ].display ( );
       cout < "  ";

       // start new line after Player2 5-Card-Deck
       if ( !( ( j + 1 ) % 5 ) )
           cout << endl;
   }

   for ( j = 0; j < 5; j++ )
   {
       int k = rand ( ) % 5;     // take random Card
       Card temp2 = Deck_2Player [ j ];    // swap it with the current
       Deck_2Player [ j ] = Deck_2Player [ k ];
       Deck_2Player [ k ] = temp2;
   }
   // displaying mixed Deck
   cout << "\nMixed 2nd Player's Deck:\n";
   for ( j = 0; j < 5; j++ )
   {
       Deck_2Player [ j ].display ( );
       cout << "  ";
       if ( !( ( j + 1 ) % 5 ) ) // start new line after each 5 Card
           cout << endl;
   }
   //--------------//
   */
    map<string, int> Deck_Player;
    for (int i = 0; i < 5; i++) {
        auto card = GetRandomCard();
        //auto effect = CGame.GetCardEffect(card);

        //Check if exists:
        if (Deck_Player.count(card) == 0) {
            Deck_Player.insert(make_pair(card, 1));
        } else {
            Deck_Player[card]++;
        }
        cout << card << "; ";
    }
    return Deck_Player;
}

/*void CardGame::CreateDisplay2Deck() {

   cout << "2nd Player Cards: " << endl;
   for (i = 0; i < 5; i++) {
      auto card = CGame.GetRandomCard();
      auto effect = CGame.GetCardEffect(card);
      Deck_2Player.insert(make_pair(card, effect));
      cout << card << "; ";
   }

}*/

//TODO CheckCommandValidity
/*CommandStatus CardGame::CheckCommandValidity(string Command) const
{
   if (!IsCommand(Command)) //if the word isn't an command, return the error Wrong_Word:
   {
       return CommandStatus::Wrong_Word;
   }
   else if (//TODO CHECK IF IT IS A CARD PLAYER HAS) //if the command tries to get a card which a player does not have, return the error No_Card:
   {
       return CommandStatus::No_Card;
   }
   else  //otherwise, return OK:
   {
       return CommandStatus::OK;
   }
   //return CommandStatus::OK;
}*/