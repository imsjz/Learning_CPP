/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 18:54:08
 */
#include "snake.h"

Snake::Snake(Wall &wall, Food &food) : wall_(wall), m_food_(food)
{
    p_head_ = NULL;
    is_circle_ = false;
}

void Snake::DestroyPoint()
{
    Point *p_current = p_head_;
    while (p_head_)
    {
        p_current = p_head_->next;
        delete p_head_; //直接delete 不用析构函数
        p_head_ = p_current;
    }
}

void Snake::AddPoint(int x, int y)
{
    //创建新节点
    Point *new_point = new Point;
    new_point->x = x;
    new_point->y = y;
    new_point->next = NULL;

    //如果原来的头不为空, 把原来的头的符号@改为身子"="
    if (p_head_ != NULL)
    {
        wall_.set_wall(p_head_->x, p_head_->y, '=');
    }
    new_point->next = p_head_;
    p_head_ = new_point;
    wall_.set_wall(p_head_->x, p_head_->y, '@');
}

void Snake::InitSnake()
{
    //把之前的对象摧毁
    DestroyPoint();
    //
    AddPoint(5, 3);
    AddPoint(5, 4);
    AddPoint(5, 5);
}

void Snake::DeletePoint()
{

    //两个节点以上 才删除
    if (p_head_ == NULL || p_head_->next == NULL)
    {
        return;
    }
    Point *p_current = p_head_->next;
    Point *p_pre = p_head_;
    while (p_current->next != NULL)
    {
        p_pre = p_current;
        p_current = p_current->next;
    }
    //设置墙为空
    wall_.set_wall(p_current->x, p_current->y, ' ');
    //删除蛇身
    p_pre->next = NULL;
    delete p_current;
}

bool Snake::Move(char key)
{

    int x = p_head_->x;
    int y = p_head_->y;

    switch (key)
    {
    case UP:
        --x;
        break;
    case DOWN:
        ++x;
        break;
    case LEFT:
        --y;
        break;
    case RIGHT:
        ++y;
        break;
    }

    //判断下一步到尾巴的时候
    Point *p_current = p_head_->next;
    Point *p_pre = p_head_;
    while (p_current->next != NULL)
    {
        p_pre = p_current;
        p_current = p_current->next;
    }
    if (p_current->x == x && p_current->y == y)
    {
        //碰到尾巴,循环
        is_circle_ = true;
    }
    else
    {
        //判断用户到达位置是否成功
        if (wall_.get_wall(x, y) == '*' || wall_.get_wall(x, y) == '=')
        {
            cout << "GAME OVER!!!" << endl;
            return false;
        }
    }

    //移动成功 分两种
    //吃到食物 未吃到食物
    if (wall_.get_wall(x, y) == '#')
    {
        AddPoint(x, y);

        //重新设置食物
        m_food_.SetFood();
    }
    //未吃到食物
    else
    {
        
        AddPoint(x, y);
        DeletePoint();
        if(is_circle_ == true){
            wall_.set_wall(x, y, '@');
        }
    }

    return true;
}