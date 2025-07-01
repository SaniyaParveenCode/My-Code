class Solution {
public:
bool isValid(vector<vector<int>>& image,int i , int j,  int n , int m ,int color) {
    if(i>= 0&& i<n && j>=0 && j<m && image[i][j] == color)
      return true;
    return false;  
}

 void floodFillRec(vector<vector<int>>& image, int i , int j ,   int n , int m ,int color, int newColor) {

    image[i][j] = newColor;

    if(isValid(image , i+1 , j,n,m,color))
      floodFillRec(image ,i+1 , j,n,m,color , newColor);

    if(isValid(image , i-1 , j,n,m,color))
       floodFillRec(image ,i-1 , j,n,m,color , newColor);

    if(isValid(image , i , j+1,n,m,color))
      floodFillRec(image ,i , j+1,n,m,color , newColor);

    if(isValid(image , i , j-1,n,m,color))
      floodFillRec(image ,i, j-1,n,m,color , newColor);


}


    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int color = image[i][j];
        if (color == newColor) return image;

        floodFillRec(image ,i, j,n,m , color , newColor);
        return image;
    }
};