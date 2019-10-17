/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-17 15:16:20
 */
#include <iostream>
#include "test_class1.h"
#include "test_class2.h"

using namespace std;

int main(int argc, char const *argv[])
{
    One *one = new One;
    Two *two = new Two;

    one->test(two);
    return 0;
}
