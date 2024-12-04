cmake_minimum_required(VERSION "3.19.2")

project(harkka)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(harkka
	"src/main.cpp"
	
)

target_include_directories(harkka
	PUBLIC src
)
