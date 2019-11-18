/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 13:44:35
 */
#include <iostream>

using namespace std;

class Cube{
public:

    Cube(int l, int w, int h):m_L(l), m_W(w), m_H(h){}

    //设置长
    int getLong() const{
        return m_L;
    }
    void setLong(int l){
        m_L = l;
    }
    int getWidth(){
        return m_W;
    }
    void setWidth(int w){
        m_W = w;
    }
    int getHeight(){
        return m_H;
    }
    void setHeight(int h){
        m_H = h;
    }

    //求立方体面积
    void getCubeS(){
        int s = 2*m_L*m_W + 2 * m_L * m_H + 2 * m_W * m_H;
        cout << "立方体面积: " << s << endl;
    }

    //求立方体体积
    void getCubeV(){
        int v = m_L * m_W * m_H;
        cout << "立方体体积： " << v << endl;
    }

private:
    int m_L;
    int m_W;
    int m_H;
};

bool compareCube(Cube &cub1, Cube &cub2){
    if(cub1.getLong() == cub2.getLong() && cub1.getWidth() == cub2.getWidth() && cub1.getHeight() == cub2.getHeight())
        return true;
    else
        return false;
}

void func(const Cube &c){
    c.getLong();
}

void test01(){

    Cube c1(10, 10, 10);
    c1.getCubeS();
    c1.getCubeV();

    Cube c2(10, 10, 10);
    bool ret = compareCube(c1, c2);
    cout << ret << endl;

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
