#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool diff_func(vector<int> &arr, int indexDiff, int valueDiff) {
    multiset<int> mult;
    int length = arr.size();
    int i = 0, j = 0;
    while (j<length) {
        auto up_br = mult.upper_bound(arr[j]);
        if ((up_br != mult.end() && *up_br - arr[j] <= valueDiff) || (up_br != mult.begin() && arr[j] - *(--up_br) <= valueDiff)) {
            return true;
        }
        mult.insert(arr[j]);
        if (mult.size() == indexDiff+1) {
            mult.erase(arr[i]);
            i++;
        }
        j++;
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << diff_func(nums, 3, 0) << endl;
    vector<int> nums2 = {1,5,9,1,5,9};
    cout << diff_func(nums2, 2, 3) << endl;
    return 0;
}