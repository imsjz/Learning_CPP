/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 10:34:49
 */
#include "hero.h"


Hero::Hero(){

    this->hp_ = 500;
    this->attack_ = 50;

    this->defence_ = 50;

    this->name_ = "刘法师";
    this->weapon_ = NULL;

}

//装备武器
void Hero::EquipWeapon(Weapon *weapon){
    this->weapon_ = weapon;
    cout << "英雄: " << this->name_ << " 装备了武器 << " << this->weapon_->weapon_name_ << " >> " << endl;
}

//攻击
void Hero::Attack(Monster *monster){

    int damage = 0;
    int add_hp = 0;
    bool is_hold = false;
    bool is_crit = false;

    if(this->weapon_ == NULL){ //武器为空, 没有加成
        damage = this->attack_;
    }
    else{
        //基础伤害
        damage = this->attack_ + this->weapon_->GetBaseDamage();
        //吸血
        add_hp = this->weapon_->GetSuckBlood();
        //定身
        is_hold = this->weapon_->GetHold();
        //暴击
        is_crit = this->weapon_->GetCrit();
    }
    if(is_crit){
        damage = damage * 2;
        cout << "英雄的武器触发了暴击效果,怪物受到了双倍的伤害, 伤害值: " << damage << endl;
    }

    if(is_hold){
        cout << "英雄的武器触发了定身效果, 怪物停止攻击一回合 " << endl;
    }

    if(add_hp > 0){
        cout << "英雄的武器触发了吸血效果, 英雄增加血量为 " << add_hp << endl;
        
    }

    //设置怪物定身
    monster->hold_ = is_hold;

    //计算真实伤害
    int true_damage = ((damage - monster->defence_) > 0) ? (damage - monster->defence_) : 1;
    monster->hp_ -= true_damage;
    this->hp_ += add_hp;
    cout << "英雄: " << this->name_ << " 攻击了怪物: " << monster->name_ << ", 造成了 " << true_damage << " 的伤害." << endl;
}