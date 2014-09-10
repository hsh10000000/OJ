#include <iostream>
using namespace std;
#define LL long long
LL count(LL num)
{
	if(-1==num){
		return 0;
	}
	LL sum=1;//计算0的个数
	LL curr=num;
	LL tail=0;
	LL idx=1;
	while(curr){
		tail=curr%10;//求尾数
		if(tail>0){
			sum+=(curr/10)*idx;
		}else{
			sum+=(num/(idx*10)-1)*idx+num%idx+1;
		}
		curr/=10;
		idx*=10;
	}
	return sum;
}

int main()
{
	LL m,n;
	while(cin>>m>>n){
		if(m<0 && n<0){
			return 0;
		}
		cout<<count(n)-count(m-1)<<endl;		
	}
	return 0;
}
