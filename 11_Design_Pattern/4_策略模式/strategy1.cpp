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
    FR_Tax //����, �����������˰��
};         //ö��

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
        {   //����: ����ԭ��, ����չ����, ���޸Ĺر�
            //...
        }

        //....
    }
};
