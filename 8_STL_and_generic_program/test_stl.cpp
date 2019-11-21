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
const int MY_RAND_MAX = 32768;

//辅助函数
long get_a_target_long(){
long target = 0;

    cout << "target (0~" << MY_RAND_MAX - 1<< "):" << endl;
    cin >> target;
    return target;
}

string get_a_target_string(){
long target = 0;
char buf[10];
    cout << "target (0~" << MY_RAND_MAX - 1<< "):" << endl;
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
    		snprintf(buf, 10, "%d", rand() / MY_RAND_MAX);
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
    		snprintf(buf, 10, "%d", rand() % MY_RAND_MAX);
        	c.push_back(string(buf));    	
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 << endl;		
	cout << "list.size()= " << c.size() << endl;
	cout << "list.max_size()= " << c.max_size() << endl;    //357913941
	cout << "list.front()= " << c.front() << endl;	
	cout << "list.back()= " << c.back() << endl;		
		
string target = get_a_target_string();		
    timeStart = clock();		
auto pItem = find(c.begin(), c.end(), target);						
	cout << "std::find(), milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 << endl;		
	
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	c.sort(); //list本身自带的排序
	cout << "c.sort(), milli-seconds : " << ((double)(clock() - timeStart) / CLOCKS_PER_SEC) * 1000 << endl;		    	
    	
	c.clear();
	// test_moveable(list<MyString>(),list<MyStrNoMove>(), value);								
}	
}

//---------------------------------------------------
#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace sanjay4
{
void test_forward_list(long& value)
{
	cout << "\ntest_forward_list().......... \n";
     
forward_list<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand() / MY_RAND_MAX);
        	c.push_front(string(buf));  			   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "forward_list.max_size()= " << c.max_size() << endl;  //536870911
	cout << "forward_list.front()= " << c.front() << endl;	


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
}											 
}

//---------------------------------------------------
#include <deque>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace sanjay5
{
void test_deque(long& value)
{
	cout << "\ntest_deque().......... \n";
     
deque<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand() % MY_RAND_MAX);
        	c.push_back(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "deque.size()= " << c.size() << endl;
	cout << "deque.front()= " << c.front() << endl;	
	cout << "deque.back()= " << c.back() << endl;	
	cout << "deque.max_size()= " << c.max_size() << endl;	//1073741821	
	
string target = get_a_target_string();	
    timeStart = clock();			
auto pItem = find(c.begin(), c.end(), target);	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;	
	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	sort(c.begin(), c.end());//用全局的sort						
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	c.clear();
	// test_moveable(deque<MyString>(),deque<MyStrNoMove>(), value);		 						
}															
}

//---------------------------------------------------
#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace sanjay6
{
void test_multiset(long& value)
{
	cout << "\ntest_multiset().......... \n";
	
multiset<string> c;  	
char buf[10];		
clock_t timeStart = clock();
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));  //multiset底层是红黑树, 会自动排序, 因此没有push_back等让你指定位置的函数,只有insert让你插入, 但是具体位置你不知道在哪里
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "multiset.size()= " << c.size() << endl;	
	cout << "multiset.max_size()= " << c.max_size() << endl;
	
string target = get_a_target_string();	
	{
    timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 	
 	{
    timeStart = clock();		
auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}	
	 
	c.clear();
	// test_moveable(multiset<MyString>(),multiset<MyStrNoMove>(), value);	 						
}															 
}
//---------------------------------------------------
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace sanjay7
{
void test_multimap(long& value)
{
	cout << "\ntest_multimap().......... \n";
     
multimap<long, string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
    		//multimap 不可使用 [] 做 insertion 
        	c.insert(pair<long,string>(i,buf));   						
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "multimap.size()= " << c.size() << endl;
	cout << "multimap.max_size()= " << c.max_size() << endl;	//178956970	
	
long target = get_a_target_long();		
    timeStart = clock();		
auto pItem = c.find(target);//用容器的findd
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;	 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;	  
		
	c.clear();		  					
}
}

//---------------------------------------------------
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace sanjay8
{
void test_unordered_multiset(long& value)
{
	cout << "\ntest_unordered_multiset().......... \n";
     
unordered_multiset<string> c;  	
char buf[10];
			
clock_t timeStart = clock();
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));   			  		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_multiset.size()= " << c.size() << endl;
	cout << "unordered_multiset.max_size()= " << c.max_size() << endl;	//357913941
	cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl; //看有几个篮子
	cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;	
	cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;	
	cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;				
  	for (unsigned i=0; i< 20; ++i) {
    	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	}
				
string target = get_a_target_string();	
	{
    timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 
 	{
    timeStart = clock();		
auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;	 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}		
	 
    c.clear();
	// test_moveable(unordered_multiset<MyString>(),unordered_multiset<MyStrNoMove>(), value);		 	 							
}
}
//---------------------------------------------------
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace sanjay9
{
void test_unordered_multimap(long& value)
{
	cout << "\ntest_unordered_multimap().......... \n";
     
unordered_multimap<long, string> c;
char buf[10];

clock_t timeStart = clock();
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			//multimap 不可使用 [] 進行 insertion 
			// c.insert(pair<long,string>(i,buf));
            c.insert(make_pair(i, buf));
            
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_multimap.size()= " << c.size() << endl;	
	cout << "unordered_multimap.max_size()= " << c.max_size() << endl;	//357913941	
	
long target = get_a_target_long();		
    timeStart = clock();		
auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;		
}															 
}
//--------------------------------------------------allocator---------------------
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> 		//abort()
#include <cstdio>  		//snprintf()
#include <algorithm> 	//find()
#include <iostream>
#include <ctime> 

#include <cstddef>
#include <memory>	//內含 std::allocator  
	//欲使用 std::allocator 以外的 allocator, 得自行 #include <ext\...> 
#ifdef __GNUC__		
#include <ext/array_allocator.h>
#include <ext/mt_allocator.h>
#include <ext/debug_allocator.h>
#include <ext/pool_allocator.h>
#include <ext/bitmap_allocator.h>
#include <ext/malloc_allocator.h>
#include <ext/new_allocator.h>  
#endif

namespace sanjay20
{
//pass A object to function template impl()，
//而 A 本身是個 class template, 帶有 type parameter T,  
//那麼有無可能在 impl() 中抓出 T, 創建一個 list<T, A<T>> object? 
//以下先暫時迴避上述疑問.
	
void test_list_with_special_allocator()
{
#ifdef __GNUC__	
	cout << "\ntest_list_with_special_allocator().......... \n";
     
    //不能在 switch case 中宣告，只好下面這樣. 				//1000000次 
    list<string, allocator<string>> c1;						//3140
	list<string, __gnu_cxx::malloc_allocator<string>> c2;  	//3110
    list<string, __gnu_cxx::new_allocator<string>> c3; 		//3156
	list<string, __gnu_cxx::__pool_alloc<string>> c4;  		//4922
	list<string, __gnu_cxx::__mt_alloc<string>> c5; 		//3297
    list<string, __gnu_cxx::bitmap_allocator<string>> c6;  	//4781 														
	 
int choice;
long value;

	cout << "select: "
		 << " (1) std::allocator "
	     << " (2) malloc_allocator "
	     << " (3) new_allocator "
	     << " (4) __pool_alloc "
	     << " (5) __mt_alloc "
		 << " (6) bitmap_allocator ";
	
	cin >> choice;
	if ( choice != 0 ) {
		cout << "how many elements: ";
		cin >> value; 		
	}
			
char buf[10];			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", i);
	        switch (choice) 
	        {
	 	        case 1 : 	c1.push_back(string(buf)); 	
		 					break;
		        case 2 : 	c2.push_back(string(buf)); 	
		 					break;		
		        case 3 : 	c3.push_back(string(buf)); 
		 					break;		
		        case 4 : 	c4.push_back(string(buf)); 	
		 					break;		
		        case 5 : 	c5.push_back(string(buf)); 		
		 					break;		
		        case 6 : 	c6.push_back(string(buf)); 	
		 					break;				
		        default: 
		 			break;		
	        }
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "a lot of push_back(), milli-seconds : " << (clock()-timeStart) << endl;	


	//test all allocators' allocate() & deallocate();
	int* p;	
    allocator<int> alloc1;	
	p = alloc1.allocate(1);  
	alloc1.deallocate(p,1);//析构的时候不仅需要指针, 还需要指定内存大小 
						
	__gnu_cxx::malloc_allocator<int> alloc2;  
	p = alloc2.allocate(1);  
	alloc2.deallocate(p,1);  	
		
    __gnu_cxx::new_allocator<int> alloc3; 	
	p = alloc3.allocate(1);  
	alloc3.deallocate(p,1); 	
		
	__gnu_cxx::__pool_alloc<int> alloc4;  	
	p = alloc4.allocate(2);  
	alloc4.deallocate(p,2); 	//我刻意令參數為 2, 但這有何意義!! 一次要 2 個 ints? 
		
	__gnu_cxx::__mt_alloc<int> alloc5; 	
	p = alloc5.allocate(1);  
	alloc5.deallocate(p,1);  	
			
    __gnu_cxx::bitmap_allocator<int> alloc6;  	
	p = alloc6.allocate(3);  
	alloc6.deallocate(p,3);  	//我刻意令參數為 3, 但這有何意義!! 一次要 3 個 ints? 
#endif 			
}															
}

///主函数
int main(){
    // sanjay1::test_array();
    long size = 1000000;
    // cin >> size;
    // sanjay2::test_vector(size);
    // sanjay3::test_list(size);
    // sanjay4::test_forward_list(size);
    // sanjay5::test_deque(size);
    // sanjay6::test_multiset(size);
    // sanjay7::test_multimap(size);
    // sanjay8::test_unordered_multiset(size);
    sanjay9::test_unordered_multimap(size);
    return 0;
}
