file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_HEADER *.hpp)


add_library(spsolver INTERFACE)

include(GNUInstallDirs)

target_include_directories(spsolver INTERFACE
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS spsolver EXPORT spsolver)

if(BUILD_STATIC_LIBS)
add_library(spsolver_static STATIC ${ROOT_SOURCE} ${ROOT_HEADER})
	target_link_libraries(spsolver_static PUBLIC spsolver)
	add_library(spsolver::spsolver_static ALIAS spsolver_static)
endif()

if(BUILD_SHARED_LIBS)
add_library(spsolver_shared SHARED ${ROOT_SOURCE} ${ROOT_HEADER})
	target_link_libraries(spsolver_shared PUBLIC spsolver)
	add_library(spsolver::spsolver_shared ALIAS spsolver_shared)
endif()