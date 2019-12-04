/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 16:58:59
 */
class ISplitter
{ //抽象基类
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

class BinarySplitter : public ISplitter
{
};

class TxtSplitter : public ISplitter
{
};

class PictureSplitter : public ISplitter
{
};

class VideoSplitter : public ISplitter
{
};
