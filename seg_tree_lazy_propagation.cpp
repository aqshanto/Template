const int N = 1e5;

int n,m;

int st[4*N+10],lazy[4*N+10],arr[N+10];

void build(int u,int s,int e){
	if(s==e){
		st[u]=arr[s];
		return;
	}
	int v = (u<<1),w = v|1,m = (s+e)>>1;
	build(v,s,m);
	build(w,m+1,e);
	st[u]=st[v]+st[w];
}

void printTree(int u, int s, int e, int indent = 0) {
    if (s == e) {
        cout << string(indent, ' ') << "-> " << st[u] << "([" << s<< "-"<<e << "])" << endl;
        return;
    }
    int mid = (s + e) / 2;
    int right_child = 2 * u + 1;
    int left_child = 2 * u;
    printTree(right_child, mid + 1, e, indent + 8);
    cout << string(indent, ' ') << "-> " << st[u] << "([" << s << "-" << e << "])" << endl;
    printTree(left_child, s, mid, indent + 8);
}

void push(int u,int s,int e){
	if(lazy[u]==0)return;
	st[u]+=lazy[u]*(e-s+1);
	int v= u<<1,w= v|1;
	if(s!=e){
		lazy[v]+=lazy[u];
		lazy[w]+=lazy[u];
	}
	lazy[u]=0;
}

void Update(int l,int r,int val,int u=1,int s=1,int e=n){
	push(u,s,e);
	int v = (u<<1),w = v|1,m = (s+e)>>1;
	if(e<l || r<s)return;
	if(l<=s && e<=r){
		st[u]+= val*(e-s+1);
		if(s!=e){
			lazy[v]+=val;
			lazy[w]+=val;
		}
		return;
	}
	Update(l,r,val,v,s,m);
	Update(l,r,val,w,m+1,e);
	st[u]=st[v]+st[w];
}

int query(int l,int r,int u=1,int s=1,int e=n){
	push(u,s,e);
	if(e<l || r<s)return 0;
	if(l<=s && e<=r)return st[u];
	int v= (u<<1),w= v|1,m = (s+e)>>1;
	return query(l,r,v,s,m)+query(l,r,w,m+1,e);
}
