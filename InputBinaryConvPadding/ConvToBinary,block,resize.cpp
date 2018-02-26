#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include<string>

using namespace std;

unsigned long ROTR(unsigned long words,int n)
{
	unsigned long res;
	
	res=((words << n) | (words >> (sizeof(words) - n)));
	return res;
}


unsigned long SHR(unsigned long x,int n)
{
	unsigned long  c=(x) >> n;
	return c;
}

unsigned long SIGMA0(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,2);
	b=ROTR(x,13);
	c=ROTR(x,22);
	d=(a)^(b)^(c);
	
	return d;
}

unsigned long SIGMA1(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,6);
	b=ROTR(x,11);
	c=ROTR(x,25);
	d=(a)^(b)^(c);
	
	return d;
}


unsigned long CH(unsigned long x, unsigned long y, unsigned long z)
{
	unsigned long res;
	res=((x)& (y)) ^ ((~x)& (z));
	
	return res;
}


unsigned long MAJ(unsigned long x,unsigned long y,unsigned long z)
{
	unsigned long res;
	res=((x) & (y)) ^ ((x)& (z)) ^ ((y) & (z));
	
	return res;
}

unsigned long EPS0(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,7);
	b=ROTR(x,18);
	c=SHR(x,3);
	d=(a)^(b)^(c);
	return d;
}

unsigned long EPS1(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,17);
	b=ROTR(x,19);
	c=SHR(x,10);
	d=(a)^(b)^(c);
	return d;
}

vector< unsigned long> convertToBinary(string msg)
{
	vector<unsigned long> converted;
	for(int i=0;i<msg.length();i++)
	{
		bitset<8>bits(msg.c_str()[i]);
		
		converted.push_back(bits.to_ulong());
	}
	return converted;
}


vector<unsigned long> paddingZeros(vector<unsigned long> block)
{
	int lengthOfString=block.size()*8;
	int k=448-1-lengthOfString;
	unsigned long pad1n70=0x10000000;
	k=k-7;
	block.push_back(pad1n70);
	//unsigned long o=0x00000000;
	
	for(int i=0;i<k/8;i++)
	{
		block.push_back(0x00000000);
	}
	
	bitset<64>len(lengthOfString);
	string bitsetString= len.to_string();
	
	for(int i=0;i<63;i=i+8)
	{
		bitset<8>len2(bitsetString.substr(i,8));
		
		block.push_back(len2.to_ulong());
	}
	
	return block;
	
	
}


int main()
{
	string msg;
	cin>>msg;
	
	vector< unsigned long> bConvertedMsgBlock;
	
	bConvertedMsgBlock=convertToBinary(msg);
//	cout<<bConvertedMsgBlock.size();
	
	vector<unsigned long int>padded;
	
	padded=paddingZeros(bConvertedMsgBlock);
	
	for(int i=0;i<padded.size();i++) cout<<padded[i]<<endl;
	
	cout<<padded.size();
	//cout<<0x10000000;
	
}
