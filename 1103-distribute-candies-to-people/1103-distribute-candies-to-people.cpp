class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people , 0);
        int i = 0, give = 1;

        while(candies > 0) {
            ans[i % num_people] += min(give , candies);
            candies -= give;
            give++;
            i++;
        }
        return ans; 
    }
};