#include <iostream>

using namespace std;

class myClass {
    public:
    string myName;
    void printName() {
        cout << "My Name is " << myName << endl;
    }
};

int main() {
    //declare an object of MyClass
    myClass object1;
    object1.myName= "Leon";
    object1.printName();
    return 0;
}