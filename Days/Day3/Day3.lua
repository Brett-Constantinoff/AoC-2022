project "Day3"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
	architecture "x64"

    targetdir "../bin/Day3/%{cfg.buildcfg}"
    objdir "../bin-int/Day3/%{cfg.buildcfg}"

    files
    {
        "**.cpp",
        "**.h"
    }
    
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"