#include <iostream>

using namespace std;

class Box{
    public:
        Box(double l=2.0, double w=2.0, double h=2.0){
            cout << "Constructor called." << endl;
            length = l;
            width = w;
            height = h;
        }
        double volume(void){
            return this->length * this->width * this->height;
        }

    private:
        double length;
        double width;
        double height;
};

int main(){
    Box box1(3.3, 1.2, 1.5);
    Box *ptrBox;

    ptrBox = &box1;

    cout << "Volume of box1: " << ptrBox->volume() << endl;

    return 0;
}
