/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-05 20:11:39
 */

class House{
};

class HouseBuilder //分离开来
{
public:
    House* GetResult(){
        return pHouse;
    }
    virtual ~HouseBuilder() {}

protected:
    House* pHouse;
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

class HouseDirector{

public:
    HouseBuilder* pHouseBuilder;
    HouseDirector(HouseBuilder* pHouseBuilder){
        this->pHouseBuilder = pHouseBuilder;
    }
    //不能用构造函数调用虚函数
    void init()
    {
        pHouseBuilder->BuildPart1();

        for (int i = 0; i < 4; ++i)
        {
            pHouseBuilder->BuildPart2();
        }
        bool flag = pHouseBuilder->BuildPart3();
        if (flag)
        {
            pHouseBuilder->BuildPart4();
        }
        pHouseBuilder->BuildPart5();
    }

};


class StoneHouse: public House{
public:
};



class StoneBuilder : public HouseBuilder{
public:
    virtual void BuildPart1(){

    }
    virtual void BuildPart2(){}
    virtual bool BuildPart3(){}
    virtual void BuildPart4(){}
    virtual void BuildPart5(){}
};

