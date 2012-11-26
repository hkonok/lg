#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 100009

using namespace std;

int a[N];
bool mat[1001];
int main()
{
	int t,n,i,m,c=0,one,two;

	scanf("%d",&t);

	while(t--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		c++;
		printf("Case %d:\n",c);
		while(m--){
			scanf("%d %d",&one,&two);
			if(two-one+1>1000)printf("0\n");
			else{
				memset(mat,0,sizeof(mat));
				for(i=one;i<=two;i++){
					if(mat[a[i]])break;
					else mat[a[i]]=true;
				}
				if(i<=two)printf("0\n");
				else{
					for(i=1;i<=1000;i++)
						if(mat[i])break;
					int prev=i;
					int mn=1000000000;
					for(i++;i<=1000;i++)
						if(mat[i]){
							mn=MIN(mn,i-prev);
							prev=i;
						}
					printf("%d\n",mn);
				}
			}
		}
	}

	return 0;
}