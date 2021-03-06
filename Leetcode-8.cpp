class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)
            return 0;
        int i=0;
        while(str[i]==' ')
            i++;
        
        bool minus=false;
        long long num=0;
        
        if(str[i]=='-')
        {
            minus=true;
            i++;
            if(str[i]<'0'||str[i]>'9')
                return num;
        }
        if(str[i]=='+')
        {
            minus=false;
            i++;
            if(str[i]<'0'||str[i]>'9')
                return num;
        }
        
 
        if(str[i]<'0'&&str[i]>'9')
            return num;
        
        while(str[i]!='\0'&&str[i]>='0'&&str[i]<='9')
        {
            num=num*10+(str[i]-'0');
            
            //检查是否溢出
            if(num==2147483649)
                return -2147483648;
            if(minus==true&&num>0xFFFFFFFF)
                return -2147483648;
            if(minus==true&&num<(signed int)0x800000000)
                return -2147483648;
            if(minus==false&&num>0x7FFFFFFF)
                return (int)0x7FFFFFFF;
            
            i++;
        }
        
        if(minus==false)
            return num;
        else
            return 0-num;
    }
};