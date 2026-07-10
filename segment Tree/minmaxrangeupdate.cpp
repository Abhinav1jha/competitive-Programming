//ek range de rkha hoga jisme hume value update krni h and phir us range me min and max element bhi find krna h
//eske liye hum 2 array segmin and segmax rkhenge jisme wo node jis range ko denote krta h uska min and max store hoga usme
//also val update krne ke liye lazy propagation ka use krenge jisme agr wo range ke andar aa rha hoga toh us node ka lazy increase kr denge and uske childrens ke lazy me store kr denge taki agr hum un tk future me aaye toh update kr denge
void update(int start,int end,int i,int l,int r,int val){
  propagate(i,l,r);
  if(l>end || r<start)return;
  if(l>=start && r<=end){
    lazy[i]+=val;
    propagate(i,l,r);
    return;
  }
  int mid=(l+r)/2;
  update(start,end,2*i+1,l,mid,val);
  update(start,end,2*i+2,mid+1,r,val);
  segmin[i]=min(segmin[2*i+1],segmin[2*i+2]);
  segmax[i]=max(segmax[2*i+1],segmax[2*i+2]);
}
void propagate(int i,int l,int r){
  if(lazy[i]!=0){
    segmin[i]+=lazy[i];
    segmax[i]+=lazy[i];
    if(l!=r){
      lazy[2*i+1]+=lazy[i];
      lazy[2*i+2]+=lazy[i];
    }
    lazy[i]=0;
  }
}