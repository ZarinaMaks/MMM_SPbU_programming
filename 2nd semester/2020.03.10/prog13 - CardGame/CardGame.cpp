#include <iostream>
#include <iterator>
#include <map>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "CardGame.h"

CardGame::CardGame() {
    CardEffect();
    EnchantmentEffect();
}

void CardGame::CardEffect() {
    CardEffectM.insert(make_pair("red_attack", -4));
    CardEffectM.insert(make_pair("green_attack", -3));
    CardEffectM.insert(make_pair("write_attack", -1));
    CardEffectM.insert(make_pair("black_attack", -10));
    CardEffectM.insert(make_pair("enchantment", 5));
    CardEffectM.insert(make_pair("heal", 2));

}
void CardGame::EnchantmentEffect() {
    EnchantmentEffectM.insert(make_pair("enchantment", 5));
}

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
    map<string, int>::iterator it = newdeck.begin();

    while (it != newdeck.end())
    {
        // Accessing KEY from element pointed by it
        string card = it->first;

        // Accessing VALUE from element pointed by it
        int count = it->second;
        //Check if exists
        if (Deck.count(card) == 0)
        {
            Deck.insert(make_pair(card, count));
        } else {
            Deck[card] += count;
        }
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
string CardGame::GetRandomCard() {

    auto it = CardEffectM.begin();
    advance(it, rand() % CardEffectM.size());
    string random_key = it->first;
    return random_key;
}


map<string, int> CardGame::CreateDisplayDeck() {

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
