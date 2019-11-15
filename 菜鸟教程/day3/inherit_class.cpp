#include <iostream>

using namespace std;

class Shape{

    public:
        void setWidth(double wid){
            width = wid;
        }
        void setHeight(double hei){
            height = hei;
        }
    protected:
        double width;
        double height;
};

class Ractangle : public Shape{
    public:
        double getArea(){
            return width * height;
        }
};

int main(){
    Ractangle rect;

    rect.setWidth(20);
    rect.setHeight(32.0);

    cout << "Total area: " << rect.getArea() << endl;

    return 0;
}
