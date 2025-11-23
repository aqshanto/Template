#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100000;
//---------------------------------------//
vector<int>v(MAXN+10,0),st(4*MAXN+10,0);

void build(int u,int s,int e){
    if(s==e){
        st[u]=v[s];
        return;
    }
    int mid = (s+e)/2;
    build(2*u,s,mid);
    build(2*u+1,mid+1,e);
    st[u]=max(st[2*u],st[2*u+1]);
}

int query(int u,int s,int e,int l,int r){
    if(l<=s && e<=r)return st[u];
    if(e<l || r<s)return INT_MIN;
    int mid = (s+e)/2;
    int left = query(2*u,s,mid,l,r);
    int right = query(2*u+1,mid+1,e,l,r);
    return max(left,right);
}

void pointUpdate(int u,int s,int e,int ind,int val){
    if(s==e){
        st[u]=val;
        v[ind]=val;
        return;
    }
    int mid = (s+e)/2;
    if(s<=ind && ind<=mid){
        pointUpdate(2*u,s,mid,ind,val);
    }else{
        pointUpdate(2*u+1,mid+1,e,ind,val);
    }
    st[u]=max(st[2*u],st[2*u+1]);
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

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    build(1,1,n);
    printTree(1,1,n,0);
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }else{
            int ind,val;
            cin>>ind>>val;
            pointUpdate(1,1,n,ind,val);
            printTree(1,1,n,0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, Case = 1;
    // cin>>t;
    while (t--) {
        // cout << "Case " << Case++ << ": ";
        solve();
    }
    return 0;
}
