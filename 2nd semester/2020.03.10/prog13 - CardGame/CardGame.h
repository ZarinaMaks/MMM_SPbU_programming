/*
The game logic (no view code or direct user interaction).
The game is a simple guess the word game based on Mastermind.
*/
#pragma once
#include <string>
#include <map>
using namespace std;

class Player {

public:

    Player(map <string, int> deck, int hpcount);
    bool PlayCard(string Card);
    void AddMoreCards(map<string, int> newdeck);
    int ChangeHPCount(int effect);
    void DisplayDeck();
    int GetHPCount();

private:

    map<string, int> Deck;
    int HPCount;
};

class CardGame {

public:

    CardGame();

    int GetCardEffect(string Command);
    int GetMaxTurns() const;
    int GetCurrentTurn() const;
    bool IsGameWon(string Command) const;

    void ResetTurnNumber();
    string GetRandomCard();
    map<string, int> CreateDisplayDeck();

private:

    void CardEffect();
    void EnchantmentEffect();
    map<string, int> CardEffectM;
    map<string, int> EnchantmentEffectM;

    map<string, int> Deck_1Player;
    map<string, int> Deck_2Player;
};

