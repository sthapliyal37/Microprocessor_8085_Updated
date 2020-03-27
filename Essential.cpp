#include<bits/stdc++.h>
#include "Essential.h"
using namespace std;
string increaseAddress(string a)
{
	int number[5];
	string nextAddress="";
	int l=a.length();
	for(int i=l-1;i>=0;i--)
	{
		if(a[i]>='A'&&a[i]<='F')
			number[i]=(int)(10+(a[i]-'A'));
		if(a[i]>='0'&&a[i]<='9')
			number[i]=(int)(a[i]-'0');
	}
	number[l-1]++;
	for(int i=l-1;i>=0;i--)
	{
		if(number[i]>=0&&number[i]<=15)
			break;
		if(number[i]>=16)
		{
			number[i]=number[i]%16;
			number[i-1]++;
		}
	}
	for(int i=0;i<l;i++)
	{
		if(number[i]>=0&&number[i]<=9)
			nextAddress+=(char)('0'+(number[i]));
		else if(number[i]>=10 && number[i]<=15)
			nextAddress+=(char)('A'+(number[i]-10));
	}
	return nextAddress;
}
string complement(string a)
{
	int l=a.length();
	string complment="";
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			int diff=15-(a[i]-'0');
			if(diff>=0&&diff<=9)
				complment+=('0'+diff);
			else if(diff>=10&&diff<=15)
				complment+=('A'+(diff-10));	
		}
		if(a[i]>='A'&&a[i]<='F')
		{
			int value=a[i]-'A';
			int diff=15-value;
			if(diff>=0&&diff<=9)
				complment+=('0'+diff);
			else if(diff>=10&&diff<=15)
				complment+=('A'+(diff-10));
		}
	}
	return complment;
}
string decimalToHex(int* deciml)
{
	string hex="";
	int size=sizeof(deciml)/sizeof(deciml[0]);
	for(int i=0;i<size;i++)
	{
		if(deciml[i]>=0 && deciml[i]<=9)
			hex = hex + char('0' + deciml[i]);
		else if(deciml[i]>=10 && deciml[i]<=15)
			hex+=(char)('A'+(deciml[i]-10));
	}
	return hex;
}
string hexAdd16bit (string arg1,string arg2,bool* flag,bool check)
{
	int l1=arg1.length();
	int l2=arg2.length();
	string hex="";
	if(l1==1&&l2==4)
	{
		int value1[4]={0,0,0,0};
		for(int i=0;i<l1;i++)
		{
			if(arg1[i]>='0'&&arg1[i]<='9')
				value1[i]=(int)(arg1[i]-'0');
			else if(arg1[i]>='A'&&arg1[i]<='Z')
				value1[i]=(int)(arg1[i]-'A');
		}
		int i=l1-1;
		value1[l1-1]++;
		while(value1[i]>=16)
		{
			value1[i]=value1[i]%16;
			if(i==0)
			{
				flag[0]=true;
				break;
			}
			else
				value1[--i]++;
		}
		int value=value1[0]*16*16*16+value1[1]*16*16+value1[2]*16+value1[3];
		bitset<16>str(value);
		flag[7]=str[15];
		int parity=str.count();
		if(parity==0)
			flag[6]=true;
		else if(parity%2==0)
			flag[2]=true;
		else if(parity%2==1)
			flag[2]=false;
		for(int i=0;i<l1;i++)
		{
			if(value1[i]>=0&&value1[i]<=9)
				hex+=(char)value1[i];
			else if(value1[i]>=10&&value1[i]<=15)
				hex+=(char)('A'+(value1[i]-10));
		}
	}
	return hex;
}
string hexAdd(string arg1,string arg2,bool* flag,bool carry){
	
	string resultant = "";
	int variable;
	int value1[5] = {0,0};
	int value2[5] = {0,0};
	int tempAnswer[2];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);
	
	tempAnswer[1] = value1[1] + value2[1];
	if(tempAnswer[1]>=16){
	
		tempAnswer[1] = tempAnswer[1]%16;
		value1[0]++;
		flag[4] = true;
		}
	tempAnswer[0] = value1[0] + value2[0];
	if(tempAnswer[0]>=16){
	
		tempAnswer[0] = tempAnswer[0]%16;
		if(carry == true)
			flag[0] = true;
	}
	
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	int parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[2] = true;
	else
		flag[2] = false;
	flag[7] = dataInBinary[7];
	if(parity == 0)
		flag[6] = true;
	
	for(int i = 1;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0' + tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	//cout<<resultant<<endl;
	return resultant;
}

void hexToDecimal(string pc,int arr[]){
 
	int l = pc.length();
	int p = 0;
	for(int i =0 ;i<l;i++){
	
		if(pc[i]>='0' && pc[i]<='9')
			arr[i] = pc[i] - '0';
		else 
			arr[i] = 10 + (pc[i] - 'A'); 
	}
}
string hexSub16bit(string arg1,string arg2,bool* flag,bool carry){
	
	string resultant = "";
	int variable;
	int parity;
	int value1[4];
	int value2[4];
	int tempAnswer[4];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);
	for(int i=3;i>=0;i--){
		
		if(value1[i] < value2[i]){
			
			tempAnswer[i] = (16 + value1[i]) - value2[i];
			if(i!=0)
				--value1[i-1];
			else{
				if(carry)
					flag[0] = true;
			}
		}
		else
		
			tempAnswer[i] = value1[i] - value2[i];
	}
	variable = tempAnswer[0]*16*16*16 + tempAnswer[1]*16*16 + tempAnswer[2]*16 + tempAnswer[3];
	bitset<16> dataInBinary(variable);
	parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[2] = true;
	else
		flag[2] = false;
	flag[7] = dataInBinary[7];
	if(parity == 0){

		flag[6] = true;
	}
	else{

		flag[6] = false;
	}
	for(int i = 3;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0'+tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}

	return resultant;
	
}
string hexSub(string arg1,string arg2,bool* flag,bool carry){
	
	string resultant = "";
	int variable;
	int parity;
	int value1[2];
	int value2[2];
	int tempAnswer[2];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);

	if(value1[1] < value2[1]){
		
		tempAnswer[1] = (16+value1[1])-value2[1];
		--value1[0];
		}
	else{
		tempAnswer[1] = value1[1] - value2[1];
	}

	if(value1[0] < value2[0]){
	
		if(carry == true)
			flag[0] = true;
			
		tempAnswer[0] = (16+value1[0]-value2[0]);
		}
	else
		tempAnswer[0] = value1[0] - value2[0];
		
	 
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[2] = true;
	else
		flag[2] = false;
	flag[7] = dataInBinary[7];
	if(parity == 0)
		flag[6] = true;
	else
		flag[6] = false;
		
	for(int i = 1;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0'+tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	//cout<<resultant<<endl;	
	return resultant;
	
}
