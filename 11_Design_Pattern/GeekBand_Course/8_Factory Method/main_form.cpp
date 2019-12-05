/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 16:58:59
 */
//file: main_form.cpp
#include "file_splitter.cpp"

//MainForm已经不依赖别的了: 很稳定了
//里面有m_factory和splitter, 都是抽象的
class MainForm{
    SplitterFactory* m_factory;
public:
    MainForm(SplitterFactory* factory): m_factory(factory){}

    void execute(){
        ISplitter* splitter = m_factory->CreateSplitter(); //用工厂创建分割器, 具体是什么要看传经来的factory
        splitter->split(); //根据上面不同的工厂返回不同的分割器
    }
};

int main(int argc, char const *argv[])
{
    //我想创建一个文本分割器
    TxtSplitterFactory* text_factory = new TxtSplitterFactory;
    MainForm m_f(text_factory);
    m_f.execute();
    delete text_factory;
    return 0;
}

