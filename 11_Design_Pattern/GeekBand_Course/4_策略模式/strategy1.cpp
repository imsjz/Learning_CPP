/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 15:54:57
 */
enum TaxBase
{
    CN_Tax,
    US_Tax,
    DE_Tax,
    FR_Tax //更改, 如果新增法国税率
};         //枚举

class SalesOrder
{
    TaxBase tax;

public:
    double CalculateTax()
    {
        //...

        if (tax == CN_Tax)
        {
            //CN***********
        }
        else if (tax == US_Tax)
        {
            //US***********
        }
        else if (tax == DE_Tax)
        {
            //DE***********
        }
        else if (tax == FR_Tax)
        {   //更改: 开闭原则, 对扩展开放, 对修改关闭
            //...
        }

        //....
    }
};
