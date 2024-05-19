#include <iostream>
using namespace std;

struct GroceryItem {
    int weight;
    int price;
    double costPerKg;
};

void bubbleSort(GroceryItem arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].costPerKg < arr[j + 1].costPerKg) {
                GroceryItem temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void fillBag(GroceryItem items[], int bagCapacity) {
    bubbleSort(items, 4);

    int totalWeight = 0;
    int totalPrice = 0;

    cout << "Items added to the bag:\n";
    for (int i = 0; i < 4; ++i) {
        if (totalWeight + items[i].weight <= bagCapacity) {
            totalWeight += items[i].weight;
            totalPrice += items[i].price;
            cout << items[i].weight << "kg of item Cost: " << items[i].price << "tk\n";
        }
    }

    cout << "Total Weight: " << totalWeight << "kg\n";
    cout << "Total Price: " << totalPrice << "tk\n";
}

int main() {
    const int bagCapacity = 10;

    GroceryItem items[4] = {
        {3, 470, 0},
        {2, 230, 0},
        {3, 360, 0},
        {5, 500, 0}

    };

    for (int i = 0; i < 4; ++i) {
        items[i].costPerKg = static_cast<double>(items[i].price) / items[i].weight;
    }

    fillBag(items, bagCapacity);

    return 0;
}
