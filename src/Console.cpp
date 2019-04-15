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
		freopen_s(&m_stderr, "CONOUT$", "w", stderr);
	#endif
	}

	Console::~Console()
	{
	#ifdef _WIN32
		fclose(m_stderr);
		fclose(m_stdout);
		FreeConsole();
	#endif
	}
}
