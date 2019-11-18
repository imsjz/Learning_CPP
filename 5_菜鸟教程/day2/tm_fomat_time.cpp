#include <iostream>
#include <ctime>

using namespace std;

int main(){
    time_t now = time(0);

    cout << "1970到目前经过秒数: " << now << endl;

    tm *ltm = localtime(&now);

    //output tm structor component
    cout << "year: " << 1900 + ltm->tm_year << endl;
    cout << "month: " << ltm->tm_mon + 1<< endl;
    cout << "day: " << ltm->tm_mday << endl;
    cout << "time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
}
