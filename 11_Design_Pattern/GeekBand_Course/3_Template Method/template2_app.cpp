/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 15:21:03
 */
//Ӧ�ó��򿪷���Ա
class Application : public Library
{
protected:
    virtual bool Step2()
    {
        //... ������дʵ��
    }

    virtual void Step4()
    {
        //... ������дʵ��
    }
};

int main()
{
    Library *pLib = new Application();
    lib->Run();

    delete pLib;
}
}
