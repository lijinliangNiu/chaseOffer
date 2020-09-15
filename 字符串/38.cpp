/*
以字符串中位置为递归参数。

对第pos位，其前都是固定好的，尝试将第pos位与之后的每一位交换。

剪枝去重：将要与pos位交换的字母中，如果有重复的，那么只要让pos和其中一个交换即可。因此每次交换前，判断之前字母是否有与当前字母相同的。
*/
class Solution {
private:
    vector<string> ans;
    string s;
    void dfs(int pos){
        if(pos == s.size() - 1){
            ans.push_back(s);
        }
        else{
            for(int i = pos; i < s.size(); i++){
                bool same_letter = false;//相同字母剪枝
                for(int j = pos; j < i; j++){
                    if(s[j] == s[i]){
                        same_letter = true;
                    }
                }
                if(!same_letter){
                    swap(s[pos], s[i]);
                    dfs(pos + 1);
                    swap(s[pos], s[i]);
                }
            }
        }
    }
public:
    vector<string> permutation(string s) {
        this->s = s;
        dfs(0);
        return ans;
    }
};