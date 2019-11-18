/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 09:48:19
 */
#ifndef __KNIFE_H__
#define __KNIFE_H__
#include "weapon.h"

class Knife: public Weapon{
public:

    Knife();

    //获取基础伤害
    virtual int GetBaseDamage();

    //获取吸血
    virtual int GetSuckBlood();

    //获取是否定身
    virtual bool GetHold();

    //获取是否暴击
    virtual bool GetCrit();


};



#endif