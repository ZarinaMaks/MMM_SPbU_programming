//  Created by Zarina Maksudova
/*
(10-40 баллов) Написать программу для настольной карточной игры (в текстовой форме).
- Игрок выбирает действия (2-3 типа)
- 4-5 видов карт (с возможностью развития)
- Взаимодействие между игроками определяется наборами карт, модификаторами, случайными событиями

Game Design:
2 players (11 HP in the beginning)
4 types(suits) of Cards - red, green, white, black
3 types of action Cards:
attack  - damaging a player
red damage = 3, green damage = 2, white damage = 1, black damage = 10
heal - raise 2 HP of a player
enchantment - take 5 Cards more

Game Steps:
Player 1 gets the 5 Card Deck
Player 2 gets the 5 Card Deck
Turn 1: Player 1 uses 1 Card
Turn 1: Player 2 uses 1 Card
Turn 2: Player 1 uses 1 Card
Turn 2: Player 2 uses 1 Card
End of game: Winner - a player with the biggest amount of HP

More Detailed Desccription of Game Steps:
STEPS 1-2: display randomized 5 Card Deck two times
STEP 3-6: player should use only Cards they got on the 1 step and they enter “red attack”, “green attack”,  “white attack”, “black attack”, “heal”, “enchantment” in other cases a player gets an ERROR
STEP 6-7: displaying HP of each player
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "CardGame.h"

using namespace std;

// Function prototypes as outside a class, which we re-use across plays:
void PrintIntro();
void PlayGame();
string GetValidInsertedCommand();
bool AskToPlayAgain();
void CreateDisplayDeck();
// instantiate a new game:
CardGame CGame;

/* Type Cards:
  type 1 - red Cards, type 2 - green Cards
  type 3 - white Cards, type 4 - black Cards
  type 5 - heal Cards, type 6 - enchantment Cards
  */


//Checked:
void PrintIntro() {
    cout << "Welcome to Magic The Colouring, a fun Card game!\n";
    cout << endl;
    cout << "          _              _                                 _       " << endl;
    cout << "   _ __  | | __ __ _   _(_)_ __   __ _    ___ __ _ _ __ __| |___   " << endl;
    cout << "  | '_ \\| |/ _`  | | | | | '_ \\/ _` |  / __/ _` | '__/ _` / __|  " << endl;
    cout << "  | |_)  | | (_|  | |_| | | | | | (_| | (_| (_| | | | (_| \\|__\\  " << endl;
    cout << "  | .__/ |_|\\__,_|\\__ |_|_| |_|\\__,| \\___\\_,_|_| \\__,_|___/  " << endl;
    cout << "  |_|              |___/          |___/                            " << endl;
    cout << "                       MAGIC THE COLOURING                         " << endl;
    cout << "                                                                   " << endl;
    cout << "                                                                   " << endl;
    cout << "                       3 types of action Cards:                    " << endl;
    cout << "          1) ATTACK  - damaging an opponent:                       " << endl;
    cout << "              1 - red_attack = 4 pts, 2 - green_attack = 3 pts     " << endl;
    cout << "              3 - white_attack = 1 pts, 4 - black_attack = 10pts   " << endl;
    cout << "          2) 5 - HEAL - raise 2 HP                                 " << endl;
    cout << "          3) 6 - ENCHANTMENT - take 5 Cards more                   " << endl;
    cout << "                           7 - EXIT GAME                           " << endl;

    return;
}
bool AskToPlayAgain() {
    cout << "Do you want to play again(y/n)? ";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

int main ( ) {
    do {
        PlayGame();
    }
    while (AskToPlayAgain());
    return 0;
}

void PlayGame() {
    int NumberOfTurns = 2;
    int CurrentTurn = NumberOfTurns - 1;
    PrintIntro();

    auto Player1 = new Player(CGame.CreateDisplayDeck(), 11);
    auto Player2 = new Player(CGame.CreateDisplayDeck(), 11);

    while (NumberOfTurns > 0) {
        cout << endl << endl << "! --- BEGINNING of turn " << CurrentTurn << " --- !"<< endl << endl;

        //----------Player1----------//
        cout << "Player 1, your turn, this is your deck: " << endl;
        Player1->DisplayDeck();
        string InsertedCommand;

        // Play Card() <- while PlayCard false display error
        do {
            cout << "Player 1, enter your command: " << endl;
            cin >> InsertedCommand;
        } while (Player1->PlayCard(InsertedCommand)==false);

        int value = CGame.GetCardEffect(InsertedCommand);
        if (InsertedCommand == "heal") {
            int HP1 = Player1->ChangeHPCount(value);
            cout << endl <<  "EFFECT of " << InsertedCommand << " is " << value << endl;
            cout << "Now Player 1 HPs: " << HP1 << endl;
        } else if (InsertedCommand == "enchantment") {
            auto newDeck_Player = CGame.CreateDisplayDeck();
            Player1->AddMoreCards(newDeck_Player);
            cout << endl << "Now Player 1 has: " << endl;
            Player1->DisplayDeck();
            cout << endl;

        } else {
            int HP2 = Player2->ChangeHPCount(value);
            cout << "Effect of " << InsertedCommand << " is " << value << endl;
            cout << "Now Player 2 HPs: " << HP2 << endl;
        }
        //--------------------//


        //----------Player2----------//
        cout << "Player 2, your turn, this is your deck: " << endl;
        Player2->DisplayDeck();

        // Play Card() <- while PlayCard false display error
        do {
            cout << "Player 2, enter your command: " << endl;
            cin >> InsertedCommand;
        } while (Player2->PlayCard(InsertedCommand)==false);


        value = CGame.GetCardEffect(InsertedCommand);
        if (InsertedCommand == "heal") {
            int HP2 = Player2->ChangeHPCount(value);
            cout << "Effect of " << InsertedCommand << " is " << value << endl;
            cout << "Now Player 2 HPs: " << HP2 << endl;
        } else if (InsertedCommand == "enchantment") {
            auto newDeck_Player = CGame.CreateDisplayDeck();
            Player2->AddMoreCards(newDeck_Player);
            cout << endl << "Now Player 2 has: " << endl;
            Player2->DisplayDeck();
            cout << endl;

        } else {
            int HP1 = Player1->ChangeHPCount(value);
            cout << "Effect of " << InsertedCommand << " is " << value << endl;
            cout << "Now Player 1 HPs: " << HP1 << endl;
        }
        //--------------------//

        cout << endl << endl << "! --- END of turn " << CurrentTurn << " --- !"<< endl << endl;
        NumberOfTurns--;
        CurrentTurn++;

    }
    int TotalHP1 = Player1->GetHPCount();
    int TotalHP2 = Player2->GetHPCount();
    cout << "Total HP of Player 1: " << TotalHP1 << endl;
    cout << "Total HP of Player 2: " << TotalHP2 << endl;

    if (TotalHP1 > TotalHP2)
    {
        cout << "Congratulations! Player 1 won!!!" << endl;
    } else if (TotalHP1 < TotalHP2) {
        cout << "Congratulations! Player 2 won!!!" << endl;
    } else {
        cout << "Its a tie!!!" << endl;
    }
}
