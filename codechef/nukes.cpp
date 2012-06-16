/*
Nuclear Reactors
Problem code: NUKES
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

There are K nuclear reactor chambers labelled from 0 to K-1. Particles are bombarded onto chamber 0. The particles keep collecting in the chamber 0. However if at any time, there are more than N particles in a chamber, a reaction will cause 1 particle to move to the immediate next chamber(if current chamber is 0, then to chamber number 1), and all the particles in the current chamber will be be destroyed and same continues till no chamber has number of particles greater than N. Given K,N and the total number of particles bombarded (A), find the final distribution of particles in the K chambers. Particles are bombarded one at a time. After one particle is bombarded, the set of reactions, as described, take place. After all reactions are over, the next particle is bombarded. If a particle is going out from the last chamber, it has nowhere to go and is lost.
Input

The input will consist of one line containing three numbers A,N and K separated by spaces. A will be between 0 and 1000000000 inclusive. N will be between 0 and 100 inclusive. K will be between 1 and 100 inclusive. All chambers start off with zero particles initially.
Output

Consists of K numbers on one line followed by a newline. The first number is the number of particles in chamber 0, the second number is the number of particles in chamber 1 and so on.
Example

Input:
3 1 3
Output:
1 1 0
*/
#include <iostream>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <ctime>
#include <numeric>
#include <cstring>
#include <functional>

using namespace std;
int main(){
	int a,n,k;
	cin>>a>>n>>k;
	int base = n+1;
	//vector<int> ans;
	while(a && k){
		//ans.push_back(a%base);
		cout<<a%base<<" ";
		k--;
		a/=base;
	}
	while(k){
		cout<<"0 ";
		k--;
	}
	cout<<endl;
	//cin>>a;
	return 0;
}
