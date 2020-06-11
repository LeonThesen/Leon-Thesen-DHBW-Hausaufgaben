#include <iostream>

using namespace std; //kann man die std weglassen

int main() {

    double summand1,summand2,ergebnis;

    cout << "first arg: " << endl;
    cin >> summand1;
    cout << "sec arg: " << endl;
    cin >> summand2;
    ergebnis=summand1+summand2;
    cout << summand1 << "+" << summand2
            << "=" << ergebnis << endl;
    return 0;
}