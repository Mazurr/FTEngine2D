workspace "FTEngine2D"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

archi = "x64"
outputdir = "%{cfg.buildcfg}-"..archi

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLWF"] = "FTEngine2D/vendor/GLWF/include"
IncludeDir["Glad"] = "FTEngine2D/vendor/Glad/include"
IncludeDir["imGui"] = "FTEngine2D/vendor/imgui"

include "FTEngine2D/vendor/GLWF"
include "FTEngine2D/vendor/Glad"
include "FTEngine2D/vendor/imGui"

project "FTEngine2D"
	location "FTEngine2D"
	kind "SharedLib"
	language "C++"

	targetdir("%{prj.name}/"..archi.."bin/"..outputdir.."/%{prj.name}")
	objdir("%{prj.name}/"..archi.."bin-int/"..outputdir.."/%{prj.name}")

	pchheader "ftepch.h"
	pchsource "FTEngine2D/src/ftepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLWF}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imGui}"
	}
	
	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "default"
		systemversion "latest"

		defines
		{
			"FTE_PLATFORM_WINDOWS",
			"FTE_BUILD_DLL",
			"_DEBUG",
			"_CONSOLE",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			"xcopy /y $(SolutionDir)%{prj.name}\\$(Platform)bin\\$(Configuration)-$(Platform)\\%{prj.name}\\FTEngine2D.dll $(SolutionDir)Sandbox\\$(Platform)bin\\$(Configuration)-$(Platform)\\Sandbox\\"
		}

	filter "configurations:Debug"
		buildoptions "/MDd"
		defines "FTE_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "FTE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FTE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir("%{prj.name}/"..archi.."bin/"..outputdir.."/%{prj.name}")
	objdir("%{prj.name}/"..archi.."bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"FTEngine2D/vendor/spdlog/include",
		"FTEngine2D/src"
	}

	links
	{
		"FTEngine2D"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "default"
		systemversion "latest"

		defines
		{
			"FTE_PLATFORM_WINDOWS",
			"_DEBUG",
			"_CONSOLE",
		}

	filter "configurations:Debug"
		buildoptions "/MDd"
		defines "FTE_DEBUG"
		optimize "On"

	filter "configurations:Release"
		buildoptions "/MD"
		defines "FTE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		buildoptions "/MD"
		defines "FTE_DIST"
		optimize "On"