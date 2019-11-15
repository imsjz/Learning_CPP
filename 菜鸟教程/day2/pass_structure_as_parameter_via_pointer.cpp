#include <iostream>
#include <cstring>

using namespace std;
void printBook(struct Books *book);

//声明一个结构体类型books
struct Books{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main(){
    Books book1;
    Books book2;

    strcpy(book1.title, "C++教程");
    strcpy(book1.author, "sanjay");
    strcpy(book1.subject, "编程语言");
    book1.book_id = 1234;

    //打印book1的信息
    printBook(&book1);

    /*
    //下面这样直接赋值是不行的，因为""的类型是const
    //char[]，但是结构体中的字符是char[]类型的
    book2.title = "python 教程";
    book2.author = "luke";
    book2.subject = "人工智能";
    book2.book_id = 3243;
    */

    strcpy(book2.title, "python教程");
    strcpy(book2.author, "luke");
    strcpy(book2.subject, "人工智能");
    book2.book_id = 3243;

    //打印book2的信息
    printBook(&book2);



    return 0;



}

void printBook(struct Books *book){

    //output information of each book
    cout << "book's title: " << book->title << endl;
    cout << "book's author: " << book->author << endl;
    cout << "book's subject: " << book->subject << endl;
    cout << "book's id: " << book->book_id << endl;
}   


