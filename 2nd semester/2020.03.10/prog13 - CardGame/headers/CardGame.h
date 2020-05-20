//  CardGame.h
//  Created by Zarina Maksudova
/* 
 The game logic (no view code or direct user interaction).
 The game is a simple guess the word game based on Mastermind.
*/
#pragma once
#include <string>

struct HPCount
{
    int HP_Player1 = 0;
    int HP_Player2 = 0;
};

enum class EWordStatus
{
    Invalid_Status,
    OK,
    Wrong_Word,
    No_Card
};

class CardGame
{
public:
    CardGame(); //constructor
    
    int GetMaxTurns() const;
    int GetCurrentTurn() const;
    //int GetWordLength() const;
    //void PickNextWord();
    bool IsGameWon(string Command) const;
    EWordStatus CheckGuessValidity(std::string) const;
    
    void Reset();
    void ResetTurnNumber();
    //counting HPs, increasing turn number, assuming valid command
    HPCount SubmitValidGuess(string);
    
private:
    bool IsCommand(string) const;
    int MyCurrentTurn = 1;
    //int MyMaxTurns = 5;
    
    string CommandBar[6] = {"red attack", "green attack", "write attack", "black attack", "heal", "enchantment",};
};