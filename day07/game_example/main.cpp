/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-16 20:20:46
 */
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include "weapon.h"
#include "knife.h"
#include "dragon_sword.h"
#include "hero.h"
#include "monster.h"

using namespace std;

void Play(){
    //创建英雄和怪物
    Hero *hero = new Hero;
    Monster *monster = new Monster;

    //创建武器
    Knife *knife = new Knife;
    DragonSword *dragon_sword = new DragonSword;

    cout << "请选择武器: " << endl;
    cout << "1. 赤手空拳" << endl;
    cout << "2. 小刀" << endl;
    cout << "3. 屠龙宝刀" << endl;

    int op_input;
    cin >> op_input;
    switch(op_input){
    case 1:
        cout << "你还是太年轻!" << endl;
        break;
    case 2:
        hero->EquipWeapon(knife);
        break;
    case 3:
        hero->EquipWeapon(dragon_sword);
        break;
    default:
        cout << "请输入0到3之间的数字" << endl;
        break;
    }

    //缓冲区内还有一个回车,吃掉
    getchar(); //gets不安全, gets不吃换行符, 但是puts却会额外增加换行符, 这两个不用

    int round = 1; //回合
    while(true){

        getchar(); //接受一个输入, 避免一下子进行
        system("clear");

        cout << "===========当前第" << round << "回合开始=========" << endl;

        //玩家攻击怪物
        hero->Attack(monster);
        if(monster->hp_ <= 0){
            cout << "怪物" << monster->name_ << "已挂, 顺利通关" << endl;
            break;
        }

        //怪物攻击玩家
        monster->Attack(hero);
        if(hero->hp_ <= 0){
            cout << "英雄" << hero->name_ << "已挂, 游戏结束" << endl;
            break;
        }

        cout << "英雄" << hero->name_ << "剩余血量: " << hero->hp_ << endl;
        cout << "怪物" << monster->name_ << "剩余血量: " << monster->hp_ << endl;

        round++;
    }

    delete hero;
    delete monster;
    delete knife;
    delete dragon_sword;
}

int main(int argc, char const *argv[])
{
    /* code */
    Play();
    return 0;
}

