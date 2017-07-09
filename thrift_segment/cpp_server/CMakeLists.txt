SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

#SET(COMM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../common")
#SET(API_SERVER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../api_server")
#SET(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/gen-cpp" "${COMM_DIR}" "${API_SERVER_DIR}/gen-cpp")
SET(JIEBA_DIR "cppjieba")
SET(INCLUDE "${JIEBA_DIR}/include" "${JIEBA_DIR}/deps" "${CMAKE_CURRENT_SOURCE_DIR}/gen-cpp")
 
# MESSAGE( STATUS "COMM_DIR: " ${COMM_DIR} )
# MESSAGE( STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR} )
# MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR} )
 
INCLUDE_DIRECTORIES(${INCLUDE})
 
# include_directories(${INCLUDE})
#file(GLOB SRC demo.cpp alg_jieba.cpp ${CMAKE_CURRENT_SOURCE_DIR}/gen-cpp/*.cpp ${API_SERVER_DIR}/gen-cpp/*.cpp)
file(GLOB SRC segmentserver.cpp alg_jieba.cpp ${CMAKE_CURRENT_SOURCE_DIR}/gen-cpp/*.cpp)
 
SET(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 -g")
 
ADD_EXECUTABLE(sr_segment ${SRC})
#target_link_libraries(demo thriftnb thrift boost_chrono boost_thread boost_system event jsoncpp glog gflags)
target_link_libraries(sr_segment thriftnb thrift boost_chrono boost_thread boost_system event )
