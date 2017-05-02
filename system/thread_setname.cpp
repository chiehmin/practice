#include <iostream>
#include <thread>

#include <unistd.h>
#include <pthread.h>

using namespace std;

int main()
{
	thread t1 = thread([](){
				cout << "thread 1" << endl;
				// change /proc/self/task/[tid]/comm
				pthread_setname_np(pthread_self(), "test_thread_1");
				while(true) {
					sleep(10);
				}
			});

	t1.join();
}
