#include <iostream>
#include <string>
using namespace std;


int * prefix_function(string str)//计算字符串的前缀函数
{
	int m=str.length();
	int q=-1;
	int *prefix_table=new int[m];
	prefix_table[0]=q;
	for(int i=1;i<m;++i){
		while(q>-1 && str[q+1]!=str[i]){
			q=prefix_table[q];
		}		
		if(str[q+1]==str[i]){
			++q;
		}
		prefix_table[i]=q;
	}

	/*for(int i=0;i<m;++i){
		cout<<prefix_table[i]<<endl;
	}*/

	return prefix_table;
}

void recursive_unit(string str)//确定循环节
{
	int *prefix_table=prefix_function(str);
	int m=str.length();
	int last=prefix_table[m-1];
	if(m%(m-1-last)==0){
		cout<<m/(m-1-last)<<endl;
	}else{
		cout<<1<<endl;
	}
	delete []prefix_table;
}



int main()
{
	string str;
	while(cin>>str){
		if(str=="."){
			return 0;
		}
		recursive_unit(str);
	}
	return 0;
}
