#include<stdio.h>

int main()
{
	unsigned int x,y;
	
	scanf("%u",&x);
	y=((x << 6) | (x >> (sizeof(x) - 6))) ^ ((x << 11) | (x >> (sizeof(x) - 11))) ^ ((x << 25) | (x >> (sizeof(x) - 25)));
	
	printf("%u",y);
	
	return 0;
}
