#include<map>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
ofstream cout("out.txt");
ifstream cin("in.txt");

int n;
int js[200];
int hs;
int safe(double psts/*proposed safe total score*/){
	double ats = 0;//audience total score
	for(int c=0; c<n; c++){
		if(js[c] >= psts)
			continue;
		double asc//audience score for candidate c
			= psts - js[c];
		ats += asc;
	}
	if(fabs(ats- hs) < 1.0e-7)
		return 0;
	if(ats>hs)
		return 1;
	return -1;
}
int main(){
	int t;
	extern ofstream cout;
	extern ifstream cin;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<":";
		cin>>n;
		hs=0;
		for(int i=0; i<n; i++){
			cin>>js[i];
			hs += js[i];
		}
		
		double beg=0, end=2*hs, mid;//total safe score can be fractional
		while(end-beg > 1.0e-7){
			mid = (beg + end)/2;
			int res = safe(mid);
			if(!res)
				break;
			else if(res>0)
				end = mid - 1.0e-7;
			else
				beg = mid + 1.0e-7;
		}
		
//		cout<<beg<<" "<<end<<" "
//cout<<mid<<"\t";
		for(int c=0; c<n; c++){
			double asp;//audience score percentage
			if(mid < js[c])
				asp = 0.0;
			else{
				double rasc; //required audience score for candidate c
				rasc = mid-js[c];
				asp = rasc*100.0/hs;
			}
			cout<<" "<<fixed<<setprecision(6)<<asp; 
		}
		cout<<endl;
		
		
	}
	cout.close();
	cin.close();
	return 0;
}
