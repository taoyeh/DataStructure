#include <bits/stdc++.h>
int Binary_Search(int SeqList[],int key)
{
	int low=0,high=11,i,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(SeqList[mid]==key) return mid;
		if(SeqList[mid]<key) low=mid+1;
		else high=mid-1;
	}
	return -1;
  }  
int main()
{
	int SeqList[12]={7,10,13,16,19,29,32,33,37,41,43},x=11;
	int res=Binary_Search(SeqList,x);
	if(res==-1) printf("Î´ÕÒµ½%d\n",x);
	else printf("ÒÑÕÒµ½%d\n",SeqList[res]);
	return 0;
 } 
