class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      for(int i=0;i<nums2.size();i++){
          nums1.push_back(nums2[i]);
      }  
      sort(nums1.begin(),nums1.end());
      int n=nums1.size();
      double c=0.0;
      if(n%2==0){
          int a=nums1[n/2];
          int b=nums1[(n/2)-1];
     c=(a+b)/2.0;
      }
      else

 c=(double)nums1[n/2];
      return c;
    }
};
