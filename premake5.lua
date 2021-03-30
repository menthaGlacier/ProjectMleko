workspace "Project Mleko"
   configurations { "Debug", "Release"}
   platforms { "Win32", "Win64" }
   location "build"

   filter "platforms:Win32"
      architecture "x32"

   filter "platforms:Win64"
      architecture "x64"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "Project Mleko"
   kind "ConsoleApp"
   language "C++"
   targetdir "source"

   files { "**.h", "**.cpp" }