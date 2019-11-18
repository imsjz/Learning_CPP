# 21天学通C++第8版（三）

## 第十三章 类型转换运算符

### 使用static_cast

* 可以将指针向上转换位基类类型，也可以向下转换为派生类型

  ```c++
  Base* objBase = new Derived();
  Derived* objDer = static_cast<Derived*>(objBase);
  ```

  > 将 Derived*转换为 Base*被称为向上转换，无需使用任何显式类型转换运算符就能进行这种转换：
  >
  > ```c++
  > Derived objDerived;
  > Base* objBase = &objDerived; // ok!
  > ```
  >
  > 将 Base*转换为 Derived*被称为向下转换，如果不使用显式类型转换运算符，就无法进行这种转换：    
  >
  > ```c++
  > Derived objDerived;
  > Base* objBase = &objDerived; // Upcast -> ok!
  > Derived* objDer = objBase; // Error: Downcast needs explicit cast
  > ```

### 使用dynamic_cast

* 先看个例子

  ```c++
  class Fish {
  public:
  	virtual void Swim() {
  		cout << "Fist swims in water" << endl;
  	}
  	virtual ~Fish() {};
  };
  class Tuna : public Fish {
  public:
  	void Swim() {
  		cout << "Tuna swims real fast in the sea" << endl;
  	}
  	void BecomeDinner() {
  		cout << "Tuna become dinner in Sushi" << endl;
  	}
  };
  class Carp : public Fish {
  public: 
  	void Swim() {
  		cout << "Carp swims real slow in the lake" << endl;
  	}
  	void Talk() {
  		cout << "Carp talked Carp!" << endl;
  	}
  };
  void DectectFishType(Fish* objFish) {
  	Tuna* objTuna = dynamic_cast<Tuna*>(objFish);
  	if (objTuna) {
  		cout << "Dectected Tuna. Making Tuna dinner" << endl;
  		objTuna->BecomeDinner();
  	}
  
  	Carp* objCarp = dynamic_cast<Carp*>(objFish);
  	if (objCarp) {
  		cout << "Dectected Carp. Making Carp dinner" << endl;
  		objCarp->Talk();
  	}
  	cout << "Verifying type using virtual Fish: Swim: " << endl;
  	objFish->Swim();
  }
  
  
  int main() {
  
  	Carp myLunch;
  	Tuna myDinner;
  
  	DectectFishType(&myLunch);
  	cout << endl;
  	DectectFishType(&myDinner);
  	
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  Dectected Carp. Making Carp dinner
  Carp talked Carp!
  Verifying type using virtual Fish: Swim:
  Carp swims real slow in the lake
  
  Dectected Tuna. Making Tuna dinner
  Tuna become dinner in Sushi
  Verifying type using virtual Fish: Swim:
  Tuna swims real fast in the sea
  ```

  这个示例的独特之处在于，给定一个基类指针（Fish），您可动态地检测它指向的是否是 Tuna 或 Carp。这种动态检测（运行阶段类型识别）是在函数DetectFishType( )中进行的。使用 dynamic_cast 传入的基类指针（Fish）参数指向的是否是 Tuna 对象。如果该 Fish指向的是 Tuna 对象，该运算符将返回一个有效的地址，否则将返回 NULL。因此，总是需要检查 dynamic_cast 的结果是否有效。如果通过了if语句的检查，您便知道指针 objTuna 指向的是一个有效的 Tuna 对象，因此可以使用它来调用函数 Tuna::BecomeDinner( )。如果传入的 Fish参数指向的是 Carp 对象，则使用它来调用函数 Carp::Talk( )。返回之前，DetectFishType( )调用了 Swim( )，以验证对象类型； Swim( )是一个虚函数，这行代码将根据指针指向的对象类型，调用相应类（Tuna 或 Carp）中实现的方法 Swim( )。

## 第十四章 宏和模板

### 宏

* 预处理器与编译器

  > 预处理器编译指令都以#打头，比如#define
  >
  > \#define ARRAY_LENGTH 25

* 使用宏避免多次包含

  C++程序员通常在.H 文件（头文件）中声明类和函数， 并在.CPP 文件中定义函数， 因此需要在.CPP文件中使用预处理器编译指令#include \<header>来包含头文件。如果在头文件 class1.h 中声明了一个类，而这个类将 class2.h 中声明的类作为其成员，则需要在 class1.h 中包含 class2.h。如果设计非常复杂，即第二个类需要第一个类，则在 class2.h 中也需要包含 class1.h！

  然而，在预处理器看来，两个头文件彼此包含对方会导致递归问题。为了避免这种问题，可结合使用宏以及预处理器编译指令#ifndef 和#endif。

  包含<header2.h>的 head1.h 类似于下面这样：

  ```c++
  #ifndef HEADER1_H_
  #define HEADER1_H_
  #include <header2.h>
  class Class1{
      //class members
  };
  #endif
  ```

  header2.h 与此类似，但宏定义不同，且包含的是<header1.h>：

  ```c++
  #ifndef HEADER2_H_
  #define HEADER2_H_
  #include <header1.h>
  class Class2{
      //class members
  };
  #endif
  ```

  因此，预处理器首次处理 header1.h 并遇到#ifndef 后，发现宏 HEADER1_H_还未定义，因此继续处理。#ifndef 后面的第一行定义了宏 HEADER1_H_，确保预处理器再次处理该文件时，将在遇到包含\#ifndef 的第一行时结束，因为其中的条件为 false。 header2.h 与此类似。

### 模板

* 模板声明语法

  模板声明以关键字 template 打头，接下来是类型参数列表。这种声明的格式如下：

  ```c++
  template <parameter list>
  template function / class declaration..
  ```

  关键字 template 标志着模板声明的开始，接下来是模板参数列表。该参数列表包含关键字 typename，它定义了模板参数 objType， objType 是一个占位符，针对对象实例化模板时，将使用对象的类型替换它。

  ```c++
  template <typename T1, typename T2 = T1>
  bool TemplateFunction(const T1& param1, const T2& param2);
  
  //A template class
  template <typename T1, typename T2 = T1>
  class MyTemplate{
  private:
  	T1 member1;
  	T2 member2;
  public:
  	T1 GetObj1() { return member1;}
  	//...other members
  };
  ```

  

* 模板函数

  下面模板声明返回两个参数中较大的一个：

  ```c++
  template <typename objType>
  const objType GetMax(const objType& value1, const objType& value2){
  	if(value1 > value2)
  		return value1;
  	else
  		return value2;
  }
  ```

  下面是一个使用该模板的实例：

  ```c++
  int num1 = 24;
  int num2 = 25;
  int maxVal = GetMax<int>(num1, num2);
  //注意到调用 GetMax 时使用了<int>，这将模板参数 objType 指定为 int。
  ```

  > 然而，实际上调用模板函数时并非一定要指定类型，因此下面的函数调用没有任何问题：
  >
  > ```c++
  > int maxVal = GetMax(num1,num2);
  > ```
  >
  > 在这种情况下，编译器很聪明，知道这是针对整型调用模板函数。然而，**对于模板类，必须显式地指定类型。**

* 模板类

  * 声明包含多个参数的模板

    ```c++
    template <typename T1, typename T2>
    class HoldPair {
    private:
    	T1 value1;
    	T2 value2;
    public:
    	HoldPair(const T1& val1, const T2& val2) {
    		value1 = val1;
    		value2 = val2;
    	}
    };
    
    //使用
    //模板实例化为一个参数int和另一个参数double
    HoldPair<int, double> pairIntDouble(1, 1.99);
    //模板两个参数都是int
    HoldPair<int, int> pairIntInt(1, 2);
    ```

  * 声明包含默认参数的模板

    ```c++
    template <typename T1=int, typename T2=int>
    class HoldsPair
    {
    // ... method declarations
    };
    
    //使用
    // Pair an int with an int (default type)
    HoldsPair <> pairInts (6, 500);
    ```

  * 模板的**实例化和具体化**

    模板类是创建类的蓝图，因此在编译器看来，仅当模板类以某种方式被使用后，其代码才存在。换言之，对于您定义了但未使用的模板类，编译器将忽略它。然而，当您像下面这样通过提供模板参数来实例化模板类（如HoldsPair）时：

    ```c++
    HoldPair<int,double> pairIntDbl;
    ```

    就相当于命令编译器使用模板来创建一个类，即使用模板参数指定的类型（这里是 int 和 double）实例化模板。因此，对模板来说，**实例化指的是使用一个或多个模板参数来创建特定的类型。**

    **另一方面，在有些情况下，使用特定的类型实例化模板时，需要显式地指定不同的行为。这就是具体化模板，即为特定的类型指定行为**。下面是模板类HoldsPair 的一个具体化，其中两个模板参数的类型都为 int：

    ```C++
    template<> class HoldPair<int,int>{
        //implementation code here
    }
    //注意具体化模板的语法形式
    ```

    下面给个实例：

    ```c++
    template <typename T1, typename T2>
    class HoldPair {
    private:
    	T1 value1;
    	T2 value2;
    public:
    	HoldPair(const T1& val1, const T2& val2) {
    		value1 = val1;
    		value2 = val2;
    	}
    	const T1& GetFirstValue() const;
    };
    //具体化模板 类型是int，int
    //specialization of HoldsPair for types int & int here
    template<> class HoldPair<int, int> {
    private:
    	int value1;
    	int value2;
    	string strFun;
    public:
    	HoldPair(const int& val1, const int& val2)
    		: value1(val1), value2(val2) {}
    	const int& GetFirstValue() const {
    		cout << "Returning integer " << value1 << endl;
    		return value1;
    	}
    };
    
    int main() {
    
    	HoldPair<int, int> pairIntInt(1, 2);
    	pairIntInt.GetFirstValue();
    
    	system("pause");
    	return 0;
    }
    ```

    输出：

    ```
    Returning integer 1
    ```

    > 事实上，在模板具体化 HoldsPair<int, int>中，对函数 GetFirstValue()做了修改，使其同时显示获得的值。如果您仔细查看具体化代码，将发现这个版本还声明了一个字符串成员； HoldsPair<>模板定义中，并没有这个成员。事实上，这个模板定义甚至都没有提供存取函数 GetFirstValue()和 GetSecondValue()的实现，但程序依然能够通过编译。这是因为编译器只需考虑针对<int, int>的模板实例化，而在这个实例化中，我们提供了完备的具体实现。总之，这个示例不仅演示了模板具体化，还表明根据模板的使用情况，编译器可能忽略模板代码。

* 模板类和静态成员 (感觉很难用到，也不是很懂)

  前面说过，在编译器看来，仅当模板被使用时，其代码才存在。在模板类中，静态成员属性的工 作原理是什么样的呢？第 9 章介绍过，如果将类成员声明为静态的，该成员将由类的所有实例共享。 模板类的静态成员与此类似，由特定具体化的所有实例共享。也就是说，如果模板类包含静态成员， 该成员将在针对 int 具体化的所有实例之间共享；同样，它还将在针对 double 具体化的所有实例之间 共享，且与针对 int 具体化的实例无关。换句话说，可以认为编译器创建了两个版本的 x： x_int 用于针 对 int 具体化的实例，而 x_double 针对 double 具体化的实例。下面展现一个例子：

  ```c++
  #include <iostream>
  using namespace std;
  
  template <typename T>
  class TestStatic
  {
  public:
     static int staticVal;
  };
   //注意下面的静态成员的语法，真让人头疼...
  // static member initialization
  template<typename T> int TestStatic<T>::staticVal;
  
  int main()
  {
     TestStatic<int> intInstance;
     cout << "Setting staticVal for intInstance to 2011" << endl;
     intInstance.staticVal = 2011;
  
     TestStatic<double> dblnstance;
     cout << "Setting staticVal for Double_2 to 1011" << endl;
     dblnstance.staticVal = 1011;
  
     cout << "intInstance.staticVal = " << intInstance.staticVal << endl;
     cout << "dblnstance.staticVal = " << dblnstance.staticVal << endl;
  
     return 0;
  }
  ```

   输出:

  ```
  Setting staticVal for intInstance to 2011
  Setting staticVal for Double_2 to 1011
  intInstance.staticVal = 2011
  dblnstance.staticVal = 1011
  ```

  > 输出表明，编译器 在两个不同的静态成员中存储了两个不同的值，但这两个静态成员都名为 staticVal。也就是说，对于针 对每种类型具体化的类，编译器确保其静态变量不受其他类的影响。 
  >
  >  对于模板类的静态成员，通用的初始化语法如下：    
  >
  > ```c++
  > template<template parameters> StaticType
  > ClassName<Template Arguments>::StaticVarName;
  > //原来这就是语法，记住~
  > ```

* 参数数量可变的模板

  先看例子：

  ```c++
  template <typename Res, typename ValType>
  void Sum(Res& result, ValType& val) { //这里val带了引用
  	result = result + val;
  }
  template <typename Res, typename First, typename...Rest>
  void Sum(Res& result, First val1, Rest... valN) { //这里val1不带，带的话有错，在拼接字符串的时候有错
  	result = result + val1;
  	return Sum(result, valN ...);
  }
  
  int main() {
  	
  	double dResult = 0;
  	Sum(dResult, 3.14, 4.56, 1.1111);
  	cout << "dResult = " << dResult << endl;
  
  	string strResult;
  	//如果Sum的第二个参数变成引用，下面有错，我猜测是字符串存储的位置不允许引用
  	Sum(strResult, "Hello ", "World");
  	//strResult.c_str()应该是返回c风格的字符串(莫非是const char*)?
  	cout << "strResult = " << strResult.c_str() << endl;
  
  	system("pause");
  	return 0;
  }
  ```

  输出：

  ```
  dResult = 8.8111
  strResult = Hello World
  ```

  

# 第15章 标准库模板简介

## 没啥好说的...

# 第16章 STL string类

## 使用STL string类

* 实例化和复制STL string

  ```c++
  const char* constCStylyString = "Hello String";
  //可以用括号
  std::string strFromConst(constCStylyString);
  //也可以用等号
  std::string strFromConst = constCStylyString;
  //可以直接用常量字符串初始化
  string str2("Hello String");
  //也可以用一个string对象来初始化
  string str2Copy(str2);
  
  //可让string的构造函数只接受输入字符串的前n个字符
  string strPartialCopy(constCStylyString, 5);
  
  //还可这样初始化 string 对象，即使其包含指定数量的特定字符：
  string strRepeatChars(10, 'a');
  ```

* 访问std::string的字符内容

  两种访问 STL string 字符元素的方式：运算符[]和迭代器    

  ```c++
  int main() {
  	
  	string stlString("Hello String");
  	//使用运算符[]访问string字符
  	cout << "Display elements in string using array-ayntax: " << endl;
  	for (size_t charCounter = 0;
  		charCounter < stlString.length();
  		++charCounter) {
  		cout << "Character [" << charCounter << "] is: ";
  		cout << stlString[charCounter] << endl;
  	}
  	cout << endl;
  
  	//使用迭代器访问string字符
  	cout << "Display elements in string using iterators: " << endl;
  	int charOffset = 0;
  	for (auto charLocator = stlString.cbegin();
  		charLocator != stlString.cend();
  		++charLocator) {
  		cout << "Character [" << charOffset++ << "] is: ";
  		cout << *charLocator << endl;
  	}
  	cout << endl;
  
  	//Access content as a const char*
  	//获取string对象的c风格表示，用成员函数c_str()
  	cout << "The char* representation of the string is: ";
  	cout << stlString.c_str() << endl;
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  Display elements in string using array-ayntax:
  Character [0] is: H
  Character [1] is: e
  Character [2] is: l
  Character [3] is: l
  Character [4] is: o
  Character [5] is:
  Character [6] is: S
  Character [7] is: t
  Character [8] is: r
  Character [9] is: i
  Character [10] is: n
  Character [11] is: g
  
  Display elements in string using iterators:
  Character [0] is: H
  Character [1] is: e
  Character [2] is: l
  Character [3] is: l
  Character [4] is: o
  Character [5] is:
  Character [6] is: S
  Character [7] is: t
  Character [8] is: r
  Character [9] is: i
  Character [10] is: n
  Character [11] is: g
  
  The char* representation of the string is: Hello String
  ```

* 拼接字符串

  要拼接字符串，可使用运算符+=，也可以使用成员函数append():

  ```c++
  string sampleStr1("Hello");
  string sampleStr2(" String");
  sampleStr1 += sampleStr2;//use std::string::operator+=
  //alternatively use std::string::append()
  sampleStr1.append(sampleStr2);// overloaded for char* too
  ```

* 在string中查找字符或字符串

  主要是**成员函数find()**

  ```c++
  int main() {
  	
  	string sampleStr("Good day String! Today is beautiful!");
  	cout << "Sample string is: " << endl << sampleStr << endl << endl;
  
  	//Find substring "day" -- find returns position
  	size_t charPos = sampleStr.find("day", 0);//0 表示从哪个位置开始搜索
  
  	//Check if the substring was found...
  	if (charPos != string::npos) //string::npos实际为-1
  		cout << "First instance \"day\" at pos: " << charPos << endl;
  	else
  		cout << "Substring not found" << endl;
  
  	cout << "Locating all instances of substring \"day\" " << endl;
  	size_t subStrPos = sampleStr.find("day", 0);
  	while (subStrPos != string::npos) {
  		cout << "\"day\" found at position: " << subStrPos << endl;
  		size_t searchOffset = subStrPos + 1;
  		subStrPos = sampleStr.find("day", searchOffset);
  	}
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  Sample string is:
  Good day String! Today is beautiful!
  
  First instance "day" at pos: 5
  Locating all instances of substring "day"
  "day" found at position: 5
  "day" found at position: 19
  ```

* 截短STL string

  STL string 类提供了 erase()函数，具有以下用途 :

  * 在给定偏移位置和字符数时删除指定数目的字符。

    ```c++
    string sampleStr ("Hello String! Wake up to a beautiful day!");
    sampleStr.erase (13, 28); // Hello String!
    ```

  * 在给定指向**字符的迭代器时删除该字符**。   

    ```c++
    sampleStr.erase (iCharS); // iterator points to a specific character
    //只删除迭代器指向的这个字符
    ```

  * 在给定由两个迭代器指定的范围时删除该范围内的字符。    

    ```c++
    sampleStr.erase (sampleStr.begin (), sampleStr.end ()); // erase from begin to end
    ```

  实例：

  ```c++
  int main() {
  	
  	string sampleStr("Hello String! Wake up to a beautiful day!");
  	cout << "The original sample string is: " << endl;
  	cout << sampleStr << endl << endl;
  
  	// Delete characters from the string given position and count
  	cout << "Truncating the second sentence: " << endl;
  	sampleStr.erase(13, 28); //这里用sampleStr.erase(13)也是一样的
  	cout << sampleStr << endl << endl;
  	//输出:Hello String!
  
  
  	// Find a character 'S' in the string using STL find algorithm
  	auto iCharS = find(sampleStr.begin(),
  		sampleStr.end(), 'S');
  	//找到处于'S'位置的迭代器
  
  	// If character found, 'erase' to deletes a character
  	cout << "Erasing character 'S' from the sample string:" << endl;
  	if (iCharS != sampleStr.end())
  		sampleStr.erase(iCharS);
  
  	cout << sampleStr << endl << endl;
  	//输出Hello tring!
  
  	// Erase a range of characters using an overloaded version of erase()
  	cout << "Erasing a range between begin() and end(): " << endl;
  	sampleStr.erase(sampleStr.begin(), sampleStr.end());
  
  	// Verify the length after the erase() operation above
  	if (sampleStr.length() == 0)
  		cout << "The string is empty" << endl;
  	//输出：The string is empty
  
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  The original sample string is:
  Hello String! Wake up to a beautiful day!
  
  Truncating the second sentence:
  Hello String!
  
  Erasing character 'S' from the sample string:
  Hello tring!
  
  Erasing a range between begin() and end():
  The string is empty
  ```

* 字符串反转

  有时需要反转字符串的内容。假设要判断用户输入的字符串是否为回文，方法之一是将其反转， 再与原来的字符串进行比较。反转 STL string 很容易，只需使用**泛型算法 std::reverse()**：    

  ```c++
  string sampleStr ("Hello String! We will reverse you!");
  reverse(sampleStr.begin(), sampleStr.end());
  cout << sampleStr << endl;
  
  //output:!uoy esrever lliw eW !gnirtS olleH
  ```

* 字符串的大小写转换

  ```c++
  int main() {
  	
  	cout << "Please enter a string for case-convertion: " << endl;
  	cout << "> ";
  
  	string inStr;
  	getline(cin, inStr);
  	cout << endl;
  	//注意transform的用法，第三个参数应该是谓词！
  	transform(inStr.begin(), inStr.end(), inStr.begin(), toupper);
  	cout << "The string converted to upper case is: " << endl;
  	cout << inStr << endl << endl;
  
  	transform(inStr.begin(), inStr.end(), inStr.begin(), tolower);
  	cout << "The string converted to lower case is: " << endl;
  	cout << inStr << endl << endl;
  
  
  	system("pause");
  	return 0;
  }
  ```

  输出：

  ```
  Please enter a string for case-convertion:
  > Convert to this string
  
  The string converted to upper case is:
  CONVERT TO THIS STRING
  
  The string converted to lower case is:
  convert to this string
  ```

###基于模板的STL string实现

* 基于模板的STL string实现

  > 前面说过， std::string 类实际上是 STL 模板类 std::basic_string <T>的具体化。容器类 basic_string 的模板声明如下：    
  >
  > ```c++
  > template<class _Elem,
  > 	class _Traits,//trait 特质
  > 	class _Ax>
  > 	class basic_string
  > ```
  >
  > 在该模板定义中，最重要的参数是第一个： **Elem，它指定了 basic_string 对象将存储的数据类型**。 因此， std::string 使用Elem=char 具体化模板basic_string 的结果，而 wstring 使用_Elem= wchar 具体化 模板basic_string 的结果。    
  >
  > 换句话说， STL string 类的定义如下 :
  >
  > ```c++
  > typedef basic_string<char, char_traits<char>, allocator<char>>
  > string;
  > ```
  >
  > 而 STL wstring 类的定义如下：    
  >
  > ```c++
  > typedef basic_string<wchar_t, char_traits<wchar_t>,allocator<wchar_t> >
  > wstring;
  > ```

### 课后习题

* 使用 tolower( )函数将字符串转换为小写时， std::transform()的作用是什么？    

  答：**std::transform()对 string 对象中指定边界内的每个字符调用 tolower ()函数**。    

* 编写一个程序，告诉用户输入的句子包含多少个元音字母。    

  ```c++
  int GetNumCharacters(string& inputStr, char findChar) {
  	int countFindChar = 0;
  	size_t findOffset = inputStr.find(findChar,0);
  	while (findOffset != string::npos) {
  		++countFindChar;
  		findOffset = inputStr.find(findChar, findOffset + 1);
  	}
  	return countFindChar;
  }
  int main() {
  	
  	cout << "Please enter a string: " << endl << "> ";
  	string inputStr;
  	getline(cin, inputStr);
  
  	int nNumberVowels = GetNumCharacters(inputStr, 'a');
  	nNumberVowels += GetNumCharacters(inputStr, 'e');
  	nNumberVowels += GetNumCharacters(inputStr, 'i');
  	nNumberVowels += GetNumCharacters(inputStr, 'o');
  	nNumberVowels += GetNumCharacters(inputStr, 'u');
  	//这里大写就不写了
  	cout << "The number of vowels in that sentence is: " << nNumberVowels;
  
  	system("pause");
  	return 0;
  }
  ```

* 将字符串的字符交替地转换为大写。   

  ```c++
  int main() {
  
  	cout << "Please enter a string: " << endl << "> ";
  	string inputStr;
  	getline(cin, inputStr);
  
  	for (size_t nCharIndex = 0;
  		nCharIndex < inputStr.length();
  		nCharIndex += 2) {
  		inputStr[nCharIndex] = toupper(inputStr[nCharIndex]);
  	}
  	cout << inputStr << endl;
  
  	system("pause");
  	return 0;
  }
  ```

  

## 第17章 STL动态数组类

### 典型的vector操作

* **vector是一种动态数组**

* 实例化vector

  ```c++
  std::vector<int> dynIntArray; // vector containing integers
  std::vector<float> dynFloatArray; // vector containing floats
  std::vector<Tuna> dynTunaArray; // vector containing Tunas
  ```

  要声明指向list中元素的迭代器，可以这样做：

  ```c++
  std::vector<int>::const_iterator elementInVec;
  ```

  下面给出各种实例化vector的方式:

  ```c++
  int main ()
  {
     // vector of integers
     std::vector<int> integers;
  
     // vector with 3 elements initialized using C++11 list initialization
     std::vector<int> initVector{ 202, 2017, -1 };
  
     // Instantiate a vector with 10 elements (it can still grow)
     std::vector<int> tenElements (10);
  
     // Instantiate a vector with 10 elements, each initialized to 90
     std::vector<int> tenElemInit (10, 90);
      //注意，第一个参数是元素个数，第二个参数是初始化的值
  
     // Instantiate one vector and initialize it to the contents of another
     std::vector<int> copyVector (tenElemInit);
  
     // Vector initialized to 5 elements from another using iterators
     std::vector<int> partialCopy (tenElements.cbegin(),
                                   tenElements.cbegin() + 5);
  
     return 0;
  }
  ```

* 使用push_back()在末尾插入元素

  ```c++
  vector <int> integers; // declare a vector of type int
  // Insert sample integers into the vector:
  integers.push_back (50);
  integers.push_back (1);
  ```

* 列表初始化

  C++11 通过 std::initialize_list<>支持列表初始化，让您能够像处理静态数组那样，在实例化 vector 的同时初始化其元素。与大多数容器一样， std::vector 也支持列表初始化，让您能够在实例化 vector 的 同时指定其元素：    

  ```c++
  vector<int> integers = {50, 1, 987, 1001};//用等号，列表初始化用的是中括号{}!
  // alternatively:
  vector<int> vecMoreIntegers {50, 1, 987, 1001}; //不用等号，直接加！
  ```

* 使用insert()在指定位置插入元素

  * 指定插入位置

    ```c++
    //insert an element at the beginning
    integers.insert(integers.begin(),25);
    ```

  * 指定插入位置、要插入的元素数以及这些元素的值（都相同）

    ```c++
    //insert 2 elements of value 45 at the end
    //就是插入两个45
    integers.insert(integers.end(), 2, 45);
    ```

  * 将另一个 vector 的内容插入到指定位置

    ```c++
    // Another vector containing 2 elements of value 30
    vector <int> another (2, 30);
    
    // Insert two elements from another container in position [1]
    integers.insert (integers.begin () + 1,
    another.begin (), another.end ());
    //第一个参数给出要插入的迭代器的位置
    //第二、第三个则把另一个vector中要插入的元素的迭代器范围传进来
    ```

  展示例子:

  ```c++
  int main() {
  
  	vector<int> integers(4, 90);
  	cout << "The initial contents of the vector: ";
  	DisplayVector(integers);
  
  	//在开头插入25
  	integers.insert(integers.begin(), 25);
  	DisplayVector(integers);
  	cout << endl;
  
  	//在末尾插入2个45
  	integers.insert(integers.end(), 45);
  	DisplayVector(integers);
  	cout << endl;
  
  	//创建另一个vector
  	vector<int> another(2, 30);
  
  	//把another插入到integers[1]
  	integers.insert(integers.begin() + 1,
  		another.begin(), another.end());
  	DisplayVector(integers);
  	cout << endl;
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  The initial contents of the vector: 90 90 90 90
  25 90 90 90 90
  
  25 90 90 90 90 45
  
  25 30 30 90 90 90 90 45
  ```

* 使用数组语法访问 vector 中的元素    

  可使用下列方法访问 vector 的元素：

  * 使用下标运算符（[]）以数组语法方式访问；

    可使用类似于数组的语法访问并设置各个元素：  

    ```c++
    std::vector <int> tenElements (10);
    tenElements[3] = 2011; // set 4th element
    ```

  * **使用成员函数 at( )**；

    > 使用[]访问 vector 的元素时，面临的风险与访问数组元素相同，即不能超出容器的边界。 使用下标运算符（[]）访问 vector 的元素时，如果指定的位置超出了边界，结果将是不 确定的（什么情况都可能发生，很可能是访问违规）。 更安全的方法是使用成员函数 at( )：    
    >
    > ```c++
    > //gets element at position 2
    > cout << integers.at(2)
    > ```
    >
    > **at( )函数在运行阶段检查容器的大小，如果索引超出边界（无论如何都不能这样做），将引发异常。** 
    >
    > 下标运算符（[]）只有在保证边界完整性的情况下才是安全的。  

  * 使用迭代器 (使用指针语法访问 vector 中的元素)

    > 迭代器(**类似于指针的语法**)访问 vector 中的元素    

    ```c++
    int main() {
    
    	vector<int> integers{ 50,1,987,1001 };
    	auto element = integers.cbegin();
    
    	while (element != integers.cend()) {
            //计算迭代器的距离用distance函数！！！
    		size_t index = distance(integers.cbegin(), element);
    		cout << "Element at position ";
    		cout << index << " is: " << *element << endl;
    
    		++element;
    	}
    
    	system("pause");
    	return 0;
    }
    ```

    输出：

    ```
    Element at position 0 is: 50
    Element at position 1 is: 1
    Element at position 2 is: 987
    Element at position 3 is: 1001
    ```

* 删除vector中的元素

  除支持使用 push_back()函数在末尾插入元素外， vector 还支持使用 pop_bac()k 函数将末尾的元素 删除。    

  ```c++
     vector<int> integers;
     // Insert sample integers into the vector:
     integers.push_back (50);
     integers.push_back (1);
     integers.push_back (987);
     integers.push_back (1001);
  //现在integers有四个元素: 50,1,987,1001
  
     // Erase one element at the end
     integers.pop_back ();
  //pop_back()后只有三个: 50,1,987
  ```

  

### 理解大小和容量

* vector 的大小指的是实际存储的元素数，而 vector 的容量指的是在重新分配内存以存储更多元素 前 vector 能够存储的元素数。

  因此， **vector 的大小小于或等于容量**。

  * 要查询 vector 当前存储的元素数，可调用 size( )：    

    ```c++
    cout << "Size: " << integers.size();
    ```

  * 要查询 vector 的容量，可调用 capacity( )：

    ```c++
    cout << "Capacity: " <, integers.capacity() << endl;
    ```

### STL deque类

* deque 是一个 STL 动态数组类，与 vector 非常类似，但支持在数组开头和末尾插入或删除元素。    

  要实例化一个整型 deque，可以像下面这样做：    

  ```c++
  std::deque<int> intDeque;
  ```

  > 要使用 std::deque，需要包含头文件<deque>： 
  >
  > `#include<deque>`

* deque 与 vector 极其相似，也支持使用函数 push_back( )和 pop_back( )在末尾插入和删除元素。

* 与 vector 一样， deque 也使用运算符[]以数组语法访问其元素。    

* **deque 与 vector 的不同之处在于，它还允许 您使用 push_front 和 pop_front 在开头插入和删除元素。**

* > 要清空 vector 和 deque 等 STL 容器，即删除其包含的所有元素，可使用函数 clear()。    
  >
  > `integers.clear();    `
  >
  > 请注意， vector 和 deque 还包含成员函数 empty()，这个函数在容器为空时返回 true，而 不像 clear()那样删除既有的元素。
  >
  > ```c++
  > intDeque.clear();
  > if(intDeque.empty())
  >     cout << "The container is now empty" << endl;
  > ```

