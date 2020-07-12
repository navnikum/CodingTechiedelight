// make set, union, find 
map<int, int> parent, size, rank;
void make_set(int v){
	parent[v] = v;
//  size[v] = 1;  <= Union by size
//  rank[v] = 0;  <= Union by rank
}
//  O(n) time
int find (int v){
	return (v == parent[v])? v: find(parent[v]);
	/* Path compression : O(logn)
	return (v == parent[v])? v: parent[v] = find(parent[v]); */
}

void union (int x, int y){
	x = find (x);
	y = find (y);
	if (x != y)
		parent[y] = x;

// Union by size/rank :  O(logn)
		/*  if (size[x] < size[y])
				swap(x, y);
			parent[y] = x;
			size[x] += size[y]; */

		/*  if (rank[x] < rank[y])
				swap (x, y);
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++; */
}

// combining both Path compression and Weighted union we will nearly reach constant time query
// final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function < 4 .
#include<bits/stdc++.h> 
using namespace std;

struct dsu{
	int n;
	map<int, int> parent, rnk;

	dsu(int n){
		this->n = n;
		for(int i=0; i<n; i++) 
			parent[i] = i, rnk[i] = 0;
	}
	// Path Compressed find
	int find(int v){
		return (v == parent[v]) ? v : parent[v] = find (parent[v]);
	}
	// Weighted Union by rank
	void union_set(int x, int y){
		x = find(x), y = find(y);
		if (x != y)
		{
			if (rnk[x] < rnk[y])	
				swap(x, y);
			parent[y] = x;

			if (rnk[x] == rnk[y])	
				rnk[x]++;
		}
	}
};

struct graph{
	int V, E;
	vector<pair<int, pair<int, int> > > edges;  // {w, {u,w}}
	graph (int V, int E){
		this->V = V, this->E = E;
	}
	void addEdge(int u, int v, int w){
		edges.push_back({w, {u, v}});
	}
	int kruskalMST();
};

int graph :: kruskalMST(){
	int mstWt = 0;
	sort (edges.begin(), edges.end());
	dsu ds(V);
	//for ( auto it=edges.begin(); it!=edges.end(); it++)  int u = it->second.first;  
	for (auto it : edges){
		int u = it.second.first;
		int v = it.second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		// if cycle is not formed by this edge {u,v} i.e. not in same set
		if (set_u != set_v)
		{
			cout<<u<<" - "<<v<<endl;
			mstWt += it.first;
			ds.union_set(set_u, set_v);
		}
	}
	return mstWt;
}


int main()
{
	int V = 9, E = 14;
	graph g(V, E);

	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7);

	cout<<"Edges of MST are : "<<endl;
	int mstWt = g.kruskalMST();
	cout<<"Wt of MST is : "<< mstWt;

	return 0;
}



























