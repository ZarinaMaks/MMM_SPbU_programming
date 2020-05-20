//  CardGame.cpp
//  Created by Zarina Maksudova

#include "CardGame.h"
#include <iostream>
#include <iterator>
#include <map>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


CardGame::CardGame() { Reset();}
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int CardGame::GetMaxTurns() const
{
   MaxTurns = getRandomNumber(1,5);
   return MaxTurns;
}
int CardGame::GetCurrentTurn() const { return CardGame::MyCurrentTurn; }
void CardGame::Reset()
{
    MyCurrentTurn = 1;
    return;
}

//TODO HPCounter
/*bool CardGame::IsGameWon(string Command) const
{
    if (Command == MyHiddenWord)
    {
        std::cout << "Congratulations! You won!\n";
        return true;
    }
    return false;
}*/

EWordStatus CardGame::CheckCommandValidity(string Command) const
{
    if (!IsCommand(Command)) //if the word isn't an command, return the error Wrong_Word:
    {
        return EWordStatus::Wrong_Word;
    }
    else if (/*TODO CHECK IF IT IS A CARD PLAYER HAS*/) //if the command tries to get a card which a player does not have, return the error No_Card:
    {
        return EWordStatus::No_Card;
    }
    else  //otherwise, return OK:
    {
        return EWordStatus::OK;
    }
    //return EWordStatus::OK;
}


//reseives a VALID command, incriments turns, returns HPCount
HPCount CardGame::SubmitValidCommand(string Command)
{
    MyCurrentTurn++;
    HPCount HPCount;  //setup a return variable
    int WordLength = MyCommand.length(); //assuming same length as command

    if (/*TODO*/)
    {
        //TODO for the amound of damage:
        HPCount.HP_Player1--;
    }
    else
        {
        //TODO for the amound of damage:
        HPCount.HP_Player2--;
        }
    }
    return HPCount;
}

void CardGame::ResetTurnNumber() { MyCurrentTurn = 1; }

bool CardGame::IsCommand(string Word) const
{
    /*TODO COMPARE TO WHAT IS IN CommandBar*/
    return true;
}