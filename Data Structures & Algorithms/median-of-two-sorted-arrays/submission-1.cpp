class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2, nums1);
        bool odd = (n+m)%2;
        int part = (n+m+1)/2;

        int mid_1 = 0;
        int mid_2 = 0;

        int l = 0;
        int r = n;

        while(l<=r){
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            int mid1 = l+(r-l)/2;
            int mid2 = part - mid1;
            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];
            if(mid1<n) r1 = nums1[mid1];
            if(mid2<m) r2 = nums2[mid2];

            if(l1<=r2 && l2<=r1){
                if(odd)
                    return double(max(l1, l2));
                return double((max(l1, l2)+min(r2, r1))/2.0);
            }

            if(l1>r2) r = mid1-1;
            else l = mid1+1;

        }
        return 0.0;
    }
};
