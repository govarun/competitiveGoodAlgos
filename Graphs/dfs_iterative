vi adj[];
bool vis[];
void dfs_iter(int st){ 
    //st - start
    stack <int> s;
    s.push(st);
    vis[st] = true;

    while(!s.empty()){
        int top = s.top();
        s.pop();
        f(i, adj[top].size()){
            int cur = adj[top][i];
            if(vis[cur] == false){
                s.push(cur);
                vis[cur] = true;
            }
        }
    }
}
