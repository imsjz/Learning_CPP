#ifndef __TEMPLATE_NAMESPACE_H__
#define __TEMPLATE_NAMESPACE_H__

namespace sanjay{

    //类模板
    template<typename T>
    class complex{
    public:
        complex(T r = 0, T i = 0): re(r), im(i){

        }
        T real() const { return re; }
        T imag() const { return im; }

    private:
        T re, im;
    };

    class stone{
    public:
        stone(int w, int h, int weight): _w(w), _h(h), _weight(weight){}
        bool operator<(const stone& rhs) const{
            return _weight < rhs._weight;
        }
    private:
        int _w, _h, _weight;
    };

    //函数模板
    template<class T>
    inline
    const T& min(const T& a, const T& b){
        return b < a ? b : a;
    }

};

#endif