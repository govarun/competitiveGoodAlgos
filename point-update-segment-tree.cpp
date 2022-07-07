// This code assigns a value to particular position 
// and gives minimum value in a range
// asks for array a
void build(int v,int tl,int tr)
{
    if(tl>tr)
        return;
    if(tl==tr)
    {
        tree[v]=a[tl];
        return;
    }
    ll mid=(tl+tr)/2;
    build(2*v,tl,mid);
    build(2*v+1,mid+1,tr);
    tree[v]=tree[2*v]+tree[2*v+1];
}
ll sum(int v,int tl,int tr,int l,int r)
{
    if(tl>tr)
        return 0;
    if(tl>r || tr<l)
        return 0;
    if(tl>=l && tr<=r)
        return tree[v];
    ll mid=(tl+tr)/2;
    return (sum(2*v,tl,mid,l,r)+sum(2*v+1,mid+1,tr,l,r));
}
void assign(int v,int tl,int tr,int pos,ll val)
{
    if(tl>tr)
        return;
    if(tl>pos || tr<pos)
        return;
    if(tl==tr)
    {
        tree[v]=val;
        if(v%2==1)
            v--;
        while(v>0)
        {
            tree[v/2]=(tree[v]+tree[v+1]);
            v/=2;
            if(v%2==1)
                v--;
        }
        return;
    }
    ll mid=(tl+tr)/2;
    assign(2*v,tl,mid,pos,val);
    assign(2*v+1,mid+1,tr,pos,val);
}
