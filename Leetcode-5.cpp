
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int **dp = new int*[len+1];
        for(int i = 0; i < len+1; i++)
            dp[i] = new int[len+1];
        for(int i = 0; i < len+1; i++){
            for(int j = 0; j < len+1; j++){
                dp[i][j] = 0;
            }
        }
        for(int j = 0; j < len; j++){
            dp[j][j] = 1;
            dp[j+1][j] = 1;//这里也就是说的要手动初始话的这种情况
        }
        int l = 0, r = 0;
        for(int i = 1; i < len; i++){
            for(int j = 0; j+i < len; j++){
                if(s[j] == s[i+j] && dp[j+1][i+j-1]){//为了保证j+1 <= i+j-1, i >= 2那么将i也就是长度为1的手动初始化
                    l = j;
                    r = j + i;
                    dp[l][r] = 1;
                }
            }
        }
        string str = "";
        for(int i = l; i <= r; i++)
            str += s[i];
        delete dp;
        return str;
        
    }
};