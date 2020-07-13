// DFS BFS of graph  // T :  O(V + E), S :  O(V)

// DFS on graph  
// Recursive DFS  : https://leetcode.com/problems/keys-and-rooms/
vector<bool> visited(V, false);
void DFS(int v) 
{ 
    visited[v] = true; 
    cout << v << " "; 
  
    for ( auto i : adj[v]) 
        if (!visited[i]) 
            DFS(i); 
} 

// Iterative DFS
void DFS(int s) 
{ 
    vector<bool> visited(V, false); 
    stack<int> stk; 

    visited[s] = true;
    stk.push(s);
  
    while (!stk.empty()) 
    { 
        s = stk.top();  
      	cout << s << " "; 
	stk.pop(); 
   
        for (auto i : adj[s]) {
            if (!visited[i]){ 
              	visited[i] = true;
                stk.push(i); 
            } 
        }
    } 
}


// BFS on graph
void BFS(int s) 
{ 
    vector<bool> visited(V, false); 
    queue<int> queue; 

    visited[s] = true;
    queue.push(s);
  
    while (!queue.empty()) 
    { 
        s = queue.front();  
      	cout << s << " "; 
	queue.pop(); 
   
        for (auto i : adj[s]) {
            if (!visited[i]){ 
              	visited[i] = true;
                queue.push(i); 
            } 
        }
    } 
}


// modification if Disconnected Graph
for (int i = 0; i < V; i++) 
    if (visited[i] == false) 
        DFS(i);// BFS(i);



// Topological sorting





// Flood Fill
// https://leetcode.com/problems/flood-fill/
class Solution {
    int rows, cols;
    void dfs(vector<vector<int>>& image, int i, int j,int oldColor, int newColor){
        if (i < 0 || j < 0 || i >= rows || j >= cols)   return;
        if (image[i][j] != oldColor || image[i][j] == newColor)     return;

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




