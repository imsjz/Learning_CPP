/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 15:11:44
 */
#include "test_class1.h"

void One::func(){
    cout << "one" << endl;
}

void One::test(Two *two){
    cout << two->a_ << endl;
}