/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 10:36:53
 */
#ifndef __WALL_H__
#define __WALL_H__

#include <iostream>
using namespace std;


class Wall{
public:
    enum ShapeType{ //枚举
        ROW = 26,
        COL = 26
    };

    //初始化墙壁
    void InitWall();

    //显示墙壁
    void DrawWall();

    //根据索引设置 二维数组的内容
    void set_wall(int x, int y, char c);

    //根据索引获取二位数组的内容
    char get_wall(int x, int y);
    


private:
    char gameArray[ROW][COL];
};



#endif