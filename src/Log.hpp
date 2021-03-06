#ifndef _LOG_HPP_
#define _LOG_HPP_

#include <string>  
#include <iostream>
#include <sstream>
#include <utility>

#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/formatting_ostream.hpp>
#include <boost/log/attributes/value_extraction.hpp>
#include <boost/log/support/date_time.hpp>


namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;

using namespace std;

#define S1(x) #x
#define S2(x) S1(x)
#define log_location __FILE__ ":" S2(__LINE__) ":   "

class Logger
{

public: 

    static void Init(string level);

    template <typename LogLevel, typename T, typename... Ts >
    static void Log(LogLevel level, T&& t, Ts&&... ts)
    {
        Message << t;
        Log(level, forward<Ts>(ts)...);
    } 


private:
    Logger() {}
    ~Logger() {}

    static stringstream Message;
    
    template < typename LogLevel >
    static void Log(LogLevel level) 
    {
        src::severity_logger< logging::trivial::severity_level > lg;

        BOOST_LOG_SEV(lg, level) << Message.str();

        std::cout << Message.str() << std::endl;

        Message.str("");    
    }

    static logging::trivial::severity_level GetLogLevelFromString(string loglevel);

};



#endif
