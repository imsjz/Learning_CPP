//业务操作
class Stream
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

//主体类
class FileStream : public Stream
{
public:
    virtual char Read(int number)
    {
        //读文件流
    }
    virtual void Seek(int position)
    {
        //定位文件流
    }
    virtual void Write(char data)
    {
        //写文件流
    }
};

class NetworkStream : public Stream
{
public:
    virtual char Read(int number)
    {
        //读网络流
    }
    virtual void Seek(int position)
    {
        //定位网络流
    }
    virtual void Write(char data)
    {
        //写网络流
    }
};

class MemoryStream : public Stream
{
public:
    virtual char Read(int number)
    {
        //读内存流
    }
    virtual void Seek(int position)
    {
        //定位内存流
    }
    virtual void Write(char data)
    {
        //写内存流
    }
};

//扩展操作===========================
class CryptoStream : public Stream //继承这个是为了规范下面接口
{
    Stream *stream; //new filestream;
public:
    CryptoStream(Stream* stm):stream(stm){}
    virtual char Read(int number)
    {

        //额外的加密操作...
        stream->Read(number); //读文件流
    }
    virtual void Seek(int position)
    {
        //额外的加密操作...
        stream->Seek(position); //定位文件流
        //额外的加密操作...
    }
    virtual void Write(byte data)
    {
        //额外的加密操作...
        stream->Write(data); //写文件流
        //额外的加密操作...
    }
};

class BufferedFileStream : public FileStream
{
    //...
};

class CryptoBufferedFileStream : public FileStream
{
public:
    virtual char Read(int number)
    {

        //额外的加密操作...
        //额外的缓冲操作...
        FileStream::Read(number); //读文件流
    }
    virtual void Seek(int position)
    {
        //额外的加密操作...
        //额外的缓冲操作...
        FileStream::Seek(position); //定位文件流
        //额外的加密操作...
        //额外的缓冲操作...
    }
    virtual void Write(byte data)
    {
        //额外的加密操作...
        //额外的缓冲操作...
        FileStream::Write(data); //写文件流
        //额外的加密操作...
        //额外的缓冲操作...
    }
};

void Process()
{

    //运行时装配
    FileStream* s1 = new FileStream;
    CryptoStream* s2 = new CryptoStream(s1);
}