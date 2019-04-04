class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==0)
            return NULL;
        if(numRows==1)
            return s;
        vector<string>rows(min(numRows,int(s.size())));
        int cur=0;
        bool flag=false;
        for(auto c:s)
        {
            rows[cur]+=c;
            if(cur==0||cur==numRows-1)
                flag=!flag;
            cur+=flag?1:-1;
        }
        string res;
        for(auto i:rows)
            res+=i;
        return res;
    }
};