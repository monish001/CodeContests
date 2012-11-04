/*
Ciel and Tomya
Problem code: CIELTOMY

SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Tomya is a girl. She loves Chef Ciel very much.
Today, too, Tomya is going to Ciel's restaurant. Of course, Tomya would like to go to Ciel's restaurant as soon as possible. Therefore Tomya uses one of the shortest paths from Tomya's house to Ciel's restaurant. On the other hand, Tomya is boring now to use the same path many times. So Tomya wants to know the number of shortest paths from Tomya's house to Ciel's restaurant. Your task is to calculate the number under the following assumptions.
This town has N intersections and M two way roads. The i-th road connects from the Ai-th intersection to the Bi-th intersection, and its length is Ci. Tomya's house is in the 1st intersection, and Ciel's restaurant is in the N-th intersection.
Input

The first line contains an integer T, the number of test cases. Then T test cases follow. The first line of each test case contains 2 integers N, M. Then next M lines contains 3 integers denoting Ai, Bi and Ci.
Output

For each test case, print the number of shortest paths from Tomya's house to Ciel's restaurant.
Constraints

1 = T = 10
2 = N = 10
1 = M = N · (N – 1) / 2
1 = Ai, Bi = N
1 = Ci = 10
Ai ? Bi
If i ? j and Ai = Aj, then Bi ? Bj
There is at least one path from Tomya's house to Ciel's restaurant.
Sample Input

5
4 6
1 2 1
1 3 2
1 4 3
2 3 1
2 4 2
3 4 1
4 3
1 3 1
3 2 1
2 4 1
2 1
1 2 4
3 3
1 2 3
2 3 6
1 3 7
3 3
1 2 3
2 3 6
1 3 9
Sample Output

1
2
Explanations

In the first sample, only one shortest path exists, which is 1-3.
In the second sample, both paths 1-2-3 and 1-3 are the shortest paths.*/
#include<iostream>
#include<queue>
#include<fstream>
#include<string>
#include<cstring>
#include<map>
#include<cstdlib>
#include<algorithm>
using namespace std;
int *distanceFromStartNode;
struct closest_node{
    bool operator()(const int node1, const int node2){
        return distanceFromStartNode[node1]>distanceFromStartNode[node2];
    }
};
int main(){
    int t;
	for( cin>>t; t>0; t--){
		int graph[11][11];
		int numNodes; cin>>numNodes;

		int pathCount[11];
		distanceFromStartNode = new int[11];
//init arrays
		for(int i=1; i<=numNodes; i++){
			pathCount[i] = 0;
			distanceFromStartNode[i] = 10000;
			for(int j=1; j<=numNodes; j++){
				graph[i][j] = 10000;
			}
		}

//input to arrays
		int numRoads; cin>>numRoads;
		for(int i=0; i<numRoads; i++){
			int a, b, d;
			cin>>a>>b>>d;
			graph[b][a] = graph[a][b] = d;
		}

//processing
		vector<int> Q;//create priority queue Q which will return node closest to start_node
		for(int node=1; node<=numNodes; node++)//put all the node in Q
			Q.push_back(node);
		distanceFromStartNode[1]=0;
		make_heap(Q.begin(), Q.end(), closest_node());
		pathCount[1] = 1;

		while(!Q.empty()){//for each level
            make_heap(Q.begin(), Q.end(), closest_node());
			int curNode = Q.front(); pop_heap(Q.begin(), Q.end(), closest_node()); Q.pop_back();
			for(int adjNode=1; adjNode<=numNodes; adjNode++){//foreach adj. node
				if(curNode!=adjNode){
					int curDist = distanceFromStartNode[curNode]+graph[curNode][adjNode];
					if(distanceFromStartNode[adjNode] > curDist){
						distanceFromStartNode[adjNode] = curDist;
						pathCount[adjNode] = pathCount[curNode];
					}else if(distanceFromStartNode[adjNode] == curDist){
						pathCount[adjNode] += pathCount[curNode];
					}
				}
			}
		}
		cout<<pathCount[numNodes]<<endl;
	}
	delete[] distanceFromStartNode;
	getchar();
	return 0;
}
