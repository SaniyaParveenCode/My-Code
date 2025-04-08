class Solution {
public:
    int myAtoi(string s) {
        int l = s.length();
        if(l==0)
          return 0;
          int i = 0;
          for(;i<l and s[i]==' ';i++);
          if(i==l)
            return 0;
            int sign =1;
            if(s[i]=='-')
            {
                sign = -1;
                i = i+1;

            } 
            else if(s[i]=='+')
            {
                i=i+1;
            }
            long num = 0;
              while(i<l and num<INT_MAX and isdigit(s[i]))
                {
                    num = 10*num + (s[i]-'0');
                    i=i+1;
                }
                if(num>INT_MAX)
                {
                    if(sign ==1)
                    {
                        return INT_MAX;
                    }
                    else {
                        return INT_MIN;
                   }
                }
                return num*sign;
            }

};