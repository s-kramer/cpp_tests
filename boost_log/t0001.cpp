#define BOOST_LOG_DYN_LINK 1
#include <boost/log/core.hpp> 
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp> 
#include <boost/log/utility/setup/file.hpp> 

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

void init()
{
    logging::add_file_log("sample.log");
    logging::core::get()->set_filter
    (
        logging::trivial::severity > logging::trivial::info
    );
}

int main()
{
    init();
    BOOST_LOG_TRIVIAL(error) << "Some error message";
    BOOST_LOG_TRIVIAL(trace) << "Some trace message";
    BOOST_LOG_TRIVIAL(info) << "Some info message";
    return 0;
}


//g++ -std=c++11 -lpthread -lboost_thread -lboost_system -lboost_log -o t0001 t0001.cpp
