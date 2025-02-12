//Project 1 for CMP_SCI-4760 Spring 2025 for Logan Bessinger
//Outputs a string that is mostly the same execpt for interation to the screeen then waits.
//Takes an int as argment and interates to that number
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
	sleep(1);
	}
	return EXIT_SUCCESS;
}
