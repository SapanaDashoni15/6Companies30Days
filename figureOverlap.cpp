#include<bits/stdc++.h>
using namespace std;

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,int x2, int y2) {

        if (y1 > xCenter + radius || y2 < xCenter - radius ||
            x2 < yCenter - radius || x1 > yCenter + radius) {
            return false;
        }

        return true;
    }

int main() {
    int r,xc,yc,x1,y1,x2,y2;
    cin >> r >> xc >> yc >> x1 >> y1 >> x2 >> y2 ;
    bool ans = checkOverlap(r, xc, yc, x1, y1,x2,y2);
    cout << ans << endl;

    return 0;
}