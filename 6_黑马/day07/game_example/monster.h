/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 12:22:13
 */
#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <iostream>
#include "weapon.h"
#include "hero.h"

class Hero;

class Monster{
public:
    Monster();

    string name_;
    int hp_;
    int attack_;
    int defence_;
    bool hold_;

    void Attack(Hero *hero);

};


#endif