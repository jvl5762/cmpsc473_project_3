////////////////////////////////////////////////////////////////////////////////
//
//  File           : myVirtualMemoryManagerInterface.h
//  Description    : extension of virtualMemoryManager abstract base class
//
//  Author         : Jeff Li, Frank Guo, Chen Dikan
//  Last Modified  : 04/28/2017
#pragma once

#include "virtualMemoryManagerInterface.hpp"

// data structure for memory map
typedef struct {
   unsigned int page;
   int time;
} MemoryMap;

class myVirtualMemoryManagerInterface: public virtualMemoryManagerInterface {
public:
	myVirtualMemoryManagerInterface(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : virtualMemoryManagerInterface(p, pS, nF, vA) {}
	unsigned long long memoryAccess(unsigned long long address) override; //Function to implement memory mapping policy

	void initializeMemoryMap(unsigned int addressLimit);
};