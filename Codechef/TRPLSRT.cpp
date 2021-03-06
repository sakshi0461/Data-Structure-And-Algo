#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n,k;
        cin>>n>>k;
        
        vector<int>v;
        unordered_map<int,deque<int>>m1;
        
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
            m1[a].push_back(i);
        }
        
        vector<int>vc=v;
        sort(vc.begin(),vc.end());
        unordered_map<int,queue<int>>m2;
        
        for(int i=0;i<n;i++){
            m2[vc[i]].push(i);
        }
        
        int count=0,p=0;
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            if(v[i]==vc[i])
              continue;
              
            int index1=i;
            int index2=m2[v[i]].front();
            int index3=m1[vc[i]].back();
           if(index2==index3){
              index2=m1[vc[index3]].back();
               
               if(index2==index1 ){
                   for(int i=index1+1;i<n;i++){
                       if(vc[i]!=v[i] && i!=index3){ 
                           index2=i;
                           break;
                       }
                   }
                   if(index2==index1){
                   for(int i=index1+1;i<n;i++){
                       if(v[i]!=v[index3] ){
                        index2=i;
                        break;}
                   }
                  }
               }
           }

           if(index2==index1 || index3==index1){
               p=1;
               cout<<"-1\n";
               break;
           }
        
            int p1=v[index1];
            int p3=v[index3];
            int p2=v[index2];
               
            if(v[index1]==v[index2]){
             if(index1<index2){
                m1[v[index1]].pop_front();
                if(index2<index3)
                 m1[v[index2]].push_back(index3);
                else
                 m1[v[index2]].push_front(index3);
              }
             else{
                m1[v[index1]].pop_back();
                if(index2<index3)
                  m1[v[index2]].push_back(index3);
                else
                  m1[v[index2]].push_front(index3);
              }
            }
            else if(v[index2]==v[index3]){
                if(index2<index3){
                    m1[v[index2]].pop_front();
                     if(index3>index1)
                       m1[v[index3]].push_front(index1);
                     else
                       m1[v[index3]].push_back(index1);
                }
                else{
                    m1[v[index2]].pop_back();
                     if(index3>index1)
                       m1[v[index3]].push_front(index1);
                     else
                       m1[v[index3]].push_back(index1);
                }
            }
            else{
                m1[v[index1]].pop_back();
                m1[v[index1]].push_front(index2);
                m1[v[index3]].pop_back();
                m1[v[index3]].push_front(index1);
                m1[v[index2]].pop_back();
                m1[v[index2]].push_front(index3);   
            }
            
            v[index1]=p3;
            v[index2]=p1;
            v[index3]=p2;
            
            count++;

            vector<int>temp={index1+1,index2+1,index3+1};
            ans.push_back(temp);

            if(count>=k+1){
                p=1;
                cout<<"-1\n";
                break;
            }
        }
        
        if(p==0){
            
            cout<<count<<"\n";
            for(int i=0;i<ans.size();i++){
                cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
            }
        }
        
    }
    return 0;
}