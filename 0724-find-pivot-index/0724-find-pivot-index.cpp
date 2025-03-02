class Solution {
public:
int pivotIndex(vector<int>& nums) {
int n = nums.size();
int total = 0 , pre = 0;
for(int i=0;i<n;i++) 
{
    total += nums[i];
}
for(int i=0; i<n;i++) {
    if(pre == total - pre -nums[i])
{
        return i;
}
    pre += nums[i];
}
return -1;
}
};