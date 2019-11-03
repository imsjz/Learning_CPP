/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 11:19:27
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "wall.h"
#include "snake.h"

using namespace std;


int main(int argc, char *argv[]){
    Wall wall;
    wall.InitWall();

    Snake snake(wall);
    snake.InitSnake();
    

    // wall.set_wall(5, 4, '=');
    // wall.set_wall(5, 5, '=');
    // wall.set_wall(5, 6, '@');
    wall.DrawWall();

    return 0;
}
