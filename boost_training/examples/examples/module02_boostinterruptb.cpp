int main(int argc, char* argv[]) {
	boost::thread thr(thrInterrupted);
	system("sleep 1");
	thr.interrupt();
	system("sleep 3");
	thr.interrupt();
	thr.join();
	return 0;
}
