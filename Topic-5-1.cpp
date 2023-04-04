#include <iostream>
#include <string>

using namespace std;

class A{
    public: 
      int a;
      void set_a(int new_a){
        this->a = new_a;
      }
      int get_a() const{ // const tells to the class that the function does not change the object value
        return a;
      }
};

class B : public A {
    private:
      double x;
    public:
    void set_x(double x){this->x = x;}
      double foo(){
        return x+a;
      }

};

int main(){
    B b;
    b.set_a(10);
    b.set_x(0.2);
    cout << b.foo() << endl;
    return 0;
}