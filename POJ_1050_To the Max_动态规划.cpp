#include <iostream>
using  namespace std;

int array_max(int *&arr,int n)//求一维数组中最大的子数组之和
{
	int max=arr[0];
	int pre=arr[0];
	for(int i=1;i<n;++i){
		if(pre+arr[i]>arr[i]){
			pre=pre+arr[i];
		}else{
			pre=arr[i];
		}
		if(pre>max){
			max=pre;
		}
	}
	return max;
}

int max_sub_matrix(int **&matrix,int n)//求二维矩阵的最大子矩阵
{
	int maximum=matrix[0][0];
	int tmpval=0;
	int *sub_mat=new int[n];//存储每列的元素值
	for(int br=0;br<n;++br){//从第br行开始的矩阵
		memset(sub_mat,0,sizeof(int)*n);
		for(int row=br;row<n;++row){//到row行结束的矩阵
			for(int col=0;col<n;++col){//从br到row行的一列元素
				sub_mat[col]+=matrix[row][col];
			}
			tmpval=array_max(sub_mat,n);
			if(tmpval>maximum){
				maximum=tmpval;
			}
		}
	}
	delete [] sub_mat;
	return maximum;	
}

int main()
{
	int n;
	cin>>n;
	int **matrix=new int *[n];
	for(int i=0;i<n;++i){
		matrix[i]=new int [n];
		for(int j=0;j<n;++j){
			cin>>matrix[i][j];
		}
	}
	cout<<max_sub_matrix(matrix,n)<<endl;
	for(int i=0;i<n;++i){
		delete[] matrix[i];
	}
	delete [] matrix;
}
