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
    