project(Core)

set(SRC
        Core.cpp
        Core.h
        Cache/Cache.h
        Cache/Cache.cpp
        Daemon/Daemon.h
        Daemon/Daemon.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DIR}/Components)
# 声明库
add_library(${PROJECT_NAME} SHARED
        ${SRC}
)

# 链接 Qt6 动态库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)
