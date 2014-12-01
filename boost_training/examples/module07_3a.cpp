// ...
int main(int argc, char* argv[]) {
	std::priority_queue< myWorkT, std::vector<myWorkT>, myPrioPolicy >
		workQueue;
	// Dane przykladowe priorytetow
	unsigned int prioTable[] = { 2, 5, 6, 3, 4, 1 };
	myWorkT work;
	// Wypelnienie kolejki
	for (int i = 0; i < 6; i++) {
		work.first = new Work(prioTable[i]);
		work.second = prioTable[i];
		workQueue.push(work);
	}
	// Sprawdzenie dzialania
	for (int i = 0; i < 6; i++) {
		work = workQueue.top();
		(*work.first)();
		workQueue.pop();
	}
}
