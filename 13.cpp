class Solution{
private:
    int get(int x){
        int res = 0;
        for(; x != 0; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k){
        if(k == 0){
            return 1;
        }
        int res = 1;
        queue<pair<int, int> > Q;
        Q.push(make_pair(0, 0));
        vector<vector<int> > visit(m, vector<int>(n, 0));
        visit[0][0] = 1;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        while(!Q.empty()){
            auto [x, y] = Q.front();
            Q.pop();
            for(int i = 0; i < 2; i++){
                int tx = x + dx[i], ty = y + dy[i];
                if(tx >= 0 && tx < m && ty >= 0 && ty < n && !visit[tx][ty] && get(tx) + get(ty) <= k){
                    res++;
                    Q.push(make_pair(tx, ty));
                    visit[tx][ty] = 1;
                }
            }
        }
        return res;
    }
};