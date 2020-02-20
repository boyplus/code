#include <cstdio>
#include <stdlib.h>
using namespace std;
bool problem[2010][2010];
int count_pass[2010];
int score[2010];
struct people
{
	int id;
	int count;
	int score;
}data[2000];
int cmp(const void* a,const void *b)
{
	people *peopleA = (people*)a;
	people *peopleB = (people*)b;
	if(peopleA->score > peopleB->score)
        return -1;
    if(peopleA->score < peopleB->score)
        return 1;
    if(peopleA->count > peopleB->count)
    	return -1;
    if(peopleA->count < peopleB->count)
    	return 1;
    if(peopleA->id < peopleB->id)
        return -1;
    return 1;
}
int main()
{
	int i,j,k,m,n,t,p;
	scanf("%d %d %d",&n,&t,&p);
	for(i=0;i<n;++i)
	{
	    data[i].id = i;
		for(j=0;j<t;++j)
		{
			scanf("%d",&problem[i][j]);
			if(problem[i][j])
			{
				++data[i].count;
				++count_pass[j];
			}
		}
	}
	for(i=0;i<t;++i)
		score[i] = n - count_pass[i];
	for(i=0;i<n;++i)
		for(j=0;j<t;++j)
			if(problem[i][j])
				data[i].score = data[i].score + score[j];
	qsort(data,n,sizeof(people),cmp);
	--p;
    for(i=0;i<n;++i)
    {
        if(data[i].id == p)
        {
            printf("%d %d\n",data[i].score,i+1);
            return 0;
        }
    }
	return 0;
}
