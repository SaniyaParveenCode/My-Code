class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller;
        vector<int>larger;
        vector<int>equal;

        for(int num: nums) {
            if(num < pivot) {
            smaller.push_back(num);
            }
            else if(num==pivot) {
                equal.push_back(num);
            }
            else {
                larger.push_back(num);            }    
            }
            smaller.insert(smaller.end() ,equal.begin() ,equal.end());
            smaller.insert(smaller.end() ,larger.begin() , larger.end());
    return smaller;
    }
};