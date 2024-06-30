class Solution {
public:

void generate(int left,int right,string &str,vector<string> &v){
    if(right==0 && left==0)  // all brac finished string is generated oush in vector
    v.push_back(str);

    if(left>right || left<0 || right<0)
    return;
    
    str.push_back('(');
    generate(left-1,right,str,v);
    str.pop_back();

    str.push_back(')');
    generate(left,right-1,str,v);
    str.pop_back();



}

    vector<string> generateParenthesis(int n) {
          vector<string>ans;
          string str="";
          generate(n,n,str,ans);
          return ans;

  

    }

 
};
