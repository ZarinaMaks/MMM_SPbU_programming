/*
 * (10-40 баллов) Написать программу для настольной карточной игры (в текстовой форме).
- Игрок выбирает действия (2-3 типа)
- 4-5 видов карт (с возможностью развития)
- Взаимодействие между игроками определяется наборами карт, модификаторами, случайными событиями
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


// Function prototypes as outside a class, which we re-use across plays
void PrintIntro();
void PlayGame();
string GetValidCommand();
bool AskToPlayAgain();
CardGame CGame; // instantiate a new game

// Type Cards
// type 1 - red cards, type 2 - green cards
// type 3 - white cards, type 4 - black cards
enum Suit { type1, type2, type3, type4 };
const int Card1 = 1; //attacking card - action 1
const int Card2 = 2; //healing card - action 2
const int Card3 = 3; //enchantment - action 3

void PrintIntro()
{
    cout << "Welcome to Magic The Colouring, a fun card game!\n";
    cout << endl;
    cout << "         _             _                                  _            " << endl;
    cout << "  _ __  | | __ _ _   _(_)_ __   __ _     ___ __ _ _ __ __| |___        " << endl;
    cout << " | '_ \\| |/ _`  | | | | | '_ \\/ _` |  / __/ _` | '__/ _` / __|       " << endl;
    cout << " | |_)  | | (_|  | |_| | | | | | (_| | (_| (_| | | | (_| \\__ \\       " << endl;
    cout << " | .__/ |_|\\__,_|\\__ |_|_| |_|\\__,| \\___\\_,_|_| \\__,_|___/       " << endl;
    cout << " |_|              |___/          |___/                                 " << endl;
    cout << "                       MAGIC THE COLOURING                             " << endl;
    cout << "                                                                       " << endl;
    cout << "                                                                       " << endl;
    cout << "                       3 types of action cards:                        " << endl;
    cout << "          1) ATTACK  - damaging an opponent:                           " << endl;
    cout << "              red attack = 3 pts, green damage = 2 pts                 " << endl;
    cout << "              white damage = 1pts, black damage = 10pts                " << endl;
    cout << "          2) HEAL - raise 2 HP                                         " << endl;
    cout << "          3) ENCHANTMENT - take 5 cards more                           " << endl;
    cout << "                                                                       " << endl;

    return;
}
class Card
{
private:
    int number;
    Suit suit;
public:
    card ( ) // constructor
    { }
    void set ( int n, Suit s ) // setting the value
    { suit = s; number = n; }
    void display ( );          // displaying the card
};
void card::display ( )
{
    if ( number >= 1 && number <= 3 )
        cout << number;
    else
    {
        switch ( number )
        {
            case Card1: cout << 'Attack'; break;
            case Card2: cout << 'Heal'; break;
            case Card3: cout << 'Enchantment'; break;
        }
    }
    switch ( suit )
    {
        case type1: cout << static_cast<char>( 4 ); break;
        case type2: cout << static_cast<char>( 5 ); break;
        case type3: cout << static_cast<char>( 6 ); break;
        case type4: cout << static_cast<char>( 7 ); break;
    }
}


int main ( )
{
    do {
        PlayGame();
        CGame.ResetTryNumber();
        //TODO ResetTryNumber
    }
    while (AskToPlayAgain());
    return 0;
}

void PlayGame()
{
    PrintIntro();
    card deck [ 15 ];
    int j;

    cout << endl;

    // create a deck
    for ( j = 0; j < 15; j++ )
    {
        int num = ( j % 5 ) + 2;
        Suit su = Suit ( j / 5 );
        deck [ j ].set ( num, su );
    }

    // displaying started deck
    cout << "Your started deck:\n";
    for ( j = 0; j < 15; j++ )
    {
        deck [ j ].display ( );
        cout < "  ";
        if ( !( ( j + 1 ) % 5 ) ) // start new line after each 5 card
            cout << endl;
    }

    // analyze generator of random numbers
    srand ( time ( NULL ) );
    for ( j = 0; j < 15; j++ )
    {
        int k = rand ( ) % 15;     // take random card
        card temp = deck [ j ];    // swap it with the current
        deck [ j ] = deck [ k ];
        deck [ k ] = temp;
    }

    // displaying mixed deck
    cout << "\nMixed deck:\n";
    for ( j = 0; j < 15; j++ )
    {
        deck [ j ].display ( );
        cout << "  ";
        if ( !( ( j + 1 ) % 5 ) ) // start new line after each 5 card
            cout << endl;
    }
    // TODO write each card's effect
}

//loop continually until the user gives a valid command
string GetValidCommand()
{
    string Command = "";
    EWordStatus Status = EWordStatus::Invalid_Status;

    do {
        int CurrentTurn = CGame.GetCurrentTurn();

        // get a command from the player
        cout << "Turn " << CurrentTurn << " of " << CGame.GetMaxTurn() << ".( ͡° ͜ʖ ͡°)Enter your command: ";
        getline(cin, Command);

        //check status, give feedback
        Status = CGame.CheckCommandValidity(Command);
        switch (Status)
        {
                //TODO write Wrong_Word
            case EWordStatus::Wrong_Word:
                cout << "Please enter a COMMAND.\n";
                break;

                //TODO write No_Card
            case EWordStatus::No_Card:
                cout << "Please enter a card which YOU HAVE.\n";
                break;

            default:
                return Command;
                break;
        }
    } while (Status != EWordStatus::OK); //keep looping until we get no errors
    return Command;
}

bool AskToPlayAgain()
{
    cout << "Do you want to play again(y/n)? ";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
