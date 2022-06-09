add_executable(Assignment h-nse-imvis.cpp)

add_library(Histogram Histogram.cpp)
add_library(Mirror Mirror.cpp)
add_library(Invert Invert.cpp)
add_library(SmartContrast SmartContrast.cpp)
add_library(Zoom Zoom.cpp)
add_library(Filtering Filtering.cpp)
add_library(Mier Mier.cpp)
add_library(Gaps Gaps.cpp)
add_library(GapsNext GapsNext.cpp)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(Assignment ${OpenCV_LIBS} Histogram Mirror Invert SmartContrast Zoom Filtering Mier Gaps GapsNext)
