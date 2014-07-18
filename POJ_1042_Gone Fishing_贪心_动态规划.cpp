#include <iostream>
using namespace std;

int get_maxfish(int *fi,int n)//返回当前鱼最多的湖
{
	int rem=-1,max=0;
	for(int i=0;i<n;++i){
		if(fi[i]>max){
			max=fi[i];
			rem=i;
		}
	}
	return rem;
}

void gone_fishing(int *&fi,int *&di,int *&ti,double  h,int n)//poj_1042动态规划
{
	int maxnum=-1;//初始化最大捕鱼个数
	int *cnt=new int[n];//每个湖捕捉的鱼的时间	
	int *tmpcnt=new int[n];//临时存放每个湖捕捉的鱼的时间
	double lefttime;//剩余时间
	int *tmpfi=new int[n];
	for(int i=0;i<n;++i){
		cnt[i]=0;
	}
	for(int k=0;k<n;++k){//在k个湖中捕鱼
		lefttime=h*60;//将时间转换为分钟
		for(int i=0;i<=k;++i){
			tmpcnt[i]=0;//初始为0
			tmpfi[i]=fi[i];
		}	
		int index;
		int tmp=0;
		for(int i=0;i<k;++i){
			lefttime-=ti[i]*5.0;//减去在每个湖之间转移时在路上耗费的时间
		}
		for(lefttime;lefttime>=5.0;lefttime-=5.0){
			index=get_maxfish(tmpfi,k+1);
			if(index==-1){
				break;
			}
			tmpcnt[index]+=5;
			tmp+=tmpfi[index];
			tmpfi[index]-=di[index];			
		}	
		tmpcnt[0]+=lefttime;
		if(tmp>maxnum){
			maxnum=tmp;
			for(int i=0;i<=k;++i){
				cnt[i]=tmpcnt[i];
			}
		}
	}
	for(int i=0;i<n-1;++i){
		cout<<cnt[i]<<", ";
	}
	cout<<cnt[n-1]<<endl;
	cout<<"Number of fish expected: "<<maxnum<<endl<<endl;
	delete []tmpcnt;
	delete []tmpfi;
	delete []cnt;
}

int main()
{
	int n;//湖的个数
	double h;//时间，小时
	int *fi;//每个湖前5分钟可以捕捉的鱼
	int *di;//每个湖每5分钟捕捉的鱼的减少量
	int *ti;//每个湖之间需要的时间，以5分钟为单位
	while(cin>>n,n){
		cin>>h;
		fi=new int[n];
		di=new int[n];
		ti=new int[n-1];
		for(int i=0;i<n;++i){
			cin>>fi[i];
		}
		for(int i=0;i<n;++i){
			cin>>di[i];
		}
		for(int i=0;i<n-1;++i){
			cin>>ti[i];
		}
		gone_fishing(fi,di,ti,h,n);
		delete[]fi;
		delete[]di;
		delete[]ti;
	}
	return 0;
}
