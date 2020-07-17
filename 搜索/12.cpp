class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int word_index,int x, int y){
        if(board[x][y] != word[word_index]){
            return false;
        }
        if(word.size() - 1 == word_index){
            return true;
        }
        char temp = board[x][y];
        board[x][y] = 0;
        word_index++;
        if((x > 0 && bfs(board, word, word_index, x - 1, y)) || (y > 0 && bfs(board, word, word_index, x, y - 1)) || (x < board.size() - 1 && bfs(board, word, word_index, x + 1, y)) || (y < board[0].size() - 1 && bfs(board, word, word_index, x, y + 1))){ 
            return  true; 
        }
        board[x][y] = temp;
        return false;
    }
};