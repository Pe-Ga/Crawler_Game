//
// Created by gamsj on 02.03.2022.
//

#ifndef UNTITLED4_PLAYER_H
#define UNTITLED4_PLAYER_H

class Player
{

public:

    Player(); // Standardkonstruktor

    void set_relic_point(int relic_points); // relic point ist private -> setter
    int get_relic_points();
    void add_relic_point();

    void set_health_points(int health_points);
    int get_health_points();

    void loose_hp();
    void gain_hp();

    void set_pos_x(int pos_x);
    int get_pos_x();
    void set_pos_y(int pos_y);
    int get_pos_y();

private:

    int health_points;
    int relic_points;
    int pos_x;
    int pos_y;

};

#endif //UNTITLED4_PLAYER_H
