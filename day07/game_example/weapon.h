/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-16 20:20:59
 */
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

using namespace std;


class Weapon{

public:
    //获取基础伤害
    virtual int GetBaseDamage() = 0;

    //获取吸血
    virtual int GetSuckBlood() = 0;

    //获取是否定身
    virtual bool GetHold() = 0;

    //获取是否暴击
    virtual bool GetCrit() = 0;

    int base_damage_;
    string weapon_name_;
};




#endif