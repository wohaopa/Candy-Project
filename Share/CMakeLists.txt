project(Share)


set(SRC
        Share.cpp
)

set(INCLUDE
        api/ICandyComponent.h
        Share.h
        Share.cpp
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DIR}/Libraries)

add_library(${PROJECT_NAME} SHARED
        ${SRC}
        ${INCLUDE}
)

# 链接 Qt6 模块
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)

# 链接其他库
target_link_libraries(${PROJECT_NAME}

)

# 安装库文件
#install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR}/Libraries)
