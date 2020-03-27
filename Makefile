main: Validation.o Memory_Allocation.o Essential.o Execution.o arithmetic.o Logical.o Branch.o DataTransfer.o main.o
	g++ Validation.o Memory_Allocation.o Essential.o Execution.o arithmetic.o Logical.o Branch.o DataTransfer.o main.o -o main							
Validation.o : Validation.cpp
	g++ -c Validation.cpp						
Memory_Allocation.o : Memory_Allocation.cpp
	g++ -c Memory_Allocation.cpp
Essential.o : Essential.cpp
	g++ -c Essential.cpp	
Execution.o : Execution.cpp
	g++ -c Execution.cpp	
arithmetic.o: arithmetic.cpp
	g++ -c arithmetic.cpp						
Logical.o : Logical.cpp
	g++ -c Logical.cpp
Branch.o : Branch.cpp
	g++ -c Branch.cpp
DataTransfer.o : DataTransfer.cpp
	g++ -c DataTransfer.cpp
main.o : main.cpp
	g++ -c main.cpp
clear:
	rm-rf*.o Validation Memory_Allocation Essential Execution arithmetic Logical main														
