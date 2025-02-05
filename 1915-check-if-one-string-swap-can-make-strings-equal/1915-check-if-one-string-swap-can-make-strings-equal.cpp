class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

            if( s1 == s2) return true;  
            if(n != m) return false;   

            for(int i= 0;i<n;i++) {
            for(int j =i+1;j < n;j++) {
                
            swap(s2[i] , s2[j]);
                if(s1==s2) return true;  
                swap(s2[i] , s2[j]);   
            
        }         
        }
            return false;       
    }
    };

        