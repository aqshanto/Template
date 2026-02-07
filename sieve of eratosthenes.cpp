const int N = 10000000+10;
vector<bool>isPrime(N,true);

void sieve(){
    isPrime[0]=isPrime[1] = false;
    for(int i = 4; i< N; i+=2) isPrime[i] = false;

    for(int i = 3; i*i < N;i+=2){
        if(isPrime[i]){
            for(ll j = 1LL * i * i; j<N;j += i){
                isPrime[j] = false;
            }
        }
    }
}
