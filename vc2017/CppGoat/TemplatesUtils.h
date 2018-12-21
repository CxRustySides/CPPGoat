#pragma once
template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		cont.push_back(token);
	}
}

template <typename T>
std::string intToString(T Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}