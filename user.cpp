#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv)
{
	int loop_Counter = atoi(argv[1]);
	for( int i = 0; i < loop_Counter; i++){
	std::cout<< "USER ";
	std::cout<< "PID:" << getpid();
	std::cout<< " PPID:" << getppid();
	std::cout<< " Iteration:" << i + 1 << "\n";
	
	}
	return EXIT_SUCCESS;
}
