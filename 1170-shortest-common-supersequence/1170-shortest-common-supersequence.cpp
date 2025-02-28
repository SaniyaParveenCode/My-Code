class Solution {
public: 

    string dp(int i, int j, string &str1, string &str2, vector<vector<string>>&mem){
        string ans;
        if(mem[i][j] != "1"){
            ans = mem[i][j];
        }
        else{
            if(i == str1.size() || j == str2.size()){
                ans = "";
            }           
            else{
                string aux;
                if(str1[i] == str2[j]){
                    aux = dp(i+1, j+1, str1, str2, mem);
                    ans = str1[i];
                    ans+=aux;
                }
                else{
                    ans = dp(i+1, j, str1, str2, mem);
                    aux = dp(i, j+1, str1, str2, mem);
                    if(aux.size() > ans.size()){
                        ans = aux;
                    }
                }
            }
            mem[i][j] = ans;
        }
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int i = 0, j = 0, k = 0;
        vector<vector<string>>mem(str1.size()+1, vector<string>(str2.size()+1, "1"));
        string ans = "", lcs = dp(0, 0, str1, str2, mem);

        while(i<str1.size() || j<str2.size()){
            if(i==str1.size()){
                ans+=str2[j];
                j++;
            }
            else if(j == str2.size()){
                ans+=str1[i];
                i++;
            }
            else{
                if(k<lcs.size() && str1[i] == lcs[k] && str2[j] == lcs[k]){
                    ans+=lcs[k];
                    k++;
                    i++;
                    j++;
                }
                else if(k<lcs.size() && str1[i] == lcs[k]){
                    ans+=str2[j];
                    j++;
                }
                else if(k<lcs.size() && str2[j] == lcs[k]){
                    ans+=str1[i];
                    i++;
                }
                else{
                    ans+=str1[i];
                    i++;
                }
            }
        }
        return ans;
    }
};