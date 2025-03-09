class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int start = 0, end = 1 , n = colors.size() , count = 0;
        while(end < n+k -1) {
            if(colors[(end -1) % n] == colors[end % n]) {
                start = end;
            }
            if(end - start + 1 == k) {
                count++;
                start++;
            }
            end++;
        }
        return count;
    }
};
