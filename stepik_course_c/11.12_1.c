/* Программа ищет пиковую даму в переданной руке.
Для перебора карт добавим последнюю фейковую со значения (0,0) для возможности перебора всех карт.
Масть (suit):
c - clubs, трефы, ♣
s - spades, пики, ♠️
h - hearts, червы, ♥️
d - diamond, бубны, ♦️
Достоинство (rank):
'2', '3', '4', '5', '6', '7', '8', '9' - от 2 до 9
'T' (ten - десять),
'J' (валет),
'Q' (дама),
'K' (король),
'A' (туз).


20.06.2025
Автор: Мялькин В.В.*/

#include <stdio.h>
#define DECKSIZE 52

struct Card {
    char rank; //достоинство
    char suit; //масть
};

void print_cards(struct Card *hand);
void read_cards(struct Card *hand);
int valid_card(struct Card *card);
int check(struct Card *hand);

int main()
{
    struct Card hand[DECKSIZE + 1];
    printf("Введите карты:\n");
    read_cards(hand);
    print_cards(hand);
    if (check(hand))
        printf("Есть пиковая дама.\n");
    else
        printf("Пиковой дамы нет.\n");
    return 0;
}

void print_cards(struct Card *hand)
{
    struct Card *p;
    for( p = hand; p->rank != 0; p++)
        printf("%c%c", p->rank, p->suit);
    printf("\n");
}

void read_cards(struct Card *hand)
{
    struct Card *p;
    for(p = hand; 2 == scanf("%c%c", &p->rank, &p->suit); p++){
        if (!valid_card(p))
            break;
    }
    p->rank = p->suit = 0;
}

int valid_card(struct Card *card)
{
    char * const suit = "cshd";
    char * const rank = "23456789TJQKA";
    int i;
    for(i = 0; suit[i] != '\0'; i++)
        if(suit[i] == card->suit)
            break;
    if(suit[i] == '\0')
        return 0;

    for(i = 0; rank[i] != '\0'; i++)
        if(rank[i] == card->rank)
            return 1;
    return 0;
}
 
int check(struct Card *hand)
{
    struct Card *p;
    for(p = hand; p->rank != 0; p++){
        if(p->rank == 'Q' && p->suit == 's')
            return 1;
    }
    return 0;
}
