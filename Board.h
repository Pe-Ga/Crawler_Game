//
// Created by gamsj on 04.03.2022.
//

#ifndef UNTITLED4_BOARD_H

#define UNTITLED4_BOARD_H
#include <iostream>
#include <vector>
#include "Player.h"

#define EMPTY_FIELD '#'
#define TRAP 207
#define WELL 127
#define RELIC 190

using namespace std;

class Board
{

public:

    Board();

    void game();
    static void manual();

private:

    vector<vector<unsigned char>> board;
    Player newPlayer;
    int level;

    unsigned char get_current_fieldtype();
    unsigned char generator();

    void move(char input);
    void print_board();
    void create_board();
    void field_action();

    bool game_won();
    bool game_lost();

    int relic_total();

};

#endif //UNTITLED4_BOARD_H
