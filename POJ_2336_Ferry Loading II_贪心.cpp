#include <iostream>
using namespace std;

void ferry_loading_2(int n,int t,int m)//poj_2336
{//n表示每次运送的车辆数，t表示每次单程所需的时间，m表示总车数
	int modular=m%n;//
	int trans_time=m/n;//需要运送的总次数
	int k=trans_time;
	int time_strart=0;
	int time_return=0;
	if(modular){
		trans_time+=1;//转运次数加1
		for(int i=0;i<modular;++i){
			cin>>time_strart;
		}
		time_return=time_strart+2*t;
	}
	for(int i=0;i<k;++i){
		for(int j=0;j<n;++j){
			cin>>time_strart;
		}
		if(time_strart>time_return){
			time_return=time_strart+2*t;
		}else{
			time_return=time_return+2*t;
		}
	}
	cout<<time_return-t<<" "<<trans_time<<endl;
}

int main()
{
	int g;//测试组数
	cin>>g;
	int n,t,m;
	for(int i=0;i<g;++i){
		cin>>n>>t>>m;
		ferry_loading_2(n,t,m);
	}
}
