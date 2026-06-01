class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m-1;
        int mid = 0;

        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(!l)
            return false;
        int x = l-1;
        l = 0;
        r = n-1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[x][mid]==target)
                return true;
            else if(matrix[x][mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
};
