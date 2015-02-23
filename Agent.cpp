/*
 * Agent.cpp
 *
 * Created on: Feb 20, 2015
 * Author: jp
 */

#include "Includes.h"
#include "SemaphoreArray.h"
#include "SharedMemory.h"

using namespace std;

int main(int argc, char** argv) {

	char* processName = argv[0];
	string id_str;

	int id = getpid();
	Process::announce(PRODUCER_PROCESS_NAME, id, UNDERLINEDGREEN, "initializing.");

	srand(time(NULL) * id);


	SemaphoreArray* paper = SemaphoreArray::get(PAPER_SEMAPHORE_ID);
	SemaphoreArray* tobaco = SemaphoreArray::get(TOBACO_SEMAPHORE_ID);
	SemaphoreArray* matches = SemaphoreArray::get(MATCHES_SEMAPHORE_ID);


	for(int i = 0; i < 2; i++){

		for(int j = 0; j < 3; j++){
			paper->post();
			tobaco->post();
			matches->post();
		}

		sleep(Process::sleepTime());

		Process::announce(processName, id, GREEN, "Refilled.");
	}

	Process::announce(PRODUCER_PROCESS_NAME, id, UNDERLINEDGREEN, "finished.");
	return 0;
}

