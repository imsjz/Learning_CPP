/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 10:24:47
 */
#ifndef __HERO_H__
#define __HERO_H__
#include <iostream>
#include "weapon.h"
#include "monster.h"

using namespace std;

class Monster;

class Hero{

public:

    Hero();

    string name_;
    int attack_;
    int defence_;
    int hp_;
    Weapon *weapon_; //武器

    void EquipWeapon(Weapon *weapon);

    void Attack(Monster *monster);

};




#endif