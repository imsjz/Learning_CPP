# 21天学通C++第8版（二）

## 第11章 多态

###多态的一些性质

* 多态（Polymorphism）是面向对象语言的一种特征，**让您能够以类似的方式处理不同类似的对象。**

* 为什么需要多态

  ```c++
  #include <iostream>
  using namespace std;
  
  class Fish
  {
  public:
     void Swim()
     {
        cout << "Fish swims!" << endl;
     }
  };
  
  class Tuna:public Fish
  {
  public:
     // override Fish::Swim
     void Swim()
     {
        cout << "Tuna swims!" << endl;
     }
  };
  
  void MakeFishSwim(Fish& InputFish)
  {
     // calling Fish::Swim
     InputFish.Swim();
  }
  
  int main() 
  {
     Tuna myDinner;
  
     // calling Tuna::Swim
     myDinner.Swim();
  
     // sending Tuna as Fish
     MakeFishSwim(myDinner);
  
     return 0;
  }
  ```

  输出：

  ```
  Tuna swims!
  Fish swims!
  ```

  > Tuna 类以公有方式继承了 Fish 类，它还覆盖了方法 Fish::Swim( )。在 main( )中，
  > 直接调用了 Tuna::Swim( )，并将 myDinner （其类型为 Tuna）作为参数传递给了 MakeFishSwim( )，而该函数将其视为 Fish 引用。换句话说，虽然传入的是 Tuna 对象，MakeFishSwim(Fish&)也将其视为 Fish，进而调用 Fish::Swim。第 2 行输出表明，虽然传入的是 Tuna对象，但得到的却是 Fish 的输出。
  >
  > 理想情况下，用户希望 Tuna 对象表现出金枪鱼的行为，即便通过 Fish 参数调用 Swim( )时亦如此。换句话说，调用 inputFish.Swim( )时，用户希望执行的是 Tuna::Swim( )。要实现这种多态行为—让 Fish 参数表现出其实际类型（派生类 Tuna）的行为，可将 Fish::Swim( )声明为虚函数。

* override（覆盖）和overload（重载）的区别

  * 重载Overload：在同一个类中，允许存在一个以上的同名函数，只要他们的参数个数或者参数类型不同即可。**与返回值类型无关，只看参数列表 。**
  * 重写Override：表示子类中的方法可以与父类中的某个方法的**名称和参数完全相同**，通过子类创建的实例对象调用这个方法时，将调用子类中定义的方法，这相当于把**父类**中定义的那个完全相同的方法给**覆盖掉了**，这也是面向对象编程的多态的一种表现。 

### 使用虚函数实现多态行为

* 通过使用关键字 virtual，可确保编译器调用覆盖版本。也就是说，如果Swim( )被声明为虚函数，则将参数 myFish（其类型为 Fish&）设置为一个Tuna对象时， myFish.Swim( )将执行Tuna::Swim( )

  ```c++
  #include <iostream>
  using namespace std;
  
  class Fish
  {
  public:
     virtual void Swim()
     {
        cout << "Fish swims!" << endl;
     }
  };
  class Tuna:public Fish
  {
  public:
     // override Fish::Swim
     void Swim()
     {
        cout << "Tuna swims!" << endl;
     }
  };
  
  class Carp:public Fish
  {
  public:
     // override Fish::Swim
     void Swim()
     {
        cout << "Carp swims!" << endl;
     }
  };
  
  void MakeFishSwim(Fish& InputFish)
  {
     // calling Swim
     InputFish.Swim();
  }
  
  int main() 
  {
     Tuna myDinner;
     Carp myLunch;
  
     // sending Tuna as Fish
     MakeFishSwim(myDinner);
  
     // sending Carp as Fish
     MakeFishSwim(myLunch);
  
     return 0;
  }
  ```

  输出结果:

  ```
  Tuna swims!
  Carp swims!
  ```

* 虚函数的工作原理--虚函数表

  ```c++
  #include <iostream>
  using namespace std;
  
  class SimpleClass {
  	int a, b;
  public:
  	void DoSomething(){}
  };
  class Base {
  	int a, b;
  public:
  	virtual void DoSomething(){}
  };
  
  int main() {
  	
  	cout << "sizeof(SimpleClass) = " << sizeof(SimpleClass) << endl;
  	cout << "Sizeof(Base) = " << sizeof(Base) << endl;
  
  	system("pause");
  	return 0;
  }
  ```

  输出结果：

  ```
  sizeof(SimpleClass) = 8
  sizeof(Base) = 12
  //在32位机的结果
  ```

  > 两个类—SimpleClass 和 Base，它们包含的成员数量和类型都相同，但在 Base 中，将 DoSomething( )声明成了虚函数，而在 SimpleClass 中没有这样做。添加关键 字 virtual 带来的影响是，编译器将为 Base 类生成一个虚函数表，并其虚函数表指针（一个隐藏成员） 预留空间。在 32 位系统中， Base 类占用的内存空间多了 4 字节，这证明确实存在这样的指针。

  

* 抽象基类和纯虚函数

  不能实例化的基类被称为抽象基类， 这样的基类只有一个用途， 那就是从它派生出其他类。 在 C++中，要创建抽象基类，可声明纯虚函数。

  * 纯虚函数

    ```c++
    class AbstractBase{
    public:
        virtual void DoSomething() = 0;//pure virtual method
    }
    //上面纯虚函数的的声明告诉编译器，AbstractBase 的派生类必须实现方法 DoSomething()：
    ```

    因此有：

    ```c++
    class Derived: public AbstractBase{
    public:
    	void DoSomething() // pure virtual fn. must be implemented
        {
    		cout << "Implemented virtual function" << endl;
        }
    }
    ```

    > **AbstractBase 类要求 Derived 类必须提供虚方法 DoSomething( )的实现。这让基类可指定派生类中 方法的名称和特征标，即指定派生类的接口**。    

### 使用虚继承解决菱形问题（也就是多继承的关系）

* 问题的由来

  ```c++
  #include <iostream>
  using namespace std;
  
  class Animal
  {
  public:
  	Animal()
  	{
  		cout << "Animal constructor" << endl;
  	}
  
  	int age;
  };
  
  class Mammal :public Animal
  {
  };
  
  class Bird :public Animal
  {
  };
  
  class Reptile :public Animal
  {
  };
  
  class Platypus :public Mammal, public Bird, public Reptile
  {
  public:
  	Platypus()
  	{
  		cout << "Platypus constructor" << endl;
  	}
  };
  
  int main()
  {
  	Platypus duckBilledP;
  
  	// uncomment next line to see compile failure
  	// age is ambiguous(模糊的) as there are three instances of base Animal 
  	// duckBilledP.age = 25;
  
  	duckBilledP.Mammal::age = 25;
  	duckBilledP.Bird::age = 25;
  	duckBilledP.Reptile::age = 25;
  
  	return 0;
  }
  ```

  输出是

  ```
  Animal constructor
  Animal constructor
  Animal constructor
  Platypus constructor
  ```

  >输出表明，由于采用了多继承，且 Platypus 的全部三个基类都是从 Animal 类派生而来的，因此创建 Platypus 实例时，自动创建了三个 Animal 实例。这太可笑了，因为鸭嘴兽是一种动物，继承 了哺乳动物、鸟类和爬行动物的属性。存在多个 Animal 实例带来的问题并非仅限于会占用更多内存。 Animal 有一个整型成员—Animal::age，为了方便说明问题，将其声明成了公有的。如果您试图通过 Platypus 实例访问 Animal::age，将导致编译错误，因为编译器不知道您要设置 Mammal::Animal::age、 Bird::Animal::age 还是 Reptile::Animal::age。更可笑的是，如果您愿意，可以分别设置这三个属性：    
  >
  >	duckBilledP.Mammal::age = 25;
  >	duckBilledP.Bird::age = 25;
  >	duckBilledP.Reptile::age = 25;
  >	//注意访问方式，派生类对象先用点(.)取出基类，再用(::)访问age

  > 显然，鸭嘴兽应该只有一个 age属性，但您希望 Platypus类以公有方式继承Mammal、Bird和 Reptile。 解决方案是使用虚继承。如果派生类可能被用作基类，派生它是最好使用关键字 virtual：

  ```c++
  class Derived1: public virtual Base
  {
  // ... members and functions
  };
  class Derived2: public virtual Base
  {
  // ... members and functions
  };
  ```

  以下是上面程序的改正版：

  ```c++
  #include <iostream>
  using namespace std;
  
  class Animal
  {
  public:
     Animal()
     {
        cout << "Animal constructor" << endl;
     }
  
     // sample member
     int age;
  };
  
  class Mammal:public virtual Animal
  {
  };
  
  class Bird:public virtual Animal
  {
  };
  
  class Reptile:public virtual Animal
  {
  };
  //同时使用final关键字禁止将Playtypus类作为基类
  class Platypus final:public Mammal, public Bird, public Reptile
  {
  public:
     Platypus()
     {
        cout << "Platypus constructor" << endl;
     }
  };
  
  int main()
  {
     Platypus duckBilledP;
  
     // no compile error as there is only one Animal::age
     duckBilledP.age = 25; 
  
     return 0;
  }
  ```

  输出：

  ```
  Animal constructor
  Platypus constructor
  ```

  > 发现构造的 Animal 实例数减少到了 1 个， 这表明只构造了一个 Platypus。这是因为从 Animal 类派生 Mammal、 Bird 和 Reptile 类时，使用了关键 字 virtual，这样 Platypus 继承这些类时，每个 Platypus 实例只包含一个 Animal 实例。    

  **总结**：

  C++关键字 virtual 的含义随上下文而异（我想这样做的目的很可能是为了省事），对其含
  义总结如下：
  *在函数声明中，virtual意味着当基类指针指向派生对象时，通过它可调用派生类的相应函数。*
  *从Base类派生出Derived1和Derived2类时，如果使用了关键字virtual，则意味着再从Derived1和Derived2派生出Derived3时，每个Derived3实例只包含一个Base实例。*

  也就是说，**关键字virtual被用于实现两个不同的概念**

* 表明覆盖意图的限定符**override**

  从 C++11 起，程序员可使用限定符 override 来**核实**被覆盖的函数在基类中是否
  被声明为虚的：

  ```c++
  class Fish
  {
  public:
  	virtual void Swim()
  	{
  		cout << "Fish swims!" << endl;
  	}
  };
  class Tuna:public Fish
  {
  public:
  	void Swim() const override // Error: no virtual fn with this sig in Fish
  	{
  		cout << "Tuna swims!" << endl;
  	}
  };
  ```

* 使用final来禁止覆盖函数

  C++11 引入了限定符 final，被声明为 final 的类不能用作基类，同样，**对于被声明为 final 的虚函数，不能在派生类中进行覆盖。**

  ```c++
  class Tuna:public Fish
  {
  public:
  	// override Fish::Swim and make this final
  	void Swim() override final    //注意格式
  	{
  		cout << "Tuna swims!" << endl;
  	}
  };
  class BluefinTuna final:public Tuna
  {
  public:
  	void Swim() // Error: Swim() was final in Tuna, cannot override
  	{
  	}
  };
  ```

  

### 可将复制构造函数声明为虚函数吗（没看懂）



## 第十二章 运算符类型与运算符重载

### 单目运算符

* 实现为全局函数或静态成员函数的单目运算符的典型定义如下：

  ```c++
  return_type operator operator_type(parameter_type){
      //...implementation
  }
  ```

* 作为类成员（非静态函数）的单目运算符没有参数，因为它们使用的唯一参数是当前类实例（*this）：

  ```c++
  return_type operator operator_type(){
      //...implementation
  }
  ```

* 单目递增与递减运算符

  * 前缀

    ```c++
    class Date {
    private:
    	int day, month, year;
    public:
    	Date(int inMonth, int inDay, int inYear)
    		: day(inDay), month(inMonth), year(inYear) {};
    	Date& operator ++() {
    		++day;
    		return *this;
    	}
    	Date& operator --() {
    		--day;
    		return *this;
    	}
    	void DisplayDate() {
    		cout << month << " / " << day << " / "
    			<< year << endl;
    	}
    };
    int main() {
    
    	Date holiday(12, 25, 2018);
    	
    	cout << "The date object is initialized to: ";
    	holiday.DisplayDate();
    
    	++holiday;
    	cout << "Date after prefix-increment is: ";
    	holiday.DisplayDate();
    
    	--holiday;
    	cout << "Date after prefix-decrement is: ";
    	holiday.DisplayDate();
    	
    
    	system("pause");
    	return 0;
    }
    ```

    输出：

    ```
    The date object is initialized to: 12 / 25 / 2018
    Date after prefix-increment is: 12 / 26 / 2018
    Date after prefix-decrement is: 12 / 25 / 2018
    ```

  * 后缀

    要支持后缀递增和递减运算符，只需在Date类中添加如下代码：

    ```c++
    Date operator ++(int) {
        Date copy(month, day, year);
        ++day;
        return copy;
    }
    Date operator --(int) {
        Date copy(month, day, year);
        --day;
        return copy;
    }
    //注意返回的类型不是引用了， 参数也加了一个int，目前我不懂加的深层原因，猜测是为了区别前缀吧...
    ```

* **转换运算符**

  `本章课后作业有个例子`。

  直接把例子贴上来：

  ```c++
  class Date
  {
      int day, month, year;
   public:
      Date(int inDay, int inMonth, int inYear):day(inDay),month(inMonth),year(inYear){};
      explicit operator int()  //可以这样用的，注意加了explicit禁止隐式转换
      {
     	 	return ((year * 10000) + (month * 100) + day);
      }
      // constructor etc
  };
  //怎么使用呢：
  int main(){
      Date myDate(14,8,2018);
      int sum = static_cast<int>(myDate);//因为类中转换函数那里加了explicit,表示不允许隐式转换，所以要加static_cast进行转换
      
      cout << sum << endl;
      
      return 0;
  }
  ```

  由上可以看出，这个和重载运算符有点不同，语法是`operator int()`，然后函数体内要返回`int`，这样就实现了由`Date`类转为`int`了。

### 双目运算符

* 以全局函数或静态成员函数的方式实现的双目运算符的定义如下：

  ```c++
  return_type operator operator_type(parameter1, parameter2);
  ```

* 以类成员的方式实现的双目运算符只接受一个参数， 其原因是第二个参数通常是从类属性获得的

  ```c++
  return_type operator operator_type(parameter);
  ```

  

* 双目加法和减法运算符实现

  ```c++
  Date operator +(int daysToAdd) {
      Date newDate(month, day + daysToAdd, year);
      return newDate;
  }
  Date operator - (int daysToSub) {
      return Date(month, day - daysToSub, year);
  }
  ```

  

* += 和 -=运算符

  ```c++
  //注意：返回类型是void
  void operator+=(int daysToAdd) {
      day += daysToAdd;
  }
  void operator-=(int daysToSub) {
      day -= daysToSub;
  }
  ```

  

* 重载等于（==）和不等（!=）

  ```c++
  bool operator==(const Date& compartTo) {
      return ((day == compartTo.day) && (month == compartTo.month)
              && (year == compartTo.year));
  }
  bool operator!=(const Date& compartTo) {
      return !(this->operator==(compartTo)); //注意这个表达
  }
  ```

  

* 重载<,>,<=,>=

  ```c++
  bool operator<(const Date& compareTo) {
      if (year < compareTo.year)
          return true;
      else if (month < compareTo.month)
          return true;
      else if (day < compareTo.day)
          return true;
      else
          return false;
  }
  bool operator<=(const Date& compareTo) {
      if (this->operator==(compareTo))
          return true;
      else
          return this->operator<(compareTo);
  }
  bool operator>(const Date& compareTo) {
      //直接用！<=即可搞定
      return !(this->operator<=(compareTo));
  }
  bool operator>=(const Date& compareTo) {
      //这里也可以用!<搞定，不过没这样做
      if (this->operator==(compareTo))
          return true;
      else
          return this->operator>(compareTo);
  }
  ```

  

* 重载复制赋值运算符（==）

  这里用了C风格字符串const char* 的例子来讲，我只简单列出语法

  ```c++
  classType& operator=(const classType& copySource){
      if(this != &copySource)//避免自己复制自己
      {
          //copy assignment operator implementation
      }
      return *this;
  }
  //返回的类型就是此类的引用，因为要改变自己嘛
  ```

  

### 函数运算符operator()

* operator()让对象像函数，被称为函数运算符。

  ```c++
  class Display {
  public:
  	void operator()(string input) const {
  		cout << input << endl;
  	}
  };
  
  int main() {
  
  	Display displayFuncObj;
  	displayFuncObj("Display this string");
  
  	system("pause");
  	return 0;
  }
  ```

  输出：

  ```
  Display this string
  ```

  > 之所以能够对象 displayFuncObj 用作函数，是因为编译器隐式地将它转换为对函数 operator()的调用。    

### 课后习题

1. 可以像下面这样， 编写两个版本的下标运算符， 一个的返回类型为 const， 另一个为非 const 吗？

   ```c++
   const Type& operator[](int index);
   Type& operator[](int index); // is this OK?
   ```

   答：不可以。 C++不允许**两个函数的名称相同，但返回类型不同**。您可编写运算符[]的这样两种实现：**它们的返回类型相同，但一个为 const 函数，另一个不是**。在这种情况下，如果执行的是与赋值相关的操作，编译器将使用非 const 版本，否则使用 const 版本：

   ```c++
   Type& operator[](int Index) const;
   Type& operator[](int Index);
   ```

2. 可以将复制构造函数或复制赋值运算符声明为私有的吗？

   答：可以，但仅当您希望类不允许复制或赋值时才应这样做。编写单例类（只能有一个实例的类） 时必须这样做。    

3. 为 Date 类编写一个转换运算符，将其存储的日期转换为整数。

   ```c++
   class Date
   {
       int day, month, year;
    public:
       explicit operator int()  //可以这样用的
       {
      	 	return ((year * 10000) + (month * 100) + day);
       }
       // constructor etc
   };
   ```

   