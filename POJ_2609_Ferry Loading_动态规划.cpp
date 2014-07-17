#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

void ferry_loading_1(int len,vector<int> &vec)//poj_2609,动态规划
{
	len*=100;//米和厘米的单位转换
	int num=vec.size();
	int **dp=new int *[num+1];
	int *sum=new int[num+1];//用来求和
	sum[0]=0;
	for(int i=0;i<num+1;++i){
		dp[i]=new int [len+1];
		for(int j=0;j<len+1;++j){
			dp[i][j]=-1;
		}
	}
	dp[0][0]=0;//初始值
	int index=0,indexJ=0;//用来保存最多的车辆和最后一辆车的放置的长度位置
	for(int i=1;i<=num;++i){
		sum[i]=sum[i-1]+vec[i-1];//到i为止的所有车辆的总长度
		for(int j=1;j<=len;++j){
			if(j>=vec[i-1] && dp[i-1][j-vec[i-1]]!=-1){
				dp[i][j]=j-vec[i-1];
				index=i;
				indexJ=j;
			}else if(sum[i]-j<=len && dp[i-1][j]!=-1){
				dp[i][j]=j; 
				index=i;
				indexJ=j;
			}			
		}
	}
	for(int i=index;i>0;--i){
		if(dp[i][indexJ]==indexJ){//此处将sum用来记录是第i辆车放置为左边或者右边
			sum[i]=1;//1表示放置在右边，0表示放置在左边					
		}else{
			sum[i]=0;
		}
		indexJ=dp[i][indexJ];
	}
	cout<<index<<endl;
	for(int i=1;i<=index;++i){
		if(sum[i]==0){
			cout<<"port"<<endl;
		}else{
			cout<<"starboard"<<endl;
		}
	}

	for(int i=0;i<num+1;++i){
		delete [] dp[i];
	}
	delete []dp;	
	delete []sum;
}


int main()
{
	int len;
	cin>>len;
	int val;
	vector<int> vec;
	while(cin>>val,val){
		vec.push_back(val);
	}
	ferry_loading_1(len,vec);
	//swap(vector<int>(),vec);//清除空间
	vec.clear();
}
