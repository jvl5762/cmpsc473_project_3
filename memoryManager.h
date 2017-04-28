////////////////////////////////////////////////////////////////////////////////
//
//  File           : memoryManager.h
//  Description    : extension of virtualMemoryManager abstract base class
//
//  Author         : Jeff Li, Frank Guo, Chen Dikan
//  Last Modified  : 04/28/2017
#pragma once

#include "virtualMemoryManagerInterface.hpp"

// data structure for memory map
typedef struct {
   unsigned long long page;
   int time;
} MemoryMap;

class memoryManager: public virtualMemoryManagerInterface {
public:
	memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : virtualMemoryManagerInterface(p, pS, nF, vA) {}
	unsigned long long memoryAccess(unsigned long long address) override; //Function to implement memory mapping policy

	void initializeMemoryMap();
};
