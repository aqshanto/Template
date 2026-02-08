const int N = 10000002;

vector<int>spf(N,1);

void sieve(){
    for(int i=1;i<N;i++)spf[i] = i;
    for(int i=4;i<N;i+=2)spf[i]=2;

    for(int i=3;i*i<N;i+=2){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=2*i){
                if(spf[j] == j)spf[j]=i;
            }
        }
    }
}


vector<int> getfactor(int n){
    vector<int>res;
    while(n>1){
        res.push_back(spf[n]);
        n/=spf[n];
    }
    return res;
}
