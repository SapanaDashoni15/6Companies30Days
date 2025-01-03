#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
        
        int n = secret.size();
        vector<int> freqbull(10, 0);
        vector<int> freqcow(10, 0);
        
        int bulls = 0;
        for(int i = 0; i<n; i++) {
            // if both places matched
            if(secret[i] == guess[i]) {
                bulls++;
            } else {
                //if not matched, increment the frequency of both the numbers
                freqbull[secret[i] -'0']++;
                freqcow[guess[i] -'0']++;
            }

        }
        
        int cows = 0;
        for(int i = 0; i< 10; i++) {
            //minimum of both the frequencies
            cows += min(freqbull[i], freqcow[i]);
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';

    }

int main() {
    string secret, guess;
    cin >> secret >> guess;
    string ans = getHint(secret, guess);
    cout << ans << endl;
    return 0;
}