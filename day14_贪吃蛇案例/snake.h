/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 18:18:44
 */
#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <iostream>
#include "wall.h"
using namespace std;

class Snake{
public:

    Snake(Wall &wall);

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

    Point *p_head_;
    Wall &wall_;


};


#endif