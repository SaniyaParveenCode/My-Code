class Solution {
public:

void number_of_plates(string s, vector<int>&prefsum_plates){
   int cnt=0; 
for(int i=0;i<s.size();i++)
{
    if(s[i]=='*')cnt++;
    prefsum_plates[i]=cnt;
}
}

void vector_pref_candle(string&s,vector<int>&pref_candle){
    int last_idx=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='|')last_idx=i;
        pref_candle[i]=last_idx;
    }
}
void vector_suff_candle(string&s,vector<int>&suff_candle){
    int last_idx=-1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='|')last_idx=i;
        suff_candle[i]=last_idx;
    }
}
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>prefsum_plates(s.size(),0);
        vector<int>ans;
        vector<int>pref_candle(s.size(),0);
        vector<int>suff_candle(s.size(),0);
        vector_pref_candle(s,pref_candle);
        vector_suff_candle(s,suff_candle);
        number_of_plates(s,prefsum_plates);
        for(auto q:queries){
            int start=q[0];
            int end=q[1];
            int left=suff_candle[start];
            int right=pref_candle[end];
            if(left==-1||left==-1||right<=left)ans.push_back(0);
            else { 
               if(left!=0) ans.push_back(prefsum_plates[right]-prefsum_plates[left-1]);
               else ans.push_back(prefsum_plates[right]);
            }
        }
        return ans;
    }
};