//
// Created by gamsj on 02.03.2022.
//
#include <iostream>
#include "Player.h"

Player::Player()           // Implementierung Standardkonstruktor
{
    health_points = 5;
    relic_points  = 0;
    pos_x         = 0;
    pos_y         = 0;
}


// Setter und Getter

void Player::set_relic_point(int relic_points)
{
    this->relic_points = relic_points;
}

int Player::get_relic_points()
{
    return relic_points;
}


void Player::set_health_points(int health_points)
{
    this->health_points = health_points;
}

int Player::get_health_points()
{
    return health_points;
}

void Player::set_pos_x(int pos_x)
{
    this->pos_x = pos_x;
}

int Player::get_pos_x()
{
    return pos_x;
}

void Player::set_pos_y(int pos_y)
{
    this->pos_y = pos_y;
}

int Player::get_pos_y()
{
    return pos_y;
}

void Player::loose_hp()
{

    set_health_points(get_health_points() -1);
}

void Player::gain_hp()
{
    set_health_points(get_health_points() +1);
}

void Player::add_relic_point()
{
    set_relic_point(get_relic_points() +1);
}






