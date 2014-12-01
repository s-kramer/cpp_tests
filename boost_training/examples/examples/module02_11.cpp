log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("com.foo"));
const char * region = "Poland";
LOG4CXX_INFO(logger, "Ble ble ble");
LOG4CXX_WARN(logger, "Welcome to " << region);
...
