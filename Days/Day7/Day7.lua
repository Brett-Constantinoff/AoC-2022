project "Day7"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
	architecture "x64"

    targetdir "../bin/Day7/%{cfg.buildcfg}"
    objdir "../bin-int/Day7/%{cfg.buildcfg}"

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