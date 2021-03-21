project(DateConverter)

set(HEADER_FILES
        Sidel.h
        )

set(SOURCE_FILES
        Sidel.cpp
        )

add_library(DateConverter_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})