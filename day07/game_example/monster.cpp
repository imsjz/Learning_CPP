/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 12:26:10
 */
#include "monster.h"

Monster::Monster(){
    this->hp_ = 300;

    this->attack_ = 70;

    this->defence_ = 40;

    this->hold_ = false;

    this->name_ = "比克大魔王";
}

void Monster::Attack(Hero *hero){

    if(this->hold_){
        cout << "怪物 " << this->name_ << "被定身了, 本回合无法攻击" << endl;
        return;
    }
    //计算攻击伤害
    int damage = ((this->attack_ - hero->defence_) > 0) ? (this->attack_ - hero->defence_) : 1;

    hero->hp_ -= damage;

    cout << "怪物: " << this->name_ << " 攻击了英雄: " << hero->name_ << ", 造成了 " << damage << " 的伤害." << endl;

}