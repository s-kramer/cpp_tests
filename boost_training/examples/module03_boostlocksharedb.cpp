void pisarz(int mytime, const char * name) {
	boost::posix_time::milliseconds myTime(mytime);
	for(int i = 0; i < 5; ++i) {
		boost::this_thread::sleep(myTime);
		myMutex.lock();
		boost::this_thread::sleep(myTime);
		myVector.push_back(name);
		myMutex.unlock();
	}
}
int main(int argc, char* argv[]) {
	boost::thread cz1(&czytelnik, 600, "*");
	boost::thread cz2(&czytelnik, 450, "+");
	boost::thread p1(&pisarz, 1000, " dane1 ");
	boost::thread p2(&pisarz, 1500, " dane2 ");
	cz1.join(); cz2.join(); p1.join(); p2.join();
	return 0;
}
