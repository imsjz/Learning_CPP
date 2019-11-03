/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 18:54:08
 */
#include "snake.h"

Snake::Snake(Wall &wall):wall_(wall){
    p_head_ = NULL;
}

void Snake::DestroyPoint(){
    Point *p_current = p_head_;
    while(p_head_){
        p_current = p_head_->next;
        delete p_head_; //直接delete 不用析构函数
        p_head_ = p_current;
    }
}

void Snake::AddPoint(int x, int y){
    //创建新节点
    Point *new_point = new Point;
    new_point->x = x;
    new_point->y = y;
    new_point->next = NULL;

    //如果原来的头不为空, 把原来的头的符号@改为身子"="
    if(p_head_ != NULL){
        wall_.set_wall(p_head_->x, p_head_->y, '=');
    }
    new_point->next = p_head_;
    p_head_ = new_point;
    wall_.set_wall(p_head_->x, p_head_->y, '@');

    
}

void Snake::InitSnake(){
    //把之前的对象摧毁
    DestroyPoint();
    //
    AddPoint(5, 3);
    AddPoint(5, 4);
    AddPoint(5, 5);

}