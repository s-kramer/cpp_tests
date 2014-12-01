LoggerPtr logger = Logger::getLogger("CPPLogger");

ConsoleAppenderPtr appender(new ConsoleAppender());
appender->setTarget(LOG4CXX_STR("System.out"));

LayoutPtr layout (new SimpleLayout());
appender->setLayout(layout);

log4cxx::helpers::Pool pool;
appender->activateOptions(pool);

logger->addAppender(appender);
LogManager::getLoggerRepository()->setConfigured(true);
