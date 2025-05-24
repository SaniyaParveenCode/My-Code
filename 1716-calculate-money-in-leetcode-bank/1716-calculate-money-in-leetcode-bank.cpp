class Solution {
public:
    int totalMoney(int n) {
    int result = 0;
    int mon = 1;
    while(n > 0) {
        int money = mon;
        for(int day = 1;day <= min( n, 7); day++) {
            result += money;
            money++;    
        }
        n -= 7;
        mon++;
    }
    return result;
    }
};