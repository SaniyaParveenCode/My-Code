class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        int count[3] = {a,b,c};
        char ch[3] = {'a','b','c'}; 

        while(true) {
            int maxIndex = -1;
            for(int i = 0;i<3;i++) {
                if(count[i] ==0  ) continue;
                if(result.size() >= 2 && 
                result[result.size() -1] == ch[i] && 
                 result[result.size() -2] == ch[i]) {
                    continue;
                 } 
                 if(maxIndex == -1 || count[i] > count[maxIndex]) {
                    maxIndex = i;
                 }
            }
            if( maxIndex ==-1) break;
            result+= ch[ maxIndex];
            count[ maxIndex]--;
        }
        return result; 
    }
};