class Solution {
public:
    // comparator function to sort in accordance to no of units per boxes
    static int comp(vector<int>&a,vector<int>&b)
    {  
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truck) {
       int n=boxTypes.size();
    
     //   We can easiliy observe that it will always be better to choose the box with maximum number of units in it so that the overall number of units that can be put on truck is maximized.
     // thus sort the vector in the order in which we will try to maximise the number of units per boxes

        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
       //  keep choosing the boxes starting from the first one from the sorted array till we fill the whole truck  
           
            if(truck-boxTypes[i][0]>=0)
            {
               ans+=(boxTypes[i][0] * boxTypes[i][1]); 
                truck-=boxTypes[i][0];
            }
            else
            {
              // condition when our truck size is less than no of boxes  
               ans+=(truck * boxTypes[i][1]); 
               break; 
            }
        }
        return ans;
    }
};