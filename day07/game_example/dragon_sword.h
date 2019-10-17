/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 09:57:40
 */

#ifndef __DRAGON_SWORD__
#define __DRAGON_SWORD__

#include "weapon.h"

class DragonSword: public Weapon{
public:

    DragonSword();

    //获取基础伤害
    virtual int GetBaseDamage();

    //获取吸血
    virtual int GetSuckBlood();

    //获取是否定身
    virtual bool GetHold();

    //获取是否暴击
    virtual bool GetCrit();

    //暴击率 吸血率  定身率
    int suck_rate_;
    int hold_rate_;
    int crit_rate_;

    //是否触发
    bool IsTrigger(int rate);

};


#endif



