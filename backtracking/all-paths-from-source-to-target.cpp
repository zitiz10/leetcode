class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>path;
        path.push_back(0);
        dfs(graph,0,path,res);
        return res;
    }

private:
    void dfs(vector<vector<int>>&graph,int node, vector<int>&path,vector<vector<int>>&res){
        if(node==graph.size()-1){
            res.push_back(path);
            return ;
        }
        for(int neigh : graph[node]){
            path.push_back(neigh);
            dfs(graph,neigh,path,res);
            path.pop_back();
        }
    }
};