#include <stdbool.h>
#include <string.h>

bool isScramble(char * s1, char * s2){
    int len = strlen(s1);
    if (len != strlen(s2)) return false;
    if (strcmp(s1, s2) == 0) return true;

    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    bool dp[len + 1][len][len];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (s1[i] == s2[j]) dp[1][i][j] = true;
        }
    }

    for (int l = 2; l <= len; l++) {
        for (int i = 0; i <= len - l; i++) {
            for (int j = 0; j <= len - l; j++) {
                for (int k = 1; k < l; k++) {
                    if ((dp[k][i][j] && dp[l - k][i + k][j + k]) || (dp[k][i][j + l - k] && dp[l - k][i + k][j])) {
                        dp[l][i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[len][0][0];
}