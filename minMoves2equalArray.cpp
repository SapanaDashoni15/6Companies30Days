#include <bits/stdc++.h>
using namespace std;

int minMoves2(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0; // Handle empty input edge case

    // Sort the array to find the median
    sort(nums.begin(), nums.end());
    
    // The median minimizes the sum of absolute differences
    int median = nums[n / 2];
    
    int totalChanges = 0;
    for (int num : nums) {
        totalChanges += abs(num - median);
    }

    return totalChanges;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = minMoves2(nums);
    cout << ans << endl;

    return 0;
}
