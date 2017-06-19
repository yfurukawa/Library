#include "TimeProviderTest.h"
#include "StringHelper.h"

TimeProviderTest::TimeProviderTest() :
    sut(NULL)
{
}

TimeProviderTest::~TimeProviderTest() {

}

void TimeProviderTest::SetUp() {
	sut = new TimeProvider();
}

void TimeProviderTest::TearDown() {
	delete sut;
}

