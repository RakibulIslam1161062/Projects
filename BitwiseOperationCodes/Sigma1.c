#include<stdio.h>

int main()
{
	unsigned int x,y;
	
	scanf("%u",&x);
	y=((x << 7) | (x >> (sizeof(x) - 7))) ^ ((x << 18) | (x >> (sizeof(x) - 18))) ^ (x >> 3);
	
	printf("%u",y);
	
	return 0;
}
