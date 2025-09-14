class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1e9 + 7;
        long long l = min(a, b);
        long long r = 1LL * n * min(a, b);  
        
        long long lcm_ab = lcm(a, b);
        
        while (l < r) {
            long long mid = (l + r) / 2;
            long long count = mid / a + mid / b - mid / lcm_ab;
            
            if (count < n) l = mid + 1;
            else r = mid;
        }
        
        return l % MOD;   
    }
    
    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    
    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
};