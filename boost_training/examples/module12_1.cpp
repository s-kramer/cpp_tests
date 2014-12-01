namespace boost {
	template<typename T> class scoped_ptr : noncopyable {
	public:
		explicit scoped_ptr(T* p = 0);
		~scoped_ptr();
		void reset(T* p = 0);
		T& operator*() const;
		T* operator->() const;
		T* get() const;
		void swap(scoped_ptr& b);
	};
	template<typename T>
			void swap(scoped_ptr<T> & a, scoped_ptr<T> & b);
}
