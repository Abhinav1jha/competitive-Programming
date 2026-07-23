class Dinic{
  public:
  int n;
  vector<vector<int>>adj;
  vector<int>level;
  vector<vector<long long>>capacity;
  Dinic(int n){
    this->n=n;
    adj.resize(n);
    capacity.assign(n,vector<long long>(n,0));
    level.resize(n);
  }
  void addedge(int u,int v,long long cap){
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v]+=cap;
  }
  bool bfs(int s,int t){
    fill(level.begin(),level.end(),-1);
    queue<int>q;
    q.push(s);
    level[s]=0;
    while(q.size()!=0){
      int u=q.front();
      q.pop();
      for(auto it:adj[u]){
        if(level[it]==-1 && capacity[u][v]>0){
          level[it]=level[u]+1;
          q.push(it);
        }
      }
    }
    return level[t]!=-1;//mtlb hume drain tk ek increasing level path mil gya
  }
  //bfs se increasing level path dhundh liya phir usse ek dfs chla diya and ek min cap pta kiya pure path pe and usko hr forward wale edge me se sub kr diya and rev wale me add kr diya.
  //phir dubara nya level pta kiya jo ki increasing ho and phir se ye dfs wala part repeat
  long long dfs(int u,int t,long long flow){
    if(u==t)return flow;
    for(auto it:adj[u]){
      if(level[it]==level[u]+1 && capacity[u][v]>0){
        long long push=dfs(it,t,min(flow,capacity[u][v]));
        if(push>0){
          capacity[u][v]-=push;
          capacity[v][u]+=push;
          return push;//jo bhi min cap aaya us pure path pe
        }
      }
    }
    return 0;
  }
  long long maxflow(int s,int t){
    long long ans=0;
    while(bfs(s,t)){
      while(true){
        long long flow=dfs(s,t,LLONG_MAX);
        if(flow==0)break;
        ans+=flow;
      }
    }
    return ans;
  }
}