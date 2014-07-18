#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct point{//存放坐标结点
	int x,y;
}point,*ppoint;

int compare(const void *a,const void *b)
{
	return ((ppoint)a)->x-((ppoint)b)->x;
}

int main()
{
	int t,d;
	ppoint pp;//存放结点坐标
	int co=0;//记录第co组测试用例
	while(cin>>t>>d,t || d){
		++co;
		int ans=1;
		pp=new point[t];
		for(int i=0;i<t;++i){
			cin>>pp[i].x>>pp[i].y;
			if(abs(pp[i].y)>d){//雷达安置在海岸线上，如果岛屿的坐标超过雷达覆盖距离，则无法覆盖
				ans=-1;
			}
		}
		cout<<"Case "<<co<<": ";
		if(ans==-1){
			cout<<ans<<endl;
			continue;
		}
		qsort(pp,t,sizeof(point),compare);//调用系统快速排序算法
		double low=pp[0].x-sqrt(0.0+d*d-pp[0].y*pp[0].y);
		double high=pp[0].x+sqrt(0.0+d*d-pp[0].y*pp[0].y);
		double k;
		for(int i=1;i<t;++i){
			k=sqrt(0.0+d*d-pp[i].y*pp[i].y);
			if(pp[i].x-k<=high){
				low=pp[i].x-k;
				high=min(high,k+pp[i].x);
			}else{
				low=pp[i].x-sqrt(0.0+d*d-pp[i].y*pp[i].y);
				high=pp[i].x+sqrt(0.0+d*d-pp[i].y*pp[i].y);
				++ans;
			}
		}
		cout<<ans<<endl;
		delete []pp;
	}
	return 0;
}
