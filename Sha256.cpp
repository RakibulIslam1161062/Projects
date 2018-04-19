#include<bits/stdc++.h>

using namespace std;


unsigned long ROTR(unsigned long words,int n)   //rotate right
{
	unsigned long res;
	
	res=((words >> n) | (words << (32 - n)));
	return res;
}


unsigned long SHR(unsigned long x,int n)      //Right shifting 
{
	unsigned long  c=(x) >> n;
	return c;
}


unsigned long EPS1(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,6);
	b=ROTR(x,11);
	c=ROTR(x,25);
	d=(a)^(b)^(c);
	
	return d;
}


/*
#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include<string>
*/
/*#define ROTR(word,bits) (((word) >> (bits)) | ((word) << (32-(bits))))
#define EPS1(x) (ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
*/
unsigned long CH(unsigned long x, unsigned long y, unsigned long z)
{
	unsigned long res;
	res=((x)& (y)) ^ ((~x)& (z));
	
	return res;
}

unsigned long EPS0(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,2);
	b=ROTR(x,13);
	c=ROTR(x,22);
	d=(a)^(b)^(c);
	
	return d;
}

unsigned long MAJ(unsigned long x,unsigned long y,unsigned long z)
{
	unsigned long res;
	res=((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z));
	
	return res;
}

unsigned long SIGMA0(unsigned long x)
{
	unsigned long a,b,c,d;
	a=ROTR(x,7);
	b=ROTR(x,18);
	c=SHR(x,3);
	d=(a)^(b)^(c);
	return d;
}

unsigned long SIGMA1(unsigned long x)
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
	
	unsigned long pad1n70=0x80;
	block.push_back(pad1n70);
	//unsigned long o=0x00000000;
	
	for(int i=0;i<k/8;i++)
	{
		block.push_back(0x00000000);
	}
	
	bitset<64>len(lengthOfString);
	string bitsetString= len.to_string();
	
	bitset<8>temp1(bitsetString.substr(0,8));
	block.push_back(temp1.to_ulong());
	
	for(int i=8;i<63;i=i+8)
	{
		bitset<8>len2(bitsetString.substr(i,8));
		
		block.push_back(len2.to_ulong());
	}
	
	return block;
	
	
}

vector<unsigned long> resizeInto16Blocks(vector<unsigned long>message)
{
	vector<unsigned long>resizedMsgBlock(16);
	
	
	for(int i=0;i<64;i=i+4)
	{
		bitset<32> temp(0);
		
		temp=(unsigned long)message[i]<< 24;
		temp|=message[i+1]<< 16;
		temp|=message[i+2]<< 8;
		temp|=message[i+3];
		
		resizedMsgBlock[i/4]=temp.to_ulong();
	}
	
	return resizedMsgBlock;
}


string show_as_hex(unsigned long input)
{
	bitset<32> bs(input);
	unsigned n = bs.to_ulong();

	stringstream sstream;
	sstream << std::hex << std::setw(8) << std::setfill('0') << n;
	string temp;
	sstream >> temp;

	return temp;
}


string computeTheHashValue(vector<unsigned long>msg)
{
	unsigned long k[64] = {
		0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,
		0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
		0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,
		0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
		0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,
		0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
		0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,
		0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
		0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,
		0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
		0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
	};
	
	
    unsigned long static H0 = 0x6a09e667;
	unsigned long static H1 = 0xbb67ae85;
	unsigned long static H2 = 0x3c6ef372;
	unsigned long static H3 = 0xa54ff53a;
	unsigned long static H4 = 0x510e527f;
	unsigned long static H5 = 0x9b05688c;
	unsigned long static H6 = 0x1f83d9ab;
	unsigned long static H7 = 0x5be0cd19;
	
	unsigned long w[64];
	
	for(int t=0;t<=15;t++)
		w[t]=msg[t] & 0xFFFFFFFF;
	
	
	for(int t=16;t<64;t++)
	{
		w[t]= SIGMA1(w[t-2]) + w[t-7] + SIGMA0(w[t-15]) + w[t-16];
		w[t]=w[t] & 0xFFFFFFFF;
	}
	//for(int t=0;t<64;t++) cout<<w[t];
	//ekhan pojnto checked
	unsigned long a = H0;
	unsigned long b = H1;
	unsigned long c = H2;
	unsigned long d = H3;
	unsigned long e = H4;
	unsigned long f = H5;
	unsigned long g = H6;
	unsigned long h = H7;
	
    unsigned long temp1;
    unsigned long temp2;
    int t;
    for( t=0;t<64;t++) 
    {
	
    	temp1= h + EPS1(e) + CH(e,f,g) + k[t] + w[t];
    //cout<<temp1;
	//cout<<h;
	//<<endl<<EPS1(e)<<endl<<CH(e,f,g)<<endl<<k[t-1]<<endl<<w[t-1]<<endl;	
    
    temp2= EPS0(a) + MAJ(a,b,c);
    
	h = g;
	g = f;
	f = e;
	e = (d + temp1) & 0xFFFFFFFF; 
	d = c;
	c = b;
	b = a;
	a = (temp1 + temp2) & 0xFFFFFFFF;
}
	H0 = (H0 + a) & 0xFFFFFFFF;
	H1 = (H1 + b) & 0xFFFFFFFF;
	H2 = (H2 + c) & 0xFFFFFFFF;
	H3 = (H3 + d) & 0xFFFFFFFF;
	H4 = (H4 + e) & 0xFFFFFFFF;
	H5 = (H5 + f) & 0xFFFFFFFF;
	H6 = (H6 + g) & 0xFFFFFFFF;
	H7 = (H7 + h) & 0xFFFFFFFF;

	return show_as_hex(H0) + show_as_hex(H1) + show_as_hex(H2) +
		   show_as_hex(H3) + show_as_hex(H4) + show_as_hex(H5) +
		   show_as_hex(H6) + show_as_hex(H7);
}


int main()
{
	string msg;
	cin>>msg;
	
	vector< unsigned long> bConvertedMsgBlock;
	
	bConvertedMsgBlock=convertToBinary(msg);
	//cout<<bConvertedMsgBlock.size();
	
	vector<unsigned long int>padded;
	
	padded=paddingZeros(bConvertedMsgBlock);
	
	
	
	//cout<<padded.size();
	//cout<<0x10000000;
	vector <unsigned long> resized;
	
	resized=resizeInto16Blocks(padded);
	//for(int i=0;i<resized.size();i++) cout<<resized[i];
	string hashValue;
	
	hashValue=computeTheHashValue(resized);
	cout<<hashValue;
	
	
	
}

