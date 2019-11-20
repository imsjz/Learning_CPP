/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-20 09:42:54
 */
//###########################################################################################################
#include <cstdlib>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//辅助函数
long get_a_target_long(){
long target = 0;

    cout << "target (0~" << RAND_MAX << "):" << endl;
    cin >> target;
    return target;
}

string get_a_target_string(){
long target = 0;
char buf[10];
    cout << "target (0~" << RAND_MAX << "):" << endl;
    cin >> target;
    snprintf(buf, 10, "%ld", target);
    return string(buf);
}

int CompareLongs(const void* a, const void* b){
    return (*(long*)a - *(long*)b);
} //if a > b , ret > 0

int CompareStrings(const void* a, const void* b){
    if(*(string*)a > *(string*)b)
        return 1;
    else if(*(string*)a < *(string*)b)
        return -1;
    else
        return 0;
}

//################华丽的分割线##################################################

#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib> //qsort bsearch NULL

#define ASIZE 500000
using namespace std;


namespace sanjay1{
void test_array(){
    cout << "\ntest_array()......" << endl;
array<long, ASIZE> c;
clock_t timeStart = clock();
    for(long i = 0; i < ASIZE; ++i){
        c[i] = rand() % 500000; //随机数
    }
    cout << "milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 << endl;
    cout << "array.size() : " << c.size() << endl;
    cout << "array.front() : " << c.front() << endl;
    cout << "array.back() : " << c.back() << endl;
    cout << "array.data() : " << c.data() << endl; //data返回array的首元素地址


long target = get_a_target_long();

    timeStart = clock();
    qsort(c.data(), ASIZE, sizeof(long), CompareLongs); //快速排序完成
long* pItem = (long*)bsearch(&target, c.data(), ASIZE, sizeof(long), CompareLongs);
    cout << "qsort() + bsearch(), milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 ;
    if(pItem != NULL){
        cout << " found, " << *pItem << endl;
    } 
    else
        cout << " not found" << endl;
}
}
/////////////////////
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm> 
namespace sanjay2
{
void test_vector(long& value)
{
	cout << "\ntest_vector().......... \n";
    
vector<string> c;  	
char buf[10];
			
clock_t timeStart = clock();
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));     		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			     //曾經最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000  << endl;	
	cout << "vector.max_size()= " << c.max_size() << endl;	//1073747823
	cout << "vector.size()= " << c.size() << endl;		
	cout << "vector.front()= " << c.front() << endl;	
	cout << "vector.back()= " << c.back() << endl;	
	cout << "vector.data()= " << c.data() << endl;
	cout << "vector.capacity()= " << c.capacity() << endl << endl;		


string target = get_a_target_string();
    {
	timeStart = clock();
auto pItem = ::find(c.begin(), c.end(), target); //用find查找, 用::表示去全局找
	cout << "std::find(), milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000  << endl;  //17.788 millisecond
	 
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;
    }

	{
	timeStart = clock();
    sort(c.begin(), c.end());
	cout << "sort(), milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 << endl;//689.445 毫秒, 排序花的时间很长
	
	timeStart = clock();	    
string* pItem = (string*)::bsearch(&target, (c.data()), 
                                   c.size(), sizeof(string), CompareStrings); 
	cout << "bsearch(), milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 << endl; //0.004毫秒
	   
  	if (pItem != NULL)
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;	
	}
	
	c.clear();
	// test_moveable(vector<MyString>(),vector<MyStrNoMove>(), value);	
}
}

//华丽的分割线============================================================================
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <algorithm> //find()
#include <iostream>
#include <ctime> 
namespace sanjay3
{
void test_list(long& value)
{
	cout << "\ntest_list().......... \n";
     
list<string> c;  	
char buf[10];
			
clock_t timeStart = clock();							
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));    	
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "list.size()= " << c.size() << endl;
	cout << "list.max_size()= " << c.max_size() << endl;    //357913941
	cout << "list.front()= " << c.front() << endl;	
	cout << "list.back()= " << c.back() << endl;		
		
string target = get_a_target_string();		
    timeStart = clock();		
auto pItem = find(c.begin(), c.end(), target);						
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	c.sort();						
	cout << "c.sort(), milli-seconds : " << (clock()-timeStart) << endl;		    	
    	
	c.clear();
	// test_moveable(list<MyString>(),list<MyStrNoMove>(), value);								
}	
}


///主函数
int main(){
    // sanjay1::test_array();
    long size = 0;
    cin >> size;
    sanjay2::test_vector(size);
    return 0;
}
