class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        
        for(int i=low;i<=high;i++){
            string num=to_string(i);
            if (num.length() % 2 != 0) continue;
            string onehalf=num.substr(0,num.length()/2);
            string shalf=num.substr(num.length()/2);
            int sum1=0;
            int sum2=0;
            for (char c : onehalf) {
            sum1 += c - '0';
        }

        for (char c : shalf) {
            sum2 += c - '0';
        }
            if(sum1==sum2){
                cnt++;
            }

        }
        return cnt;
        
    }
};