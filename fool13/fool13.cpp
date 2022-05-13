// Дурак проект.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include <ctime>
#include<conio.h>
using namespace std;
//void cleanTable(Card*& table);


enum Suit { Heart = 3, Diamonds, Clubs, Spades };
enum Rank { Six = 6, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
//структура карты
struct Card {
    char Suit;
    int Rank;
};

//структура игрока
struct Player {
    string name;
    int score = 5000;
    Card* array;
};
//структура противника
struct Enemy {
    string name;
    int score = 5000;
    Card* array;
};

//заполнение колоды
void deck_init(Card*& deck) {
    for (int i = 0, k = 6; i < 9; i++, k++) {
        deck[i].Suit = Heart;
        deck[i].Rank = k;
    }
    for (int i = 9, k = 6; i < 18; i++, k++) {
        deck[i].Suit = Diamonds;
        deck[i].Rank = k;
    }
    for (int i = 18, k = 6; i < 27; i++, k++) {
        deck[i].Suit = Clubs;
        deck[i].Rank = k;
    }
    for (int i = 27, k = 6; i < 36; i++, k++) {
        deck[i].Suit = Spades;
        deck[i].Rank = k;
    }
}


//вывод колоды
void showDeck(Card*& deck) {
    int size = _msize(deck) / sizeof(deck[0]);
    for (int i = 0; i < size; i++) {

        //switch (i) {
        //case 9: //hearts
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 10:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 11:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 12:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //case 22: //diamonds
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 23:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 24:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 25:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //case 35: //spades
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 36:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 37:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 38:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //case 48: //clubs
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 49:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 50:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 51:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //default:
        //    cout << deck[i].Rank << " " << deck[i].Suit << endl;
        //    break;
        //}

        if (deck[i].Rank == 11) cout << "[J]" << " of " << deck[i].Suit << endl;
        else if (deck[i].Rank == 12) cout << "[Q]" << " of " << deck[i].Suit << endl;
        else if (deck[i].Rank == 13) cout << "[K]" << " of " << deck[i].Suit << endl;
        else if (deck[i].Rank == 14) cout << "[A]" << " of " << deck[i].Suit << endl;
        else cout << "[" << deck[i].Rank << "]" << " of " << deck[i].Suit << endl;



    }
}

//вывод буквенного значения карты

void show_pic(Card*& hand1, int i) {

    if (hand1[i].Rank == 11) cout << "[ J" << " of " << hand1[i].Suit << " ] " << endl;
    else if (hand1[i].Rank == 12) cout << "[ Q" << " of " << hand1[i].Suit << " ] " << endl;
    else if (hand1[i].Rank == 13) cout << "[ K" << " of " << hand1[i].Suit << " ] " << endl;
    else if (hand1[i].Rank == 14) cout << "[ A" << " of " << hand1[i].Suit << " ] " << endl;
    else cout << "[ " << hand1[i].Rank << " of " << hand1[i].Suit << " ] " << endl;
}

//перемешка колоды
void shuffleDeck(Card*& deck) {
    for (int i = 0; i < 36; i++) {
        swap(deck[i], deck[rand() % 36]);
    }
}


// первая раздача карт
void takeCard(Card*& deck, Card*& hand1, Card*& hand2) {

    for (int i = 0, k = 0; i < 6; i++) {
        hand1[i].Rank = deck[i].Rank;
        hand1[i].Suit = deck[i].Suit;
    }
    for (int i = 0, k = 0; i < 6; i++) {
        hand2[i].Rank = deck[i + 6].Rank;
        hand2[i].Suit = deck[i + 6].Suit;
    }

}

//удаление карт из колоды после первой раздачи
void delFromDeck(Card*& deck) {
    int size = _msize(deck) / sizeof(deck[0]);
    int size2 = size - 12;
    Card* buf = new Card[size2];

    for (int i = 0, k = 12; i < size2, k < size; i++, k++) {
        buf[i] = deck[k];

    }

    delete[]deck;


    deck = buf;
}

//вывод рук
//добавить функцию show pic
void showHand(Card*& hand1, Card*& hand2) {
    int size = _msize(hand1) / sizeof(hand1[0]);
    int size2 = _msize(hand2) / sizeof(hand2[0]);
    cout << endl;
    cout << "[----My hand----] " << endl;

    for (int i = 0; i < size; i++) {

        cout << i + 1 << ": ";
        show_pic(hand1, i);

    }
    cout << endl;

    cout << "[----Enemy hand----] " << endl;
    for (int i = 0; i < size2; i++) {

        cout << i + 1 << ": ";
        show_pic(hand2, i);
    }
}

//козырь


// удаление из руки и вкладывание в стол.
void delHandToTable(Card*& hand, Card*& table, int b) {
    int size = _msize(hand) / sizeof(hand[0]);
    int size2 = _msize(table) / sizeof(table[0]);

    Card* buf = new Card[size - 1];
    Card* buftable = new Card[size2 + 1];

    for (int j = 0; j < size2; j++) {
        buftable[j] = table[j];
    }
    for (int j = size2; j < size2 + 1; j++) {
        buftable[j] = hand[b];
    }


    for (int j = 0; j < b; j++) {
        if (b != 0) {
            buf[j] = hand[j];
        }

    }
    for (int j = b; j < size; j++) {

        buf[j] = hand[j + 1];


    }


    delete[]table;
    table = buftable;

    delete[]hand;
    hand = buf;
}

//Вывод стола
void show_table(Card*& table) {
    int size = _msize(table) / sizeof(table[0]);
    if (size > 0) {
        for (int i = 0; i < size; i++) {

            cout << i + 1 << ":";
            show_pic(table, i);
        }
    }
    else cout << "[__][__][__][__][__][__]" << endl;
}

//если нечем отбиваться и забираешь карты
void TakeAll(Card*& hand, Card*& table) {
    int size = _msize(hand) / sizeof(hand[0]);
    int size2 = _msize(table) / sizeof(table[0]);

    Card* buf = new Card[size + size2];
    for (int i = 0; i < size; i++) {
        buf[i] = hand[i];
    }

    for (int i = size; i < (size + size2); i++) {
        buf[i] = table[i - size];
    }
    delete[]table;
    delete[]hand;
    hand = buf;
    size2 = 0;
    table = new Card[size2];
}
//козырь
void trump_suit(Card*& deck, Card*& trump) {
    int size = _msize(deck) / sizeof(deck[0]);
    int size2 = _msize(trump) / sizeof(trump[0]);
    Card* buf = new Card[size2];
    for (int i = 0; i < size2; i++) {
        buf[i] = deck[size - 1];
    }
    delete[]trump;
    trump = buf;
    cout << '\t' << '\t' << "[" << trump[0].Suit << "]" << endl;
}
//void show_trump(Card*& deck, char trump) {
//    cout << trump << endl;
//}
//добор карт и удаление из колоды
//сделать добор если в колоде меньше,чем надо
void moreCards(Card*& deck, Card*& hand, Card*& trump) {

    int size = _msize(hand) / sizeof(hand[0]);
    int size2 = _msize(deck) / sizeof(deck[0]);
    int a = size;
    int b = size;
    int c = size2 - size;
    int d = size2;

    if (a < 6 && d>c) {
        Card* buf = new Card[6];
        Card* buf2 = new Card[c];
        for (int i = 0; i < a; i++) {
            buf[i] = hand[i];
        }
        for (int i = a; i < 6; i++) {
            buf[i] = deck[i - size];
        }

        for (int i = 0; i < c; i++) {
            buf2[i] = deck[b];
            b++;
        }
        delete[]hand;
        hand = buf;
        delete[]deck;
        deck = buf2;
        trump_suit(deck, trump);
    }

}



//если мой ход первый
void my_turn(Card*& deck, Card*& hand1, Card*& hand2, Card*& table, int a, int b, Card*& trump) {
    int size2 = _msize(table) / sizeof(table[0]);
    a = 0;
    cout << "Select card:";
    cin >> a;
    cout << endl;
    //прописать условия для выхода из игры
    if (a > 0) {
        b = a - 1;
        delHandToTable(hand1, table, b);

    }
    else {
        delete[]table;
        size2 = 0;
        table = new Card[size2];
        moreCards(deck, hand1, trump);
    }
}

//если отбиваюсь
// можно прописать условия жульничества
void my_answer(Card*& hand1, Card*& table, int a, int b) {

    a = 0;
    b = a - 1;
    cout << "Select card:";
    cin >> a;
    cout << endl;

    if (a > 0) {
        b = a - 1;
        delHandToTable(hand1, table, b);

    }

    else TakeAll(hand1, table);

}

//если ход противника
//прописать условия подкида
void enemy_turn(Card*& hand2, Card*& table) {
    int size = _msize(hand2) / sizeof(hand2[0]);
    int size2 = _msize(table) / sizeof(table[0]);
    int a = rand() % 1 + 6;
    int b = 0;
    if (size2 == 0) {
        delHandToTable(hand2, table, a - 1);
    }
    else if (size2 > 0) {

        for (int i = 0; i < size2; i++) {
            for (int j = 0; j < size; j++) {
                if (hand2[j].Rank > table[i].Rank) {
                    delHandToTable(hand2, table, j);
                    b = 1;
                    break;
                }
                if (b == 0) {
                    delete[]table;
                    size2 = 0;
                    table = new Card[size2];

                }

            }
        }
    }



}

//если противник отбивается
void enemy_answer(Card*& deck, Card*& hand2, Card*& hand1, Card*& table, int r, Card*& trump) {
    //эту функцию в цикл с его условиями для ответа на мою карту. ПРОВЕРИТЬ!
    //ее же на его подкид карты. тоже по условиям цикла.

    int sizedeck = _msize(deck) / sizeof(deck[0]);
    int size = _msize(hand2) / sizeof(hand2[0]);
    int size2 = _msize(table) / sizeof(table[0]);

    int a = 0;

    //если на столе не козырь
    if (table[size2 - 1].Suit != trump[0].Suit/*&& a==0*/) {
        for (int j = 0; j <= size; j++) {
            if (j != size) {
                //если сьют равен сьюту стола
                if (hand2[j].Suit == table[size2 - 1].Suit) {
                    //если ранк больше ранка руки
                    if (hand2[j].Rank > table[size2 - 1].Rank) {
                        delHandToTable(hand2, table, j);
                        /*show_table(table);*/
                        /*a = 1;*/
                        break;
                    }
                }
            }
            if (j == size) {
                for (int i = 0; i <= size; i++) {
                    if (i != size) {
                        if (hand2[i].Suit == trump[0].Suit /*&& i != size*/) {

                            delHandToTable(hand2, table, i);

                            break;

                        }
                    }
                    if (i == size) {
                        TakeAll(hand2, table);
                        r = 0;
                        moreCards(deck, hand1, trump);
                    }
                }
            }

        }
    }
    //если на столе козырь
    if (table[size2 - 1].Suit == trump[0].Suit && a == 0) {

        for (int k = 0; k <= size; k++) {
            //если на руке козырь
            if (k != size) {
                if (hand2[k].Suit == trump[0].Suit) {
                    //если козырь старше
                    if (k != size) {
                        if (hand2[k].Rank > table[size2 - 1].Rank) {
                            delHandToTable(hand2, table, k);
                            /*show_table(table);*/
                            a = 1;
                            break;
                        }
                    }
                    /*else {
                        TakeAll(hand2, table);
                        r = 0;
                        moreCards(deck, hand1, trump);
                    }*/
                }
            }
            else {
                TakeAll(hand2, table);
                r = 0;
                moreCards(deck, hand1, trump);
            }
        }
    }
    //если на столе не козырь,но карт подходящих нет. побить козырем
    /* if (table[size2 - 1].Suit != trump && a == 0) {
         int counter = 1;
         for (int k = 0; k <= size; k++) {
             counter++;

             if (hand2[k].Suit == trump&&k!=size) {

                     delHandToTable(hand2, table, k);

                     break;

             }
             else
                 TakeAll(hand2, table);
             r = 0;
             moreCards(deck, hand1);

         }
     }*/
     /* else if (a == 0) {
          TakeAll(hand2, table);
          r = 0;
          moreCards(deck, hand1);

      }*/
}








//функция игры
//реализовать принцип игры с условиями(смотреть на блок схему)
//реализовать последовательность ходов булевой переменной 
void startGame(Card*& deck) {
    deck_init(deck);
    shuffleDeck(deck);

}


int main() {
    srand(time(NULL));
    Card* trump = new Card[1];
    int a = 0; //номер карты для ввода
    int b = 0; //индекс карт

    Card* deck = new Card[36];
    Card* my_hand = new Card[6];
    Card* enemy_hand = new Card[6];

    Card* table = new Card[0];


    /*int decksize = _msize(deck) / sizeof(deck[0]);
    int myhandsize = _msize(my_hand) / sizeof(my_hand[0]);
    int enemysize = _msize(enemy_hand) / sizeof(enemy_hand[0]);*/
    /*int tablesize = _msize(table) / sizeof(table[0]);*/

    deck_init(deck);
    shuffleDeck(deck);
    /*showDeck(deck);*/
    /*cout << endl;*/

    /*cout << "[----Trump Card----]" << endl;
    cout<<trump_suit(deck)<<endl;*/
    takeCard(deck, my_hand, enemy_hand);

    /*showHand(my_hand, enemy_hand);*/
    delFromDeck(deck);

    /*my_turn(my_hand,table,a,b);
    cout << "Table" << endl;
    show_table(table);
    cout << endl;

    enemy_answer(deck, enemy_hand, table);
    cout << endl;

    showHand(my_hand, enemy_hand);
    cout << endl;*/
    /*enemy_turn(enemy_hand, table);
    show_table(table);
    my_answer(my_hand, table, a, b);
    show_table(table);*/

    bool flag = true;
    while (flag = true) {
        for (int i = 1; i <= 12; i++) {
            cout << '\t' << "[----Trump Card----]" << endl;
            trump_suit(deck, trump);

            showHand(my_hand, enemy_hand);
            cout << endl;
            cout << "[----Table----]" << endl;
            show_table(table);
            cout << endl;
            my_turn(deck, my_hand, enemy_hand, table, a, b, trump);
            /*cout << "Table" << endl;
            show_table(table);
            cout << endl;*/
            system("cls");
            /*system("pause");*/
            if (i > 0) {

                enemy_answer(deck, enemy_hand, my_hand, table, i, trump);
                cout << endl;
                if (i > 0) {
                    cout << '\t' << "[----Trump Card----]" << endl;
                    trump_suit(deck, trump);
                    showHand(my_hand, enemy_hand);
                    cout << endl;
                    cout << "[----Table----]" << endl;
                    show_table(table);
                    cout << endl;

                }
                else {
                    i = 0;
                    moreCards(deck, my_hand, trump);
                    cout << endl;
                }
            }

            else {
                moreCards(deck, my_hand, trump);
                moreCards(deck, enemy_hand, trump);
                flag = false;
                break;
            }

            system("cls");

        }



    }
}
