typedef long long ll;

bool check(ll mid) {

    return true; 
}

void bs_maximize() {
    ll lo = 0, hi = 2e18, ans = lo;
    
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        
        if (check(mid)) {
            ans = mid;
            lo = mid + 1; 
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}

void bs_minimize() {
    ll lo = 0, hi = 2e18, ans = hi;
    
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        
        if (check(mid)) {
            ans = mid;
            hi = mid - 1; 
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}
