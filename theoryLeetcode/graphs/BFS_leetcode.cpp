//shortest paths-unweighted graph---->bfs(very standard)
// nearest/farthest something ==> start at boundary as something

class Solution {
	int m, n;
	bool isValid(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;    
    }
public:
// https://leetcode.com/problems/01-matrix/
// find nearest zero  : start at zeros
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0)
                    q.push({i, j});
                else
                	matrix[i][j] = INT_MIN;
                
            }
        }
        
        vector<pair<int, int>> dir={{-1,0},{1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            
            for(auto e: dir){
                int x=cell.first+e.first;
                int y=cell.second+e.second;
                if(isValid(x, y) && matrix[x][y] == INT_MIN){
                    matrix[x][y] = 1+matrix[cell.first][cell.second];
                    q.push({x, y});
                }
            }
        }
        return matrix;        
    }

// https://leetcode.com/problems/as-far-from-land-as-possible/
// nearest land : start at land
    int maxDistance(vector<vector<int>>& grid) {
    	if (grid.empty())	return -1;
    	m = grid.size();
    	n = grid[0].size();

    	queue<pair<int, int>> q;
    	for(int i=0; i<m; i++) {
    		for(int j=0; j<n; j++) {
    			if (grid[i][j] == 1)
    				q.push({i,j});
                else
                	grid[i][j] = INT_MIN;
    		}
    	}

    	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}} ;
    	int res = INT_MIN;
    	while (!q.empty()){
    		auto cur = q.front();
    		q.pop();
    		for (auto e : dir){
    			int x = cur.first + e.first;
    			int y = cur.second + e.second;
    			if (isValid(x,y)  && grid[x][y] == INT_MIN)
    			{
    				grid[x][y] = grid[cur.first][cur.second] + 1;
    				q.push({x,y});
                    res = max(res, grid[x][y]);
    			}
    		}
    	}
    	return res > 0 ? res-1 : -1 ;        
    }

// https://leetcode.com/problems/rotting-oranges/
    int orangesRotting(vector<vector<int>>& grid) {
    	if (grid.empty())	return -1;
    	m = grid.size();
    	n = grid[0].size();

    	queue<pair<int, int>> q;
    	for(int i=0; i<m; i++) {
    		for(int j=0; j<n; j++) {
    			if (grid[i][j] == 2)
    				q.push({i,j});
    		}
    	}
    	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    	
    	int steps = 0;
    	while (!q.empty()){
            steps++;
			int size = q.size();
			for (int i = 0; i < size; i++){
                auto cur = q.front();
                q.pop();
                for (auto e : dir){
                    int x = cur.first + e.first;
                    int y = cur.second + e.second;
                    if (isValid(x,y)  && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
    	}
        for(int i=0; i<m; i++) 
    		for(int j=0; j<n; j++) 
                if(grid[i][j] == 1) return -1;
        
    	return steps > 0 ? steps-1 :  0;        
    }

// https://leetcode.com/problems/shortest-path-in-binary-matrix/
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    	m = grid.size();
    	n = grid[0].size();
    	if (m == 0 || n == 0) return -1;
    	if (grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;

    	queue<pair<int, int>> q;
    	q.push({0,0});

    	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}} ;

    	grid[0][0] = 1;
    	int steps = 0;
    	while (!q.empty()){
            steps++;
			int size = q.size();
			for (int i = 0; i < size; i++){
                auto cur = q.front();
                if(cur.first == m-1 && cur.second == n-1) return grid[cur.first][cur.second];
                q.pop();
                for (auto e : dir){
                    int x = cur.first + e.first;
                    int y = cur.second + e.second;
                    if (isValid(x,y)  && grid[x][y] == 0){
                        q.push({x,y});
                        grid[x][y] = 1 + grid[cur.first][cur.second];
                    }
                }
            }
    	} 
   		return -1;        
    }
};

