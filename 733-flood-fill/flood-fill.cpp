class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> bfs;
        bfs.emplace(sr, sc);
        int org = image[sr][sc];
        image[sr][sc] = color;

        while ( !bfs.empty() ) {
            pair<int, int> node = bfs.front();
            bfs.pop();

            int x = node.first;
            int y = node.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};

            for (int i=0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >=0 && ny >=0 && nx < n && ny < m && image[nx][ny] != color && image[nx][ny] == org) {
                    image[nx][ny] = color;
                    bfs.emplace(nx, ny);
                }
            }

        }

        return image;
    }
};