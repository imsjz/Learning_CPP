#include <iostream>
using namespace std;

class Box{
    public:
        double getArea(void){
            return width * height;
        }
        void setWidth(double wid){
            width = wid;
        }
        void setHeight(double hei){
            height = hei;
        }
        Box operator+(const Box& b){
            Box box;
            box.width = this->width + b.width;
            box.height = this->height + b.height;
            return box;
        }

    private:
        double width;
        double height;
};

int main(){
    Box box1;
    Box box2;
    Box box3;

    box1.setWidth(2.0);
    box1.setHeight(3.0);
    cout << "Area of box1: " << box1.getArea() << endl;

    box2.setWidth(3.3);
    box2.setHeight(4.3);
    cout << "Area of box2: " << box2.getArea() << endl;

    box3 = box1 + box2;

    cout << "Area of box3: " << box3.getArea() << endl;

    return 0;
}
