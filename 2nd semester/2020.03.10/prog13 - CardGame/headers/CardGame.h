//  CardGame.h
//  Created by Zarina Maksudova
/*
The game logic (no view code or direct user interaction).
The game is a simple guess the word game based on Mastermind.
*/
#pragma once
#include <string>
using namespace std;

/*class Card {
private:

   int number;
   Suit Suit;

public:

   // constructor:
   Card ( )
   { }

   // set the value:
   void set ( int n, Suit s )
   { suit = s; number = n; }

   void display ( );
};

enum class CommandStatus {
   Invalid_Status,
   OK,
   Wrong_Word,
   No_Card
};*/

class Player {

public:

    Player(map<string, int> deck, int hpcount);
    bool PlayCard(string Card);
    void AddMoreCards(map<string, int> newdeck);
    int ChangeHPCount(int effect);
    void DisplayDeck();

private:

    map<string, int> Deck;
    int HPCount;
}

class CardGame {

public:

    CardGame();

    int GetCardEffect(string Command);
    //int GetEnchantmentEffect(string Command);
    int GetMaxTurns() const;
    int GetCurrentTurn() const;
    bool IsGameWon(string Command) const;

    void Reset();
    void ResetTurnNumber();
    string GetRandomCard();
    map<string, int> CreateDisplayDeck();
    //CommandStatus CheckGuessValidity(string /*TODO*/) const;
    //counting HPs, increasing turn number, assuming valid command
    //HPCount SubmitValidGuess(string /*TODO*/);

private:

    void CardEffect();
    void EnchantmentEffect();
    map<string, int> CardEffectM;
    map<string, int> EnchantmentEffectM;

    map<string, int> Deck_1Player;
    map<string, int> Deck_2Player;

    //bool IsCommand(string) const;
    //int MyCurrentTurn; = 1;
    //int MyMaxTurns = 5;
    //string CommandBar[6] = {"red attack", "green attack", "write attack", "black attack", "heal", "enchantment",};
};

