#include <iostream>
#include <string>
using namespace std;

typedef struct tiretree{//字典树
	int times;//节点被作为前缀的次数
	bool leaves;//判断是否是节点
	tiretree *next[10];//存放子节点
}tiretree,*pTiretree;

string dispose(string str)//对每次输入的字符串进行处理，将所有的输入都转换成为数字字符串
{
	string strRes="";
	int size=str.length();//获取字符串的长度
	for(int i=0;i<size;++i){//从最后一个字符开始处理
		if(str[i]>='0' && str[i]<='9'){//数字
			strRes+=str[i];
		}else if(str[i]=='-'){//character '-'
			continue;
		}else{//字母
			if(str[i]<'Q'){
				strRes+=(str[i]-'A')/3+2+'0';
			}else{
				strRes+=(str[i]-'A'-1)/3+2+'0';
			}
		}
	}
	return strRes;
}

pTiretree createTiretreeNode()//创建字典树结点
{
	pTiretree ptt=new tiretree;
	ptt->times=0;
	ptt->leaves=false;
	for(int i=0;i<10;++i){
		ptt->next[i]=NULL;
	}
	return ptt;
}

void createTiretree(pTiretree &ptt,string str)//创建字典树
{
	pTiretree ptmp=ptt;
	int k;
	pTiretree pn;
	int size=str.size();//字符串个数
	while(ptmp && size){
		--size;
		k=str[str.size()-size-1]-'0';
		if(ptmp->next[k]==NULL){			
			pn=createTiretreeNode();
			ptmp->next[k]=pn;			
		}		
		ptmp=ptmp->next[k];
	}
	//叶子结点，设置其标记和相应的访问次数
	ptmp->leaves=true;
	++ptmp->times;
}


void dfs(pTiretree pthead,int depth,string str,bool &duplicates)//深度优先遍历
{
	for(int i=0;i<10;++i){
		if(pthead->next[i]){
			str+=i+'0';
			if(depth==2){
				str+='-';
			}
			if(pthead->next[i]->leaves){//如果为叶子结点
				if(pthead->next[i]->times>1){
					cout<<str<<" "<<pthead->next[i]->times<<endl;
					duplicates=true;
				}
			}
			dfs(pthead->next[i],depth+1,str,duplicates);
			if(depth>2){
				str.erase(depth+1,1);
			}else{
				if(depth==2){
					str.erase(depth,1);
				}
				str.erase(depth,1);
			}
			delete pthead->next[i];//删除元素
		}
	}
}

int main()
{
	int n;
	cin>>n;
	string str,strRes;
	pTiretree ptthead=createTiretreeNode();//头结点
	for(int i=0;i<n;++i){
		cin>>str;
		strRes=dispose(str);
		//cout<<strRes<<endl;
		createTiretree(ptthead,strRes);
	}
	strRes="";
	bool duplicates=false;
	dfs(ptthead,0,strRes,duplicates);
	if(!duplicates){
		cout<<"No duplicates."<<endl;
	}
}
