class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
          int i=0,j=0;
          while(i<name.length() && j<typed.length()){
                  if(name[i]==typed[j]){
                          i++;
                          j++;
                          continue;
                  }
                 if(j>0 && typed[j]==typed[j-1]){
                         j++;
                         continue;
                 }
                  return false;
          }
            while(j<typed.length()){
                    if(typed[j]==typed[j-1])
                            j++;
                    else
                            return false;
            }
            if(j!=typed.length() || i!=name.length())
                    return false;
            
            return true;
    }
};