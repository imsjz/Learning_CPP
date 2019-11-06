/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-04 14:13:58
 */
#include "food.h"

Food::Food(Wall &wall) : m_wall_(wall)
{
}

void Food::SetFood()
{

    while (true)
    {
        m_food_x_ = rand() % (Wall::ROW - 2) + 1;
        m_food_y_ = rand() % (Wall::COL - 2) + 1;

        //如果随机的位置是蛇头或者蛇身, 则重新生成随机数
        if (m_wall_.get_wall(m_food_x_, m_food_y_) == ' ')
        {
            m_wall_.set_wall(m_food_x_, m_food_y_, '#');
            break;
        }
    }
}
