// Tworzy w±tek.
thread * make_thread() {
	static int i = 0;
	MyThread * thr = new MyThread('A' + i++);
	thread * thrPtr;
	thrPtr = new thread(*thr);
	delete thr;
	return thrPtr;
}
// Przy³±cza w±tek i usuwa go.
void join_deleter(thread * thrPtr) {
	thrPtr->join(); 
	delete thrPtr; 
}
