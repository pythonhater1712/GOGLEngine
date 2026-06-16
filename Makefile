# |-- LINUX -------------------------------------------------------------------------|

CXX = clang++
CXXFLAGS = -std=c++17 -g -I./stb $(shell pkg-config --cflags glfw3) -I /mnt/Code/libs
LDFLAGS = $(shell pkg-config --libs glfw3)
TARGET = output/a.out
SOURCES = main.cpp glad.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p $(dir $(TARGET))
	$(CXX) $(CXXFLAGS) $(SOURCES) $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)

run:
	./output/a.out

rund:
	./output/a.out d

# |-- WINDOWS --------------------------------------------------------------------------|

CXXw = clang++
CXXFLAGSw = -std=c++17 -g -I C:\Code\GLFW\include -I C:\Code\GLAD\include -I C:\Code\GLM
LDFLAGSw = -L C:\Code\GLFW\lib-vc2022 -lglfw3 -lopengl32 -luser32 -lgdi32 -lshell32
TARGETw = output\a.exe
SOURCESw = main.cpp glad.c

allw: $(TARGETw)

$(TARGETw): $(SOURCESw)
	$(CXXw) $(CXXFLAGSw) $(SOURCESw) $(LDFLAGSw) -o $(TARGETw)

cleanw:
	del $(TARGETw)

runw:
	output/a.exe

rundw:
	output/a.exe d
