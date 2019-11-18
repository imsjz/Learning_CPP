#include <iostream>

using namespace std;

class Box{

public:
    double length;
    double width;
    double height;
    
    //declare member function
    //but don't realize them
    double getVolume(void);
    void setLength(double len);
    void setWidth(double wid);
    void setHeight(double hei);
};

//define member function
double Box::getVolume(){
    return length * width * height;
}

void Box::setLength(double len){
    length = len;
}

void Box::setWidth(double wid){
    width = wid;
}

void Box::setHeight(double hei){
    height = hei;
}

int main(){
    Box box1;
    Box box2;
    double volume = 0.0;

    box1.setLength(6.0);
    box1.setWidth(7.0);
    box1.setHeight(5.0);

    volume = box1.getVolume();
    cout << "box1's volume: " << volume << endl;

    return 0;
}


