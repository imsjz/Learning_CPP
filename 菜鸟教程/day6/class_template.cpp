#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack{
    private:
        vector<T> elems;

    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const{
            return elems.empty();
        }
};

template <class T>
void Stack<T>::push (T const& elem){
    //追加传入元素的副本
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::pop():empty stack");
    }
    //删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const{
    return elems.back();
}

int main(){
    try{
        Stack<int> intStack;
        Stack<string> stringStack;

        //操作int类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;

    }
    catch (exception const& ex){
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }

}
