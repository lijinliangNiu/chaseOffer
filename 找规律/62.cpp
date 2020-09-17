class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for(int i = 2; i <= n; i++){
            pos = (pos + m) % i;
        }
        return pos;
    }
    
};

//递归
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n == 1){
            return 0;
        }
        return (lastRemaining(n - 1, m) + m) % n;
    }
};