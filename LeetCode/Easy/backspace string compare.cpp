class Solution {
public:
  //METHOD 1
    bool backspaceCompare(string S, string T) {
      string s="",t="";
        for(auto i:S){
            if(i!='#')
                s.push_back(i);
            else{
                if(s.size()>0)
                    s.pop_back();
            }
        }
         for(auto i:T){
            if(i!='#')
                t.push_back(i);
            else{
                if(t.size()>0)
                    t.pop_back();
            }
        }
        return s==t;
    }
};