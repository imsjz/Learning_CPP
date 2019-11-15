#include <iostream>

using namespace std;

class Line{
    public:
        void setLength(double len);
        double getLength(void);
        //构造函数在声明的时候不用加初始化字段，在实现的时候要。
        Line(double len);

    private:
        double length;
};


Line::Line(double len):length(len) {
   cout << "Object is being created" << endl;
}

void Line::setLength(double len){
    length = len;
}

double Line::getLength(void){
    return length;
}

int main(){
    Line line(10.0);

    //set length
    //line.setLength(20.0);
    cout << "Length of line: " << line.getLength() << endl;
    return 0;
}
