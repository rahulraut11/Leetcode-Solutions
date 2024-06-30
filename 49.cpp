class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

vector<pair<string,string>>v;
for(int i=0;i<strs.size();i++){
    string p=strs[i];
    sort(p.begin(),p.end());
    v.push_back({p,strs[i]});
}

sort(v.begin(),v.end());
string r=v[0].first;
vector<vector<string>>ans;
vector<string>mp;

mp.push_back(v[0].second);
for(int i=1;i<v.size();i++){
    if(v[i].first==r){
        mp.push_back(v[i].second);
    }
    else{
        ans.push_back(mp);
        r=v[i].first;
        mp.clear();
        mp.push_back(v[i].second);

    }
}

if(mp.size()>0){
    ans.push_back(mp);
    }
return ans;
        
    }
};