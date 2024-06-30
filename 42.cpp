class Solution {
public:


       
    int trap(vector<int>& arr) {
        int n=arr.size();
  vector<int>left(n,0),right(n,0);
        int l_mx=0;
        int r_mx=0;
        for(int i=1;i<n;i++){
            l_mx=max(l_mx,arr[i-1]);
            left[i]=l_mx;
            
            
        }
        for(int i=n-2;i>=0;i--){
            r_mx=max(r_mx,arr[i+1]);
            right[i]=r_mx;
        }
        // for(auto i:left)
        // cout<<i<<" ";
        
        // for(auto i:right)
        // cout<<i<<" ";
        
        long long ans=0;
       
       for(int i=0;i<n;i++){
           int mn=min(left[i],right[i]);
           if(mn>arr[i])
           ans+=(min(left[i],right[i])-arr[i]);
       }
       return ans;
    }
};
