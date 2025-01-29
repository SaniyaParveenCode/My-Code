class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int hIndex = 0;
        for(int i=0;i<n;i++) {
            if(citations[i] >= n-i){
            hIndex = n-i;
            break;
        }
    }
return hIndex;
    }
};