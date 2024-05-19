#include <iostream>
using namespace std;

void payBack(int amount, int notes[], int supplySize) {
    cout << "Amount: " << amount << " taka" << endl;
    cout << "Notes used:" << endl;

    for (int i = 0; i < supplySize; ++i) {
        int noteCount = amount / notes[i];
        if (noteCount > 0) {
            cout << notes[i] << " taka notes: " << noteCount << endl;
            amount %= notes[i];
        }
    }
}

int main() {
    int amount = 2887;
    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2};
    int supplySize = sizeof(notes) / sizeof(notes[0]);

    payBack(amount, notes, supplySize);

    return 0;
}
