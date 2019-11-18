/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-03 11:19:27
 */
#include "include_files.h"

using namespace std;

int main(int argc, char *argv[])
{

    bool is_dead = false;
    char pre_key = NULL;

    srand((unsigned int)time(NULL));

    Wall wall;
    wall.InitWall();

    Food food(wall);
    food.SetFood();

    Snake snake(wall, food);
    snake.InitSnake();

    // snake.DeletePoint();

    // wall.set_wall(5, 4, '=');
    // wall.set_wall(5, 5, '=');
    // wall.set_wall(5, 6, '@');
    wall.DrawWall();

    while (!is_dead)
    {
        char key = getchar();

        //判断 如果是第一次按了左键 不能激活游戏
        if (pre_key == NULL && key == snake.LEFT)
        {
            continue;
        }
        do
        {
            if (key == snake.LEFT || key == snake.RIGHT || key == snake.UP || key == snake.DOWN)
            {
                //判断本次按键和上次是否有冲突
                if ((key == snake.LEFT && pre_key == snake.RIGHT) ||
                    (key == snake.RIGHT && pre_key == snake.LEFT) ||
                    (key == snake.UP && pre_key == snake.DOWN) ||
                    (key == snake.DOWN && pre_key == snake.UP))
                {
                    key = pre_key;
                }
                else
                {
                    pre_key = key; //不是冲突按键, 更新按键
                }

                if (snake.Move(key) == true)
                {
                    //移动成功代码
                    system("clear");
                    wall.DrawWall();
                    sleep(1);
                    // usleep(5 * 1000);
                    // usleep(5 * 1000);
                    // usleep(5 * 1000);
                }
                else
                {
                    is_dead = true;
                    break;
                }
            }
            else
            {
                key = pre_key;
            }

        } while (!kbhit());
        //接受用户输入
    }

    return 0;
}
