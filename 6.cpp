#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solve(vector<int> prices) {
    int max_val = 0;
    int n = prices.size();
    for (int buy1 = 0; buy1 < n; buy1++) {
        for (int sell1 = buy1+1; sell1 < n; sell1++) {
            if (prices[sell1]-prices[buy1] > max_val) {
                max_val = prices[sell1]-prices[buy1];
            }
            for (int buy2 = sell1+1; buy2 < n; buy2++) {
                for (int sell2 = buy2+1; sell2 < n; sell2++) {
                    if (prices[sell1]-prices[buy1]+prices[sell2]-prices[buy2] > max_val) {
                        max_val = prices[sell1]-prices[buy1]+prices[sell2]-prices[buy2];
                    }
                }
            }
        }
    }
    return max_val;
}



int main() {
    vector<int> prices1 {3,3,5,0,0,3,1,4};
    vector<int> prices2 {1,2,3,4,5};
    vector<int> prices3 {7,6,5,3,1};
    cout << solve(prices1) << endl;
    cout << solve(prices2) << endl;
    cout << solve(prices3) << endl;

    return 0;
}