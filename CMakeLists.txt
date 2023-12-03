cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(TROJAN_ENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)

add_library(rend 
    src/rend/Animation.cpp
    src/rend/Buffer.cpp
    src/rend/Debug.cpp
    src/rend/Font.cpp
    src/rend/Mesh.cpp
    src/rend/Model.cpp
    src/rend/ModelShader.cpp
    src/rend/RenderTexture.cpp
    src/rend/rendmath.cpp
    src/rend/Shader.cpp
    src/rend/TextShader.cpp
    src/rend/Texture.cpp
    src/rend/utils.cpp
)
target_link_libraries(rend GLEW32 opengl32)

add_library (trojan_engine
	src/trojan_engine/Core.cpp
	src/trojan_engine/Core.h
	src/trojan_engine/Entity.cpp 
	src/trojan_engine/Entity.h
	src/trojan_engine/Component.cpp
	src/trojan_engine/Component.h 
	src/trojan_engine/trojanEngine.h
	src/trojan_engine/TriangleRenderer.cpp
	src/trojan_engine/TriangleRenderer.h
		src/trojan_engine/Transform.h
        src/trojan_engine/Transform.cpp
        src/trojan_engine/Resource.cpp
        src/trojan_engine/Resource.h
		src/trojan_engine/Texture.cpp
		src/trojan_engine/Texture.h
		src/trojan_engine/Resources.cpp
		src/trojan_engine/Resources.h
		src/trojan_engine/image.jpg

)
target_link_libraries(trojan_engine rend SDL2)

add_executable(demo
  src/demo/player.h
  src/demo/main.cpp
)

# Add custom command to copy DLL files after building demo
add_custom_command(TARGET demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/bin
    $<TARGET_FILE_DIR:demo>
)
target_link_libraries(demo trojan_engine)