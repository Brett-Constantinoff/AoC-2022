workspace "AoC-2022"
    configurations { "Debug", "Release" }
    startproject "Sandbox"
    flags { "MultiProcessorCompile" }

    filter "configurations:Debug"
        defines { "DEBUG", "DEBUG_SHADER" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"
        flags { "LinkTimeOptimization" }


include "Days/Day1/Day1.lua"
include "Days/Day2/Day2.lua"
include "Days/Day3/Day3.lua"
include "Days/Day4/Day4.lua"
include "Days/Day5/Day5.lua"
include "Days/Day6/Day6.lua"
include "Days/Day7/Day7.lua"