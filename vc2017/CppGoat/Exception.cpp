#include "Exception.h"
namespace cx {

	Exception::Exception(int code) : _pNested(0), _code(code)
	{
	}


	Exception::Exception(const std::string& msg, int code) : _msg(msg), _pNested(0), _code(code)
	{
	}


	Exception::Exception(const std::string& msg, const std::string& arg, int code) : _msg(msg), _pNested(0), _code(code)
	{
		if (!arg.empty())
		{
			_msg.append(": ");
			_msg.append(arg);
		}
	}


	Exception::Exception(const std::string& msg, const Exception& nested, int code) : _msg(msg), _pNested(nested.clone()), _code(code)
	{
	}


	Exception::Exception(const Exception& exc) :
		std::exception(exc),
		_msg(exc._msg),
		_code(exc._code)
	{
		_pNested = exc._pNested ? exc._pNested->clone() : 0;
	}


	Exception::~Exception() throw()
	{
		delete _pNested;
	}


	Exception& Exception::operator = (const Exception& exc)
	{
		if (&exc != this)
		{
			Exception* newPNested = exc._pNested ? exc._pNested->clone() : 0;
			delete _pNested;
			_msg = exc._msg;
			_pNested = newPNested;
			_code = exc._code;
		}
		return *this;
	}

}