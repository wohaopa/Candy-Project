project(Launcher)

set(SRC
        main.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DIR})

# 声明可执行程序
add_executable(${PROJECT_NAME}
        ${SRC}
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt6::Core Qt6::Network Qt6::Widgets
)