#include<bits/stdc++.h>
#include "Essential.h"
#include "Memory_Allocation.h"
#include "arithmetic.h"
#include "Validation.h"
using namespace std;

void ADD(string instruction,string* registers,bool* flag,map<string,string> &memory)
{
	int length=instruction.length();
	if(length == 1){
		
		if(validityRegisters(instruction) || validityRegisterPair(instruction)){
			
			if(instruction != "M"){
				int registerID = registerNumber(instruction);
				registers[0] = hexAdd(registers[registerID],registers[0],flag,true);
				
			}
			else{                         
		
				string address = "";
				address = address + registers[5] + registers[6];
				if(address >= "0000" && address <= "FFFF"){
					registers[0] = hexAdd(memory[address],registers[0],flag,true);				 
				}						
			}
			
			}
			}
}
void ADI(string instruction,string* registers,bool* flag)
{
		int length = instruction.length();
	if(length == 2){
	
		if(validityData(instruction)){
			registers[0] = hexAdd(instruction,registers[0],flag,true);
		}
		}
}
void SUB(string instruction,string* registers,bool* flag,map<string,string> &memory)
{
	int length=instruction.length();
	if(length == 1){
		
		if(validityRegisters(instruction)|| validityRegisterPair(instruction)){
			
			if(instruction != "M"){
				int registerID = registerNumber(instruction);              
				registers[0] = hexSub(registers[registerID],registers[0],flag,true);
				
			}
			else{                         
				string address = "";
				address = address + registers[5] + registers[6];
				if(address >= "0000" && address <= "FFFF"){
					registers[0] = hexSub(memory[address],registers[0],flag,true);				
					
				}
				}
				}
				}
}
void INR(string instruction,string* registers,bool* flag,map<string,string> &memory)
{
	int length = instruction.length();
	if(length == 1){
	
		if(validityRegisters(instruction)){
		
			if(instruction != "M"){
				int registerID = registerNumber(instruction);
				registers[registerID] = hexAdd(registers[registerID],"01",flag,false); 
			}
			else{
				string address = "";
				address = address + registers[5] + registers[6];
				if(validityAddress(address)){
				
					memory[address] = hexAdd(memory[address],"01",flag,false);
				}
					else{
					
					cout<<"Error:\n";
					exit(0);
				}
			}
			}
			}
}
void DCR(string instruction,string* registers,bool* flag,map<string,string>& memory)
{	int length = instruction.length();
		if(length == 1){
	
		if(validityRegisters(instruction)){
		
			if(instruction != "M"){
				int registerID = registerNumber(instruction);
				registers[registerID] = hexSub(registers[registerID],"01",flag,false);
			}
			else{
				string address = "";
				address = address + registers[5] + registers[6];
				if(validityAddress(address)){
				
					memory[address] = hexSub(memory[address],"01",flag,false);
				}
				else{
					cout<<"Error: \n";
					exit(0);
				}
			}
		}
		}
}
void INX(string instruction,string* registers,bool* flag)
{
int length = instruction.length();
	if(length == 1){
	
		if(validityRegisters(instruction)){
			
			int registerID = registerNumber(instruction);
			if(registerID == 1 || registerID == 3 || registerID == 5){
			
				string data16bit = "";
				string temporary = "";	
				string s1 = "";
				string s2 = "";
				if(validityData(registers[registerID]) == true && validityData(registers[registerID+1]) == true){
					
					data16bit = data16bit + registers[registerID] + registers[registerID + 1];
					temporary = increaseAddress(data16bit);
					 s1 = s1 + temporary[0] + temporary[1];		
					 s2 = s2 + temporary[2] + temporary[3];
					 registers[registerID] = s1; 
					 registers[registerID+1] = s2;
				}
				else{
					
					cout<<"Error: \n";
					exit(0);
				}
			}
			}
			}
}
void DCX(string instruction,string* registers,bool* flag)
{
	int length = instruction.length();
	if(length == 1){
	
		if(validityRegisters(instruction)){
			
			int registerID = registerNumber(instruction);
			if(registerID == 1 || registerID == 3 || registerID == 5){
			
				string data16bit = "";
				string temporary = "";
				string s1 = "";
				string s2 = "";
				string x="5000";
				if(validityData(registers[registerID]) == true && validityData(registers[registerID+1]) == true){
					
					data16bit = data16bit + registers[registerID] + registers[registerID + 1];
					temporary = hexSub16bit(data16bit,x,flag,false);
					 s1 = s1 + temporary[0] + temporary[1];		
					 s2 = s2 +temporary[2] + temporary[3];
					registers[registerID] = s1;
					registers[registerID+1] = s2;
				}
				else{
					cout<<"Error: \n";
					exit(0);
				}
			}
			}}
}
void DAD(string instruction,string* registers,bool* flag)
{
	int length = instruction.length();
	if(length == 1){
	
		if(validityRegisters(instruction)){
		
			int registerID = registerNumber(instruction);
			if(registerID == 1 || registerID == 3 || registerID == 5){
				
				string data16bit = "";
				string data16bitHL = "";
				string resultant = "";
				if(validityData(registers[registerID]) && validityData(registers[registerID+1]) && validityData(registers[5]) && validityData(registers[6])){
				
					data16bit = data16bit + registers[registerID] + registers[registerID];
					data16bitHL = data16bitHL + registers[5] + registers[6];
					int value16bit[4];
					int value16bitHL[4];
					int carry = 0;
					hexToDecimal(instruction,value16bit);
					hexToDecimal(instruction,value16bitHL);	  
					for(int i = 3;i>=0;i--){
					
						int value = value16bit[i] + value16bitHL[i] + carry;
						if(value >= 16)
							flag[0] = true;
						else
							flag[0] = false;
						carry = value / 16;
						value = value % 16;
						if(value>=0 && value<=9)
							resultant = (char)('0' + value) + resultant;
						else{
							switch(value){
							
								case 10:
									resultant = "A" + resultant;
									break;
								case 11:
									resultant = "B" + resultant;
									break;
								case 12:
									resultant = "C" + resultant;
									break;
								case 13:
									resultant = "D" + resultant;
									break;
								case 14:
									resultant = "E" + resultant;
									break;
								case 15:
									resultant = "F" + resultant;
									break;	
							}
						}
					}
					
					registers[5] = resultant[0] + resultant[1];
					registers[6] = resultant[2] + resultant[3];	
				}		
				else{
					cout<<"Error: \n";
					exit(0);
				}
			}

			}
		}
}
void SUI(string instruction,string* registers,bool* flag)
{
	int length = instruction.length();
	if(length == 2){
	
		if(validityData(instruction)){		
				registers[0] = hexSub(instruction,registers[0],flag,true);
		}
		else{
			
			cout<<"Error: \n";
			exit(0);
		}
	}
}
