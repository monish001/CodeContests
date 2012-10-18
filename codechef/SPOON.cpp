/*
Spoon in Matrix
Problem code: SPOON
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Chef recently saw the movie Matrix. He loved the movie overall but he didn't agree with some things in it. Particularly he didn't agree with the bald boy when he declared - There is no spoon. Being a chef, he understands the importance of the spoon and realizes that the universe can't survive without it. Furthermore, he is sure there is a spoon; he saw it in his kitchen this morning. So he has set out to prove the bald boy is wrong and find a spoon in the matrix. He has even obtained a digital map already. Can you help him? Formally you're given a matrix of lowercase and uppercase Latin letters. Your job is to find out if the word "Spoon" occurs somewhere in the matrix or not. A word is said to be occurred in the matrix if it is presented in some row from left to right or in some column from top to bottom. Note that match performed has to be case insensitive.
Input

The first line of input contains a positive integer T, the number of test cases. After that T test cases follow. The first line of each test case contains two space separated integers R and C, the number of rows and the number of columns of the matrix M respectively. Thereafter R lines follow each containing C characters, the actual digital map itself.
Output

For each test case print one line. If a "Spoon" is found in Matrix, output "There is a spoon!" else output "There is indeed no spoon!" (Quotes only for clarity).
Constraints

1 = T = 100
1 = R, C = 100
Sample Input

3
3 6
abDefb
bSpoon
NIKHil
6 6
aaaaaa
ssssss
xuisdP
oooooo
ioowoo
bdylan
6 5
bdfhj
cacac
opqrs
ddddd
india
yucky
Sample Output

There is a spoon!
There is a spoon!
There is indeed no spoon!
Explanation

In the first test case, "Spoon" occurs in the second row. In the second test case, "spOon" occurs in the last column.
*/

#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>
using namespace std;
#define Ten9 1000000000L

int main(){
    
//    ifstream cin("STEPAVG_IN.TXT");
//    ofstream cout("STEPAVG_OUT.TXT");
    
	int t;
	cin>>t;
	string SPOON="SPOON", spoon="spoon";
	while(t--){
		int n, k;
		cin>>n>>k;
		string array[n];
		for(int i=0; i<n; i++){
			cin>>array[i];
		}
		bool isSpoonPresent = 0;
		int h_level=0, 	v_level=0;
		for(int i=0; i<n && !isSpoonPresent; i++){
			for(int j=0; j<k; j++){
				if(array[i][j] == spoon[h_level] || array[i][j] == SPOON[h_level] )
					if(h_level == 4){
						isSpoonPresent=1;
						break;
					}else{
						h_level++;
					}
				else
					h_level=0;
			}
		}
		for(int i=0; i<k && !isSpoonPresent; i++){
			for(int j=0; j<n; j++){
				if(array[j][i] == spoon[v_level] || array[j][i] == SPOON[v_level] )
					if(v_level == 4){
						isSpoonPresent=1;
						break;
					}else{
						v_level++;
					}
				else
					v_level=0;
			}
		}


		
		cout<<((isSpoonPresent)?("There is a spoon!\n"):("There is indeed no spoon!\n"));
	}
	
	
//	getchar();
	return 0;
}
