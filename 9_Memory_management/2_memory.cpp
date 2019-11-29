/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-28 17:20:41
 */
//----------------------------------------------------
#include <iostream>
#include <string>
//#include <memory>				 //std::allocator
using namespace std;

namespace sanjay02
{

class A
{
public:
    int id;

    A() : id(0) { cout << "default ctor. this=" << this << " id=" << id << endl; }
    A(int i) : id(i) { cout << "ctor. this=" << this << " id=" << id << endl; }
    ~A() { cout << "dtor. this=" << this << " id=" << id << endl; }
};

void test_call_ctor_directly()
{
    cout << "\ntest_call_ctor_directly().......... \n";

    string *pstr = new string;
    cout << "str= " << *pstr << endl;

    //! pstr->string::string("jjhou");
    //[Error] 'class std::basic_string<char>' has no member named 'string'
    //! pstr->~string();	//crash -- 其語法語意都是正確的, crash 只因為上一行被 remark 起來嘛.
    cout << "str= " << *pstr << endl;

    //------------

    A *pA = new A(1);       //ctor. this=000307A8 id=1
    cout << pA->id << endl; //1
                            //!	pA->A::A(3);                //in VC6 : ctor. this=000307A8 id=3
                            //in GCC : [Error] cannot call constructor 'jj02::A::A' directly

    //!	A::A(5);	  				//in VC6 : ctor. this=0013FF60 id=5
    //         dtor. this=0013FF60
    //in GCC : [Error] cannot call constructor 'jj02::A::A' directly
    //         [Note] for a function-style cast, remove the redundant '::A'

    cout << pA->id << endl; //in VC6 : 3
                            //in GCC : 1

    delete pA; //dtor. this=000307A8

    //simulate new
    void *p = ::operator new(sizeof(A));
    cout << "p=" << p << endl; //p=000307A8
    pA = static_cast<A *>(p);
    //!	pA->A::A(2);				//in VC6 : ctor. this=000307A8 id=2
    //in GCC : [Error] cannot call constructor 'jj02::A::A' directly

    cout << pA->id << endl; //in VC6 : 2
                            //in GCC : 0

    //simulate delete
    pA->~A();              //dtor. this=000307A8
    ::operator delete(pA); //free()
}
} // namespace sanjay02

//----------------------------------------------------
#include <iostream>
#include <new> //placement new
namespace sanjay03
{

using sanjay02::A;

//测试array new 和 placement new
void test_array_new_and_placement_new()
{
    cout << "\ntest_placement_new().......... \n";

    size_t size = 3;

    ///{
    /////case 1
    /////模擬 memory pool 的作法, array new + placement new. 崩潰
    ///cout << "这里测试的是 new char" << endl;
    ///A* buf = (A*)(new char[sizeof(A)*size]);
    ///A* tmp = buf;

    ///cout << "buf=" << buf << "  tmp=" << tmp << endl;

    ///for(int i = 0; i < size; ++i)
    ///new (tmp++) A(i);  			//3次 ctor

    ///cout << "buf=" << buf << "  tmp=" << tmp << endl;

    /////!	delete [] buf;    	//crash. why?
    /////因為這其實是個 char array，看到 delete [] buf; 編譯器會企圖喚起多次 A::~A.
    ///// 但 array memory layout 中找不到與 array 元素個數 (本例 3) 相關的信息,
    ///// -- 整個格局都錯亂 (從我對 VC 的認識而言)，於是崩潰。
    ///delete buf;     	//dtor just one time, ~[0]

    ///cout << "\n\n";
    ///}

    {
        //case 2
        //回頭測試單純的 array new

        A *buf = new A[size]; //default ctor 3 次. [0]先於[1]先於[2])
                              //A必須有 default ctor, 否則 [Error] no matching function for call to 'jj02::A::A()'
        A *tmp = buf;

        cout << "buf=" << buf << "  tmp=" << tmp << endl;

        for (int i = 0; i < size; ++i)
            new (tmp++) A(i); //3次 ctor

        cout << "buf=" << buf << "  tmp=" << tmp << endl;

        delete[] buf; //dtor three times (次序逆反, [2]先於[1]先於[0])
    }

    {
        //case 3
        //掌握崩潰原因, 再次模擬 memory pool作法, array new + placement new.
        //不, 不做了, 因為 memory pool 只是供應 memory, 它並不管 construction,
        //也不管 destruction. 它只負責回收 memory.
        //所以它是以 void* 或 char* 取得 memory, 釋放 (刪除)的也是 void* or char*.
        //不像本例 case 1 釋放 (刪除) 的是 A*.
        //
        //事實上 memory pool 形式如 jj04::test
    }
}
} // namespace sanjay03
//////////////////////////////////////////////////////////////////////////
namespace sanjay04
{
void test()
{
    using sanjay02::A;
    int *pi = new int[10];
    delete[] pi;

    A *a_demo = new A[3];
    delete a_demo;
}
} // namespace sanjay04

//########################重载::operator new和 ::operator delete##############################
//----------------------------------------------------
// #include <cstdlib>	//malloc, free

// void* myAlloc(size_t size)
// {  return malloc(size); }

// void myFree(void* ptr)
// {  return free(ptr); }

// //我要設計一個可以累計總分配量和總釋放量的 operator new() / operator delete().
// //除非 user 直接使用 malloc/free, 否則都避不開它們, 這樣就可以累積總量.
// static long long countNew = 0;
// static long long countDel = 0;
// static long long countArrayNew = 0;
// static long long countArrayDel = 0;
// static long long timesNew = 0;

// //小心，這影響無遠弗屆
// //它們不可被聲明於一個 namespace 內
// //以下是成功的, 但我暫時不想要它 (免得對我這整個測試程序帶來影響).

// 	inline void* operator new(size_t size)
// 	{
// 		// //cout << "jjhou global new(), \t" << size << "\t";
// 		// countNew += size;
// 		// ++timesNew;

// 		//void* p = myAlloc( size );
// 		//cout << p << endl;
// 	    //return p;

//         cout << "sanjay global new() " << endl;
// 	    return myAlloc( size );
// 	}

// 	inline void* operator new[](size_t size)
// 	{
// 		cout << "sanjay global new[]()" << endl;
// 		return myAlloc( size ); //虽然不符合, 但是只是测试
// 	}

// 	//天啊, 以下(1)(2)可以並存並由(2)抓住流程 (但它對我這兒的測試無用).
// 	//當只存在 (1) 時, 抓不住流程.
// 	//在 class members 中二者只能擇一 (任一均可)
// 	//(1)
// 	// inline void  operator delete(void* ptr, size_t size)
// 	// {
//  	// 	cout << "sanjay global delete(ptr,size), \t" << ptr << "\t" << size << endl;
// 	// 	countDel += size;
// 	//  	myFree( ptr );
// 	// }
// 	//(2)
// 	inline void  operator delete(void* ptr)
// 	{
//  		cout << "sanajy global delete(ptr) " << endl;
// 	 	myFree( ptr );
// 	}

// 	//(1)
// 	// inline void  operator delete[](void* ptr, size_t size)
// 	// {
// 	//     cout << "sanjay global delete[](ptr,size), \t" << ptr << "\t" << size << endl;
// 	//     // countArrayDel += size;
// 	// 	myFree( ptr );
// 	// }
// 	//(2)
// 	inline void  operator delete[](void* ptr)
// 	{
// 	    cout << "sanjay global delete[](ptr) " << endl;
// 		myFree( ptr );
// 	}

void test05()
{
    int *p = new int[5];
    delete[] p;
    using sanjay02::A;
    A *p_a = new A;
    delete p_a;
}

//----------------------测试类内operator new------------------------------
#include <cstddef>
#include <iostream>
#include <string>
namespace sanjay06
{

class Foo
{
public:
    int _id;     //4
    long _data;  //4
    string _str; // 32 ==> 4 + 4 + 32 = 40 ==> 48 //64位 8字节对齐

public:
    static void *operator new(size_t size);
    static void operator delete(void *deadObject, size_t size);
    static void *operator new[](size_t size);
    static void operator delete[](void *deadObject, size_t size);

    Foo() : _id(0) { cout << "default ctor. this=" << this << " id=" << _id << endl; }
    Foo(int i) : _id(i) { cout << "ctor. this=" << this << " id=" << _id << endl; }
    virtual ~Foo() { cout << "dtor. this=" << this << " id=" << _id << endl; }

    //不加 virtual dtor, sizeof = 12, new Foo[5] => operator new[]() 的 size 參數是 64,
    //加了 virtual dtor, sizeof = 16, new Foo[5] => operator new[]() 的 size 參數是 84,
    //上述二例，多出來的 4 可能就是個 size_t 欄位用來放置 array size.
};

void *Foo::operator new(size_t size)
{
    Foo *p = (Foo *)malloc(size);
    cout << "Foo::operator new(), size=" << size << "\t  return: " << p << endl;

    return p;
}

void Foo::operator delete(void *pdead, size_t size)
{
    cout << "Foo::operator delete(), pdead= " << pdead << "  size= " << size << endl;
    free(pdead);
}

void *Foo::operator new[](size_t size)
{
    Foo *p = (Foo *)malloc(size); //crash, 問題可能出在這兒
    cout << "Foo::operator new[](), size=" << size << "\t  return: " << p << endl;

    return p;
}

void Foo::operator delete[](void *pdead, size_t size)
{
    cout << "Foo::operator delete[](), pdead= " << pdead << "  size= " << size << endl;

    free(pdead);
}

//-------------测试重载operator new 类内
void test_overload_operator_new_and_array_new()
{
    cout << "\ntest_overload_operator_new_and_array_new().......... \n";

    cout << "sizeof(Foo)= " << sizeof(Foo) << endl;

    {
        Foo *p = new Foo(7);
        delete p;

        Foo *pArray = new Foo[5]; //無法給 array elements 以 initializer
        delete[] pArray;
    }
    cout << "====================分割==========================" << endl;
    {
        cout << "testing global expression ::new and ::new[] \n";
        // 這會繞過 overloaded new(), delete(), new[](), delete[]()
        // 但當然 ctor, dtor 都會被正常呼叫.

        Foo *p = ::new Foo(7);
        ::delete p;

        Foo *pArray = ::new Foo[5];
        ::delete[] pArray;
    }
}
} // namespace sanjay06

// overloading new
//----------------------------------------------------
#include <vector>

namespace sanjay07
{

class Bad
{
};
class Foo
{
public:
    Foo() { cout << "Foo::Foo()" << endl; }
    Foo(int)
    {
        cout << "Foo::Foo(int)" << endl;
        throw Bad();
    }

    //(1) 這個就是一般的 operator new() 的重載
    void *operator new(size_t size)
    {
        cout << "operator new(size_t size), size= " << size << endl;
        return malloc(size);
    }

    //(2) 這個就是標準庫已經提供的 placement new() 的重載 (形式)
    //    (所以我也模擬 standard placement new 的動作, just return ptr)
    void *operator new(size_t size, void *start)
    {
        cout << "operator new(size_t size, void* start), size= " << size << "  start= " << start << endl;
        return start; // 模拟标准的placement new的动作, 只返回指针
    }

    //(3) 這個才是嶄新的 placement new
    void *operator new(size_t size, long extra)
    {
        cout << "operator new(size_t size, long extra)  " << size << ' ' << extra << endl;
        return malloc(size + extra);
    }

    //(4) 這又是一個 placement new
    void *operator new(size_t size, long extra, char init)
    {
        cout << "operator new(size_t size, long extra, char init)  " << size << ' ' << extra << ' ' << init << endl;
        return malloc(size + extra);
    }

    //(5) 這又是一個 placement new, 但故意寫錯第一參數的 type (它必須是 size_t 以滿足正常的 operator new)
    //!  	void* operator new(long extra, char init) { //[Error] 'operator new' takes type 'size_t' ('unsigned int') as first parameter [-fpermissive]
    //!	  	cout << "op-new(long,char)" << endl;
    //!    	return malloc(extra);
    //!  	}

    //以下是搭配上述 placement new 的各個 called placement delete.
    //當 ctor 發出異常，這兒對應的 operator (placement) delete 就會被喚起.
    //應該是要負責釋放其搭檔兄弟 (placement new) 分配所得的 memory.
    //(1) 這個就是一般的 operator delete() 的重載
    void operator delete(void *, size_t)
    {
        cout << "operator delete(void*,size_t)  " << endl;
    }

    //(2) 這是對應上述的 (2)
    void operator delete(void *, void *)
    {
        cout << "operator delete(void*,void*)  " << endl;
    }

    //(3) 這是對應上述的 (3)
    void operator delete(void *, long)
    {
        cout << "operator delete(void*,long)  " << endl;
    }

    //(4) 這是對應上述的 (4)
    //如果沒有一一對應, 也不會有任何編譯報錯
    void operator delete(void *, long, char)
    {
        cout << "operator delete(void*,long,char)  " << endl;
    }

private:
    int m_i;
};

//-------------
void test_overload_placement_new()
{
    cout << "\n\n\ntest_overload_placement_new().......... \n";

    Foo start; //Foo::Foo //这里直接在栈申请内存, 不需要new

    Foo *p1 = new Foo;            //op-new(size_t) //先调用new, 再构造
    Foo *p2 = new (&start) Foo;   //op-new(size_t,void*)
    Foo *p3 = new (100) Foo;      //op-new(size_t,long)
    Foo *p4 = new (100, 'a') Foo; //op-new(size_t,long,char)

    Foo *p5 = new (100) Foo(1);      //op-new(size_t,long)  op-del(void*,long)
    Foo *p6 = new (100, 'a') Foo(1); //可以直接传入参数, 调用对应的构造函数
    Foo *p7 = new (&start) Foo(1);   //
    Foo *p8 = new Foo(1);            //
                                     //VC6 warning C4291: 'void *__cdecl Foo::operator new(unsigned int)'
                                     //no matching operator delete found; memory will not be freed if
                                     //initialization throws an exception
}
} // namespace sanjay07

//==============================================内存池---version1============================
//----------------------------------------------------
#include <cstddef>
#include <iostream>
namespace sanjay08
{
//ref. C++Primer 3/e, p.765
//per-class allocator 单个类的分配器

class Screen
{
public:
    Screen(int x) : i(x){};
    int get() { return i; }

    void *operator new(size_t);
    void operator delete(void *, size_t); //(2)
    //! void  operator delete(void*);			//(1) 二擇一. 若(1)(2)並存,會有很奇怪的報錯 (摸不著頭緒)

private:
    Screen *next;             //需要多一个指针来维护, 本来类中只有4个字节大小, 现在是12个字节, 内存对齐, 所以16个字节大小.
    static Screen *freeStore; //静态变量来标识剩余的容量
    static const int screenChunk;

private:
    int i;
};
Screen *Screen::freeStore = 0;
const int Screen::screenChunk = 24; //一次申请24

void *Screen::operator new(size_t size)
{
    Screen *p;
    if (!freeStore)
    {
        //linked list 是空的，所以攫取一大塊 memory
        //以下呼叫的是 global operator new
        size_t chunk = screenChunk * size; //也就是24 * sizeof(Screen)
        freeStore = p =
            reinterpret_cast<Screen *>(new char[chunk]);
        //將分配得來的一大塊 memory 當做 linked list 般小塊小塊串接起來
        for (; p != &freeStore[screenChunk - 1]; ++p)
            p->next = p + 1;
        p->next = 0;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

//! void Screen::operator delete(void *p)		//(1)
void Screen::operator delete(void *p, size_t) //(2)二擇一
{
    //將 deleted object 收回插入 free list 前端
    (static_cast<Screen *>(p))->next = freeStore;
    freeStore = static_cast<Screen *>(p);
}

//-------------
void test_per_class_allocator_1()
{
    cout << "\ntest_per_class_allocator_1().......... \n";

    cout << sizeof(Screen) << endl; //16

    size_t const N = 100;
    Screen *p[N];

    for (int i = 0; i < N; ++i) //new 100个Screen
        p[i] = new Screen(i);

    //輸出前 10 個 pointers, 用以比較其間隔
    for (int i = 0; i < 10; ++i)
        cout << p[i] << endl;

    for (int i = 0; i < N; ++i) //调用delete
        delete p[i];
}
} // namespace sanjay08

//----------------------------------------------------
#include <cstddef>
#include <iostream>
namespace sanjay09
{
//ref. Effective C++ 2e, item10
//per-class allocator

class Airplane
{ //支援 customized memory management
private:
    struct AirplaneRep
    {
        unsigned long miles; //8
        char type;
    }; //16

private:
    union {
        AirplaneRep rep; //此針對 used object
        Airplane *next;  //此針對 free list
    };                   //当内存还在内存时, 使用next, 当被new了之后, 使用rep

public:
    unsigned long getMiles() { return rep.miles; }
    char getType() { return rep.type; }
    void set(unsigned long m, char t)
    {
        rep.miles = m;
        rep.type = t;
    }

public:
    //重载operator new
    static void *operator new(size_t size);
    static void operator delete(void *deadObject, size_t size);

private:
    static const int BLOCK_SIZE;
    static Airplane *headOfFreeList;
};

Airplane *Airplane::headOfFreeList = NULL;
const int Airplane::BLOCK_SIZE = 512;

void *Airplane::operator new(size_t size)
{
    //如果大小錯誤，轉交給 ::operator new() 当有继承关系的时候, 会出现大小出错
    if (size != sizeof(Airplane))
        return ::operator new(size);

    Airplane *p = headOfFreeList;

    //如果 p 有效，就把list頭部移往下一個元素
    if (p)
        headOfFreeList = p->next;
    else
    {
        //free list 已空。配置一塊夠大記憶體，
        //令足夠容納 BLOCK_SIZE 個 Airplanes
        Airplane *newBlock = static_cast<Airplane *>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
        //組成一個新的 free list：將小區塊串在一起，但跳過
        //#0 元素，因為要將它傳回給呼叫者。
        for (int i = 1; i < BLOCK_SIZE - 1; ++i)
            newBlock[i].next = &newBlock[i + 1];
        newBlock[BLOCK_SIZE - 1].next = 0; //以null結束

        // 將 p 設至頭部，將 headOfFreeList 設至
        // 下一個可被運用的小區塊。
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}

// operator delete 接獲一塊記憶體。
// 如果它的大小正確，就把它加到 free list 的前端
void Airplane::operator delete(void *deadObject,
                               size_t size)
{
    if (deadObject == 0)
        return;
    if (size != sizeof(Airplane))
    {
        ::operator delete(deadObject);
        return;
    }

    Airplane *carcass =
        static_cast<Airplane *>(deadObject);

    carcass->next = headOfFreeList;
    headOfFreeList = carcass;
}

//-------------
void test_per_class_allocator_2()
{
    cout << "\ntest_per_class_allocator_2().......... \n";

    cout << sizeof(Airplane) << endl; //16

    size_t const N = 100;
    Airplane *p[N];

    for (int i = 0; i < N; ++i)
        p[i] = new Airplane;

    //隨機測試 object 正常否
    p[1]->set(1000, 'A');
    p[5]->set(2000, 'B');
    p[9]->set(500000, 'C');
    cout << p[1] << ' ' << p[1]->getType() << ' ' << p[1]->getMiles() << endl;
    cout << p[5] << ' ' << p[5]->getType() << ' ' << p[5]->getMiles() << endl;
    cout << p[9] << ' ' << p[9]->getType() << ' ' << p[9]->getMiles() << endl;

    //輸出前 10 個 pointers, 用以比較其間隔
    for (int i = 0; i < 10; ++i)
        cout << p[i] << endl; //间隔16, 没有cookie

    for (int i = 0; i < N; ++i)
        delete p[i];
}
} // namespace sanjay09

//----------------------------------------------------
#include <complex>
namespace sanjay10
{

//搞一个通用的内存分配类
class allocator
{
private:
    struct obj
    {
        struct obj *next; //embedded pointer
    };

public:
    void *allocate(size_t);
    void deallocate(void *, size_t);
    void check();

private:
    obj *freeStore = nullptr;
    const int CHUNK = 5; //小一點方便觀察
};

void *allocator::allocate(size_t size)
{
    obj *p;

    if (!freeStore)
    {
        //linked list 是空的，所以攫取一大塊 memory
        size_t chunk = CHUNK * size;
        freeStore = p = (obj *)malloc(chunk);

        //cout << "empty. malloc: " << chunk << "  " << p << endl;

        //將分配得來的一大塊當做 linked list 般小塊小塊串接起來
        for (int i = 0; i < (CHUNK - 1); ++i)
        { //沒寫很漂亮, 不是重點無所謂.
            p->next = (obj *)((char *)p + size);
            p = p->next;
        }
        p->next = nullptr; //last
    }
    p = freeStore;
    freeStore = freeStore->next;

    //cout << "p= " << p << "  freeStore= " << freeStore << endl;

    return p;
}
void allocator::deallocate(void *p, size_t)
{
    //將 deleted object 收回插入 free list 前端
    ((obj *)p)->next = freeStore;
    freeStore = (obj *)p;
}
void allocator::check()
{
    obj *p = freeStore;
    int count = 0;

    while (p)
    {
        cout << p << endl;
        p = p->next;
        count++;
    }
    cout << count << endl;
}
//--------------
class Foo
{
public:
    long L;
    string str;
    static allocator myAlloc;

public:
    Foo(long l) : L(l) {}
    static void *operator new(size_t size)
    {
        return myAlloc.allocate(size);
    }
    static void operator delete(void *pdead, size_t size)
    {
        return myAlloc.deallocate(pdead, size);
    }
};
allocator Foo::myAlloc;

class Goo
{
public:
    complex<double> c;
    string str;
    static allocator myAlloc;

public:
    Goo(const complex<double> &x) : c(x) {}
    static void *operator new(size_t size)
    {
        return myAlloc.allocate(size);
    }
    static void operator delete(void *pdead, size_t size)
    {
        return myAlloc.deallocate(pdead, size);
    }
};
allocator Goo::myAlloc;

//-------------
void test_static_allocator_3()
{
    cout << "\n\n\ntest_static_allocator().......... \n";

    {
        Foo *p[100];

        cout << "sizeof(Foo)= " << sizeof(Foo) << endl;
        for (int i = 0; i < 23; ++i)
        { //23,任意數, 隨意看看結果
            p[i] = new Foo(i);
            cout << p[i] << ' ' << p[i]->L << endl;
        }
        //Foo::myAlloc.check();

        for (int i = 0; i < 23; ++i)
        {
            delete p[i];
        }
        //Foo::myAlloc.check();
    }

    {
        Goo *p[100];

        cout << "sizeof(Goo)= " << sizeof(Goo) << endl;
        for (int i = 0; i < 17; ++i)
        { //17,任意數, 隨意看看結果
            p[i] = new Goo(complex<double>(i, i));
            cout << p[i] << ' ' << p[i]->c << endl;
        }
        //Goo::myAlloc.check();

        for (int i = 0; i < 17; ++i)
        {
            delete p[i];
        }
        //Goo::myAlloc.check();
    }
}
} // namespace sanjay10
//----------------------------------------------------
#include <complex>
namespace sanjay11
{
using sanjay10::allocator;

//下面借鉴MFC 的 macro定义
// DECLARE_POOL_ALLOC -- used in class definition
#define DECLARE_POOL_ALLOC()                                           \
public:                                                                \
    void *operator new(size_t size) { return myAlloc.allocate(size); } \
    void operator delete(void *p) { myAlloc.deallocate(p, 0); }        \
                                                                       \
protected:                                                             \
    static allocator myAlloc;

// IMPLEMENT_POOL_ALLOC -- used in class implementation file
#define IMPLEMENT_POOL_ALLOC(class_name) \
    allocator class_name::myAlloc;

// in class definition file
class Foo
{
    DECLARE_POOL_ALLOC()
public:
    long L;
    string str;

public:
    Foo(long l) : L(l) {}
};
//in class implementation file
IMPLEMENT_POOL_ALLOC(Foo)

//  in class definition file
class Goo
{
    DECLARE_POOL_ALLOC()
public:
    complex<double> c;
    string str;

public:
    Goo(const complex<double> &x) : c(x) {}
};
//in class implementation file
IMPLEMENT_POOL_ALLOC(Goo)

void test_macros_for_static_allocator()
{
    cout << "\n\n\ntest_macro_for_static_allocator().......... \n";

    Foo *pF[100];
    Goo *pG[100];

    cout << "sizeof(Foo)= " << sizeof(Foo) << endl;
    cout << "sizeof(Goo)= " << sizeof(Goo) << endl;

    for (int i = 0; i < 23; ++i)
    { //23,任意數, 隨意看看結果
        pF[i] = new Foo(i);
        pG[i] = new Goo(complex<double>(i, i));
        cout << pF[i] << ' ' << pF[i]->L << "\t";
        cout << pG[i] << ' ' << pG[i]->c << "\n";
    }

    for (int i = 0; i < 23; ++i)
    {
        delete pF[i];
        delete pG[i];
    }
}
} // namespace sanjay11

//----------------------------------------------------
namespace sanjay12
{

class Foo
{
public:
    long _x;

public:
    Foo(long x = 0) : _x(x) {}

    // static void *operator new(size_t size) = default; 
    // static void operator delete(void *pdead, size_t size) = default;  //cannot be defaulted
    static void *operator new[](size_t size) = delete;
    static void operator delete[](void *pdead, size_t size) = delete;
};

class Goo
{
public:
    long _x;

public:
    Goo(long x = 0) : _x(x) {}

    static void *operator new(size_t size) = delete;
    static void operator delete(void *pdead, size_t size) = delete;
};

void test_delete_and_default_for_new()
{
    cout << "\n\n\ntest_delete_and_default_for_new().......... \n";

    Foo *p1 = new Foo(5); //因为不允许设置为default, 所以可以
    delete p1; //同上
    
    // Foo* p2 = new Foo[5]; //delete 掉了
    // delete[] p2;

    //! Goo* p2 = new Goo(7);	//[Error] use of deleted function 'static void* jj12::Goo::operator new(size_t)'
    //!	delete p2;				//[Error] use of deleted function 'static void jj12::Goo::operator delete(void*, size_t)'
    Goo *pG = new Goo[10];
    delete[] pG;
}
} // namespace sanjay12

int main()
{

    //sanjay03::test_array_new_and_placement_new();
    // sanjay04::test();
    // test05();
    // sanjay06::test_overload_operator_new_and_array_new();
    // sanjay07::test_overload_placement_new();
    // cout << sizeof(sanjay08::Screen) << endl;
    // sanjay08::test_per_class_allocator_1();
    // sanjay09::test_per_class_allocator_2();
    // sanjay11::test_macros_for_static_allocator();
    sanjay12::test_delete_and_default_for_new();
    return 0;
}