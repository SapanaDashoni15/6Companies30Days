#include<bits/stdc++.h>
using namespace std;

int smoothen(int i, int j, vector<vector<int>> &img) {
        int n = img.size();
        int m = img[0].size();

        int sum = img[i][j], cnt = 1;
        vector<int> drow = {1, -1, 0, 0, -1, -1, 1, 1 };
        vector<int> dcol = {0, 0, -1, 1, -1, 1, -1, 1};

        for(int k = 0; k<8; k++) {
            int nr = i + drow[k];
            int nc = j + dcol[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m  ) {
                sum += img[nr][nc];
                cnt++;
            }
        }
        return sum/cnt;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[i][j] = smoothen(i, j, img);
            }
        }

        return ans;
    }

int main() {

    int n,m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> nums[i][j];
        }
    }

    vector<vector<int>> res;
    res = imageSmoother(nums);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}