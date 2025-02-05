class Solution {
public:
 bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int>a;
            if( s1 == s2) return true;  
            for(int i= 0;i<m;i++)
             {
                if(s1[i]!=s2[i]) a.push_back(i);
            }
            if(a.size()==2)
            {
                int x = a[0] , y = a[1];
                if(s1[x]==s2[y] && s1[y]==s2[x]) return true;
            }
            return false;       
    }
    };

        