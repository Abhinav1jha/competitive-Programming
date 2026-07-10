//there will be a range given low to high and we have to count how many times a specific
//digit occured
#include<bits/stdc++.h>
using namespace std;
int dp[20][2][20];//digits(idx),tight,cnt..max no.can be 10^18 so max consider 20 digits
//tight 1 means we are bounded and we can choose from only those digits so that no.does
//not go beyond but when tight 0 then we can choose from any digit between 0 to 9
int solve(string &s,int idx,int tight,int cnt){
    if(idx==s.size()) return cnt;
    int limit=0;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    if(tight==1){
      limit=s[idx]-'0';
    }
    else limit=9;
    int ans=0;
    for(int i=0;i<=limit;i++){
        int updatedcnt=cnt;
        if(i==3) updatedcnt+=1;
        ans+=solve(s,idx+1,tight & (i==s[idx]-'0'),updatedcnt);
    }
    return dp[idx][tight][cnt]=ans;
}
int main(){
    int low,high;
    cin>>low>>high;
    string r=to_string(high);
    int rans=solve(r,0,1,0);
    string l=to_string(low-1);
    int lans=solve(l,0,1,0);
    cout<<rans-lans;
    return 0;
}