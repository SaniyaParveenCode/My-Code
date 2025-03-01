class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int age;
        int n = details.size();
        for(int i=0;i<n;i++) {
         age = (details[i][11] -'0') * 10 + (details[i][12] - '0');
            if(age>60) 
                count++;
            }
            return count;
    }
};

