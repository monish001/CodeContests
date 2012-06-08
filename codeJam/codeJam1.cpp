#include<map>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
ofstream cout("outNew.txt");
ifstream cin("inNew.txt");

class Game{
public:
	const string word;
	const int index;
	vector<string> dict;
	bool gameEnd;
	Game(int in, string& w, vector<string>& d):index(in), word(w), gameEnd(false), dict(d){}
	void cutLetter(char c){
	//prun the non-viable options while input c is process
		vector<int> indices;
		this->getCharPos(word, indices, c);
		int wordsLeftAfterProcessing=0;
		for(int i=0; i<dict.size(); i++){
			if(dict[i]=="")
				continue;
			vector<int> indices2;
			this->getCharPos(dict[i], indices2, c);
			if(indices != indices2)
				dict[i] = "";
			else wordsLeftAfterProcessing++;
		}
		if(wordsLeftAfterProcessing==1)
			gameEnd == true;
/*	//remove all occurences of c from each string in dict
		for(int i=0; i<dict.size(); i++){
			if(dict[i] != NULL)
			for(int j=0; j<word.size(); j++)
				if(dict[i][j] == c)
					dict[i][j] == '0';
		}*/
	}
private:
	
	void getCharPos(const string& w, vector<int>& indices, char c){
		for(int i=0; i<word.size(); i++)
			if(w[i] == c)
				indices.push_back(i);
	}
};
class Dictionary{
public:
	map<int, vector<string>* > words;
	Dictionary(int n, vector<string>& inputWords){
		for(int i=0; i<n; i++){
			string tmp;
			cin>>tmp;
			inputWords.push_back(tmp);
			int len = tmp.length();
			if( words.find(len) == words.end() )
				words[len] = new vector<string>;
			(*(words[len])).push_back(tmp);
		}
	}
	~Dictionary(){
		map<int, vector<string>* >::iterator it;
		for ( it=words.begin() ; it != words.end(); it++ )
			delete it->second;
	}
};
void readVecStr(vector<string>& dict, int n){
	extern ifstream cin;
	//dict.reserve(n);
	string tmp;
	for(int i=0; i<n; i++){
		cin>>tmp;
		dict.push_back(tmp);
	}
}
void printStrVec(vector<string>& vs) {
	extern ofstream cout;
	for(int i=0; i<vs.size(); i++)
		cout<<vs[i]<<endl;
}
int main(){
	int t;
	extern ofstream cout;
	extern ifstream cin;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		int n,m;
		cin>>n>>m;
		
		vector<string> inputWords;
		Dictionary  dict(n, inputWords);
		vector<string> seqs;
		readVecStr(seqs, m);
cout<<"Dict and seqs read\n";
//printStrVec(inputWords);		
//printStrVec(seqs);		
		for(int i=0; i<m; i++){//for each seq
			string& seq = seqs[i];
			vector<pair<string, int> > AnsOptions;
			int maxPointsLost = 0;
			for(map<int, vector<string>* >::iterator it = dict.words.begin(); it != dict.words.end(); it++){
			//for words of length=(it->first)
				int len = it->first, num_words = (it->second)->size();
				vector<Game*> games; games.reserve(num_words);
				map<char, bool> viable;
				for(int j=0; j<num_words; j++){//for each word
					games[j] = new Game(j, (*(it->second))[j], *(it->second));
					for(int k=0; k<len; k++)
						viable[(*(it->second))[j][k]] = true;
				}
				
				string ans; int pointsLost=0;
				for(int j=0; j<26; j++){//for each letter c, call cutLetter for each game
					char c = seq[j];
					if(viable.find(c)==viable.end())
						continue;
					pointsLost++;
					for(int k=0; k<num_words; k++){
						if(games[k]->gameEnd == false){
							ans = games[k]->word;
							break;
						}
					}
					for(int k=0; k<num_words; k++){
						if(games[k]->gameEnd)
							continue;
						games[k]->cutLetter(c);
					}
					int k=0;
					while(k<num_words){
						if(games[k]->gameEnd == false)
							break;
						k++;
					}
					if(k==num_words && maxPointsLost<=pointsLost){
						AnsOptions.push_back(make_pair(ans, pointsLost));
						maxPointsLost = max(maxPointsLost, pointsLost);
						break;
					}
				}
				
				for(int j=0; j<num_words; j++)
					delete games[j];
			}
			//find words having max points lost
			vector<string> goodWords;
			for(int j=0; j<AnsOptions.size(); j++)
				if(AnsOptions[j].second == maxPointsLost)
					goodWords.push_back(AnsOptions[j].first);
			
			//find the first word from input list
			for(int j=0; j<inputWords.size(); j++)
			for(int k=0; k<goodWords.size(); k++)
			if(inputWords[j] == goodWords[k]){
				cout<<inputWords[j]<<" ";
				j=inputWords.size();
				break;
			}
		}
		
		cout<<endl;
	}
	cout.close();
	cin.close();
	return 0;
}
