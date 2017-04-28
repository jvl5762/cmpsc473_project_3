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
	int frameToSwap, frameToSwapTime;	// tracks the frames that will be swapped 

	timer++;

	if(frames.size() < numFrames) { initializeMemoryMap(); }

	frameToSwap = 0;
	frameToSwapTime = frames[0].time;

	for(unsigned int i = 0; i < numFrames; i++) {
		// compulsory miss
		if(frames[i].time == -1) {
			frames[i].page = address >> N;
			frames[i].time = timer;

			return(frames[i].page);
		}

		// hit
		if(frames[i].page == address >> N) {
			if(policy == LRU) {
				frames[i].time = timer;
			}
			return(frames[i].page);
		}

		// find space to swap if miss occurs
		if(frames[i].time < frameToSwapTime) {
			frameToSwap = i;
			frameToSwapTime = frames[i].time;
		}
	}

	// swap
	frames[frameToSwap].page = address >> N;
	frames[frameToSwap].time = timer;

	swap(frameToSwap, frames[frameToSwap].page);

	return(frames[frameToSwap].page);
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
