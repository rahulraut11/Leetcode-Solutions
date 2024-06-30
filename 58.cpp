class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        vector<int>v;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')
            ans++;
                
            else if(s[i]==' '){
                if(ans>0)
                v.push_back(ans);
                ans=0; 

            }
               

        }
        if(ans>0)
        v.push_back(ans);
        return v[v.size()-1];
        
    }
};