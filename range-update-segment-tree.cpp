
ll arr[N];
ll mini[4*N];
ll maxi[4*N];
ll lazy[4*N];
void build(int v,int tl,int tr)
{
    if(tl>tr)
        return;
    if(tl==tr)
    {
        lazy[v]=0;
        maxi[v]=arr[tl];
        mini[v]=arr[tl];
        return;
    }
    ll mid=(tl+tr)/2;
    build(2*v,tl,mid);
    build(2*v+1,mid+1,tr);
    mini[v]=min(mini[2*v],mini[2*v+1]);
    maxi[v]=max(maxi[2*v],maxi[2*v+1]);
    lazy[v]=0;
}
ll maximum(int v,int tl,int tr,int l,int r)
{
    if(tl>tr)
        return (-1e18);
    if(tl>r || tr<l)
        return (-1e18);
    if(tl!=tr)
    {
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
    }
    mini[v]+=lazy[v];
    maxi[v]+=lazy[v];
    lazy[v]=0;
    if(tl>=l && tr<=r)
    {
        return maxi[v];
    }
    ll mid=(tl+tr)/2;
    return max(maximum(2*v,tl,mid,l,r),maximum(2*v+1,mid+1,tr,l,r));
}
ll minimum(int v,int tl,int tr,int l,int r)
{
    if(tl>tr)
        return (1e18);
    if(tl>r || tr<l)
        return (1e18);
    if(tl!=tr)
    {
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
    }
    mini[v]+=lazy[v];
    maxi[v]+=lazy[v];
    lazy[v]=0;
    if(tl>=l && tr<=r)
    {
        return mini[v];
    }
    ll mid=(tl+tr)/2;
    return min(minimum(2*v,tl,mid,l,r),minimum(2*v+1,mid+1,tr,l,r));
}
void update(int v,int tl,int tr,int l,int r,int val)
{
    if(tl>tr)
        return;
    if(tl!=tr)
    {
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
    }
    mini[v]+=lazy[v];
    maxi[v]+=lazy[v];
    lazy[v]=0;
    if(tl>r || tr<l)
        return;
    if(tl>=l && tr<=r)
    {
        lazy[v]+=val;
        if(tl!=tr)
        {
            lazy[2*v]+=lazy[v];
            lazy[2*v+1]+=lazy[v];
        }
        mini[v]+=lazy[v];
        maxi[v]+=lazy[v];
        lazy[v]=0;
        return;
    }
    ll mid=(tl+tr)/2;
    update(2*v,tl,mid,l,r,val);
    update(2*v+1,mid+1,tr,l,r,val);
    maxi[v]=max(maxi[2*v],maxi[2*v+1]);
    mini[v]=min(mini[2*v],mini[2*v+1]);
}
