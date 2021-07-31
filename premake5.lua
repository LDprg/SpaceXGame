workspace "SpaceX"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "%{wks.location}/SpaceX/vendor/SFML/include"

LinkDir = {}
LinkDir["SFML"] = "%{wks.location}/SpaceX/vendor/SFML/lib"

project "SpaceX"
	location "SpaceX"

	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{IncludeDir.SFML}"
	}

	libdirs{
		"%{LinkDir.SFML}"
	}

	defines{
		"SFML_STATIC"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "on"
		systemversion "latest"
		 
		defines{
			"PLATFORM_WINDOWS" 
		}

	filter "configurations:Debug"
		kind "ConsoleApp"
		defines	"DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"
		links{
			"sfml-main-d",
			"sfml-system-s-d",
			"sfml-graphics-s-d",
			"sfml-window-s-d",
			"sfml-audio-s-d",
			"sfml-network-s-d",
			"opengl32",
			"winmm",
			"gdi32"
		}

	filter "configurations:Release"
		kind "ConsoleApp"
		defines "RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"
		links{
			"sfml-main",
			"sfml-system-s",
			"sfml-graphics-s",
			"sfml-window-s",
			"sfml-audio-s",
			"sfml-network-s",
			"opengl32",
			"winmm",
			"gdi32"
		}

	filter "configurations:Dist"
		kind "WindowedApp"
		defines "DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"
		links{
			"sfml-main",
			"sfml-system-s",
			"sfml-graphics-s",
			"sfml-window-s",
			"sfml-audio-s",
			"sfml-network-s",
			"opengl32",
			"winmm",
			"gdi32"
		}