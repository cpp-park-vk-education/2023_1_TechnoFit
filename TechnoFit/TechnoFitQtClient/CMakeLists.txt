cmake_minimum_required(VERSION 3.1.0)

project(QtClient)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Network)
find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(QtClient
    Sources/mainwindow.ui
    Sources/mainwindow.cpp
    Sources/dialog.ui
    Sources/main.cpp
    Sources/dialog.cpp
    resource.qrc
    Headers/mainwindow.h
    Headers/header.h
    Headers/dialog.h
    Headers/Device.h
    Headers/DeviceCard.h
    Headers/Sensors.h
    UseCase/IMetricsUseCase.h
    UseCase/MetricsUseCase.h
    UseCase/MetricsUseCase.cpp
    UseCase/IMetricsNetworkHandler.h
    Network/IMetricsNetwork.h
    Network/INetworkManager.h
    Network/MetricsNetwork.h
    Network/MetricsNetwork.cpp
    Network/NetworkManager.h
    Network/NetworkManager.cpp
    ../IRequest.h
    ../IResponse.h
    RequestAdapter.h
    RequestAdapter.cpp
    ResponseAdapter.h
    ResponseAdapter.cpp
    AppRoot.h
)

add_executable(QtClientTest
    Sources/main_test.cpp
    Headers/mainwindow.h
    Headers/Device.h
    Sources/mainwindow.cpp
    Network/NetworkManager.h
    Network/NetworkManager.cpp
    Network/NetworkManagerTests.cpp
    Network/MetricsNetwork.h
    Network/MetricsNetwork.cpp
    Network/MetricsNetworkTests.cpp
    UseCase/MetricsUseCase.h
    UseCase/MetricsUseCase.cpp
    UseCase/MetricsUseCaseTests.cpp
    Mocks/MockMetricsNetwork.h
    Mocks/MockMetricsUI.h
    Mocks/MockMetricsUseCase.h
    Mocks/MockNetworkManager.h
    Mocks/MockRequest.h
    Mocks/MockResponse.h
    RequestAdapter.h
    RequestAdapter.cpp
    ResponseAdapter.h
    ResponseAdapter.cpp
    )


target_link_libraries(QtClientTest -lgtest -lgmock Qt6::Widgets Qt6::Gui  Qt6::Network Qt6::Core)
target_link_libraries(QtClient Qt6::Widgets Qt6::Gui  Qt6::Network Qt6::Core)
