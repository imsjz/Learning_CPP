#include <iostream>

using namespace std;

class Box{
public:
    double getWidth(void);
    double getHeight(void);
    void setWidth(double wid);
    void setHeight(double hei);

private:
    double width;
    double height;
};

//class member method realize
double Box::getWidth(void){
    return width;
}

void Box::setWidth(double wid){
    width = wid;
}

double Box::getHeight(void){
    return height;
}

void Box::setHeight(double hei){
    height = hei;
}

int main(){
    Box box;

    //使用成员函数设置
    box.setWidth(10);
    box.setHeight(20.0);
    cout << "Width of box: " << box.getWidth() << endl;
    cout << "Height of box: " << box.getHeight() << endl;

    return 0;
}
