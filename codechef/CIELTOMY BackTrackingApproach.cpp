//GIVING WA
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

int L, C, N;
int graph[11][11], visited[11];
void findLen(int nodeNum, int len){
   // cout<<nodeNum<<"with len="<<len<<endl;
    if(nodeNum == N){
		if(len< L){
			L = len; C=1;
		}else if(len==L){
			C++;
		}
		return;
	}
	visited[nodeNum] = true;
	for(int adjNode =  1; adjNode<=N; adjNode++){
		if(graph[nodeNum][adjNode] != -1 && !visited[adjNode])
			findLen(adjNode, len+graph[nodeNum][adjNode]);
	}
	visited[nodeNum] = false;
}
int main(){
	int t;
	for( cin>>t; t>0; t--){
		cin>>N;

L=10000; C=0;
//init arrays
		for(int i=1; i<=N; i++){
		    visited[i]=0;
			for(int j=1; j<=N; j++){
				graph[i][j] = -1;
			}
		}

//input to arrays
		int numRoads; cin>>numRoads;
		for(int i=0; i<numRoads; i++){
			int a, b, d;
			cin>>a>>b>>d;
			graph[b][a] = graph[a][b] = d;
		}

		findLen(1, 0);

		cout<<C<<endl;
	}
	getchar();
	return 0;
}
