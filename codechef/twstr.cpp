/*
Remember the recipe
Problem code: TWSTR
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
Chef Jessie has a lot of recipes with her (N). She often remembered the starting few characters of the recipe and forgot the rest. As all the great chefs do, Jessie also numbered the recipes depending on the priority. So, given the list of recipes along with their priorities answer Jessie�s queries.
Jessie�s queries are as follows:
She gives you the first few characters of a recipe; you have to print the complete recipe with the highest priority.
Note:
Every recipe has a unique priority
Input

First line contains an integer N - the number of recipes.
Followed by N strings Si along with an integer each Vi.
Si stands for the recipe and Vi for the priority.
It is followed by an integer Q - the number of queries.
Followed by Q strings Qi.
Each string Si, Qi contain only lowercase Latin alphabets ('a' - 'z') and '-'.
Output

Q � lines, each contain the answer for each of the query.
If for a query no recipe matches print "NO". (Without quotes)
Constraints:
0 <= N <= 1000
0 <= Q <= 1000
-10^9 <= Vi <= 10^9
1 <= |Si| <= 1000 (length of Si)
1 <= |Qi| <= 1000 (length of Qi)
Example

Input:
4
flour-with-eggs 100
chicken-ham -10
flour-without-eggs 200
fish-with-pepper 1100
6
f
flour-with
flour-with-
c
fl
chik

Output:
fish-with-pepper
flour-without-eggs
flour-with-eggs
chicken-ham
flour-without-eggs
NO
*/

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class rec{
	public:
	string str;
	int pr;
	rec(string s, int p):str(s), pr(p){}
};
bool operator<(const rec& r1, const rec& r2){
	return r1.pr > r2.pr;
}
int main(){
//	int tests;
//	cin>>tests;
//	for(int test=0; test<tests; test++){
		int n, q;
		cin>>n;
		vector<rec> recs;
		for(int i=0; i<n; i++){
			string str; int pr;
			cin>>str>>pr;
			rec r(str, pr);
			recs.push_back(r);
		}
		sort(recs.begin(), recs.end());
		cin>>q;
		for(int i=0; i<q; i++){
			string str, ans("NO");
			cin>>str;
			for(int j=0; j<n; j++){
				if(recs[j].str.substr(0, str.size()) == str){
					ans = recs[j].str;
					break;
				}
			}
			cout<<ans<<endl;
		}
//	}
	return 0;
}
