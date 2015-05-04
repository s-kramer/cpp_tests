#define BOOST_LOG_DYN_LINK 1

#include <boost/move/utility.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

int main()
{
    src::logger lg;
    BOOST_LOG(lg) << "some user-defined logger here";

    return 0;
}


//g++ -std=c++11 -lpthread -lboost_thread -lboost_system -lboost_log -o t0001 t0001.cpp
