#pragma once
#include <cstdint>

namespace ccm
{
	/*
	 * Color class
	 * Members:
	 * r : red channel [0-255]
	 * g : green channel [0-255]
	 * b : blue channel [0-255]
	 * a : alpha channel [0-255]
	 */
	struct Color
	{
		std::uint8_t r{};
		std::uint8_t g{};
		std::uint8_t b{};
		std::uint8_t a{ 255 };
		constexpr Color() = default;
		constexpr Color(std::uint8_t r, std::uint8_t g,
			std::uint8_t b, std::uint8_t a = 255)
			: r{ r }, g{ g }, b{ b }, a{ a }{}
	};
	namespace Colors
	{
		constexpr Color Black{ 0, 0, 0 };
		constexpr Color Red{ 255, 0, 0 };
		constexpr Color Green{ 0, 255, 0 };
		constexpr Color Blue{ 0, 0, 255 };
		constexpr Color White{ 255, 255, 255 };
	}
}