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
    void set_a(int new_a){
      if(new_a < 0){
        a = 0;
      }
      else{
        A::set_a(new_a);
      }
    }
      double foo(){
        return x*a;
      }

};

int main(){
    B b;
    A a;
    a.set_a(10);
    b.set_a(-50);
    cout << b.get_a() << endl;
    return 0;
}