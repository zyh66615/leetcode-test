static int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    bool isMatch(string s, string p) {
        //使用动态规划,dp[i][j]表示s中前i个字符与p中前j个字符的匹配结果
        //动态规划适合解决当前状态依赖于之前状态的问题
        //注意：dp下标与s,p对应元素的下表相差1，也就是说，dp[i][j]表示当前应该匹配s[i-1]与p[j-1]
        int slen = s.size();
        int plen = p.size();
        bool** dp = new bool*[slen+1];
        for(int i = 0;i <= slen;++i){
            dp[i] = new bool[plen+1];
        }
        //当字符模式p为空时，匹配都是失败
        for(int i = 0;i <= slen;++i){
            dp[i][0] = false;
        }
        //当字符串和字符模式都为空时，匹配正确
        dp[0][0] = true;
        //遍历字符串和模式串
        for(int i = 0;i <= slen;++i){
            for(int j = 1;j <= plen;++j){
                //当前状态由当前模式字符决定
                if(p[j-1] == '*'){
                    /*如果当前模式字符位'*',那么当前状态由1、dp[i][j-2](此时s[i-1] != p[j-2]);
                    或者2、上一个模式字符位与当前字符位匹配，并且上一个字符位之前和当前模式字符位之前的字串相匹配
                    为什么满足条件2的状态也会成为dp[i][j]的状态呢？说白了这个条件就是重复匹配'*'前一个字符。当前所处的模式字符位为'*',它可匹配它前面相邻一个字符的多次匹配（因为条件1已经是重复0次的情况了，所以这里不考虑），那么也就是说如果前一个模式字符位(p中的j-2位)与当前字符位(s中的i-1位)相同的话，dp[i][j]的状态就由dp[i-1][j]决定*/
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[slen][plen];
        
    }
};