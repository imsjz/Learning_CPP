/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 18:18:44
 */
#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;

class Snake{
public:

    Snake(Wall &wall, Food &food);
    enum MoveType{
        UP = 'w',
        DOWN = 's',
        LEFT = 'a',
        RIGHT = 'd'
    };

    //节点
    struct Point{
        //数据域
        int x;
        int y;
        //指针域
        Point *next;
    };

    //初始化
    void InitSnake();

    //销毁节点
    void DestroyPoint();

    //添加节点
    void AddPoint(int x, int y);

    //删除节点
    void DeletePoint();

    //移动蛇操作
    //返回值代表 移动是否成功
    bool Move(char key);

    Point *p_head_;
    Wall &wall_;
    Food &m_food_;
    bool is_circle_;


};


#endif