#pragma once
#include <functional>
#include <string>
#include <map>

/*@brief base class for arguments management*/
class Arguments
{
public:
	using ArgCallback = std::function<void(const std::string& /*arg value*/, void*/*user data*/)>;
	Arguments(void* a_userData);
	void process(const int argv, const char* argc[]);
	void registerCallback(const std::string& a_arg, ArgCallback a_fun);

private:
	void* m_userData;
	std::map<std::string, ArgCallback> m_argumentsCallback;
};

