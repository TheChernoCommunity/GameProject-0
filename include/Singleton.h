#pragma once
#include <memory>

namespace ccm
{
	template<typename T, typename Deleter = std::default_delete<T>>
	class Singleton
	{
	public:
		Singleton() = default;
		virtual ~Singleton() = default;
	
		template<typename... Args>
		static T& initialize(Args&&... args) { return *(s_instance = std::make_unique<T>(std::forward<Args>(args)...)); }
		static void deinitialize() { s_instance.reset(); }
	
		[[nodiscard]] static T& getInstance() { return *s_instance; }
	
		[[nodiscard]] static bool isInitialized() { return !!s_instance; }
	
	private:
		static std::unique_ptr<T, Deleter> s_instance;
	};

	template<typename T, typename Deleter>
	std::unique_ptr<T, Deleter> Singleton<T, Deleter>::s_instance;
}
