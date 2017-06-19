/*
 * HelperMethodTest.h
 *
 *  Created on: 2015/07/30
 *      Author: CE122548
 */

#ifndef TEST_STRINGHELPERTEST_H_
#define TEST_STRINGHELPERTEST_H_

#include <gtest/gtest.h>
#include "StringHelper.h"

class StringHelperTest : public ::testing::Test {
protected:
	void SetUp();
	void TearDown();

public:
	StringHelperTest();
	virtual ~StringHelperTest();

};


#endif /* TEST_STRINGHELPERTEST_H_ */
