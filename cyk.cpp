#include <cstdio>
#include <cstring>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct abhi{
	string head;
	vector<string> body;
	float prob;
	int prev[4];
	int num[2];
};
typedef struct abhi node;
struct matrix{
	vector<node> cell;
};
typedef struct matrix matrix;
int split(char *buf, vector<string> &v, char ch)
{
	int i;
	int len=strlen(buf);
	string s;

	for(i=0;i<len;i++)
	{
		if(buf[i]-ch==0)
		{
			v.push_back(s);
			s="";
			continue;
		}
		else
		{
			s=s+buf[i];
		}
	}
	v.push_back(s);
	return v.size();
}
void print(int i,int j,int maxi);
matrix mat[20][20];
int main()
{
	int n;
	scanf("%d",&n);
	node a[n];
	int i,j,k;
	string s;
	int l;
	for(i=0;i<n;i++)
	{
		scanf("%d",&l);
		cin >> a[i].head;
		for(j=0;j<l-2;j++)
		{
			string temp1;
			cin >> temp1;
			a[i].body.push_back(temp1);
		}
		cin >> a[i].prob;
	}
	char c;
	c=getchar();
	c=getchar();
	char buf[1024];
	scanf("%[^\n]",buf);
	while(buf[0]-'0'<9)
	{
		gets(buf);
	}

	vector<string> v;

	//	printf("%s\n",buf);
	int len=split(buf,v,' ');
//	printf("%d\n",);

	/*vector<string>::iterator it3;
	  for(it3=v.begin();it3!=v.end();it3++)
	  {
	  cout << *it3 << endl;
	  }*/

	for(i=0;i<len;i++)
	{
		for(j=0;j<n;j++)
		{
			vector<string>::iterator it;
			it=find(a[j].body.begin(),a[j].body.end(),v[i]);
			if(it!=a[j].body.end())
			{
				mat[i][i].cell.push_back(a[j]);
			}
		}
	}

	/*	checking what are in the single cells
		cout << "len is "<<len << endl;
		for(i=0;i<len;i++)
		{
		puts("what the fuck");
		int t=mat[i][i].cell.size();
		for(j=0;j<t;j++)
		{
		cout << mat[i][i].cell[j].head << " ";
		int y=mat[i][i].cell[j].body.size();
		for(k=0;k<y;k++)
		{
		cout << mat[i][i].cell[j].body[k] << " ";
		}
		cout << mat[i][i].cell[j].prob << endl;
		}
		}*/


	for(j=1;j<len;j++)//traversing columns of matrix
	{
		for(i=j-1;i>=0;i--)//traversing rows of matrix
		{
			int temp1,temp2;
		//		cout << "i is " << i << "j is " << j << endl;
			for(temp1=1;j-temp1>=i;temp1++)
			{
		//		cout << "temp1 is "<< temp1 << endl;
			//	cout << "i is " << i << "j is " << j << endl;
		//			cout << "one is " << j-temp1+1 << " " << j <<"other is "<<i<< " "<<j-temp1 << endl;
				int q1,q2,q3,q4;
				q1=mat[i][j-temp1].cell.size();
				for(q2=0;q2<q1;q2++)//traversing the items in the cell [i][j-temp1]
				{
					q3=mat[j-temp1+1][j].cell.size();
			//		cout << "row is " << i+j-temp1<<"column is "<<j-temp1 << endl;

					for(q4=0;q4<q3;q4++)//traversing the items in the cell [i+temp1][j]
					{
						vector<string> temp3;
						temp3.push_back(mat[i][j-temp1].cell[q2].head);
						temp3.push_back(mat[j-temp1+1][j].cell[q4].head);
			//			cout <<"RHS is " << temp3[0] << " " << temp3[1] << endl;
						int q5,q6,q7,q8;
						for(q5=0;q5<n;q5++)//checking if a rule matches the combination of two items
						{

							if(a[q5].body==temp3)//if it does
							{
								node temp4;
								temp4.head=a[q5].head;
								temp4.body=temp3;
								temp4.prob=mat[j-temp1+1][j].cell[q2].prob*mat[i][j-temp1].cell[q4].prob*a[q5].prob;
								temp4.prev[0]=j-temp1+1;
								temp4.prev[1]=j;
								temp4.prev[2]=i;
								temp4.prev[3]=j-temp1;
								temp4.num[0]=q2;
								temp4.num[1]=q4;
								mat[i][j].cell.push_back(temp4);//push it into the cell
	//				cout << "pushed " << temp4.head << "->" << temp3[0] << " " << temp3[1]<< endl;

							}
						}

					}
				}
			}
		}
	}

	int size9=mat[0][len-1].cell.size();
	float max=-1;
	int maxi=0;
	for(i=0;i<size9;i++)
	{
		if(mat[0][len-1].cell[i].prob>max)
		{
			maxi=i;
			max=mat[0][len-1].cell[i].prob;
		}
	}
	print(0,len-1,maxi);
	puts("");
//	cout << mat[0][len-1].cell[maxi].head << " -> " << mat[0][len-1].cell[maxi].body[0] << " " << mat[0][len-1].cell[maxi].body[1] << endl;
	return 0;
}
void print(int i,int j,int maxi)
{
	cout << mat[i][j].cell[maxi].head<< " ";
	int sz=mat[i][j].cell[maxi].body.size();
	int t;
	for(t=0;t<sz;t++)
	{
		cout << mat[i][j].cell[maxi].body[t]<< " ";
	}
	puts("");
	if(i==j)
	{
	//	cout <<"("<< mat[i][j].cell[maxi].body[0]<< ") ";
		return;
	}
	print(mat[i][j].cell[maxi].prev[2],mat[i][j].cell[maxi].prev[3],mat[i][j].cell[maxi].num[1]);
	print(mat[i][j].cell[maxi].prev[0],mat[i][j].cell[maxi].prev[1],mat[i][j].cell[maxi].num[0]);
}
