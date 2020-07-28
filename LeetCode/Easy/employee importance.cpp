/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int find(unordered_map<int,pair<int,vector<int>>>graph,int id){
        int sum=graph[id].first;
        
        for(int i=0;i<graph[id].second.size();i++){
            int nextid=(graph[id].second)[i];
            sum+=find(graph,nextid);
        }
        
        return sum;
    }
    int getImportance(vector<Employee*> emp, int id) {
        unordered_map<int,pair<int,vector<int>>>graph(emp.size());
        
        for(int i=0;i<emp.size();i++){
            graph[emp[i]->id].first=emp[i]->importance;
            graph[emp[i]->id].second=emp[i]->subordinates;
        }
        
        return find(graph,id);
    }
};