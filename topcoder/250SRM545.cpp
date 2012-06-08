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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef map<string, int> MSI;

int count1(int a){
	int n=0;
	while(a){
		if(a%2==1)
			n++;
		a/=2;
	}
	return n;
}
bool gt1(int a, int b){
	return ((count1(a)-count1(b))>0)?true:false;
}
class ANDEquation{
	public:
	int restoreY(vector <int> a){
		int minIndex, andd;
		if(gt1(a[0], a[1])){
			minIndex = 1;
			andd = a[0];
		}else{
			minIndex = 0;
			andd = a[1];
		}
		for(int i=2; i<a.size(); i++){
			if( gt1(a[minIndex], a[i])){
				andd &= a[minIndex];
				minIndex = i;
			}else{
				andd &= a[i];
			}			
		}
		int totAnd=0xFFFFFFFF;
		for(int i=0; i<a.size(); i++){
			if(minIndex == i)
				continue;
			totAnd &= a[i];
		}
		if(a[minIndex] == totAnd)
			return a[minIndex];
		return -1;
	}
};
