cmake_minimum_required(VERSION 3.23)
project(Project_sprint_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Project_sprint_2 main.c Application/app.c Application/app.h Card/card.c Card/card.h Server/server.c Server/server.h Terminal/terminal.c Terminal/terminal.h)
