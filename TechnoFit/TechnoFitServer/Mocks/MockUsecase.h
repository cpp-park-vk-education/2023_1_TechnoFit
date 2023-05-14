#pragma once
#include "../UseCase/IServerUsecase.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>




struct MockUsecase : public IServerUsecase
{
    MOCK_METHOD(std::string, ProcessDeviceRequest, (std::vector<unsigned char>& request), (override));
    MOCK_METHOD(std::string, ProcessClientRequest, (std::vector<unsigned char>& request), (override));
    MOCK_METHOD(std::string, ProcessMLRequest, (std::vector<unsigned char>& request), (override));
};