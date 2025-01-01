#include<bits/stdc++.h>
using namespace std;

int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i = 1; i<=n; i++) {
            nums.push_back(i);
        }

        int start = 0;
        while(nums.size() > 1) {
            int num2Delete = (start + k - 1) % nums.size();
            nums.erase(nums.begin() + num2Delete);
            start = num2Delete;
        }

        int ans = nums[0];
        return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int ans = findTheWinner(n, k);
    cout << ans << endl;
}