/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 10:51:19
 */
#include "wall.h"

void Wall::InitWall(){
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            if(i == 0 || j == 0 || i == ROW - 1 || j == COL - 1){
                gameArray[i][j] = '*';
            }
            else{
                gameArray[i][j] = ' ';
            }
        }
    }
}

void Wall::DrawWall(){
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            cout << gameArray[i][j] << " ";
        }
        if(i == 9){
            cout << "created by sanjay";
        }
        if(i == 10){
            cout << "a: left";
        }
        if(i == 11){
            cout << "r: right";
        }
        if(i == 12){
            cout << "w: up";
        }
        if(i == 13){
            cout << "s: down";
        }
        cout << endl;
    }
}


void Wall::set_wall(int x, int y, char c){
    gameArray[x][y] = c;
}


char Wall::get_wall(int x, int y){
    return gameArray[x][y];
}