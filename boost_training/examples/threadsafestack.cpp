#include <stack>
#include <boost/thread/mutex.hpp>
// Implementacja okrojona...
template<class T>
class ThreadSafeStack {
	private:
		mutable boost::mutex myMutex;
		std::stack<T> myStack;
	public:
		typedef typename std::stack<T>::size_type size_type;
		ThradSafeStack() {}
		~ThreadSafeStack() {}
		void push(const T& t) {
			boost::mutex::scoped_lock lock(myMutex);
			myStack.push(t);
		}
	void pop(T& t) {
		boost::mutex::scoped_lock lock(myMutex);
		if(!myStack.empty) myStack.pop();
	}
	size_type size() const {
		boost::mutex::scoped_lock lock(myMutex);
		return myStack.size();
	}
};
