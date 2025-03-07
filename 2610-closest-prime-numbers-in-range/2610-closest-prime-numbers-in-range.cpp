class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>a(right+1 , true);
        a[0] = a[1] = false;

        for(int i= 2;i * i <= right; i++) {
            if(a[i]) {
                // all multiples of i as false
                for(int j = i*i;j<= right; j+=i) {
                    a[j] = false;
                }
            }
        }

        // collect prime
        vector<int>p;
        for(int i = left;i<=right;i++) {
            if(a[i]) {
                p.push_back(i);
            }
        }
        vector<int>res(2 , -1);
        int diff = INT_MAX;

        // if less than 2 primes , return [-1, -1]
        if(p.size() < 2) return res;

        for(int i=1;i<p.size();i++) {
            if(p[i] - p[i-1] < diff) {
                res[0] = p[i-1];
                res[1] = p[i];
                diff = p[i] - p[i-1];
            }
        }
        return res; 
    }
};