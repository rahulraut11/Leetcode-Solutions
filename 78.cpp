class Solution {
public:


void find(vector<vector<int>>&ans,vector<int>&nums,int i){
    if(i==nums.size())
    return;

    int n=ans.size();
    for(int j=0;j<n;j++){
        vector<int>r=ans[j];
        r.push_back(nums[i]);
        ans.push_back(r);
    }
    find(ans,nums,i+1);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        ans.push_back(v);

        find(ans,nums,0);

        return ans; 
    }
};