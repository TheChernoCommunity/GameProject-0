#pragma once
#include "Singleton.h"

namespace ccm
{
	class Console : public Singleton<Console>
	{
	public:
		Console();
		~Console();

	private:

	#ifdef _WIN32
		FILE* m_stdout;
	#endif
	};
}
