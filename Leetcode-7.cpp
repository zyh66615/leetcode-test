#include <algorithm>
#include <sstream>
class Solution {
public:
    int reverse(int x) {
        if(x==0||x<=-2147483648||x>=2147483647)
            return 0;
        bool flag=false;
        if(x<0)
        {
            x=-x;
            flag=true;
        }
        string res = std::to_string(x);
        std::reverse(res.begin(),res.end());
        stringstream a(res);
        long ans;
        a>>ans;
        if(flag)
            ans=-ans;
        if(ans<-2147483648||ans>2147483647)
            return 0;
        return ans;
    }
};