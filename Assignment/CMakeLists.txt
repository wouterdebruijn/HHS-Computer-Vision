add_executable(Assignment h-nse-imvis.cpp)

add_library(Histogram Histogram.cpp)
add_library(Mirror Mirror.cpp)
add_library(Invert Invert.cpp)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(Assignment ${OpenCV_LIBS} Histogram Mirror Invert)
