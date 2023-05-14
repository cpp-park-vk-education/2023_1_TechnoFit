#pragma once
#include "../Database/IRepository.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

struct MockRepository : public IRepository
{
    MOCK_METHOD(std::string, formMLQuery, (std::vector<unsigned char>& request), (override));
    MOCK_METHOD(std::string, formClientQuery, (std::vector<unsigned char>& request), (override));
    MOCK_METHOD(std::string, formDeviceQuery, (std::vector<unsigned char>& request), (override));
};