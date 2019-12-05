/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-05 19:42:25
 */
#include "prototype.cpp"

class MainForm
{
    ISplitter *prototype; //原型对象

public:
    MainForm(ISplitter *prototype)
    {
        this->prototype = prototype;
    }

    void Button1_Click()
    {

        ISplitter *splitter =
            prototype->clone(); //克隆原型

        splitter->split();
    }
};
