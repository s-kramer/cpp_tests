namespace boost {
	template<typename T> class weak_ptr {
	public:
		template<typename Y> weak_ptr(const shared_ptr<Y>& r);
		template<class Y> weak_ptr(weak_ptr<Y> const & r);
		~weak_ptr();
		T* get() const;
		bool expired() const;
		shared_ptr<T> lock() const;
	};
}
