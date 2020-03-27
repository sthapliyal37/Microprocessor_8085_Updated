#include<bits/stdc++.h>
#include"Validation.h"
using namespace std;
bool validityRegisters(string reg)
{
	if(reg=="A"||reg=="B"||reg=="C"||reg=="D"||reg=="E"||reg=="H"||reg=="L")
		return true;
	else
		return false;
}
void print()
{
	cout<<"HELLO";
}
bool validityRegisterPair(string reg)
{
	if(reg=="B"||reg=="D"||reg=="H"||reg=="M")
		return true;
	else 
		return false;
}
int stoi(char character)
{	
		return character-'0';
}
int registerNumber(string str)
{
	if(str=="A")
		return 0;
	if(str=="B")
		return 1;
	if(str=="C")
		return 2;
	if(str=="D")
		return 3;
	if(str=="E")
		return 4;
	if(str=="H")
		return 5;
	if(str=="L")
		return 6;
	return 0;
}
string itos(int integer)
{	
		stringstream ss; 
  		ss<<integer;  
  		string s;  
  		ss>>s; 
	return s;
}
string split(string s)
{
string p="ABC";
	int i=0;
	while(s[i]!=' ' && s[i]!='\0')		
	{
					p[i]=s[i];
					i++;
	}	
		p[i]='\0';
		return p;
}
bool validityData(string a)
{
	int l=a.length();
	if(l==2)
	{
		if((a[0]>='0'&&a[0]<='9')||(a[0]>='A'&&a[0]<='F'))
		{
			if((a[1]>='0'&&a[1]<='9')||(a[1]>='A'&&a[1]<='F'))
				return true;
			else 
				return false;
		}
		else
			return false;
	}
	else 
		return false;
}
bool validityAddress(string data)
{
	bool flag;
	int l=data.length();
	if(l==4)
	{
		for(int i=0;i<l;i++)
			if(( data[i]>='0' && data[i]<='9')||( data[i]>='A' && data[i]<='F' ))
				flag = true;
			else
				flag = false;
		return flag;
	}
	else
		return false;
}

bool memoryValidation(string start)
{
			int num=0;
			int n=start.length();
			for(int i=0;i<n;i++)
			{	
					int a=stoi(start[i]);
					num=(num*10) + a; 
			}
			if(num>=2000 && num<=8000)
							return 1;
			return 0;				
}
bool inputValidation(string input)
{
	input=split(input);
	string arithmetic[]={"ADD","ADI","SUB","INR","DCR","INX","DCX","DAD","SUI"};
	string logical[]={"CMA","CMP"};
	string branch[]={"JMP","JC","JNC","JZ","JNZ"};
	string transfer[]={"MOV","MVI","LXI","LDA","SHLD","STAX","XCHG","STA","LHLD","SET"};
	int n=sizeof(arithmetic)/sizeof(arithmetic[0]);
	for(int i=0;i<n;i++)
	{
				if(!input.compare(arithmetic[i]))
								return true;
	}
	n=sizeof(logical)/sizeof(logical[0]);
	for(int i=0;i<n;i++)
	{
				if(!input.compare(logical[i]))
								return true;
	}
	n=sizeof(branch)/sizeof(branch[0]);
	for(int i=0;i<n;i++)
	{
				if(!input.compare(branch[i]))
								return true;
	}
		n=sizeof(transfer)/sizeof(transfer[0]);
	for(int i=0;i<n;i++)
	{
				if(!input.compare(transfer[i]))
								return true;
	}
	return false;
}
