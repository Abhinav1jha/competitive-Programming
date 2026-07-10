void update(idx,i,l,r,val){//idx needs to update,i->root,l,rr,val this is the value
   if(l==r){
    segement[i]=val;//base case
    return;
   }
   int mid=(l+r)/2;
   if(idx<=mid){//left child
    update(idx,2*i+1,l,mid,val);
   }
   else{//right child
    update(idx,2*i+2,mid+1,r,val);
   }
   segement[i]=segement[2*i+1]+segment[2*i+2];

//not visiting all elements just height O(log2n);base
//then again apply range sum query
}