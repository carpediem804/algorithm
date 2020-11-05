class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>>graph(n); //n개를 0으로 넣기 
        vector<int> degree(n,0) ; //n개를 0으로 넣기 
       
        if(n==1){
       
            ans.push_back(0);
            return ans ;
        }
        for(vector<int>&edge : edges){
            cout << edge[0] <<"\n";
            cout << edge[1]<<"\n";
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }   
        
        // leaf nodes to the centre
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int sz = q.size();
            n -= sz;
            for(int i=0;i<sz;i++){
                int t = q.front();
                q.pop();
                for(int j=0;j<graph[t].size();j++){
                    degree[graph[t][j]]--;
                    if(degree[graph[t][j]]==1){
                        q.push(graph[t][j]);
                    }
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};