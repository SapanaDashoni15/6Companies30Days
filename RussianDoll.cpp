#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(),[](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }

                 return a[0] < b[0];
             });

        vector<int> ans;
        ans.push_back(nums[0][1]);

        for(int i = 1; i<n; i++) {
            if(nums[i][1] > ans.back()) {
                ans.push_back(nums[i][1]);
            } else {
                int lb = lower_bound(ans.begin(), ans.end(),nums[i][1]) - ans.begin();
                ans[lb] = nums[i][1];
            }
        }

        return ans.size();
    }

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m,0));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> nums[i][j];
        }
    }
    int ans = solve(nums);
    cout << ans << endl;
    return 0;
}