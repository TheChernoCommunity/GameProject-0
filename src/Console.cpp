#include "Console.h"

#ifdef _WIN32
#include <windows.h>
#endif

namespace ccm
{
	Console::Console()
	{
	#ifdef _WIN32
		AllocConsole();
		freopen_s(&m_stdout, "CONOUT$", "w", stdout);
	#endif
	}

	Console::~Console()
	{
	#ifdef _WIN32
		fclose(m_stdout);
		FreeConsole();
	#endif
	}
}
