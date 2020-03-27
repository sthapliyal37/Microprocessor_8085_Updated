#include<bits/stdc++.h>
#include "Logical.h"
#include "Essential.h"
#include "Validation.h"
using namespace std;

void CMP(string instruction,string registers[],bool flag[],map<string,string>& memory)
{
	int l1=instruction.length();
	if(l1==1)
	{
		if(instruction=="M")
		{
		    string address=registers[5]+registers[6];
			if(registers[0]<memory[address])
			{
			    flag[0]=true;
			}
			else if(registers[0]==memory[address])
			{
				flag[6]=true;
			}
			else
			{
				flag[0]=false;
				flag[6]=false;
			}
		}
		else if(validityRegisters(instruction))
		{
			int index=registerNumber(instruction);
    		if(registers[0]<registers[index])
    		{
				flag[0]=true;
			}
			else if(registers[0]==registers[index])
			{
				flag[6]=true;
			}
			else
			{
			    flag[0]=false;
				flag[6]=false;
			}
		}
		else{
			
			cout<<"Error: "<<instruction<<"\nInvalid registers\nThe program will quit\n";
			exit(0);
		}
	}


}
void CMA(string instruction,string registers[],bool flags[])
{
string complment = complement(registers[0]);
	registers[0] = complment;
		
	if(registers[0]=="00")
    {
        flags[6] = true;
        flags[2] = true;
    }
    else
    {
        string temp = registers[0];
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

}
