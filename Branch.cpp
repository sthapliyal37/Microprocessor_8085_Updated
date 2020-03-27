#include<bits/stdc++.h>
#include "Branch.h"
#include "Essential.h"
#include "Validation.h"
#include"Memory_Allocation.h"
using namespace std;
string JMP(string instruction,string* registers,bool* flag){
if(validityAddress(instruction))
		return instruction;
}
string JC(string instruction,string pc,string* registers,bool* flag){
	if(flag[0] == true)
		return instruction;
	else{
		string resultant = "";
		int value16bit[4];
		int returnValue[] = {0,0,0,3};
		int carry = 0;
		hexToDecimal(pc,value16bit);	  
		for(int i = 3;i>=0;i--){
					
			int value = value16bit[i] + returnValue[i] + carry;
			carry = value / 16;
			value = value % 16;
			if(value>=0 && value<=9)
				resultant = (char)('0'+value) + resultant;
			else{
				resultant = (char)('A'+(value-10)) + resultant;
			}
		}
		if(validityAddress(resultant))
			return resultant;
		
	}
}
string JNC(string instruction,string pc,string* registers,bool* flag){

	if(flag[0] == false)
		return instruction;
	else{
		
		string resultant = "";
		int value16bit[4];
		int returnValue[] = {0,0,0,3};
		int carry = 0;
		hexToDecimal(pc,value16bit);	  
		for(int i = 3;i>=0;i--){
					
			int value = value16bit[i] + returnValue[i] + carry;
			carry = value / 16;
			value = value % 16;
			if(value>=0 && value<=9)
				resultant = (char)('0' + value) + resultant;
			else{
				resultant = (char)('A' + (value-10)) + resultant;
			}
		}
		if(validityAddress(resultant))
			return resultant;
	}
}
string JZ(string instruction, string pc, string* registers,bool* flag){

	if(flag[6] == true)
		return instruction;
	else{
		string resultant = "";
		int value16bit[4];
		int returnValue[] = {0,0,0,3};
		int carry = 0;
		hexToDecimal(pc,value16bit);	  
		for(int i = 3;i>=0;i--){
					
			int value = value16bit[i] + returnValue[i] + carry;
			carry = value / 16;
			value = value % 16;
			if(value>=0 && value<=9)
				resultant = (char)('0' + value) + resultant;
			else{
				resultant = (char)('A'+(value-10)) + resultant;
			}
		}
		if(validityAddress(resultant))
			return resultant;
	}
}
string JNZ(string instruction, string pc, string* registers,bool* flag){
	if(flag[6] == false){
		//cout<<"inside jnz::"<<" "<<instruction<<endl;	
		return instruction;
		}
		else{
		string resultant = "";
		int value16bit[4];
		int returnValue[] = {0,0,0,3};
		int carry = 0;
		hexToDecimal(pc,value16bit);	  
		for(int i = 3;i>=0;i--){
					
			int value = value16bit[i] + returnValue[i] + carry;
			carry = value / 16;
			value = value % 16;
			if(value>=0 && value<=9)
				resultant = (char)('0' + value) + resultant;
			else{
				resultant = (char)('A'+(value-10)) + resultant;
			}
		}
		if(validityAddress(resultant))
			return resultant;
	}
}

