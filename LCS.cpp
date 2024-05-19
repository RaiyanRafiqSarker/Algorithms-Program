#include <iostream>
using namespace std;

int main() {
    string word1 = "madhabilata";
    string word2 = "madhurika";

    int count1[26] = {0};
    int count2[26] = {0};

    for (char c : word1) {
        count1[c - 'a']++;
    }

    for (char c : word2) {
        count2[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count1[i] > 0 && count2[i] > 0) {
            int common = min(count1[i], count2[i]);
            for (int j = 0; j < common; j++) {
                cout << (char)('a' + i);
            }
        }
    }

    return 0;
}

