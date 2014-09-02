#include <iostream>
#include <string>
using namespace std;

void solve(string &str1,string &str2)
{
	int len1=str1.size();
	int len2=str2.size();
	int *len=new int[len2+1];
	memset(len,0,sizeof(int)*(len2+1));
	int maxi=0;
	for(int i=1;i<=len1;++i){
		for(int j=len2;j>0;--j){
			if(str1[i-1]==str2[j-1]){
				len[j]=len[j-1]+1;
				if(len[j]>maxi){
					maxi=len[j];
				}
			}else{
				len[j]=0;
			}
		}
	}
	delete [] len;
	cout << "Nejdelsi spolecny retezec ma delku " << maxi << "." << endl;
}

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	string str1,str2;
	for(int i=0;i<n;++i){
		getline(cin,str1);
		getline(cin,str2);
		solve(str1,str2);
	}
	return 0;
}
