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

project "FTEngine2D"
	location "FTEngine2D"
	kind "SharedLib"
	language "C++"

	targetdir("%{prj.name}/"..archi.."bin/"..outputdir.."/%{prj.name}")
	objdir("%{prj.name}/"..archi.."bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "default"
		systemversion "10.0.18362.0"

		defines
		{
			"FTE_PLATFORM_WINDOWS",
			"FTE_BUILD_DLL",
			"_DEBUG",
			"_CONSOLE",
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
		systemversion "10.0.18362.0"

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
		defines "FTE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FTE_DIST"
		optimize "On"