-- A solution contains projects, and defines the available configurations
solution "Simulation"
  configurations { "Debug", "Release" }
  
  project "Demo"
    kind "ConsoleApp"
    language "C++"
    files {"*.hpp", "*.cpp"}
    includedirs {".", "/usr/include/OGRE/", "/usr/include/OIS/"}
    links{'OgreMain', 'OIS', 'boost_system'}
    buildoptions {"--std=c++11" } ---Wall -Wextra
    configuration "Debug"
      defines { "DEBUG" }
      flags { "Symbols" }

    configuration "Release"
      defines { "NDEBUG" }
      flags { "Optimize" }
