/*
Chef's Dream
Problem code: DREAM
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

The Chef is sleeping now. He tries to cook new kind of meals in his dream.

These meals are arranged in a row and numbered from 1 to N consecutively. For each meal i (1<=i<=N) there is given one integer f(i) which denotes the time needed to cook it. Initially, all meals are uncooked. Each assistant of The Chef (there are infinite number of them) can help him with cooking.

The abilities of all assistants are same. There can be at most one assistant cooking at each moment. He must choose some continuous subsequence of meals with length K(any such subsequence can be chosen). And if there are uncooked meals in it, he will cook all uncooked meals which has the minimum cooking time among uncooked meals in the chosen subsequence. Nothing done to another meals. 

The dream was so interesting that he tried to solve such a problem: What is the minimum number of assistants which can cook all the meals assuming that each of them will cook at most once? But since the bell rings and Chef's friends has come to visit him, he will wake up after 2 seconds. Your program should calculate the answer before The Chef will come to himself.
Input

First line of input file contains two integers N (1<=N<=105) and K (1<=K<=N), followed by a line containing N integers. The ith integer denotes f(i)-the cooking time of meal number i (1<=f(i)<=109)
Output

Print minimum number of assistans which can cook all the meals in one line.
Example

Input:
5 3
40 30 40 30 40

Output:
3

Explanation: 
3 assistants are enough to cook all the meals. They can work in following schedule: 
1st assistant chooses interval [2,4] and cooks meals 2 and 4. 
2nd assistant chooses interval [1,3] and cooks meals 1 and 3. 
3rd assistant chooses interval [3,5] and cooks meal 5. 
Other schedules can also be possible.*/
#include <iostream>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <ctime>
#include <numeric>
#include <cstring>
#include <functional>

using namespace std;
int main(){
	int n, k, f[100000];
	cin>>n>>k;
	int ans=0;
	map<int, int> mp;
	for(int i=0; i<n; i++){
		cin>>f[i];
	}
	for(int i=0; i<n; i++){
		int time = f[i];
		if(mp.count(time)==0 || i>mp[time]){
			ans++;
			mp[time] = i+k-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
