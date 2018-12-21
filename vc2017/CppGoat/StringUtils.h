#pragma once

#include <algorithm>
#include <string>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include <iostream>

namespace cx {
	namespace util {

		const std::string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		std::string& to_lower(std::string& str)
		{
			std::transform(str.begin(), str.end(), str.begin(), static_cast<int(*)(int)>(std::tolower));
			return str;
		}

		std::string& to_upper(std::string& str)
		{
			std::transform(str.begin(), str.end(), str.begin(), static_cast<int(*)(int)>(std::toupper));
			return str;
		}
	}
}