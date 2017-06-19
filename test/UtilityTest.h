/*! ********************************************************************************
 @file       UtilityTest.h
 @brief      ユーティリティ機能（範囲チェック等）のテスト
 @attention  なし
 **********************************************************************************/

#ifndef UTILITYTEST_H_
#define UTILITYTEST_H_

#include <gtest/gtest.h>
#include "Utility.h"

class UtilityTest : public ::testing::Test {
protected:
    Helper::Utility* sut;
    void SetUp();
    void TearDown();

public:
    UtilityTest();
    virtual ~UtilityTest();
};

#endif /* UTILITYTEST_H_ */
