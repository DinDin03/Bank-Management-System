#include <iostream>
#include <string>

using namespace std;

class BillBoard{
    private:
    string title;

    public:
    void setTitle(string x){
        title = x;
    }
    string getTitle(){
        return title;
    }
};

int main(){
    BillBoard bill;
    bill.setTitle("Top 5 songs of 2023");
    cout << bill.getTitle() << endl;
    return 0;
}