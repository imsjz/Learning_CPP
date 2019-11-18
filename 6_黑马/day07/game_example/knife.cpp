/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 09:50:27
 */
#include "knife.h"

Knife::Knife()
{
    this->base_damage_ = 10;
    this->weapon_name_ = "小刀";
}

int Knife::GetBaseDamage()
{
    return this->base_damage_;
}

//获取吸血
int Knife::GetSuckBlood(){
    return 0;
}

//获取是否定身
bool Knife::GetHold(){
    return false;
}

//获取是否暴击
bool Knife::GetCrit(){
    return false;
}