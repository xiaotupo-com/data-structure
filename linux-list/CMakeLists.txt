cmake_minimum_required(VERSION 3.15)

project(linux_list)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 将 src 目录中的所有文件保存到 SOURCE_PATH 变量中
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_PATH)
message(src 下的所有 ".c" 文件：${SOURCE_PATH})

# 设置头文件的路径
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
message(inc 路径：${INCLUDE_PATH})

# 包含头文件的路径
include_directories(${INCLUDE_PATH})

add_executable(${PROJECT_NAME} 
    ${SOURCE_PATH}
)
