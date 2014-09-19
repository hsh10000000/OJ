#include <stdio.h>
int arr[50005];
int re1[50005];
int re2[50005];
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	for(int k=0;k<t;++k){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
		re1[0]=arr[0];
		for(int i=1;i<n;++i){
			if(re1[i-1]>0){
				re1[i]=re1[i-1]+arr[i];
			}else{
				re1[i]=arr[i];
			}
		}
		for(int i=1;i<n;++i){
			if(re1[i]<re1[i-1]){
				re1[i]=re1[i-1];
			}
		}
		re2[n-1]=arr[n-1];
		for(int i=n-2;i>=0;--i){
			if(re2[i+1]>0){
				re2[i]=re2[i+1]+arr[i];
			}else{
				re2[i]=arr[i];
			}
		}		
		for(int i=n-2;i>=0;--i){
			if(re2[i]<re2[i+1]){
				re2[i]=re2[i+1];
			}
		}
		int sum=re1[0]+re2[1];
		for(int i=1;i<n-1;++i){
			if(re1[i]+re2[i+1]>sum){
				sum=re1[i]+re2[i+1];
			}
		}
		printf("%d\n",sum);
	}	
}
