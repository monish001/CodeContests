/*
Stone Game
Problem code: RESN04
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Alice and Bob play the following game : There are N piles of stones with Si stones in the ith pile. Piles are numbered from 1 to N. Alice and Bob play alternately, with Alice starting. In a turn, the player chooses any pile i which has atleast i stones in it, and removes exactly i stones from it. The game ends when there is no such pile. The player who plays last wins the game. Assuming Alice and Bob play optimally, who will win the game?
Input

The first line contains the number of test cases T (<= 100). There follow 2T lines, 2 per test case. The first line of each test case conains N (<= 100), the number of piles. The second line contains N space seperated integers, specifying the number of stones in pile 1, pile 2, ..., pile N. There will be atleast 1 and atmost 1000 stones in any pile.
Output

Output T lines, one per test case. For each test case, output "ALICE" if Alice wins the game, and "BOB" if Bob wins the game.
Example

Input:
2
1
1
2
1 1

Output:
ALICE
ALICE
*/
#include <iostream>
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
int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	for(int test=0; test<t; test++){
		int turns=0, n;
		cin>>n;
		for(int i=1; i<=n; i++){
			int count;
			cin>>count;
			turns ^= count/i;
		}
		cout<<((turns&1)?("ALICE"):("BOB"))<<endl;
	}
	return 0;
}
