#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    string str;
    cin >> str;

    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    ll ans = 0;
    string strToreturn = "";

    for (int diff = 0; diff < n; diff++)
    {
        for (int i = 0, j = i + diff; j < n; j++, i++)
        {
            if (diff == 0)
            {
                dp[i][j] = 1;
            }
            else if (diff == 1)
            {
                if (str[i] == str[j]) {
                    dp[i][j] = 2;
                }
            }
            else{
                if ((str[i] == str[j]) && dp[i + 1][j - 1] > 0) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (dp[i][j] > ans){
                        ans = dp[i][j];
                        strToreturn = str.substr(i, dp[i][j]);
                    }
                }
            }
        }
    }

    cout << ans << " " << endl;
    cout << strToreturn<<endl;

    return 0;
}