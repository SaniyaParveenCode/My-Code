class Solution {
public:
    int countBinarySubstrings(string s) {
        int l=1, r=0; int ret = 0;
        int len = s.length();
        for(int i=1; i<len; i++)
        {
            if(s[i]==s[i-1])
                l++;
            else
            {
                ret+= min(l,r);
               r= l;
                l=1;
            }
        }
        return ret + min(l, r);
    }
};