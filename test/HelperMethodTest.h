/*
 * HelperMethodTest.h
 *
 *  Created on: 2015/07/30
 *      Author: CE122548
 */

#ifndef TEST_HELPERMETHODTEST_H_
#define TEST_HELPERMETHODTEST_H_

#include <gtest/gtest.h>
#include "HelperMethod.hpp"

class HelperMethodTest : public ::testing::Test {
protected:
	void SetUp();
	void TearDown();

public:
	HelperMethodTest();
	virtual ~HelperMethodTest();

};

class DummyClass {
public:
    DummyClass(){};
    ~DummyClass(){};
};


#endif /* TEST_HELPERMETHODTEST_H_ */
