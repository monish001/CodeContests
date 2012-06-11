/*
Turbo Sort
Problem code: TSORT
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Given the list of numbers, you are to sort them in non decreasing order.
Input

t – the number of numbers in list, then t lines follow [t <= 10^6]. 

Each line contains one integer: N [0 <= N <= 10^6]
Output

Output given numbers in non decreasing order.
Example

Input:
5
5
3
6
7
1
Output:
1
3
5
6
7
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int tests;
	scanf("%d", &tests);
	vector<int> list;
	for(int t=0; t<tests; t++){
		int n;
		scanf("%d", &n);
		list.push_back(n);
	}
	sort(list.begin(), list.end());
	for(int t=0; t<tests; t++){
		printf("%d\n", list[t]);
	}
//	puts("Done");
//	scanf("%d", &tests);
	return 0;
}
