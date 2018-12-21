#pragma once
#include <string>
#include <vector>
#include "Logger.h"
namespace cx {
	namespace util {
		namespace logging {
			using namespace std;
			class LoggerImpl : public Logger
			{
			private:
				string logCh;
				string levels[4];
				unsigned int level;
				void logMessage(const vector<string>& messageParts, LogLevel level);
				void logMessage(const string& msg, const vector<int>& messageParts, LogLevel level);
				void logMessage(const string& msg, const vector<bool>& messageParts, LogLevel level);

			public:

				LoggerImpl(const string& channel);
				void log(LogLevel level, const string& message);
				void setLogLevel(Logger::LogLevel level);
			};
		}
	}
};