vector<vector<int>> mat_multi(vector<vector<int>>a,vector<vector<int>>b){
	int n = a.size();
	int m = b[0].size();
	int k = b.size();
	vector<vector<int>>c(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int l=0;l<k;l++){
				c[i][j]=(c[i][j]+(a[i][l]*b[l][j]))%mod;
			}
		}
	}
	return c;
}

int mat_expo(vector<vector<int>>base,int n){
	int sz = base.size();
	vector<vector<int>>ans(sz,vector<int>(sz,0));
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			if(i==j){
				ans[i][j]=1;
			}
		}
	}
	while(n!=0){
		if(n&1){
			ans = mat_multi(ans,base);
		}
		base= mat_multi(base,base);
		n>>=1;
	}
	return ans[0][sz-1];
}
