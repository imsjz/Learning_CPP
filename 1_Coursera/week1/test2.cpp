int main(){
    class A { public: int v; A *p;};
    A a; a.p  = & a; return 0;
}
