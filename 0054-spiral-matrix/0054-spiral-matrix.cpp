class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

int n = matrix.size();
int m = matrix[0].size();
vector<int>output;
if(n==0) {
return output;
}

int top = 0; 
int bottom = n - 1;
int left = 0;
int right = m - 1;

while(top <= bottom && left <=right) {
    
for(int j = left;j<=right;j++) {
    output.push_back(matrix[top][j]);
}
top++;


for(int i = top;i<=bottom;i++) {
    output.push_back(matrix[i][right]);
}
right--;


if(top <= bottom) {
for(int k = right;k>=left;k--) {
    output.push_back(matrix[bottom][k]);
}
}
    bottom--;

if(left<= right) {
for(int l = bottom;l>=top;l--) {
    output.push_back(matrix[l][left]);
}
}
    left++;
}
return output;
}
};


