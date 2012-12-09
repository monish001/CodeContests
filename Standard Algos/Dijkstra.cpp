//Dijkstra Algo
//Assuming max nodes as 10 and max distance between any two nodes as 9999 (i.e. 10000 or more means infinity)

#include<queue>
#include<iostream>
using namespace std;
int *distance_global;
struct closest_node{
    bool operator()(const int node1, const int node2){
        return distance_global[node1]>distance_global[node2];
    }
};
void dijkstra(int **graph, int numNodes, int start_node, int *distance/*distance from the start node*/){
	//Data Structure, assuming graph has atmost 10 vertices: 1 to 10.
	bool visited[11];
	int predecessor[11];

	//initialize
	for(int i=1; i<=numNodes; i++){
		visited[i]=false;//mark all nodes as unvisited
		predecessor[i]=-1;//mark predecessor for each node as -1 (not known)

	}

	//start node initialization
	distance[start_node]=0;//start node can be reached in zero distance
	predecessor[start_node] = -1;//no predecessor for start node

	distance_global = distance;
	priority_queue<int, vector<int>, closest_node > Q;//create priority queue Q which will return node closest to start_node
	for(int node=1; node<=numNodes; node++)//put all the node in Q
		Q.push(node);
	while(!Q.empty()){//while Q not empty
		int cur_node = Q.top(); Q.pop();//cur_node = pop node from Q with min distance from start node
		visited[cur_node] = true;//mark cur_node as visited
		for(int adjNode =1; adjNode<=numNodes; adjNode++)//for each adj. node n2
		if(adjNode!=cur_node && distance[adjNode] > distance[cur_node]+graph[cur_node][adjNode]){//if dist[adjNode] improves via cur_node
			predecessor[adjNode] = cur_node;//mark n2's predecessor as cur_node
			distance[adjNode] = distance[cur_node]+graph[cur_node][adjNode];//update dist[n2]
		}
	}
	//output dist[end node]
}
void _init2Darray(int**& graph, int size, int defaultVal){
	graph = new int*[size];
	for(int i=0; i<size; i++){
        graph[i] = new int[size];
        for(int j=0; j<size; j++)
            graph[i][j] = defaultVal;
	}
}
void _delete2Darray(int** &graph, int size){
	for(int i=0; i<size; i++)
        delete[] graph[i];
    delete[] graph;
}
int main(){
    int **graph=NULL;
    _init2Darray(graph, 11, 10000);

	int numNodes, numEdges, distance[11];
	//read input
	cout<<"Enter numNodes and numEdges:\n";
	cin>>numNodes>>numEdges;//input no. of nodes, no. of egdes
	for(int index1 = 1; index1<=numNodes; index1++){//for each edge update the graph[][]{
		distance[index1]=10000;
	}
	for(int i=0; i<numEdges; i++){
		int a, b, d;
		cout<<"Enter two nodes and undirected weight:\n";
		cin>>a>>b>>d;
		graph[b][a] = graph[a][b] = d;
	}

	dijkstra(graph, numNodes, 1, distance);

	for(int i=1; i<=numNodes; i++)
        cout<<distance[i]<<" "; cout<<endl;

    _delete2Darray(graph, 11);
}
