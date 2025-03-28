vector<vector<int>> adj(n);
vector<bool> vis(n);

void dfs(int curr)
{
    if(vis[curr]) return;

    vis[curr]=true;

    for(auto &ele:adj[curr])
    {
        dfs(ele);
    }

}

for(int i=0;i<n;i++)
{
    if(!visisted[i])
    {
        queue<int> q;

        q.push(i);

        visited[i]=true;
        while(!q.empty())
        {
            int curr_node = q.front();
            q.pop();
            for(auto ele:adj[curr_node])
            {
                if(!visited[ele])
                {
                    visited[ele]=1;
                    q.push(ele);
                }
            }
        }
    }
}

void sieve(int n,vector<int> &prime)
{
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

prime[0]=prime[1]=false;