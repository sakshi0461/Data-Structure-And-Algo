class compare
{
    public:
    bool operator()(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first==p2.first)
        return p1.second>p2.second;
        return p1.first<p2.first;
    }
};
vector<int> Solution::getMode(vector<int> &a, vector<vector<int> > &b) {
    unordered_map<int,int> m;// map store the exact count of elements
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    vector<int> ans;

// take a max heap which store element count and its value
    priority_queue<pair<int,int> ,vector<pair<int,int> >,compare >pq;
    for(int i=0;i<n;i++)
        pq.push(make_pair(m[a[i]],a[i]));
        
    int i=0,q=b.size();
    while(i<q)
    {
        int index=b[i][0]-1;
        int val=b[i][1];
        int val1=a[index];
        a[index]=val;
        if(val!=val1)
        {
            m[val1]--;
        m[val]++;
        pq.push(make_pair(m[val1],val1));
        pq.push(make_pair(m[val],val));
        }
        while(true)
        {
            pair<int,int> t=pq.top();
            int cnt=t.first;int vall=t.second;
            if(m[vall]==cnt)
            {

         // when top of heap has cnt same as in map then this the answer for the ith query
                ans.push_back(vall);
                break;
            }
            else
            pq.pop();
        }
        i++;
    }
    return ans;
}