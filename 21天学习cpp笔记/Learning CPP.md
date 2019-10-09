# 21天学通C++第八版笔记（一）

#第三章

1. **sizeof**返回的是变量的长度，单位为字节。

   ```c++
   cout << sizeof(bool) //返回1 
        << sizeof(char) //返回1
        << sizeof(int)  //返回4
        << sizeof(float) //返回4
        << sizeof(double) //返回8
        << endl;
   //C++11中有int8_t和uint8_t，分别用于存储8位的有符号和无符号整数，当然还有16，32，64的整型
   ```

   

2. 关键字**const**和**constexpr**

   **const** 

   > 如果变量的值不应改变，就应将其声明为常量，这是一种良好的编程习惯。

   **constexpr**

   > 通过关键字 constexpr，可让常量声明像函数：    
   >
   > ```c++
   > constexpr double GetPi() {return 22.0/7;}
   > ```
   >
   > 在一个常量表达式中，可使用另一个常量表达式：    
   >
   > ```c++
   > constexpr double TwicePi() {return 2 * GetPi();}
   > ```
   >
   > 常量表达式看起来像函数，但在编译器和应用程序看来，它们提供了优化可能性。只要编译器能够从常量表达式计算出常量，就可在语句和表达式中可使用常量的地方使用它。在前面的示例中， TwicePi()是一个常量表达式，它使用了另一个常量表达式 GetPi()。这可能引发编译阶段优化，即编译 器将所有的 TwicePi()都替换为 6.28571，从而避免在代码执行时计算 2×22/7 的值。
   >
   > GetPi()和 TwicePi()看起来像函数，但其实不是函数。函数在程序执行期间被调用，但 GetPi()和 TwicePi()是函数表达式，编译器将每个GetPi()都替换成了 3.14286，并将每个 TwicePi()都替换成了 6.28571。通过在编译阶段对 TwicePi()进行解析，程序的执行速度比将这些计算放在函数中时更快。    

3. **typedef**

   systax: 如将int指定为 myInt

   ```c++
   typedef int myInt
   ```

4. **#define**定义常量

   ```c++
   #define pi 3.14286
   //#define 是一个预处理器宏，让预处理器将随后出现的所有 pi 都替换为 3.14286。预处理器将进行文本替换，而不是智能替换。编译器既不知道也不关心常量的类型。
   ```

   > Warning : 使用#define 定义常量的做法已被摒弃，因此不应采用这种做法。    

# 第四章

##1. C风格字符串



* **字符串与字符数组**

  ```c++
  std::cout << "Hello World";
  ```

  等价于

  ```c++
  char sayHello[] = {'H','e','l','l','o',' ','W','o','r','l','d',
  	                  '\0'};
  std::cout << sayHello << std::endl;
  ```

  > **请注意，该数组的最后一个字符为空字符‘\0’。这也被称为字符串结束字符，因为它告诉编译器， 字符串到此结束。这种 C 风格字符串是特殊的字符数组，因为总是在最后一个字符后加上空字符‘\0’。 您在代码中使用字符串字面量时，编译器将负责在它后面添加‘\0’。** 

  > 在数组中间插入‘\0’并不会改变数组的长度，而只会导致将该数组作为输入的字符串处理将到这个位置结束。

  > *‘\0’看起来像两个字符。使用键盘输入它时，确实需要输入两个字符，但反斜杆是编译器 能够理解的特殊转义编码， \0 表示空，即它让编译器插入空字符或零。**不能将其写做‘0’，因为它表示字符 0，其 ASCII 编码为 48**。



* **分析C风格字符串中的终止控制符**

  ```c++
  char sayHello[] = { 'H','e','l','l','o',' ','W','o','r','l','d','\0' };
  cout << sayHello << endl;
  cout << sizeof(sayHello) << endl;
  
  sayHello[5] = '\0';
  cout << sayHello << endl;
  cout << sizeof(sayHello) << endl;
  ```

  最后的结果是：

  ```c++
  Hello World
  12
  Hello
  12
  ```

  将数组sayHello中的下标为5的' '换为'\0'，数组的大小（字节）没有变，但是打印出来的变了。

* **字符数组的存储大小**

  ```c++
  char userInput[21] = {'\0'};
  //userInput最大只能存储20个字符，因为最后一个字符必须是终止符'\0'
  ```

  

# 第五章

* **int和short的大小**（在x64（*86位*）和x86（*32位*）下运行，结果一样）

  **int** 4个字节，32位

  **short** 2个字节，16位

# 第七章 函数

## 1. 用栈理解函数调用

![Stack](C:\Users\Administrator\Pictures\Stack.png)

## 2. lambda函数速览

lambda 函数是 C++11 引入的，有助于使用 STL 算法对数据进行排序或处理。**排序函数要求您提供一个二元谓词，以帮助确定元素的顺序。二元谓词是一个这样的函数，即对两个参数进行比较，并在一个小于另一个时返回 true，否则返回 false。这种谓词通常被实现为类中的运算符，这导致编码工作非常烦琐。使用 lambda 函数可简化谓词的定义**。

下面给出个例子：

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void DisplayNums(vector<int>& dynArray) {
	for_each(dynArray.begin(), dynArray.end(),
		[](int Element) {cout << Element << " "; });
	cout << endl;
}
int main() {
	vector<int> myNums;
	myNums.push_back(501);
	myNums.push_back(-1);
	myNums.push_back(25);
	myNums.push_back(-35);
	//打印vector
	DisplayNums(myNums);

	cout << "Sorting them in descending order" << endl;
	sort(myNums.begin(), myNums.end(),
		[](int num1, int num2) {return num1 > num2; });
	//打印
	DisplayNums(myNums);
	//Visual Studio中要用system来暂停控制台，这样才能看见输出
	system("pause");
	return 0;
}

```

# 第八章 指针和引用

## 1. 指针的大小

* 32位的机器指针的大小为： **4字节(4 Bytes)**
* 64位的机器指针的大小为：**8字节(8 Bytes)**

## 2. 动态内存分配

* 使用new和delete动态分配共和释放内存

  > 通常情况下，如果成功， new 将返回指向一个指针，指向分配的 内存，否则将引发异常。使用 new 时，需要指定要为哪种数据类型分配内存：    

  ```c++
  Type* Pointer = new Type; //request memory for one element
  Type* Pointer = new Type[numElements]; //request memory for numElements
  ```

  eg.

  ```c++
  int* pointToAnInt = new int;
  int* PointToNus = new int[10];
  ```

  > 使用 new 分配的内存最终都需使用对应的 delete 进行释放：   

  ```c++
  Type* Pointer = new Type;//allocate memory
  delete Pointer; // release memory allocated above
  
  Type* Pointer = new Type[numElements];//allcate a block
  delete[] Pointer; //release block allocated above
  ```

## 3. 将递增和递减用于指针

* delete的时候要将指针归位

  eg.

  ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  
  using namespace std;
  
  int main() {
      
  	cout << "How many integers you wish to enter? ";
  	int numEntries = 0;
  	cin >> numEntries;
  
  	int* pointsToInts = new int[numEntries];
  
  	cout << "Allocated for " << numEntries << " integers" << endl;
  	for (int counter = 0; counter < numEntries; ++counter) {
  		cout << "Enter number " << counter << ": ";
  		cin >> *(pointsToInts + counter);
  	}
  	
  	cout << "Displaying all numbers entered: " << endl;
  	for (int counter = 0; counter < numEntries; ++counter)
  		cout << *(pointsToInts++) << " ";
  	cout << endl;
  //--------------------Hint:this is important----------------//
  	//return pointer to initial position
  	pointsToInts -= numEntries;
  //---------------------------------------------------------//
  	delete[] pointsToInts;
  
  	system("pause");
  	return 0;
  }
  ```

  

##4. 将关键字const用于引用

* 看例子

  ```c++
  int original = 30;
  const int& constRef = original;
  constRef = 40; //Not allowed: constRef cannot change value in original
  int& ref2 = constRef; //Not allowed: ref2 is not const
  const int& constRef2 = constRef; //OK
  ```

# 第九章 类和对象

##1. 构造函数

* 没有**默认构造函数**的类

  本来类会有默认构造函数，当有了重载的构造函数后，默认构造函数就没了：

  ```c++
  #include <iostream>
  #include <string>
  
  using namespace std;
  
  class Human {
  private:
  	string name;
  	int age;
  
  public:
  	Human(string humanName, int humanAge) {
  		name = humanName;
  		age = humanAge;
  	}
  	void IntroduceSelf() {
  		cout << "I am " + name << " and am ";
  		cout << age << " years old" << endl;
  	}
  };
  int main(){
      Human firstMan("Adam", 25);
      Human secondMan;//不存在默认构造函数,error
  
  	firstMan.IntroduceSelf();
  	
  	system("pause");
  	return 0;
  }
  ```

* 构造函数包含**初始化列表**

  ```c++
  class Human {
  private:
  	string name;
  	int age;
  
  public:
      Human(string humanName, int humanAge)
          : name(humanName), age(humanAge){}
      ...
  };
  ```

  

## 2. 析构函数

* 温馨提示：

  > 使用 char*缓冲区时，您必须自己管理内存分配和释放，因此本书建议不要使用它们，而使用 std::string。 std::string 等工具都是类，它们充分利用了构造函数和析构函数，还有将在第 12 章介绍的 运算符，让您无需考虑分配和释放等内存管理工作。    

* 析构函数例子（用C字符串风格写的，类似于string的封装）

  ```c++
  #define _CRT_SECURE_NO_WARNINGS //VS要加这个，因为不用这个的话strcpy会提示不安全，编译不通过
  #include <iostream>
  #include <string.h>
  using namespace std;
  
  class MyString {
  private:
  	char* buffer;
  public:
  	MyString(const char* initString) {
  		if (initString != NULL) {
  			buffer = new char[strlen(initString) + 1];//为了存放'\0'
  			strcpy(buffer, initString);
  		}
  		else
  			buffer = NULL;
  	}
      //析构函数
  	~MyString() {
  		cout << "Invoking destructor, clearing up" << endl;
  		if (buffer != NULL)
  			delete[] buffer;
          //如果在vs中想要看到这个打印，可以加下面代码
          //system("pause");
  	}
  	int GetLength() {
  		return strlen(buffer);
  	}
  	const char* GetString() {
  		return buffer;
  	}
  };
  
  int main(){
      
      MyString sayHello("Hello from String Class");
  	cout << "String buffer in sayHello is " << sayHello.GetLength();
  	cout << " characters long" << endl;
  	
  	cout << "Buffer contains: " << sayHello.GetString() << endl;
  
  	system("pause");
  	return 0; 
  }
  ```

  输出结果：

  ```
  String buffer in sayHello is 23 characters long
  Buffer contains: Hello from String Class
  Invoking destructor, clearing up
  ```

  

## 3. 复制构造函数

* 语法

  ```c++
  class MyString{
      Mystring(const MyString& copySource); //copy constructor
  };
  MyString::MyString(const MyString& conpySource){
      //Copy constructor implementation code
  }
  ```

  

* > 通过在复制构造函数声明中使用 const，可确保复制构造函数不会修改指向的源对象。另外，复制构造函数的参数必须**按引用传递，否则复制构造函数将不断调用自己，直到耗 尽系统的内存为止**。    

* >   类包含原始指针成员（char *等）时，务必编写复制构造函数和复制赋值运算符。
  >
  >  *除非万不得已，不要类成员声明为原始指针*。

## 4. 避免隐式转换关键字explicit

* 为避免隐式转换，可在声明构造函数时使用关键字 explicit：  

  ```c++
  class Human{
      int age;
  public:
      explicit Human(int humanAge):age(humanAge){}
  };
  ```

  

## 5. 声明友元

* 友元有：**友元函数和友元类**

  ```c++
  #include <iostream>
  #include <string>
  using namespace std;
  
  class Human
  {
  private:
     //声明友元类
     friend class Utility;
     //声明友元函数
     friend void DisplayAge(const Human& person);
     string name;
     int age;
  
  public:
     Human(string humansName, int humansAge) 
     {
        name = humansName;
        age = humansAge;
     }
  };
  //友元函数的定义
  void DisplayAge(const Human& person)
  {
     cout << person.age << endl;
  }
  //友元类
  class Utility
  {
  public:
     static void DisplayAge(const Human& person)
     {
        //在友元类中可以访问到Human的私有成员变量
        cout << person.age << endl;
     }
  };
     
  int main()
  {
     Human firstMan("Adam", 25);
     cout << "Accessing private member age via friend class: ";
     Utility::DisplayAge(firstMan);
  
     return 0;
  }
  ```

  

## 6. 共用体union

* syntax:

  ```c++
  union UnionName{
      Type1 menber1;
      Type2 menber2;
      ...
      TypeN menberN;
  };
  UnionName unionObject;
  unionObeject.menber2 = value;//choose menber2 as the active menber
  ```

  * > 与结构类似，共用体的成员默认也是公有的，但不同的是，共用体不能继承。
    > 另外，**将 sizeof()用于共用体时，结果总是为共用体最大成员的长度，即便该成员并不处于活动状态**。

* enum的用法

  ```c++
  enum day{
      sun,
      mon,
      tue,
      wed,
      thu,
      fri,
      sat
  };
  day d = sun; //d只能等于"Sun,Mon,Tue,Wed,Thu,Fri,Sat"中的一个,没有其它值!
  
  //enum枚举值对应着一个整型数,通常情况下如果其中的枚举常量没有定义数值,那么第一个枚举值对应着常量值0,然后依次递增，如果第一个枚举常量定义了数值，那么其后的值将随之递增，其中每个常量之间用“,”隔开，而不是“;”，最后一个数值不用符号。
  ```

  

* 下面给出一个实例（值得琢磨）

  ```C++
  //定义共用体
  union SimpleUnion {
  	int num;
  	char alphabet;
  };
  //定义一个复杂类
  struct ComplexType {
      //枚举变量，别名为Type
  	enum DataType {
  		Int,
  		Char
  	} Type;
      //共用体，别名为value
  	union Value {
  		int num;
  		char alphabet;
  	} value;
  };
  void DisplayComplexType(const ComplexType& obj) {
  	switch (obj.Type) {
       //注意：这里ComplexType是可以直接访问到枚举变量里面的Int的,下一个case同理
  	case ComplexType::Int:
  		cout << "Union contains number: " << obj.value.num << endl;
  		break;
  
  	case ComplexType::Char:
  		cout << "Union contains charactor: " << obj.value.alphabet << endl;
  		break;
  	}
  }
  
  int main() {
  	
  	SimpleUnion u1, u2;
  	u1.num = 2100;
  	u2.alphabet = 'c';
  	cout << "Sizeof(u1): " << sizeof(u1) << endl;
  	cout << "Sizeof(u2): " << sizeof(u2) << endl;
  
  	ComplexType myData1, myData2;
      //枚举变量只能取一个，用ComplexType::Int来赋值给Type
  	myData1.Type = ComplexType::Int;
      //共用体则不同，要访问到里面的成员变量，然后赋值
  	myData1.value.num = 2018;
  
  	myData2.Type = ComplexType::Char;
  	myData2.value.alphabet = 'x';
  
  	DisplayComplexType(myData1);
  	DisplayComplexType(myData2);
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  Sizeof(u1): 4
  Sizeof(u2): 4
  Union contains number: 2018
  Union contains charactor: x
  ```

## 7. 对类和结构使用聚合初始化

* 简单理解（以后再填坑）

  ```c++
  struct Aggregate1{
      int num;
      double pi;
  };
  Aggregate1 a1{2017, 3.14};
  
  ```

  

# 第10章 实现继承

## 1 .基类和派生类 

* syntax：

  ```c++
  //base class
  class Fish{
      //...Fish's members
  };
  
  //derived class
  class Carp:public Fish{
      //...Carp's members
  };
  ```

  > **基类**也被称为**超类**；从基类派生而来的类称为**派生类**，也叫**子类**

* protected关键字

  > 与 public 和 private 一样， protected 也是一个访问限定符。将属性声明为protected 的时，相当于允许派生类和友元类访问它，但禁止在继承层次结构外部（包括 main( )）访问它。

  eg.

  ```c++
  #include <iostream>
  using namespace std; 
  
  class Fish
  {
  //基类的成员变量声明为protected,允许派生类和友元类访问
  protected:
     bool isFreshWaterFish; // accessible only to derived classes
  
  public:
    void Swim()
     {
        if (isFreshWaterFish)
           cout << "Swims in lake" << endl;
        else
           cout << "Swims in sea" << endl;
     }
  };
  
  class Tuna: public Fish
  {
  public:
     Tuna()
     {
        isFreshWaterFish = false; // set base class protected member
     }
  };
  
  class Carp: public Fish
  {
  public:
     Carp()
     {
        isFreshWaterFish = false;
     }
  };
  
  int main()
  {
     Carp myLunch;
     Tuna myDinner;
  
     cout << "Getting my food to swim" << endl;
  
     cout << "Lunch: ";
     myLunch.Swim();
  
     cout << "Dinner: ";
     myDinner.Swim();
  
     // 因为基类的成员变量声明为protected，在main函数访问不了
     // myLunch.isFreshWaterFish = false; 
  
     return 0;
  }
  ```

* 基类初始化--向基类传递参数

  eg.

  ```c++
  class Base{
  public;
      Base(int someNumber){
          //use someNumber
      }
  };
  class Derived:public Base{
  public:
      Deriverd() : Base(25){  //instantiate Base with argument 25
          //deriverd class constructor code
      }
  }
  ```

* 在派生类中覆盖基类的方法

  ```c++
  #include <iostream>
  using namespace std; 
  
  class Fish
  {
  private:
     bool isFreshWaterFish;
  
  public:
     // Fish constructor
     Fish(bool IsFreshWater) : isFreshWaterFish(IsFreshWater){}
  
     void Swim()
     {
        if (isFreshWaterFish)
           cout << "Swims in lake" << endl;
        else
           cout << "Swims in sea" << endl;
     }
  };
  
  class Tuna: public Fish
  {
  public:
     Tuna(): Fish(false) {}
  
     void Swim()
     {
        cout << "Tuna swims real fast" << endl;
     }
  };
  
  class Carp: public Fish
  {
  public:
     Carp(): Fish(true) {}
  
     void Swim()
     {
        cout << "Carp swims real slow" << endl;
     }
  };
  
  int main()
  {
     Carp myLunch;
     Tuna myDinner;
  
     cout << "Getting my food to swim" << endl;
  
     cout << "Lunch: ";
     //调用的是派生类中的Swim方法
     myLunch.Swim();
  
     cout << "Dinner: ";
     //调用的是派生类中的Swim方法
     myDinner.Swim();
  
     return 0;
  }
  ```

  输出结果：

  ```
  About my food
  Lunch: Carp swims real slow
  Dinner: Tuna swims real fast
  ```

  * 如果想要调用基类的方法，在上面的程序中：

    ```c++
    myDinner.Fish::Swim();//注意语法
    ```

  * 如果想在派生类中调用基类的方法，则

    ```c++
    class Carp: public Fish{
    public:
        Carp(): Fish(true){}
        
        void Swim(){
            cout << "Carp swims real slow" << endl;
            Fish::Swim(); //调用基类的Swim()方法
        }
    };
    ```

    

* 基类和派生类的构造顺序

  > 如果Tuna 类是从 Fish 类派生而来的，创建Tuna 对象时，先调用Tuna 的构造函数还是Fish 的构造函数？另外，实例化对象时，成员属性（如Fish::isFreshWaterFish）是调用构造函数之前还是之后实例化？**好在实例化顺序已标准化，基类对象在派生类对象之前被实例化。因此，首先构造 Tuna 对象的Fish 部分，这样实例化 Tuna 部分时，成员属性（具体地说是 Fish 的保护和公有属性）已准备就绪，可以使用了。实例化 Fish 部分和 Tuna 部分时，先实例化成员属性（如 Fish::isFreshWaterFish），再调用构造函数，确保成员属性准备就绪，可供构造函数使用。这也适用于Tuna::Tuna( )**。

##2. 私有继承

* 1中主要讲的是共有继承（关键字public)，私有继承用关键字private:

  ```c++
  class Base{
      //...
  };
  class Derived : private Base{
      //...
  };
  ```

  > 私有继承意味着在派生类的实例中， 基类的所有公有成员和方法都是私有的—不能从外部访问。
  > 换句话说，**即便是 Base 类的公有成员和方法，也只能被 Derived 类使用，而无法通过 Derived 实例来使用它们**。

* 例子

  ```c++
  #include <iostream>
  using namespace std;
  //发动机类
  class Motor
  {
  public:
     //点火开关
     void SwitchIgnition()
     {
        cout << "Ignition ON" << endl;
     }
     //喷油...
     void PumpFuel()
     {
        cout << "Fuel in cylinders" << endl;
     }
     //点火
     void FireCylinders()
     {
        cout << "Vroooom" << endl;
     }
  };
  //发动机派生类：汽车
  class Car:private Motor
  {
  public:
     void Move()
     {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
     }
  };
  
  int main()
  {
     Car myDreamCar;
     myDreamCar.Move();
  
     return 0;
  }
  ```

  输出

  ```
  Ignition ON
  Fuel in cylinders
  Vroooom
  ```

  > Tips:如果有一个 RaceCar 类，它继承了 Car 类，则不管 RaceCar 和 Car 之间的继承关系是什么样的， RaceCar 都不能访问基类 Motor 的公有成员和方法。这是因为 Car 和 Motor 之间是私有继承关系，**这意味着除 Car 外，其他所有实体都不能访问基类 Motor 的公有或保护成员。**

## 3. 保护继承

* 在保护继承层次结构中，子类的子类（即 Derived2）能够访问 Base 类的公有和保护成员。

* > 更好的办法 : 将 Motor 对象作为 Car 类的私有成员被称为组合（composition）或聚合（aggergation），这样的 Car 类类似于下面这样：

  ```c++
  class Car{
  private:
      Motor heartOfCar;
  public:
      void Move(){
          heartOfCar.SwitchIgnition();
          heartOfCar.PumpFuel();
          heartOfCar.FireCylinders();
      }
  };
  ```

  

## 4. 多重继承

* sytax：

  ```c++
  class Derived: access-specifier Base1, acess-specifier Base2{
      //...
  };
  
  eg.
      class Platypus: public Mammal, public Reptile, public Bird{
          //...
      };
  ```

  

## 5. 使用final禁止继承

* 从 C++11 起，编译器支持限定符 final。被声明为 final 的类不能用作基类。

  > 例如， Platypus（鸭嘴兽） 类表示一种进化得很好的物种，因此您可能想将其声明为 final 的，从而禁止继承它。对于 Platypus 类，要将其声明为 final 的，可像下面这样做：

  ```c++
  class Platypus final: public Mammal, public Bird, public Reptile
  {
  public:
  	void Swim()
  	{
  		cout << "Platypus: Voila, I can swim!" << endl;
  	}
  };
  ```

  * 书中说：

    > 要建立 is-a 关系， 务必创建公有继承层次结构。
    > 要建立 has-a 关系，务必创建私有或保护继承层
    > 次结构。

    **我不是很懂**

* > 务必牢记，**无论继承关系是什么，派生类都不能访问基类的私有成员。**

  类的私有成员，除了**类的方法和类的友元函数和友元类**能访问，其他都不可以。