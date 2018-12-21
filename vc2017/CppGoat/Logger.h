#pragma once

#include <string>
#include <vector>

namespace cx {
	namespace util {
		namespace logging {
			using namespace std;

			class Logger
			{
			public:

				enum LogLevel { LOG_NOLOG, LOG_ERROR = 1, LOG_TRACE, LOG_DEBUG };

				virtual void log(LogLevel level, const string& message) = 0;

				virtual void setLogLevel(LogLevel level) = 0;
			};
		}
	}
};
