#include <iostream>
#include <string>
#include <limits>
using namespace std;
const int maxi=16000005;
int alpha[256];//全局数组
bool flag[maxi];

int main()
{
	int n,nc;
	string str;
	int c;
	int val;
	int count=0;
	int hd;
	while(cin>>n>>nc){
		cin>>str;
		c=str.length();
		memset(alpha,0,sizeof(alpha));
		memset(flag,0,maxi);
		count=0;
		hd=static_cast<int>(pow(nc*1.0,n-1));
		for(int i=0,j=0;i<c;++i){//根据字符的出现次序为其分配一个数值
			if(!alpha[str[i]]){
				alpha[str[i]]=j++;
				if(j==nc){
					break;
				}
			}
		}
		val=0;
		for(int i=0;i<n;++i){
			val=val*nc+alpha[str[i]];//初始值
		}
		for(int i=0;i<c-n+1;++i){
			if(!flag[val]){
				flag[val]=true;
				++count;
			}
			if(i<c-n){
				val=(val-alpha[str[i]]*hd)*nc+alpha[str[i+n]];
			}
		}
		cout<<count<<endl;
	}	
	return 0;
}
