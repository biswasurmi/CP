class Solution {
public:
    int dp1[1005], dp2[1005], dp[1005][1005][2];

    int func(int i1, int i2, int st, string& s, string& t) {
        if (i1 >= s.size() && i2 < 0) return 0;
        if (i1 >= s.size()) return dp2[i2];
        if (i2 < 0) return dp1[i1];
        if (dp[i1][i2][st] != -1) return dp[i1][i2][st];

        int ans = 0;
        if (st) {
            if (s[i1] == t[i2]) {
                ans = max(ans, func(i1 + 1, i2 - 1, st, s, t) + 2);
            } else {
                ans = max({ans, dp1[i1], dp2[i2]});
            }
        } else {
            ans = max({ans, func(i1 + 1, i2, st, s, t), func(i1, i2 - 1, st, s, t)});
            if (s[i1] == t[i2]) {
                ans = max(ans, func(i1 + 1, i2 - 1, 1, s, t) + 2);
            }
        }
        return dp[i1][i2][st] = ans;
    }

    void solve(string &s, string &t) {
        bool dpp[1005][1005] = {}, dpp1[1005][1005] = {};
        int n = s.size();

        for (int i = 0; i < n; i++) dpp[i][i] = 1;
        for (int i = 0; i < n - 1; i++) dpp[i][i + 1] = (s[i] == s[i + 1]);
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (s[i] == s[j] && dpp[i + 1][j - 1]) dpp[i][j] = 1;
            }
        }

        memset(dp1, 0, sizeof(dp1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dpp[i][j]) dp1[i] = max(dp1[i], j - i + 1);
            }
        }

        n = t.size();
        for (int i = 0; i < n; i++) dpp1[i][i] = 1;
        for (int i = 0; i < n - 1; i++) dpp1[i][i + 1] = (t[i] == t[i + 1]);
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (t[i] == t[j] && dpp1[i + 1][j - 1]) dpp1[i][j] = 1; 
            }
        }

        memset(dp2, 0, sizeof(dp2));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dpp1[i][j]) dp2[j] = max(dp2[j], j - i + 1);
            }
        }
    }

    int longestPalindrome(string s, string t) {
        solve(s, t);
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < s.size(); i++) ans = max(ans, dp1[i]);
        for (int i = 0; i < t.size(); i++) ans = max(ans, dp2[i]);

        return max(func(0, t.size() - 1, 0, s, t), ans);
    }
};
