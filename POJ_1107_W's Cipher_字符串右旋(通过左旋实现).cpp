#include <iostream>
#include <string>
using namespace std;
int pos[3][81];

void invert(string &str,int *pos,int low,int high)
{
	if(low<high){
		int p1=low,p2=high;
		char tmp;
		while(p1<p2){
			tmp=str[pos[p1]];
			str[pos[p1]]=str[pos[p2]];
			str[pos[p2]]=tmp;
			++p1,--p2;
		}
	}
}

void rotate(string &str,int *pos,int k,int m)
{
	if(m){
		k=k%m;
			if(k){
			invert(str,pos,0,m-k-1);
			invert(str,pos,m-k,m-1);
			invert(str,pos,0,m-1);
			}
	}
}

int main()
{
	string str;
	int k1,k2,k3;
	while(cin>>k1>>k2>>k3,k1|k2|k3){
		cin>>str;
		int len=str.size();
		int l1=0,l2=0,l3=0;
		for(int i=0;i<len;++i){	
			if(str[i]>='a' && str[i]<='i'){
				pos[0][l1++]=i;		
			}else if(str[i]>'i' && str[i]<='r'){
				pos[1][l2++]=i;
			}else{
				pos[2][l3++]=i;
			}	
		}
		rotate(str,pos[0],k1,l1);
		rotate(str,pos[1],k2,l2);
		rotate(str,pos[2],k3,l3);
		cout<<str<<endl;
	}
	return 0;
}
