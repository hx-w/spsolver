file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE HPPS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
add_library(xmat ${SRCS} ${HEADERS} ${HPPS})
target_include_directories(xmat INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS xmat EXPORT xmat)

# link pthread