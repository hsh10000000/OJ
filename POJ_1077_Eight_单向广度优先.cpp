#include <iostream>
#include <bitset>
using namespace std;
char *target="123456780";//终止状态
bitset<387420498>flags;
int frdQueue[400000];//前向队列
int father[400000];
char szMove[400000];
int fqHead=0,fqTail=1;
int nine2ten(char *s)//九进制数转换成为十进制数
{
	int nResult=0;
	for(int i=0;i<9;++i){
		nResult*=9;
		nResult+=(s[i]-'0');
	}
	return nResult;
}
int ten2nine(int n,char *s)//十进制数转换为九进制数，并且找出0元素的位置
{
	int nZeroPos;
	int nBase=1;
	for(int i=0;i<8;++i){
		nBase*=9;
	}
	for(int i=0;i<9;++i){
		s[i]=n/nBase+'0';
		n%=nBase;
		nBase/=9;		
		if(s[i]=='0'){
			nZeroPos=i;
		}
	}
	return nZeroPos;
}

int newstatus(int nStatus,char cMove)
{
	char szTmp[10];
	szTmp[9]='\0';
	int nZeroPos=ten2nine(nStatus,szTmp);
	switch(cMove){
		case 'u':
			if(nZeroPos<3){
				return -1;
			}
			szTmp[nZeroPos]=szTmp[nZeroPos-3];
			szTmp[nZeroPos-3]='0';
			break;
		case 'd':
			if(nZeroPos>5){
				return -1;
			}
			szTmp[nZeroPos]=szTmp[nZeroPos+3];
			szTmp[nZeroPos+3]='0';
			break;
		case 'l':
			if(!(nZeroPos%3)){
				return -1;
			}
			szTmp[nZeroPos]=szTmp[nZeroPos-1];
			szTmp[nZeroPos-1]='0';
			break;
		case 'r':
			if(nZeroPos%3==2){
				return -1;
			}
			szTmp[nZeroPos]=szTmp[nZeroPos+1];
			szTmp[nZeroPos+1]='0';
			break;
	}
	return nine2ten(szTmp);
}

bool bfs(int nStatus)//广度优先
{
	 frdQueue[fqHead]=nStatus;
	 int targetStatus=nine2ten(target);
	 int currStatus;//当前处理的结点
	 char *sz4Move="udlr";//4个移动方向
	 int nNewStatus;
	 while(fqHead!=fqTail){//队列非空
		currStatus=frdQueue[fqHead];		
		if(currStatus==targetStatus){
			return true;
		}
		for(int i=0;i<4;++i){
			nNewStatus=newstatus(currStatus,sz4Move[i]);
			if((-1==nNewStatus)||flags[nNewStatus]){
				continue;
			}
			flags.set(nNewStatus,true);
			frdQueue[fqTail]=nNewStatus;
			father[fqTail]=fqHead;
			szMove[fqTail]=sz4Move[i];
			++fqTail;
		}
		++fqHead;
	 }
	 return false;
}

void print(int nPos)//打印最终结果
{
	if(nPos){
		print(father[nPos]);
		cout<<szMove[nPos];
	}
}

int main()
{
	char str[10];//初始状态
	str[9]='\0';
	for(int i=0;i<9;++i){
		cin>>str[i];
		if(str[i]=='x'){
			str[i]='0';
		}
	}
	if(bfs(nine2ten(str))){
		print(fqHead);
		cout<<endl;
	}else{
		cout<<"unsolvable"<<endl;
	}
	return 0;
}
