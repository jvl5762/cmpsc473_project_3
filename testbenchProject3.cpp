////////////////////////////////////////////////////////////////////////////////
//
//  File           : testbenchProject3.cpp
//  Description    : test bench for virtual memory manager interface
//
//  Author         : Jeff Li, Frank Guo, Chen Dikan
//  Last Modified  : 04/28/2017

#include "memoryManager.h"

int main() 
{
	memoryManager test_FIFO(FIFO, 2, 2, 4);
	memoryManager test_LRU(LRU, 2, 2, 4);

	// FIFO example on the slides 
//	test_FIFO.memoryAccess(0);	
//	test_FIFO.memoryAccess(2);
//	test_FIFO.memoryAccess(1);
//	test_FIFO.memoryAccess(6);
//	test_FIFO.memoryAccess(4);
//	test_FIFO.memoryAccess(0);
//	test_FIFO.memoryAccess(1);	
//	test_FIFO.memoryAccess(0);
//	test_FIFO.memoryAccess(3);
//	test_FIFO.memoryAccess(1);
//	test_FIFO.memoryAccess(2);
//	test_FIFO.memoryAccess(1);

	// LRU example on the slides
	test_LRU.memoryAccess(0);	
	test_LRU.memoryAccess(2);
	test_LRU.memoryAccess(1);
	test_LRU.memoryAccess(6);
	test_LRU.memoryAccess(4);
	test_LRU.memoryAccess(0);
	test_LRU.memoryAccess(1);	
	test_LRU.memoryAccess(0);
	test_LRU.memoryAccess(3);
	test_LRU.memoryAccess(1);
	test_LRU.memoryAccess(2);
	test_LRU.memoryAccess(1);

	return 0;
}
