Core=./source/Core
Renderer=./source/Renderer
RendererAbstraction=./source/Renderer/Abstractions
Importer=./source/Importer
Meshes=./source/Meshes
Scene=./source/Scene
Bin=./bin
ImGui=./dependencies/IMGUI
OpenGL=./dependencies/GL
GLFW=./dependencies/GLFW
GLM=./dependencies/GLM

CC=g++
Vendors=$(ImGui)/imgui.cpp $(ImGui)/imgui_demo.cpp $(ImGui)/imgui_draw.cpp $(ImGui)/imgui_widgets.cpp $(ImGui)/imgui_impl_glfw.cpp $(ImGui)/imgui_impl_opengl3.cpp
Includes=-I./dependencies -I./dependencies/IMGUI -I./source/Core -I./source/Importer -I./source/Renderer -I./source/Renderer/Abstractions -I./source/Meshes -I./source/Scene
LibPaths=-L$(OpenGL)/ -L$(GLFW)/
Libs=-lglew32s -lglfw3 -lopengl32 -lUser32 -lGdi32 -lShell32 -lcomdlg32
MiscFlags=-DRE_DEBUG -DGLEW_STATIC -m32 -std=c++17
Output=-o $(Bin)/RasterEngine.exe 

Objects= main.o RasterEngine.o RendererManager.o SceneRenderer.o UIRenderer.o Camera.o VertexBuffer.o IndexBuffer.o Shader.o ImportManager.o Importer_OBJ.o PreMesh.o Mesh.o Scene.o SceneNode.o
PCH_SRC= $(Core)/masterInclude.hpp
PCH_OUT= masterInclude.hpp.pch
# PCH_HEADERS= 


all: program

# release: clean
# 	nmake MiscFlags=-DRE_DEBUG -DGLEW_STATIC -m32 -std=c++17 -O3 -g0
# 	nmake programRelease

# debug: clean
# 	nmake MiscFlags=-DRE_DEBUG -DGLEW_STATIC -m32 -std=c++17 -O0 -g3
# 	nmake programDebug

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


$(PCH_OUT): $(PCH_SRC)
	$(CC) $(PCH_SRC) $(LibPaths) $(Includes) -o $(PCH_OUT) -std=c++17 -O3 -g0

programRelease: $(Objects) $(PCH_OUT) $(Core)/errorChecking.hpp 
	$(CC) $(Objects) $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) $(Output) -O3 -g0
	
programDebug: $(Objects) $(PCH_OUT) $(Core)/errorChecking.hpp 
	$(CC) $(Objects) $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) $(Output) -O0 -g3

program: $(Objects) $(PCH_OUT) $(Core)/errorChecking.hpp 
	$(CC) $(Objects) $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags) $(Output)

main.o: $(Core)/main.cpp $(PCH_OUT)
	$(CC) -c $(Core)/main.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

RasterEngine.o: $(Core)/RasterEngine.cpp $(Core)/RasterEngine.hpp $(PCH_OUT)
	$(CC) -c $(Core)/RasterEngine.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

RendererManager.o: $(Renderer)/RendererManager.cpp $(Renderer)/RendererManager.hpp $(PCH_OUT)
	$(CC) -c $(Renderer)/RendererManager.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

SceneRenderer.o: $(Renderer)/SceneRenderer.cpp $(Renderer)/SceneRenderer.hpp $(PCH_OUT)
	$(CC) -c $(Renderer)/SceneRenderer.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

UIRenderer.o: $(Renderer)/UIRenderer.cpp $(Renderer)/UIRenderer.hpp $(PCH_OUT)
	$(CC) -c $(Renderer)/UIRenderer.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

Camera.o: $(Renderer)/Camera.cpp $(Renderer)/Camera.hpp $(PCH_OUT)
	$(CC) -c $(Renderer)/Camera.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

VertexBuffer.o: $(RendererAbstraction)/VertexBuffer.cpp $(RendererAbstraction)/VertexBuffer.hpp $(PCH_OUT)
	$(CC) -c $(RendererAbstraction)/VertexBuffer.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

IndexBuffer.o: $(RendererAbstraction)/IndexBuffer.cpp $(RendererAbstraction)/IndexBuffer.hpp $(PCH_OUT)
	$(CC) -c $(RendererAbstraction)/IndexBuffer.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

Shader.o: $(RendererAbstraction)/Shader.cpp $(RendererAbstraction)/Shader.hpp $(PCH_OUT)
	$(CC) -c $(RendererAbstraction)/Shader.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

ImportManager.o: $(Importer)/ImportManager.cpp $(Importer)/ImportManager.hpp $(PCH_OUT)
	$(CC) -c $(Importer)/ImportManager.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

Importer_OBJ.o: $(Importer)/Importer_OBJ.cpp $(Importer)/Importer_OBJ.hpp $(Importer)/importer.hpp $(PCH_OUT)
	$(CC) -c $(Importer)/Importer_OBJ.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

PreMesh.o: $(Meshes)/PreMesh.cpp $(Meshes)/PreMesh.hpp $(Meshes)/Primitives.hpp  $(PCH_OUT)
	$(CC) -c $(Meshes)/PreMesh.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

Mesh.o: $(Meshes)/Mesh.cpp $(Meshes)/Mesh.hpp $(PCH_OUT)
	$(CC) -c $(Meshes)/Mesh.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

Scene.o: $(Scene)/Scene.cpp $(Scene)/Scene.hpp $(PCH_OUT)
	$(CC) -c $(Scene)/Scene.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)

SceneNode.o: $(Scene)/SceneNode.cpp $(Scene)/SceneNode.hpp $(Core)/masterInclude.hpp $(PCH_OUT)
	$(CC) -c $(Scene)/SceneNode.cpp $(Vendors) $(Includes) $(LibPaths) $(Libs) $(MiscFlags)
