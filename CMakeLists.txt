cmake_minimum_required(VERSION 3.30)
project(3_ejercicio_de_dise_o_y_codificaci_n_ctrl_c_ctrl_v)

set(CMAKE_CXX_STANDARD 20)

add_executable(3_ejercicio_de_dise_o_y_codificaci_n_ctrl_c_ctrl_v main.cpp
        src/Product.cpp
        src/Product.h
        src/Purchase.cpp
        src/Purchase.h
        src/Customer.cpp
        src/Customer.h
        src/Store.cpp
        src/Store.h
)
