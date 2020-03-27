#include<bits/stdc++.h>
#include"Execution.h"
#include"Validation.h"
#include"Memory_Allocation.h"
using namespace std;

//SIDDHANT THAPLIYAL 8085 SIMULATOR

int main(int argc , char*argv[])
{
	map<string,string> memory;
	vector<string> sequence;
	string input;
	ifstream infile("test5.txt");
	if(argc!=0)	
	{
			ifstream infile(argv[1]);
	}
	string start=" ",pc=" ";
	string end="HLT",s;
	string registers[7];
	bool flag[8];
	int n;
	cout<<"Enter  Number of MemoryAddresses needed:: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{		
		string str1,str2;
		cin>>str1>>str2;
		memory[str1]=str2;		
	}
	for(int i=0;i<7;i++)
			registers[i]="00";
	for(int i=0;i<8;i++)
			flag[i]=false;	
	cout<<"Starting Memory Address :: ";
	
	cin>>start;
	pc=start;
	/*if(memoryValidation(start))
	/{
				cout<<endl<<"INVALID/MEMORY ADDRESS OR RESERVED ADDRESS"<<endl;
					return 0;
	}*/	
	getline(infile,s);
	while(s.compare(end))
	{
				//if(inputValidation(s))
				//{
					cout<<pc;
					sequence.push_back(pc);	
					memory[pc]=s;
					string delimiter = " ";
					string token = s.substr(0, s.find(delimiter)); 
					pc=allocate_memory(token,pc);
					cout<<"::"<<s<<endl;
					getline(infile,s);
				//}		
				/*else
				{
							cout<<"INVALID INPUT"<<endl;
							return 0;	
			}*/
	}
	pc=start;
	int count=0;	
	int last=sequence.size()-1;
	//cout<<sequence[last];
	while(pc.compare(sequence[last]))
	{					
			cout<<memory[pc]<<endl;		
		pc=execute_statement(memory[pc],flag,registers,memory,pc);
	}
	pc=execute_statement(memory[pc],flag,registers,memory,pc);
	cout<<"*************************************************"<<endl<<endl;
	cout<<"REGISTERS"<<endl;
	for(int i=0;i<7;i++)	
		cout<<registers[i]<<" ";
	cout<<endl;	
	cout<<"*************************************************"<<endl;	
	cout<<endl;
	cout<<"flag"<<endl;
	for(int i=0;i<7;i++)	
		cout<<flag[i]<<" ";
	cout<<endl;

	cout<<"Enter  Number of RESult Addresses needed:: ";
	cin>>n;
	string result[n];
	for(int i=0;i<n;i++)
		cin>>result[i];
		
	cout<<"*************************************************"<<endl;
	cout<<"Accumulator Result ::"<<registers[0]<<endl;	
	cout<<"*************************************************"<<endl;
	cout<<"Memory Result"<<endl;
	for(int i=0;i<n;i++)
		cout<<result[i]<<" :: "<<memory[result[i]]<<endl;;

return 0;
}







