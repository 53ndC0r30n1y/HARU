cmake_minimum_required(VERSION 3.15)
project(GLAD)

add_library(${PROJECT_NAME} STATIC 
  #E:/Libraries/GLAD/include/KHR/khrplatform.h
  include/glad/glad.h 
  src/glad.c
)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "thirdParty")
target_include_directories(${PROJECT_NAME} PUBLIC include/)