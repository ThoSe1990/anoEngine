
#include "Log.hpp"

std::stringstream Logger::Message;


void Logger::Init(string level) 
{
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= GetLogLevelFromString(level)
    );

    logging::add_file_log
    (
        keywords::file_name = "log_%N.log",
        keywords::rotation_size = 5 * 1024 * 1024,
        keywords::max_files = 5,
        keywords::target = "log",
        keywords::format =
        (
            expr::stream
                << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
                << ": [" << logging::trivial::severity
                << "] " << expr::smessage
        )
    );

    logging::add_common_attributes();
}


logging::trivial::severity_level Logger::GetLogLevelFromString(string loglevel)
{
    if (loglevel == "info")
        return logging::trivial::info; 
    else if (loglevel == "debug")
        return logging::trivial::debug;
    else if (loglevel == "warning")
        return logging::trivial::warning;
    else if (loglevel == "error")
        return logging::trivial::error;
    else if (loglevel == "fatal")
        return logging::trivial::fatal;
    else 
        return logging::trivial::info;
}
