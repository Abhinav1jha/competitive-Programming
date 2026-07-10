int range(int start,int end,int i,int l,int r){
    if(r<start||l>end)return 0;
    if(l>=start && r<=end)return segtree[i];
    int mid=(l+r)/2;
    return range(start,end,2*i+1,l,mid)+range(start,end,2*i+2,mid+1,r);
}
//TC-worst case me 2 baar hi end node tk jaana pdega start ke liye aur end ke liye 2*log(n)=log(n)
