class Solution {
public:
void dfs(int node,vector<int>adj[],vector<int> &vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(v,0);
        int provinces=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,adj,vis);
            }
        }
    return provinces;
    }
};

// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
//         vis[node] = 1;
//         for (int j = 0; j < isConnected.size(); j++) {
//             if (isConnected[node][j] == 1 && !vis[j]) {
//                 dfs(j, isConnected, vis);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<int> vis(n, 0);
//         int provinces = 0;

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 provinces++;
//                 dfs(i, isConnected, vis);
//             }
//         }

//         return provinces;
//     }
// };






