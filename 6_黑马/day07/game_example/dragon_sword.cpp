/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 09:50:27
 */
#include "dragon_sword.h"

DragonSword::DragonSword()
{
    this->base_damage_ = 20;
    this->weapon_name_ = "屠龙宝刀";
    this->crit_rate_ = 20;
    this->suck_rate_ = 30;
    this->hold_rate_ = 40;
}

int DragonSword::GetBaseDamage()
{
    return this->base_damage_;
}

//获取吸血
int DragonSword::GetSuckBlood(){
    if(IsTrigger(suck_rate_)){
        return this->base_damage_ * 0.5; //按照武器基础伤害一半吸血
    }
    return 0;
}

//获取是否定身
bool DragonSword::GetHold(){
    if(IsTrigger(hold_rate_)){
        return true;
    }
    return false;
}

//获取是否暴击
bool DragonSword::GetCrit(){
    if(IsTrigger(crit_rate_)){
        return true;
    }
    return false;
}


bool DragonSword::IsTrigger(int rate){


    //在1-100中随机选取1个数字,如果 传入的rate大于这个数字,则触发
    int trigger_number = rand() % 100 + 1;
    if(rate > trigger_number){
        return true;
    }
    return false;
}