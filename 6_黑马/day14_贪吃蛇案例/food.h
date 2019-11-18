/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-04 13:58:52
 */
#ifndef __FOOD_H__
#define __FOOD_H__
#include <iostream>
#include "wall.h"
using namespace std;


class Food{
public:
    Food(Wall &wall);
    
    //设置食物
    void SetFood();

    int m_food_x_;
    int m_food_y_;

    Wall &m_wall_;

};

#endif