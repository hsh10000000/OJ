#include <iostream>
using namespace std;

int gcd(int a,int b)//求最小公倍数
{
	if(b){
		return gcd(b,a%b);
	}
	return a;
}

int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	bool *flag=new bool[n+1];
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		flag[i]=false;
	}	
	int pos=1,len=0;
	int next=1;//标记下一个循环节的开始元素
	int lcm=1;
	for(int i=1;i<=n;++i){
		if(!flag[pos]){
			flag[pos]=true;
			if(pos==next){
				while(next<=n && flag[next]){
					++next;
				}
			}
			pos=arr[pos];
			++len;
		}else{
			lcm=lcm*len/gcd(lcm,len);
			--i;
			len=0;
			pos=next;
		}
	}
	lcm=lcm*len/gcd(lcm,len);
	cout<<lcm<<endl;
	delete []arr;
	delete []flag;
	return 0;
}
