int main(int argc, char* argv[]) {
	// Wektor w�tk�w.
	vector<thread *> thread_table(max_threads);
	// P�tla tworz�ca w�tki.
	generate(thread_table.begin(), thread_table.end(), make_thread);
	// P�tla przy��czaj�ca w�tki i niszcz�ca obiekty.
	for_each(thread_table.begin(), thread_table.end(), join_deleter);
	cout << '\n';
	return EXIT_SUCCESS;
}
