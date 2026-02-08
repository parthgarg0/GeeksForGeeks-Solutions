class Solution {
public:
    void getPath(vector<vector<int>>& maze, int row, int col,
                 vector<string> &ans, string path,
                 vector<vector<bool>> &visit) {

        int n = maze.size();

        if (row < 0 || col < 0 || row >= n || col >= n ||
            maze[row][col] == 0 || visit[row][col])
            return;

        if (row == n-1 && col == n-1) {
            ans.push_back(path);
            return;
        }

        visit[row][col] = true;   // mark visited

        getPath(maze, row+1, col, ans, path+"D", visit);
        getPath(maze, row-1, col, ans, path+"U", visit);
        getPath(maze, row, col+1, ans, path+"R", visit);
        getPath(maze, row, col-1, ans, path+"L", visit);

        visit[row][col] = false;  // backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();

        if (maze[0][0] == 0) return ans;

        vector<vector<bool>> visit(n, vector<bool>(n, false));

        getPath(maze, 0, 0, ans, "", visit);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
