namespace boost {
	template<class T> class intrusive_ptr {
	public:
		intrusive_ptr(T* p, bool add_ref=true);
		intrusice_ptr(const intrusive_ptr & r);
		~intrusive_ptr();
		T& operator*() const;
		T* operator->() const;
		T* get() const;
	};
	template <class T> T* get_pointer(const intrusive_ptr<T>& p);
	template <class T, class U> intrusive_ptr<T>
		static_pointer_cast(const intrusive_ptr<U>& r);
}
