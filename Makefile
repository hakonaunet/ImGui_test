# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -I./lib/imgui -I./lib/imgui-sfml -I/usr/include/SFML -I./include

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OPENGL_LIBS = -lGL
LIBS = $(SFML_LIBS) $(OPENGL_LIBS)

# All cpp and corresponding obj files
IMGUI_SRC = $(wildcard ./lib/imgui/*.cpp) $(wildcard ./lib/imgui-sfml/*.cpp)
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) $(IMGUI_SRC:%.cpp=%.o)

# Executable Name
EXEC = ImGui_test

# Rules
all: $(OBJ)
	$(CXX) $(OBJ) $(LIBS) -o $(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ_DIR)/*.o $(EXEC) *.o