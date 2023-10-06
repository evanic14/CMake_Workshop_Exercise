add_library(rpi_pico_mqtt_lib ${CMAKE_CURRENT_LIST_DIR}/src/mqtt_lib.cpp ${CMAKE_CURRENT_LIST_DIR}/inc/mqtt_lib.hpp)
target_include_directories(rpi_pico_mqtt_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc/)
target_link_libraries(rpi_pico_mqtt_lib
        pico_cyw43_arch_lwip_poll
        pico_stdlib
        pico_lwip_mbedtls
        pico_mbedtls
        pico_lwip_mqtt)