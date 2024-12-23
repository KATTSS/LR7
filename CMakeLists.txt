cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(MyProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем опцию для включения санитайзеров 
option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

if(ENABLE_SANITIZERS) 
    message(STATUS "Sanitizers enabled") 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address,undefined")
endif()



# Добавьте ваш исполняемый файл
add_executable(main task5.cpp input.cpp)

# Добавка директории с заголовками
include_directories(${PROJECT_SOURCE_DIR})


