#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to return k closest elements to x
vector<int> printKClosest(vector<int> &arr, int k, int x) {
    
    // Custom comparator using absolute difference and tie-breaker
    sort(arr.begin(), arr.end(), [x](int a, int b) {
        int diffA = abs(a - x);
        int diffB = abs(b - x);
        // If differences are equal, prefer the larger element
        if (diffA == diffB)
            return a > b;
        return diffA < diffB;
    });

    vector<int> result;
    int count = 0;

    // Pick first k elements which are not equal to x
    for (int num : arr) {
        // skip if element is equal to x
        if (num == x) continue; 
        result.push_back(num);
        count++;
        if (count == k)
            break;
    }

    return result;
}

// Main function with example
int main() {
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int x = 35;

    vector<int> closest = printKClosest(arr, k, x);
    
    for (int num : closest) {
        cout << num << " ";
    }

    return 0;
}
