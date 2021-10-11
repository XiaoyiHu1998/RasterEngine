#source files
Core=./source/Core
Rendering=./source/Rendering
GlAbstractions=./source/Rendering/Abstractions
SceneObjects=./source/Rendering/SceneObjects
Scene=./source/Rendering/Scene

#compile directories
Obj=./obj
Bin=./bin

#dependencies
ImGui=./../dependencies/IMGUI
OpenGL=./../dependencies/GL
GLFW=./../dependencies/GLFW
GLM=./../dependencies/GLM

#compiler flags
CC=g++
Vendors=$(ImGui)/imgui.cpp $(ImGui)/imgui_demo.cpp $(ImGui)/imgui_draw.cpp $(ImGui)/imgui_widgets.cpp $(ImGui)/imgui_impl_glfw.cpp $(ImGui)/imgui_impl_opengl3.cpp
Includes=-I./../dependencies -I./../dependencies/IMGUI -I./source/Core -I./source/SceneObjects -I./source/Rendering -I./source/Rendering/Abstractions -I./source/Rendering/SceneObjects -I./source/Rendering/Scene
LibPaths=-L$(OpenGL)/ -L$(GLFW)/
Libs=-lglew32s -lglfw3 -lopengl32 -lUser32 -lGdi32 -lShell32 -lcomdlg32
MiscFlags=-DRE_DEBUG -DGLEW_STATIC -m32 -std=c++17
Output=-o $(Bin)/RasterEngine.exe 

# object and PCH files
Objects= $(Obj)/main.o $(Obj)/RasterEngine.o $(Obj)/VertexBuffer.o $(Obj)/IndexBuffer.o $(Obj)/Shader.o $(Obj)/Mesh.o  $(Obj)/Camera.o $(Obj)/Scene.o $(Obj)/SceneNode.o
PCH_SRC= $(Core)/masterInclude.hpp
PCH_OUT= $(Core)/masterInclude.hpp.pch
PCH_HEADERS= $(Core)/errorChecking.hpp $(Core)/namespace.hpp
Namespace= $(Core)/namespace.hpp

#commands
all: program

pch: $(PCH_OUT)

run:
	$(Bin)/RasterEngine.exe

removeObjects: 
	Del /Q /F /S "*.o"
removeProgram: 
	Del /Q /F /S "RasterEngine.exe"
cleanObj: removeObjects

clean: removeObjects
clean: removeProgram

#build
$(PCH_OUT): $(PCH_SRC) $(PCH_HEADERS)
	$(CC) $(PCH_SRC) $(LibPaths) $(Includes)  -o $(PCH_OUT) -std=c++17 -O3 -g0

program: $(Objects) $(PCH_OUT) $(Core)/errorChecking.hpp $(Core)/namespace.hpp
	$(CC) $(Objects) $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) $(Output)

$(Obj)/main.o: $(Core)/main.cpp $(PCH_OUT) $(Namespace) $(Obj)/RasterEngine.o
	$(CC) $(Core)/main.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/main.o

$(Obj)/RasterEngine.o: $(Core)/RasterEngine.cpp $(Core)/RasterEngine.hpp $(PCH_OUT) $(Namespace)
	$(CC) $(Core)/RasterEngine.cpp $(Scene)/Scene.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/RasterEngine.o

$(Obj)/VertexBuffer.o: $(GlAbstractions)/VertexBuffer.cpp $(GlAbstractions)/VertexBuffer.hpp $(PCH_OUT)
	$(CC) $(GlAbstractions)/VertexBuffer.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/VertexBuffer.o

$(Obj)/IndexBuffer.o: $(GlAbstractions)/IndexBuffer.cpp $(GlAbstractions)/IndexBuffer.hpp $(PCH_OUT)
	$(CC) $(GlAbstractions)/IndexBuffer.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/IndexBuffer.o

$(Obj)/Shader.o: $(GlAbstractions)/Shader.cpp $(GlAbstractions)/Shader.hpp $(PCH_OUT)
	$(CC) $(GlAbstractions)/Shader.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/Shader.o

$(Obj)/Camera.o: $(SceneObjects)/Camera.cpp $(SceneObjects)/Camera.hpp $(PCH_OUT)
	$(CC) $(SceneObjects)/Camera.cpp $(Scene)/Scene.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/Camera.o

$(Obj)/Mesh.o: $(SceneObjects)/Mesh.cpp $(SceneObjects)/Mesh.hpp $(PCH_OUT)
	$(CC) $(SceneObjects)/Mesh.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/Mesh.o

$(Obj)/Scene.o: $(Scene)/Scene.cpp $(Scene)/Scene.hpp $(Obj)/SceneNode.o $(PCH_OUT)
	$(CC) $(Scene)/Scene.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/Scene.o

$(Obj)/SceneNode.o: $(Scene)/SceneNode.cpp $(Scene)/SceneNode.hpp $(Core)/masterInclude.hpp $(PCH_OUT)
	$(CC) $(Scene)/SceneNode.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) -o $(Obj)/SceneNode.o
