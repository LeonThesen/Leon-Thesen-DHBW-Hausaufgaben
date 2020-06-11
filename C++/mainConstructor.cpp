#include <iostream>

using namespace std;

class Car {
    private:
    string brand;
    string model;
    int year;
    public:
    Car(string x,string y,int z) {
        brand=x;
        model=y;
        year=z;
    }
    string getBrand(){
        return brand;
    }
    string getModel(){
        return model;
    }
    string getYear(){
        return year;
    }
};

int main() {
    Car myCar1("BMW","X5",1999);
    Car myCar2("Ford","Mustang",1969);
    cout << myCar1.getBrand() << " " << myCar1.getModel() << " " << myCar1.getYear() << endl;
    cout << myCar2.getBrand() << " " << myCar2.getModel() << " " << myCar2.getYear() << endl;
    
    return 0;
}