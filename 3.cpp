#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {}

    void addNum(int num) {
        arr.push_back(num);
        sort(begin(arr), end(arr));
        return;
    }

    double findMedian() {
        if (arr.size() % 2 == 0 && arr.size() >= 2) {
            return (arr[arr.size()/2] + arr[arr.size()/2 - 1])/2.0;
        } else if (arr.size() == 0) {
            return 0;
        } else {
            return arr[arr.size()/2];
        }
    }

};

int main() {
    MedianFinder object1;
    object1.addNum(1);
    object1.addNum(2);
    cout << object1.findMedian() << endl;
    object1.addNum(3);
    cout << object1.findMedian() << endl;
    return 0;
}