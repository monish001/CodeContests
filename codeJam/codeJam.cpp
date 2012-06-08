#include<map>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
ofstream cout("out.txt");
ifstream cin("in.txt");
class level{
public:
	int a, b;
	bool f;
	level(int aa, int bb):f(false), a(aa), b(bb){}
};

	bool lessBWise(const level* ob1, const level* ob2){
		return ob1->b < ob2->b;
	}
	bool lessAWise(const level* ob1, const level* ob2){
		if(ob1->a != ob2->a)
			return ob1->a < ob2->a;
		else
			return ob1->b < ob2->b;
	}
int main(){
	int t;
	extern ofstream cout;
	extern ifstream cin;
	cin>>t;
	
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		int max=-1, max2=-1;
		int s=0;
		vector<int> nums;
		for(int i=0; i<n; i++){
			int num;
			cin>>num;
			nums.push_back(num);
			if(max <= num){
				max2 = max;
				max = num;
			}
			s += num;
			
			for(int i=0; i<n; i++){
				
			}
			
			(ans)?(cout<<lp):(cout<<"Too Bad");
			cout<<endl;
		}
	}
	cout.close();
	cin.close();
	return 0;
}
