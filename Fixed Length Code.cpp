#include <iostream>
#include <algorithm>
using namespace std;

struct CharFreq {
    char ch;
    int freq;
};

bool compareFreq(const CharFreq& a, const CharFreq& b) {
    return a.freq > b.freq;
}

void findFixedLengthCode(CharFreq charFreq[], int n) {

    sort(charFreq, charFreq + n, compareFreq);

    int codeLength = 3;

    cout << "Fixed-length codes for characters:" << endl;
    for (int i = 0; i < n; ++i) {
        char ch = charFreq[i].ch;
        int f = charFreq[i].freq;
        int code = 0;

        for (int j = 0; j < codeLength; ++j) {
            code |= (f % 2) << j;
            f /= 2;
        }

        cout << ch << " : ";
        for (int j = codeLength - 1; j >= 0; --j) {
            cout << ((code >> j) & 1);
        }
        cout << endl;
    }
}

int main() {

    CharFreq charFreq[] = {
        {'a', 45},
        {'b', 13},
        {'c', 12},
        {'d', 16},
        {'e', 9},
        {'f', 5}
    };
    int n = sizeof(charFreq) / sizeof(charFreq[0]);

    findFixedLengthCode(charFreq, n);

    return 0;
}
