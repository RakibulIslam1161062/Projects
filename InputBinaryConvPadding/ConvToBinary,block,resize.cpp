#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include<string>

using namespace std;

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
