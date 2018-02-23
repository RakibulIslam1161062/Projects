#include<stdio.h>

int main()
{
	unsigned int x,y;
	
	scanf("%u",&x);
	y=((x << 17) | (x >> (sizeof(x) - 17))) ^ ((x << 19) | (x >> (sizeof(x) - 19))) ^ (x >> 10);
	
	printf("%u",y);
	
	return 0;
}
