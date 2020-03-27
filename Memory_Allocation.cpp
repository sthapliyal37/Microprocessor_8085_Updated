#include<bits/stdc++.h>
#include"Validation.h"
using namespace std;

#include <bits/stdc++.h> 
using namespace std; 
# define bool int 

int getNumeralValue(char ); 
char getNumeral(int ); 

char *sumBase14(string num1, string num2) 
{ 
	int l1 = num1.length(); 
	int l2 = num2.length(); 
	char *res; 
	int i; 
	int nml1, nml2, res_nml; 
	bool carry = 0; 
		
	if(l1 != l2) 
	{ 
		cout << "Function doesn't support numbers of different"
				" lengths. If you want to add such numbers then"
				" prefix smaller number with required no. of zeroes"; 
		assert(0); 
	} 
	res = new char[(sizeof(char)*(l1 + 1))]; 
			
	for(i = l1-1; i >= 0; i--) 
	{ 
		nml1 = getNumeralValue(num1[i]); 
		nml2 = getNumeralValue(num2[i]); 
		
		res_nml = carry + nml1 + nml2; 
		
		if(res_nml >= 14) 
		{ 
			carry = 1; 
			res_nml -= 14; 
		} 
		else
		{ 
			carry = 0; 
		} 
		res[i+1] = getNumeral(res_nml); 
	} 
	if(carry == 0) 
		return (res + 1); 
	
	res[0] = '1'; 
	return res; 
} 

int getNumeralValue(char num) 
{ 
	if( num >= '0' && num <= '9') 
		return (num - '0'); 
	if( num >= 'A' && num <= 'D') 
		return (num - 'A' + 10); 
			
	assert(0); 
} 
char getNumeral(int val) 
{ 
	if( val >= 0 && val <= 9) 
		return (val + '0'); 
	if( val >= 10 && val <= 14) 
		return (val + 'A' - 10); 
	assert(0); 
} 


int hexadecimalToDecimal(string hexVal) 
{    
    int len = hexVal.length(); 
      
    int base = 1; 
      
    int dec_val = 0; 
      
    for (int i=len-1; i>=0; i--) 
    {    
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            base = base * 16; 
        } 
          else if (hexVal[i]>='a' && hexVal[i]<='f') 
        { 
            dec_val += (hexVal[i] - 55)*base; 
          
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 
string allocate_memory(string s,string pc)
{
		string 						size1[]={"MOV","LDAX","STAX","XCHG","ADD","DCR","INR","SUB","INX","DCX","CMP","CMA","DAD"};
		string size2[]={"ADI","SUI","MVI"};
		string size3[]={"LDA","LXI","STA","SHLD","LHLD","SET","JMP","JC","JNC","JZ","JNZ"};
		int num=0;
		string num1="0001",num2="0002",num3="0003";	
		int n=pc.length();
		//cout<<num<<endl;
		n=sizeof(size1)/sizeof(size1[0]);
		for(int i=0;i<n;i++)
		{
			if(!size1[i].compare(s))
			{
				/*std::stringstream ss;
				ss<< std::hex << num+1;
				std::string res ( ss.str() );*/
				pc=sumBase14(pc,num1);
				return pc;
			}
		}
		n=sizeof(size2)/sizeof(size2[0]);
		for(int i=0;i<n;i++)
		{
				if(!size2[i].compare(s))
				{
					/*pc=itos(num+2);
					std::stringstream ss;
					ss<< std::hex << num+2;
					std::string res ( ss.str() );*/
					pc=sumBase14(pc,num2);
					return pc;
				}							
		}
		n=sizeof(size3)/sizeof(size3[0]);
		for(int i=0;i<n;i++)
		{
				if(!size3[i].compare(s))
				{									
					/*pc=itos(num+3);
					std::stringstream ss;
					ss<< std::hex << num+3;
					std::string res ( ss.str() );*/
					pc=sumBase14(pc,num3);
					return pc;
				}				
		}

	}
