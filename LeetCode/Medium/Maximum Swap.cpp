class Solution {
public:
    int maximumSwap(int num) {
        
        deque<pair<char,int>>s;
        string s1=to_string(num);
        
        for(int i=0;i<s1.length();i++){
            char n=s1[i];
            while(!s.empty() && s.back().first<=n)
                s.pop_back();
            
            s.push_back(make_pair(n,i));
        }
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<s1.length();i++){
            if(s.empty())
               continue;
            if(s.front().second==i)
                s.pop_front();
            else if(s.front().second>i){
                if(s1[s.front().second]==s1[i])
                continue;
                swap(s1[i],s1[s.front().second]);
                return stoi(s1);
            }
        }
        
        return stoi(s1);
    }
};