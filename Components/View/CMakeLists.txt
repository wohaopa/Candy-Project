project(View)

set(SRC
        View.cpp
        View.h

)
# 声明库
add_library(${PROJECT_NAME} SHARED
        ${SRC}
)

# 链接 Qt6 动态库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# 安装库文件
install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR}/Components)
