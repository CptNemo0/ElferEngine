include(FetchContent)

FetchContent_Declare(
 	EnTT
  	GIT_REPOSITORY https://github.com/skypjack/entt.git
	GIT_TAG 78213075654a688e9da6bc49f7f873d25c26d12c
)
FetchContent_MakeAvailable(EnTT)
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)

FetchContent_Declare(
 	imgui
  	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG cb16be3a3fc1f9cd146ae24d52b615f8a05fa93d
)
FetchContent_MakeAvailable(imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)

FetchContent_Declare(
 	glm
  	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 33b0eb9fa336ffd8551024b1d2690e418014553b
)
FetchContent_MakeAvailable(glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)