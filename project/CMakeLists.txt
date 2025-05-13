cmake_minimum_required(VERSION 3.10)
project(Chess LANGUAGES CXX)

# Устанавливаем стандарт C++14 (для std::make_unique)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включаем предупреждения компилятора
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif(MSVC)
    add_compile_options(/W4)
endif()

# Список исходных файлов
set(SOURCES
    main.cpp
    Figure.cpp
    ChessBoard.cpp
)

# Список заголовочных файлов
set(HEADERS
    Figure.h
    ChessBoard.h
)

# Создание исполняемого файла
add_executable(chess ${SOURCES} ${HEADERS})

# Указываем каталоги для поиска заголовочных файлов
target_include_directories(chess PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
