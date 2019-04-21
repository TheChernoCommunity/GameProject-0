#pragma once

#include <unordered_map>
#include <string>

namespace ccm
{
	template<typename AssetT>
	class AssetManager
	{
	public:
		template<typename StringT, typename... AssetArgs>
		AssetT* add(StringT&& str, AssetArgs&&... args)
		{
			auto it = m_assets.try_emplace(std::forward<StringT>(str), std::forward<AssetArgs>(args)...);
			auto& asset = it.first->second;
			return std::addressof(asset);
		}

		AssetT* get(const std::string& str)
		{
			auto iter = resources.find(resourceName);
			return iter != resources.end() ? std::addressof(*iter.second) : nullptr;
		}
	private:
		std::unordered_map<std::string, AssetT> m_assets;
	};
}
