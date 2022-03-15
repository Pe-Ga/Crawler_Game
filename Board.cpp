//
// Created by gamsj on 04.03.2022.
//

#include "Board.h"
#include <iostream>
#include <vector>
#include "Player.h"
#include<time.h>

using namespace std;

Board::Board()
{

    newPlayer.set_health_points(5);
    newPlayer.set_relic_point(0);
    newPlayer.set_pos_x(0);
    newPlayer.set_pos_y(0);
    level = 1;
    create_board();


}


unsigned char Board::generator()
{

    unsigned char field[10] = {EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,EMPTY_FIELD,
                               TRAP,TRAP,TRAP,TRAP, WELL, RELIC};

    switch(level)
    {
        case 1:
            break;
        case 2:
            field[0] = TRAP;
            break;
        case 3:
            field[8] = EMPTY_FIELD;
            break;
        case 4:
            field[8] = EMPTY_FIELD;
            field[0] = TRAP;
            break;
        default:
            field[8] = EMPTY_FIELD;
            field[0] = TRAP;
            field[1] = TRAP;
            break;

    }



    int random_index = rand() % 10;

    return field[random_index];


}


void Board::create_board() // creates Board, 2d Vector
{

    bool relic_exists = false;

    srand(time(0));
    vector<vector<unsigned char>> newBoard;                     // 2d Vector

    for(int i = 0; i < 5; i++)
    {

        newBoard.push_back(vector<unsigned char>{});

        for(int j = 0; j < 5; j++)
        {
            unsigned char test = generator();

            relic_exists = test == RELIC ? true : relic_exists;

            newBoard[i].push_back(test);
        }
    }

    if(relic_exists)
    {
        this->board = newBoard;
    }
    else
    {
        create_board();
    }

    /*
    vector<vector<unsigned char>> newBoard
            {
                    {RELIC, '#','#','#','#'},
                    {'#','#','#','#','#'},
                    {'#','#','#','#','#'},
                    {'#','#','#','#','#'},
                    {'#','#','#','#','#'}

            };

    this->board = newBoard;
    */
}

int Board::relic_total()  // Counts existing relics on board
{
    int relic_cnt = 0;

    for(int y = 0; y < board.size(); y++)
    {
        for(int x = 0; x <board.size(); x++)
        {
           // relic_cnt = (board[y][x] == RELIC) ? relic_cnt+1 : relic_cnt;
            if(board[y][x] == RELIC)
                relic_cnt++;
        }
    }

    return relic_cnt;
}

bool Board::game_won()
{
    if(relic_total() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool Board::game_lost()
{
    if(newPlayer.get_health_points() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


void Board::print_board() // Prints board P = Player position
{
    for(int y = 0; y < board.size(); y++)
    {
        for(int x = 0; x < board[y].size(); x++)
        {
            if(y == newPlayer.get_pos_y() && x == newPlayer.get_pos_x())
            {

                cout << 'P' << " ";
            }
            else
            {
                cout << board[y][x] << " ";
            }

        }
        cout << endl;
    }

//    std::cout << "X: " << newPlayer.get_pos_x() << std::endl;
//    std::cout << "Y: " << newPlayer.get_pos_y() << std::endl;

}

unsigned char Board::get_current_fieldtype() // Evaluates Type of Field Trap, Well, relic, empty field
{
   return board[newPlayer.get_pos_y()][newPlayer.get_pos_x()];
}

void Board::field_action()
{
    switch(get_current_fieldtype())
    {
        case TRAP:
            newPlayer.loose_hp();
            break;
        case WELL:
            newPlayer.gain_hp();
            break;
        case RELIC:
            newPlayer.add_relic_point();
            break;
        case EMPTY_FIELD:
            break;
    }

    board[newPlayer.get_pos_y()][newPlayer.get_pos_x()] = '#';
}

void Board::move(char input) // input char a w s d
{

    int x = newPlayer.get_pos_x();
    int y = newPlayer.get_pos_y();

        if(input != 'a' && input !='w' && input !='s' && input !='d')
        {
            std::cout << "Invalid input, try again";
        }
        else
        {
            switch (input)
            {
                case 'a':
                    if (x < 1)
                    {
                        std::cout << " move out of bound, try again" << endl;
                    }
                    else
                    {
                        newPlayer.set_pos_x(--x);
                        std::cout << "moved left";
                        std::cout << endl;
                    }
                    break;
                case 'w':
                    if (y < 1)
                    {
                        std::cout << "move out of bound, try again" << endl;
                    }
                    else
                    {
                        newPlayer.set_pos_y(--y);
                        std::cout << "moved up";
                        std::cout << endl;
                    }
                    break;
                case 's':
                    if (y >= 4)
                    {
                        std::cout << "move out of bound, try again" << endl;
                    }
                    else
                    {
                        newPlayer.set_pos_y(++y);
                        std::cout << "moved down";
                        std::cout << endl;
                    }
                    break;
                case 'd':
                    if (x >= 4)
                    {
                        std::cout << "move out of bound, try again" << endl;
                    }
                    else
                    {
                        newPlayer.set_pos_x(++x);
                        std::cout << "moved right";
                        std::cout << endl;
                    }
                    break;
            }
        }
}

void Board::game()
{



    std::cout << " LEVEL " << level <<std::endl;
    std::cout << endl;

    bool game_over = false;

    while(!game_over)
    {
        char input;


        field_action();
        std::cout << "HP: " << newPlayer.get_health_points() << std::endl;
        print_board();

        if(game_won())
        {
            game_over = true;
            std::cout << "Game won, hurray" << std::endl;
            std::cout << "Get ready for the next round";
            level++;
            newPlayer.set_pos_x(0);
            newPlayer.set_pos_y(0);
            create_board();
            game();

        }
        else if(game_lost())
        {
            game_over = true;
            std::cout << "Game lost, what a pity";
        }
        else
        {
            std::cout << "Move: " << endl;
            std::cin >> input;
            move(input);
        }

    }

}

 void Board::manual()
{
    std::cout << "====OASENCRAWLER==== "  << std::endl;
    std::cout << "====Controls==== "  << std::endl;
    std::cout << "Move left(a) "  << std::endl;
    std::cout << "Move right(d) "  << std::endl;
    std::cout << "Move up(w) "  << std::endl;
    std::cout << "Move down(s) "  << std::endl;

    std::cout << "====Legend===="  << std::endl;
    std::cout << "Empty field: "<< char(EMPTY_FIELD)  << std::endl;
    std::cout << "Well: gives +1 HP: "<< char(WELL) << std::endl;
    std::cout << "Trap: damage -1 HP:  "<< char(TRAP)  << std::endl;
    std::cout << "Relic: gather all relics to win:  "<< char(RELIC)  << std::endl;

    std::cout << "====Good Luck===="  << std::endl;
}


