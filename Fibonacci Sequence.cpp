#include <iostream>
using namespace std;

int main() {

    int houseNum1 = 1;
    int houseNum2 = 2;
    int houseNum;

    cout << "First 20 house numbers:"<<endl;


    cout << houseNum1 << " "<<endl;
    cout << houseNum2 << " "<<endl;

    for (int i = 3; i <= 20; ++i) {
        houseNum = houseNum1 + houseNum2;
        cout << houseNum << " "<<endl;
        houseNum1 = houseNum2;
        houseNum2 = houseNum;
    }

    cout << "The 18th house number is: " << houseNum << endl;

    return 0;
}
