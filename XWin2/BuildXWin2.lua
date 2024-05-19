project "XWin2"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++Latest"
	targetname "XWin2"

	-- Base output directory
	local baseDir = "%{wks.location}/Build/"
	local debugDirectory = baseDir .. "%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}/"

	targetdir(baseDir .. "%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}/")
	objdir(baseDir .. "Intermediate/%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}/")
	debugdir(baseDir .. "%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}/")

	location "%{wks.location}/XWin2/"

	nuget
	{
		-- "directxtk_desktop_win10:2024.2.22.1"
	}

	links
	{
		-- None
	}

	includedirs
	{
		"%{wks.location}/Project/",
	}

	files
	{
		"%{prj.location}/**.h",
		"%{prj.location}/**.hpp",
		"%{prj.location}/**.cpp",
		"%{prj.location}/**.inl",
		"%{prj.location}/**.ixx",
	}

	flags
	{
		"MultiProcessorCompile",
		"FatalWarnings"
	}

	shadermodel ("5.0")

		shaderassembler("AssemblyCode")
		local shader_dir = debugDirectory .. "Shaders/"

		-- Treat warnings as errors
		shaderoptions({"/WX"})

	-- HLSL files that don't end with 'Extensions' will be ignored as they will be
	-- used as includes
		filter("files:**.hlsl")
			flags("ExcludeFromBuild")
			shaderobjectfileoutput(shader_dir.."%{file.basename}"..".cso")
			shaderassembleroutput(shader_dir.."%{file.basename}"..".asm")

		filter("files:**PS.hlsl")
			removeflags("ExcludeFromBuild")
			shadertype("Pixel")

		filter("files:**VS.hlsl")
			removeflags("ExcludeFromBuild")
			shadertype("Vertex")

		filter("files:**GS.hlsl")
			removeflags("ExcludeFromBuild")
			shadertype("Geometry")

		filter("files:**HS.hlsl")
			removeflags("ExcludeFromBuild")
			shadertype("Hull")

		filter("files:**DS.hlsl")
			removeflags("ExcludeFromBuild")
			shadertype("Domain")

	scanformoduledependencies "true"
	floatingpoint "Fast"

	filter { "system:windows", "action:vs2022"}
		buildoptions
		{
			"/EHsc",
			"/Zc:preprocessor",
			"/Zc:__cplusplus",
			"/experimental:module"
		}

	filter { "configurations:Debug" }
		defines { "DEBUG", "_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter { "configurations:Release" }
		defines { "NDEBUG" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter { "configurations:Shipping" }
		defines { "NDEBUG" }
		runtime "Release"
		optimize "On"
		symbols "Off"
