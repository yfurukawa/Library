/*
 * HelperMethodTest.cpp
 *
 *  Created on: 2015/07/30
 *      Author: CE122548
 */

#include "HelperMethodTest.h"

void HelperMethodTest::SetUp() {
}

void HelperMethodTest::TearDown() {
}

HelperMethodTest::HelperMethodTest() {
}

HelperMethodTest::~HelperMethodTest() {
}

/**
 * \test ポインタがNULLの場合、判定値は偽となる
 */
TEST_F (HelperMethodTest, testHasInstance_InstanceIsNull) {
    DummyClass* dummy(NULL);
	EXPECT_EQ(false, Helper::hasInstance<DummyClass*>(dummy));
}

/**
 * \test ポインタがNULLでない場合、判定値は真となる
 */
TEST_F (HelperMethodTest, testHasInstance_InstanceIsNotNull) {
    DummyClass* dummy(NULL);
    dummy = new DummyClass();
	EXPECT_EQ(true, Helper::hasInstance<DummyClass*>(dummy));
	delete dummy;
}

/**
 * \test ポインタがNULLでない場合にインスタンスを削除する
 */
TEST_F (HelperMethodTest, testDeleteInstance_InstanceIsNotNull) {
    DummyClass* dummy(NULL);
    dummy = new DummyClass();
    EXPECT_EQ(NULL, Helper::deleteInstance<DummyClass*>(dummy));
}

/**
 * \test ポインタがNULLの場合にインスタンスを削除する
 */
TEST_F (HelperMethodTest, testDeleteInstance_InstanceIsNull) {
    DummyClass* dummy(NULL);
    EXPECT_EQ(NULL, Helper::deleteInstance<DummyClass*>(dummy));
}

/**
 * \test ポインタがNULLでない場合に配列インスタンスを削除する
 */
TEST_F (HelperMethodTest, testDeleteInstance_ArrayInstanceIsNotNull) {
    DummyClass* dummy(NULL);
    dummy = new DummyClass[10];
    EXPECT_EQ(NULL, Helper::deleteArrayInstance<DummyClass*>(dummy));
}

/**
 * \test ポインタがNULLの場合に配列インスタンスを削除する
 */
TEST_F (HelperMethodTest, testDeleteInstance_ArrayInstanceIsNull) {
    DummyClass* dummy(NULL);
    EXPECT_EQ(NULL, Helper::deleteArrayInstance<DummyClass*>(dummy));
}

