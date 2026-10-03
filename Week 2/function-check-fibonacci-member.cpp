
bool checkMember(int n){
    int a = 0;
    int b = 1;
    
    if(n == a || n == b)
        return true;
    
    while(b <= n) {    
        int t = a + b;
        a = b;
        b = t;
        
        if(b == n) {
            return true;
        }
    }
    return false;
}
