#include<bits/stdc++.h>
#include "Essential.h"
#include"Validation.h"
#include"Memory_Allocation.h"
#include "DataTransfer.h"
using namespace std;
void MOV (string instruction,string instruction2,string* registers,bool* flag,map<string,string> &memory)
{
	int length=instruction.length();
	int length2=instruction2.length();
	if(length==1&&length2==1)
	{
        if(instruction=="M"&&instruction2!="M")
        {
            if(validityRegisters(instruction2))
            {
                string address=registers[5]+registers[6];
                memory[address]=registers[registerNumber(instruction2)];
            }
        }
        else if(instruction!="M" && instruction2=="M")
        {
            if(validityRegisters(instruction))
            {
                string address=registers[5]+registers[6];
                registers[registerNumber(instruction)]=memory[address];
            }
        }
        else if(instruction!="M"&&instruction2!="M")
        {
            if(validityRegisters(instruction2)&&validityRegisters(instruction)){
               registers[registerNumber(instruction)]=registers[registerNumber(instruction2)];
		   }
		 }
		 }  
}
void MVI (string instruction,string instruction2,string* registers,bool* flags,map<string,string> &memory)
{
	int length=instruction.length();
	int length2=instruction2.length();
	//cout<<instruction<<" "<<instruction2<<endl;	
	if(length==1&&length2==2)
	{
	        if(instruction=="M")
	        {
	            string address=registers[5]+registers[6];
	            if(validityData(instruction))
	                memory[address]=instruction2;
	        }

	else if(validityRegisters(instruction)&&validityData(instruction2))
	{
			
			if(instruction == "A" && instruction2 == "00")
			{
				
				flags[6] = true;
				flags[2] = true;
			}
			else if(instruction=="A" && instruction2!="00")
            		{
				string temp = instruction2;
				int array[2];
        		        hexToDecimal(temp,array);
        		        int value=array[1]*16+array[0];
        		        bitset<8> dataInBinary(value);
        		        int parity = dataInBinary.count();
        		        if(parity%2 == 0 && parity!=0)
        		           flags[2] = true;
        		        else
        		           flags[2] = false;
        		}
			registers[registerNumber(instruction)]=instruction2;
	//	cout<<registerNumber(instruction)<<" "<<registers[registerNumber(instruction)]<<endl;		
	}

}
    
}
void LXI (string instruction,string instruction2,string* registers,bool* flags,map<string,string> &memory)
{
	int length=instruction.length();
	int length2=instruction2.length();
	if(length==1&&length2==4)
	{
		if(instruction=="M")
		{
			if(validityAddress(instruction2))
			{
				string str1="",str2="";
				for(int i=0;i<2;i++)
				{
					str1+=instruction2[i];
					str2+=instruction2[i+2];
				}
				registers[5]=str1;
				registers[6]=str2;
			}
		}
		else
		{
			if(validityRegisterPair(instruction)&&validityAddress(instruction2))
			{
				string str1="",str2="";
				for(int i=0;i<2;i++)
				{
					str1+=instruction2[i];
					str2+=instruction2[i+2];
				}
				registers[registerNumber(instruction)]=str1;
				registers[registerNumber(instruction)+1]=str2;
			}
		}	
		}
}
void LDA(string instruction,string* registers,bool* flag,map<string,string>&memory){
		int length=instruction.length();
	if(length==4)
		if(validityAddress(instruction))
			registers[0] = memory[instruction];
}
void SHLD(string instruction,string* registers,bool* flag,map<string,string>&memory){
	
	int length=instruction.length();
	if(length==4)
	{
		if(validityAddress(instruction)&&validityAddress(increaseAddress(instruction)))
		{
			memory[instruction]=registers[6];
			memory[increaseAddress(instruction)]=registers[5];
		}
	}
}
void STAX(string instruction,string* registers,bool* flag,map<string,string>& memory){
int length=instruction.length();
	if(length==1)
	{
		if(validityRegisterPair(instruction))
		{
			string address="";
			int index=registerNumber(instruction);
			address+=registers[index]+registers[index+1];
			if(validityAddress(address))
				memory[address]=registers[0];
		}
	}
}
void XCHG(string* registers,bool* flag){
string temp=registers[3];
	registers[3]=registers[5];
	registers[5]=temp;
	temp=registers[4];
	registers[4]=registers[6];
	registers[6]=temp;
}
void STA(string instruction,string* registers,bool* flag,map<string,string> &memory){

int length=instruction.length();
	//cout<<length<<endl;
	if(length==4)
	{
		if(validityAddress(instruction))
		{	memory[instruction]=registers[0];
			//cout<<memory[instruction]<<endl;
		}	
	}
}
void LHLD(string instruction,string* registers,bool* flag,map<string,string>& memory){
int length=instruction.length();
	if(length==4)
	{
		if(validityAddress(instruction)&&validityAddress(increaseAddress(instruction)))
		{
			registers[6]=memory[instruction];
			registers[5]=memory[increaseAddress(instruction)];
		}
	}
}
void SET(string instruction,string instruction2,map<string,string>& memory){
int length1=instruction.length();
	int length2=instruction2.length();
	if(length1==4&&length2==2)
		if(validityAddress(instruction)&&validityData(instruction2))
			memory[instruction]=instruction2;		
}
