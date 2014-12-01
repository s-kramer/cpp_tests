#include <ext/hash_map> // dla kompilatora gcc
struct HashFunction {
	size_t operator(std::string const& s) const {
		size_t answer = 0;
		for (unsigned ui = 0; ui < s.size(); ++ui) {
			answer = 5*answer + s[ui];
		}
		return answer;
	}
};
// Definicja typu dla kompilatora gcc
typedef __gnu_cxx::hash_map<std::string, int, HashFunction> myHash_map;
