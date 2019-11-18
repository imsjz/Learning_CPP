/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-13 19:45:41
 */
// file String.hpp
class StringRep;
class String{
public:
    String();
    String(const char* s);
    String(const String& s);
    String& operator=(const String& s);
    ~String();
...
private:
    StringRep* rep;
};