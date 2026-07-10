#include<bits/stdc++.h>
using namespace std;
long long dp[20][2][20];
long long solve(string &s,int idx,int tight,int cnt){
    if(cnt>3) return 0;
    if(idx==s.size()) return 1;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    int limit=0;
    if(tight==1) limit=s[idx]-'0';
    else limit=9;
    long long ans=0;
    for(int i=0;i<=limit;i++){
        int newcnt=cnt;
        if(i!=0) newcnt++;
        ans+=solve(s,idx+1,tight &(i==s[idx]-'0'),newcnt);
    }
    return dp[idx][tight][cnt]=ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long low,high;
        cin>>low>>high;
        string l=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        long long lans=solve(l,0,1,0);
        string r=to_string(high);
        memset(dp,-1,sizeof(dp));
        long long rans=solve(r,0,1,0);
        cout<<(rans-lans)<<endl;
    }
    return 0;
}
// //999999 1000001
// //1000000000000000000 1000000000000000000
