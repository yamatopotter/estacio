cmake_minimum_required(VERSION 3.30)
project(estacio C)

set(CMAKE_C_STANDARD 23)

add_executable(estacio main.c
        aventureiro/desafio.c)
