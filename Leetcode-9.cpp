class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
        string tmp=to_string(x);
        int left=0,right=tmp.size()-1;
        while(left<right)
        {
            if(tmp[left]!=tmp[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};