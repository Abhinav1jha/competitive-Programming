//in this we will learn range update query through lazy propagation
//we know how to update a value at an index but that takes O(logn) time so,for updating a range it will take O(nlogn).
//so,we will use lazy propagation. if a range is coming entirely in start to end then we will update its value.but we will not go left and right and update them and then come to update it.instead,we will find how many nodes are there in this range and everyone needs to get updated by that val so,we just update it by (r-l+1)*val.and store the update of its children in a lazy array so that if we ever come at this point again then we know that we have to update this value also.
//implement krne ke liye hr index pe pehle check krenge ki wahan pe koi lazy array me value h ya nhi.agr hoga toh yani yhan pe pending update h.toh hum sb se pehle us index pe seg[idx]=(r-l+1)*lazy[i] krennge and then us lazy value ko uske childrens tk bhi propagate kr denge.
//uske baad normal jese hum check krte h ki koi range start se end tk bahar h ya fully andar h ya overlap ho rha.agr fully andar h toh bs (r-l+1)*val se update and uske childrens ke lazy array me bhi wo val store krdenge
void update(int start,int end,int i,int l,int r,int val,vector<int>&seg,vector<int>&lazy){
  if(lazy[i]!=0){
    seg[i]+=(r-l+1)*lazy[i];
    if(l!=r){
    lazy[2*i+1]+=lazy[i];
    lazy[2*i+2]+=lazy[i];
    }
  }
  if(r>start || l>end || l>r)return;
  if(l>=start && r<=end){//completely inside
    seg[i]+=(r-l+1)*val;
    if(l!=r){
    lazy[2*i+1]+=val;
    lazy[2*i+2]+=val;
    }
  }
  else{
    int mid=(l+r)/2;
    update(start,end,2*i+1,l,mid,val,seg,lazy);
    update(start,end,2*i+2,mid+1,r,val,seg,lazy);
    seg[i]=seg[2*i+1]+seg[2*i+2];
  }
}
int main(){
  update(start,end,0,0,n-1,seg,lazy);
}