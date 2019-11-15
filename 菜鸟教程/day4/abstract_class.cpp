#include <iostream>
using namespace std;

class Shape{
    protected:
        int width, height;
    public:
        virtual int getArea() = 0;
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }
};

class Rectangle : public Shape{
    public:
        int getArea(){
            cout << "Rectangle class area: " << endl;
            return width * height;
        }
};

class Triangle :public Shape{
    public:
        int getArea(){
            cout << "Triangle class area: " << endl;
            return (width * height) / 2;
        }
};

int main(){
    Rectangle rec;
    Triangle tri;


    rec.setWidth(5);
    rec.setHeight(7);

    cout << "Total Rectangle area: " << rec.getArea() << endl;

    tri.setWidth(5);
    tri.setHeight(7);

    cout << "Total Triangle area: " << tri.getArea() << endl;

    return 0;

}
