////////////////////////////////////////////////////////////////////////////////
//
//  File           : memoryManager.cpp
//  Description    : Defines all the functions in "memoryManager.h"
//
//  Author         : Jeff Li, Frank Guo, Chen Dikan
//  Last Modified  : 04/28/2017

#include "memoryManager.h"
#include <vector>

// global variables
std::vector<MemoryMap> frames;
int timer = 0;

unsigned long long memoryManager::memoryAccess(unsigned long long address)
{
	// local variables
	int lowest, lowestTime;	// tracks the frames that will be swapped 

	timer++;

	if(frames.size() < numFrames) { initializeMemoryMap(); }

	lowest = 0;
	lowestTime = frames[0].time;

	// display contents of memory map -- remove before submission
	for(unsigned int i = 0; i < numFrames; i++) {
		printf("%d ", frames[i].page);
	}
	printf("\n");

	for(unsigned int i = 0; i < numFrames; i++) {
		// compulsory miss
		if(frames[i].time == -1) {
			frames[i].page = address;
			frames[i].time = timer;

			return(i);
		}

		// hit
		if(frames[i].page == address) {
			if(policy == LRU) {
				frames[i].time = timer;
			}
			return(i);
		}

		// find space to swap if miss occurs
		if(frames[i].time < lowestTime) {
			lowest = i;
			lowestTime = frames[i].time;
		}
	}

	// swap
	// remove these two lines before submission
	frames[lowest].page = address;
	frames[lowest].time = timer;

	swap(lowest, frames[lowest].page);

	return(lowest);
}

// intialize virutal memory map
void memoryManager::initializeMemoryMap()
{
	MemoryMap initFrame;

	for(unsigned int i = 0; i < numFrames; i++) {
		initFrame.page = 0;
		initFrame.time = -1;
		frames.push_back(initFrame);
	}
}
