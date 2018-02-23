#include<stdio.h>

int main()
{
	unsigned int x,y,z,r;
	scanf("%u %u %u",&x,&y,&z);
	
	r=(x & y) ^ (x & z) ^ (y & z);
	
	printf("%u",r);
	
	return 0;
}
