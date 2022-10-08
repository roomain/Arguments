#include "Arguments.h"
#include <algorithm>

Arguments::Arguments(void* a_userData) : m_userData{ a_userData }
{
	//
}

void Arguments::process(const int argv, const char* argc[])
{
	struct argumentItem
	{
		std::string arg;
		std::string value;
	};
	std::vector<argumentItem> vArgs;

	argumentItem current;
	for (int i = 0; i < argv; ++i)
	{
		// check if it's an argument or value
		if (std::string(argc[i]).starts_with("-"))
		{
			if (!current.arg.empty())
			{
				vArgs.emplace_back(std::move(current));
				current.arg.clear();
				current.value.clear();
			}

			current.arg = argc[i];
		}
		else if (!current.arg.empty())
		{
			if (!current.value.empty())
				current.value += " ";
			current.value += argc[i];
		}
	}

	// last
	if (!current.arg.empty())
	{
		vArgs.emplace_back(std::move(current));
		current.arg.clear();
		current.value.clear();
	}

	for (auto& item : vArgs)
	{
		auto iter = std::find_if(m_argumentsCallback.begin(), m_argumentsCallback.end(), [&](auto& iterArg)
			{
				return iterArg.first == item.arg;
			});
		if (iter != m_argumentsCallback.end())
			iter->second(item.value, m_userData);
	}
}

void Arguments::registerCallback(const std::string& a_arg, ArgCallback a_fun)
{
	m_argumentsCallback[a_arg] = a_fun;
}

