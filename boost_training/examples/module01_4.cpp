class exception {
public:
	exception () throw();
	virtual ~exception() throw();
	virtual const char* what() const throw();
}
