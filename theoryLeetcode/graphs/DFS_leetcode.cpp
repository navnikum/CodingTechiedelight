// Depth First Search
// 1. DFS from boundary
class Solution {
	int rows, cols;
	void dfs(vector<vector<int>>& A, int i, int j){
		if (i < 0 || j < 0 || i > rows-1 || j > cols-1)
			return;
		if (A[i][j] != 1)
			return;
		A[i][j] = -1;
		dfs(A, i+1, j);
		dfs(A, i-1, j);
		dfs(A, i, j+1);
		dfs(A, i, j-1);
	}
// https://leetcode.com/problems/number-of-enclaves/
public:
    int numEnclaves(vector<vector<int>>& A) {
    	if (A.empty())	return 0;
    	rows = A.size(), cols = A[0].size();
    	for(int i=0; i<rows; i++) {
    		for(int j=0; j<cols; j++) {
    			if (i == 0 || j == 0 || i == rows-1 || j == cols-1)
    				dfs(A, i, j);    			
    		}
    	}

    	int count = 0;
    	for(int i=0; i<rows; i++) {
    		for(int j=0; j<cols; j++) {
    			if (A[i][j] == 1)
    				count++;    			
    		}
    	}
        return count;
    }
// https://leetcode.com/problems/surrounded-regions/
    void dfs(vector<vector<char>>& Ai, int i, int j){
		if (i < 0 || j < 0 || i > rows-1 || j > cols-1)
			return;
		if (Ai[i][j] == '_' || Ai[i][j] == 'X')
			return;
		Ai[i][j] = '_';
		dfs(Ai, i+1, j);
		dfs(Ai, i-1, j);
		dfs(Ai, i, j+1);
		dfs(Ai, i, j-1);
	}
public:
void solve(vector<vector<char>>& A) {
    	if (A.empty())	return;
    	rows = A.size() ,cols = A[0].size();
    	for(int i=0; i<rows; i++) {
    		for(int j=0; j<cols; j++) {
    			if (i == 0 || j == 0 || i == rows-1 || j == cols-1){
    				if (A[i][j] == 'O')
    					dfs(A, i, j);    			
    			}
    		}
    	}
        for(int i=0; i<rows; i++) {
    		for(int j=0; j<cols; j++) {
    			if (A[i][j] == 'O') A[i][j] = 'X'; 
                else if (A[i][j] == '_') A[i][j] = 'O';
    		}
    	}        
    }
};

// 2. Time taken to reach all nodes or share information to all graph nodes
// https://leetcode.com/problems/time-needed-to-inform-all-employees/
class Solution {
	void dfs (unordered_map<int, vector<int>>& hm, int i, vector<int>& informTime, int curr, int &res){

		curr += informTime[i];
		res = max(res, curr);

		for(auto it : hm[i])
			dfs(hm, it, informTime, curr, res);
	}
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    	// transforming manager relation into adj list using map representation
    	unordered_map<int, vector<int>> hm;
    	for(int i=0; i<n; i++) {
    		if (manager[i] != -1)
    			hm[manager[i]].push_back(i);    		
    	}
    	// DFS to find max time taken
    	int res = 0, curr = 0;
    	dfs(hm, headID, informTime, curr, res);
    	return res;      
    }
};

// 3. DFS from each unvisited node/Island problems
// https://leetcode.com/problems/number-of-islands/
class Solution {
    int rows, cols;
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
		if (i < 0 || j < 0 || i >= rows || j >= cols)	return;
		if (grid[i][j] == '0' || visited[i][j])	return;
		visited[i][j] = true;
		dfs(grid, visited, i+1, j);
		dfs(grid, visited, i-1, j);
		dfs(grid, visited, i, j+1);
		dfs(grid, visited, i, j-1);
	}
public:
    int numIslands(vector<vector<char>>& grid) {
    	if (grid.empty())	return 0;
    	rows = grid.size(), cols = grid[0].size();
    	vector<vector<bool>> visited(rows, vector<bool> (cols, false));

    	int res = 0;
    	for(int i=0; i<rows; i++) {
    		for(int j=0; j<cols; j++) {
    			if (grid[i][j] == '1'  && !visited[i][j]){
    				dfs(grid, visited, i, j);
    				res++;    				
    			}
    		}
    	}
        return res;
    }
};

// https://leetcode.com/problems/max-area-of-island/
class Solution {
	int rows, cols, curr;
	void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
		if (i < 0 || j < 0 || i >= rows || j >= cols)	return;
		if (grid[i][j] == 0 || visited[i][j])	return;
		visited[i][j] = true;
		curr++;
		dfs(grid, visited, i+1, j);
		dfs(grid, visited, i-1, j);
		dfs(grid, visited, i, j+1);
		dfs(grid, visited, i, j-1);
	}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	if (grid.empty())	return 0;
    	rows = grid.size(), cols = grid[0].size();
    	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    	curr = 0;
    	int res = 0;
    	for(int i=0; i<rows; i++) {
    		for(int j=0; j<cols; j++) {
    			if (grid[i][j] == 1  && !visited[i][j]){
    				dfs(grid, visited, i, j);
    				res = max(res, curr);   
                    curr = 0;
                }
    		}
    	}
    	return res;         
    }
};

// https://leetcode.com/problems/flood-fill/
class Solution {
	int rows, cols;
	void dfs(vector<vector<int>>& image, int i, int j,int oldColor, int newColor){
		if (i < 0 || j < 0 || i >= rows || j >= cols)	return;
		if (image[i][j] != oldColor || image[i][j] == newColor)		return;

		image[i][j] = newColor;
		dfs(image, i+1, j, oldColor, newColor);
		dfs(image, i-1, j, oldColor, newColor);
		dfs(image, i, j+1, oldColor, newColor);
		dfs(image, i, j-1, oldColor, newColor);
	}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    	rows = image.size(), cols = image[0].size();
    	dfs(image, sr, sc, image[sr][sc], newColor);
    	return image;        
    }
};

// https://leetcode.com/problems/number-of-closed-islands/
class Solution {
	int rows, cols;
	bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
		// if dfs path from inner land comes to boundary reject path
		if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && grid[i][j] == 0) return false;

		// if path is blocked by water or by visited and accept path
		if (grid[i][j] == 1 || visited[i][j])	return true;

		visited[i][j] = true;
		bool left, right, top, down;
		down = dfs(grid, visited, i+1, j);
		top = dfs(grid, visited, i-1, j);
		right = dfs(grid, visited, i, j+1);
		left = dfs(grid, visited, i, j-1);
		return left  && right  && top  && down;
	}

public:
    int closedIsland(vector<vector<int>>& grid) {
    	if (grid.empty())	return 0;
    	rows = grid.size(), cols = grid[0].size();
    	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    	int res = 0;
    	// start at non-boundary non-visited land 
    	for(int i=1; i<rows-1; i++) {
    		for(int j=1; j<cols-1; j++) {
    			if (grid[i][j] == 0  && !visited[i][j]){
    				// check is valid closed island
    				if (dfs(grid, visited, i, j))
                    	res++ ;  	
                }
    		}
    	}
    	return res;     
    }
};

// https://leetcode.com/problems/keys-and-rooms/
// simple DFS on adj list
class Solution {
	int n;
	void dfs(vector<vector<int>>& adj,vector<bool>& visited, int v) 
	{ 
	    visited[v] = true; 	  
	    for (auto i : adj[v]) 
	        if (!visited[i]) 
	            dfs(adj,visited, i); 
	}
	
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	n = rooms.size();
    	vector<bool> visited(n, false);
    	dfs(rooms, visited, 0);

    	for(auto i : visited)
    		if (i == false)
    			return false;

    	return true;
    }
};

// 4. Cycle Find : uses integer visited vector for storing multiple states not binary values
// https://leetcode.com/problems/find-eventual-safe-states/
// reduced to returning all nodes not on a cycle i.ie. safe = no-cycle, unsafe = cycle

class Solution {
	int n;
	bool dfs (vector<vector<int>>& graph, vector<int>& visited, int v){
		if (visited[v]) // if visited check if safe or unsafe
			return visited[v] == 1;

		visited[v] = -1;	// visited but unsafe
		for(auto it : graph[v])
    		if(!dfs(graph, visited, it))
    			return false;
    		
    	visited[v] = 1; // node is safe nocycle
    	return true;
	}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    	n = graph.size();
    	vector<int> res;
    	vector<int> visited(n, 0);
    	// Check cycle for each node
    	for(int i=0; i<n; i++) {
    		if(dfs(graph, visited, i))
    			res.push_back(i);
    	}
     	return res;      
    }
};