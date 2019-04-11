local function configure_project_base()
  -- Directories
  location "build/%{_ACTION}/"
  objdir "build/%{_ACTION}/%{cfg.platform}/%{cfg.buildcfg}/obj/"
  targetdir "bin/%{cfg.buildcfg}/"

  -- Single-value settings
  cppdialect "C++17"
  exceptionhandling "On"
  rtti "On"
  warnings "Default"

  -- List settings
  includedirs { "src/" }
  sysincludedirs { "src/" }

  -- Debug settings
  filter "configurations:Debug"
    optimize "Off"
    symbols "On"

  -- Release settings
  filter "configurations:Release"
  	optimize "Full"
  	symbols "On"

  -- Windows
  filter "system:windows"
    defines { "NOMINMAX", "WIN32_LEAN_AND_MEAN" }

  -- Reset filter
  filter{}
end

workspace "Test"
  platforms { io.popen("uname -m", "r"):read("*l") }
  configurations { "Debug", "Release" }

project "Program"
  kind "ConsoleApp"
  configure_project_base()
  files { "src/**.cpp", "src/**.h" }
