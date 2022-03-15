#include "Player.h"
#include "Board.h"

using namespace std;

int main()
{

    Board newBoard;
    newBoard.manual();
    newBoard.game();

    return 0;
}

/*
    Player player1;
    std::cout << "\nLP: " << player1.get_health_points() << std::endl;
    player1.loose_hp();
    std::cout << "\nLP: " << player1.get_health_points() << std::endl;
    player1.loose_hp();
    player1.loose_hp();
    std::cout << "\nLP: " << player1.get_health_points() << std::endl;
*/

/*
   board1.print_board();
   board1.move('a');
   board1.print_board();
   board1.move('a');
   board1.print_board();

   std::cin >> input;
*/


/*

    while(1)
    {
        board1.print_board();
        std::cin >> input;
        board1.move(input);

    }
*/

/*

    player1.move('s');

    std::cout << "Relic Points: " << player1.get_relic_points() << std::endl;
    std::cout << "X: " << player1.get_pos_x() << std::endl;
    std::cout << "Y: " << player1.get_pos_y() << std::endl;

*/


