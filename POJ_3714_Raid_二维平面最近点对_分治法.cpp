#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;

typedef struct point{
	int x,y;
	bool flag;
}point;
point parr[200005];
int psub[200005];
const double maxi=numeric_limits<double>::max();

bool cmp(point a,point b)
{
	return a.x<b.x;
}
bool compare(int a,int b)
{
	return parr[a].y<parr[b].y;
}
double dist(point a,point b)//返回两点间的距离
{
	if(a.flag==b.flag){
		return maxi;
	}
	return sqrt(pow(a.x-b.x,2.0)+(pow(a.y-b.y,2.0)));	
}

double min_dist(int low,int high)
{
	if(low==high){
		return maxi;
	}
	if(low+1==high){
		return dist(parr[low],parr[high]);
	}
	int mid=(low+high)>>1;
	double l_min=min_dist(low,mid);
	double r_min=min_dist(mid+1,high);
	double mini=l_min<r_min?l_min:r_min;
	int idx=0;
	for(int i=mid;i>=low;--i){
		if(parr[mid].x-parr[i].x<=mini){
			psub[idx++]=i;
		}else{
			break;
		}
	}
	for(int i=mid+1;i<=high;++i){
		if(parr[i].x-parr[mid].x<=mini){
			psub[idx++]=i;
		}else{
			break;
		}
	}
	sort(psub,psub+idx,compare);
	for(int i=0;i<idx;++i){
		for(int j=i+1;j<=i+8;++j){
			if(j>idx){
				break;
			}
			if(parr[psub[j]].y-parr[psub[i]].y>mini){
				break;
			}
			double tmp=dist(parr[psub[j]],parr[psub[i]]);
			if(tmp<mini){
				mini=tmp;
			}
		}
	}
	return mini;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>parr[i].x>>parr[i].y;
			parr[i].flag=false;
		}
		for(int i=n;i<2*n;++i){
			cin>>parr[i].x>>parr[i].y;
			parr[i].flag=true;
		}
		sort(parr,parr+2*n,cmp);	
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<min_dist(0,2*n-1)<<endl;
	}
}
