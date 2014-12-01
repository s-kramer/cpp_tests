int main(int argc, char* argv[]) {
	// Wektor w±tków.
	vector<thread *> thread_table(max_threads);
	// Pêtla tworz±ca w±tki.
	generate(thread_table.begin(), thread_table.end(), make_thread);
	// Pêtla przy³±czaj±ca w±tki i niszcz±ca obiekty.
	for_each(thread_table.begin(), thread_table.end(), join_deleter);
	cout << '\n';
	return EXIT_SUCCESS;
}
