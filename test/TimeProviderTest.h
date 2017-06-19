#ifndef TIMEPROVIDERTEST_H_
#define TIMEPROVIDERTEST_H_

#include <gtest/gtest.h>
#include "TimeProvider.h"

class TimeProviderTest : public ::testing::Test {
public:
    TimeProviderTest();
    virtual ~TimeProviderTest();

protected:
	TimeProvider* sut;
	void SetUp();
	void TearDown();
};

#endif
