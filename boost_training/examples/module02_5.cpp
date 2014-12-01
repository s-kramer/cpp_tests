namespace log4cxx {
	class Logger {
		// Pobranie root logger -- bez nazwy
		static LoggerPtr getRootLogger();
		// Pobranie loggera o znanej nazwie
		static LoggerPtr getLogger(const std::string & name);
		static LoggerPtr getLogger(const char * const name);
		...
	};
}
