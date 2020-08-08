class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>s;
        
        int j=0,i=0;
        
    while(i<pushed.size()){
        while(i<pushed.size() && popped[j]!=pushed[i]){
                s.push(pushed[i]);
                i++;
                }
           j++;
           i++;
        while(!s.empty() && s.top()==popped[j]){
            s.pop();
            j++;
        } 
    }
        
        while(!s.empty() && s.top()==popped[j] && j<popped.size()){
            s.pop();
            j++;
        }
       
        return s.empty();
    }
};