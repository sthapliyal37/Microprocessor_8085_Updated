#include<bits/stdc++.h>
#include "Memory_Allocation.h"
#include"arithmetic.h"
#include"Branch.h"
#include"DataTransfer.h"
#include"Logical.h"
#include"Execution.h"	
using namespace std;
string execute_statement(string input,bool* flag,string* registers,map<string,string>& memory,string pc)
{
	string str;
	const char *partition = input.c_str();
	char *temp = (char*)partition;
	const char *delimiter = " ,";
	char *token = strtok(temp,delimiter);
	vector<string> statement;
	int statementSize;	
	while(token!=NULL){
		str = token;
		statement.push_back(token);
		token = strtok(NULL,delimiter);

	}
	if(!statement[0].compare("ADD"))	
	{
				ADD(statement[1],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("ADI"))	
	{
				ADI(statement[1],registers,flag);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("SUB"))	
	{
				SUB(statement[1],registers,flag,memory);
			return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("INR"))	
	{
				INR(statement[1],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("DCR"))	
	{
				DCR(statement[1],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("INX"))	
	{
				INX(statement[1],registers,flag);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("DCX"))	
	{
				DCX(statement[1],registers,flag);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("DAD"))	
	{
				DAD(statement[1],registers,flag);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("SUI"))	
	{
				SUI(statement[1],registers,flag);
				return allocate_memory(statement[0],pc);
	}
	
	else if(!statement[0].compare("JMP"))	
	{
				//	JMP(statement[1],registers,flag,memory);
				return(JMP(statement[1],registers,flag));
	}
	else if(!statement[0].compare("JC"))	
	{	
				//cout<<"JC"<<endl;
			//	JC(statement[1],registers,flag,memory);
				return(JC(statement[1],pc,registers,flag));
	}
	else if(!statement[0].compare("JNC"))	
	{
		//		JNC(statement[1],registers,flag,memory);
				return(JNC(statement[1],pc,registers,flag));
	}
	else if(!statement[0].compare("JZ"))	
	{
				//JZ(statement[1],registers,flag,memory);
				return(JZ(statement[1],pc,registers,flag));
	}
	else if(!statement[0].compare("JNZ"))	
	{
	//			JNZ(statement[1],registers,flag,memory);
				return(JNZ(statement[1],pc,registers,flag));
	}
	else if(!statement[0].compare("MOV"))	
	{
				MOV(statement[1],statement[2],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("MVI"))	
	{
				MVI(statement[1],statement[2],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("LXI"))	
	{
			LXI(statement[1],statement[2],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("LDA"))	
	{
		LDA(statement[1],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("SHLD"))	
	{
				SHLD(statement[1],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("STAX"))	
	{
			STAX(statement[1],registers,flag,memory);
				return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("XCHG"))	
	{
			XCHG(registers,flag);
								return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("STA"))	
	{	
			STA(statement[1],registers,flag,memory);
			return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("LHLD"))	
	{
			LHLD(statement[1],registers,flag,memory);
								return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("SET"))	
	{
		SET(statement[1],statement[2],memory);			
								return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("CMP"))	
	{
				CMP(statement[1],registers,flag,memory);
								return allocate_memory(statement[0],pc);
	}
	else if(!statement[0].compare("CMA"))	
	{
				CMA(statement[0],registers,flag);
				return allocate_memory(statement[0],pc);
	}
}

