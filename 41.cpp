class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // priority_queue<int>pq;
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);;
        }
        int ans=-1;
        int e=1;
        int r1=0;
        while(!pq.empty()){
            int r=pq.top();
            r1=r;
            if(r<=0)
            pq.pop();

            else{
                if(r==e){
                    pq.pop();
                    e++;
                }
                
                else if(r<e)
                pq.pop();
                else{
                    ans=e;
                    break;
                }

            }
        }
            if(ans==-1){
                if(r1<=0)
                return 1;
                return r1+1;
            }
            
            return ans;
        
    }
};
