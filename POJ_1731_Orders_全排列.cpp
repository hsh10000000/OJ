#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void permutation(string &str)
{
	sort(str.begin(),str.end());//排序
	int len=str.size();
	int idx=0,idy=0;
	while(true){
		cout<<str<<endl;
		for(int i=len-1;i>0;--i){
			if(str[i-1]<str[i]){
				idx=i-1;
				break;
			}
		}
		for(int i=len-1;i>idx;--i){
			if(str[i]>str[idx]){
				idy=i;
				break;
			}
		}
		if(!idx && !idy){
			break;
		}
		swap(str[idx],str[idy]);
		reverse(str.begin()+idx+1,str.end());
		idx=0,idy=0;
	}	
}

int main()
{
	string str;
	cin>>str;
	permutation(str);
	return 0;
}
