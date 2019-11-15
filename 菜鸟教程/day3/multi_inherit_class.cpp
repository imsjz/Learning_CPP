#include <iostream>

using namespace std;

//parent1
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
//parent2
class PaintCost{
    public:
        double getCost(double area){
            return area * 70;
        }
};

//child inherits from parent1 and parent2
class Ractangle : public Shape, public PaintCost{
    public:
        double getArea(){
            return width * height;
        }
};

int main(){
    Ractangle rect;
    double area;

    rect.setWidth(20);
    rect.setHeight(32.0);

    area = rect.getArea();



    cout << "Total area: " << rect.getArea() << endl;

    cout << "Total paint cost: $" << rect.getCost(area) << endl;

    return 0;
}
