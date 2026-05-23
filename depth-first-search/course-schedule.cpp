class Solution {
public:
    bool canFinish(int nums, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(nums);
        for(auto &edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(nums,false);
        vector<bool>recstack(nums,false);
        for(int i=0;i<nums;i++){
            if(!visited[i]){
                if(dfs(adj,visited,recstack,i))
                 return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&recstack, int node){
        visited[node]=true;
        recstack[node]=true;

        for(int neigh:adj[node]){
            if(!visited[neigh]){
                if(dfs(adj,visited,recstack,neigh))
                return true;
            }
                else if(recstack[neigh]) 
                return true;
            
        }
            recstack[node]=false;
            return false;
    }
};