#include<map>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
ofstream cout("outNew.txt");
ifstream cin("inNew.txt");

int main(){
	int t;
	extern ofstream cout;
	extern ifstream cin;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		
		cout<<endl;
	}
	cout.close();
	cin.close();
	return 0;
}
