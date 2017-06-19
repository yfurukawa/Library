/*
 * HelperMethodTest.cpp
 *
 *  Created on: 2015/07/30
 *      Author: CE122548
 */

#include <vector>
#include <string>
#include "StringHelperTest.h"
#include "mock/TimeProviderMock.h"

void StringHelperTest::SetUp() {
}

void StringHelperTest::TearDown() {
}

StringHelperTest::StringHelperTest() {
}

StringHelperTest::~StringHelperTest() {
}

/**
 * \test 2桁の整数を変換する
 */
TEST_F (StringHelperTest, testItoa_2digits) {
    EXPECT_EQ("10", Helper::itoa(10));
}

/**
 * \test 10桁の整数を変換する
 */
TEST_F (StringHelperTest, testItoa_10digits) {
    EXPECT_EQ("1234567890", Helper::itoa(1234567890));
}

/**
 * \test 4桁の浮動小数を変換する
 */
TEST_F (StringHelperTest, testDtoa_4digits) {
    EXPECT_EQ("10.54", Helper::dtoa(10.54));
}


/**
 * \test 5桁の浮動小数を変換する
 */
TEST_F (StringHelperTest, testDtoa_5digits) {
    EXPECT_EQ("0.12345", Helper::dtoa(0.12345));
}

/**
 * \test 6桁の浮動小数を変換する
 */
TEST_F (StringHelperTest, testDtoa_6digits) {
    EXPECT_EQ("18520.1", Helper::dtoa(18520.1));
}

/**
 * \test 7桁の浮動小数を変換する
 */
//TEST_F (StringHelperTest, testDtoa_7digits) {
//    EXPECT_EQ("185200.1", Helper::dtoa(185200.1));
//}

/**
 * \test 負の時の浮動小数を変換する
 */
TEST_F (StringHelperTest, testDtoa_minusdigits) {
    EXPECT_EQ("-1.12345", Helper::dtoa(-1.12345));
}

/**
 * \test 正の時の浮動小数を変換する
 */
TEST_F (StringHelperTest, testDtoa_plusdigits) {
    EXPECT_EQ("0.12345", Helper::dtoa(0.12345));
}

/**
 * \test 2つの文字列を結合する
 */
TEST_F (StringHelperTest, testJoin_2strings) {
    std::vector<std::string> messages;
    messages.push_back("firstMessage");
    messages.push_back("SecondMessage");
    EXPECT_EQ("firstMessage/SecondMessage", Helper::join(messages, "/"));
}

/**
 * \test 5つの文字列を結合する
 */
TEST_F (StringHelperTest, testJoin_5strings) {
    std::vector<std::string> messages;
    messages.push_back("firstMessage");
    messages.push_back("SecondMessage");
    messages.push_back("ThirdMessage");
    messages.push_back("FourthMessage");
    messages.push_back("FifthMessage");
    EXPECT_EQ("firstMessage/SecondMessage/ThirdMessage/FourthMessage/FifthMessage", Helper::join(messages, "/"));
}

/**
 * \test 空白を含む文字列を結合する
 */
TEST_F (StringHelperTest, testJoin_2stringsWithWhiteSpace) {
    std::vector<std::string> messages;
    messages.push_back("first Message");
    messages.push_back("SecondMessage");
    EXPECT_EQ("first Message/SecondMessage", Helper::join(messages, "/"));
}

/**
 * \test デリミタが複数文字の場合
 */
TEST_F (StringHelperTest, testJoin_multiCharctersDelimiter) {
    std::vector<std::string> messages;
    messages.push_back("firstMessage");
    messages.push_back("SecondMessage");
    EXPECT_EQ("firstMessage*-+SecondMessage", Helper::join(messages, "*-+"));
}

/**
 * \test デリミタが複数の同じ文字の場合
 */
TEST_F (StringHelperTest, testJoin_sameMultiCharctersDelimiter) {
    std::vector<std::string> messages;
    messages.push_back("firstMessage");
    messages.push_back("SecondMessage");
    EXPECT_EQ("firstMessage / SecondMessage", Helper::join(messages, " / "));
}

/**
 * \test 文字列が1つの場合
 */
TEST_F (StringHelperTest, testJoin_1string) {
    std::vector<std::string> messages;
    messages.push_back("firstMessage");
    EXPECT_EQ("firstMessage", Helper::join(messages, "/"));
}

/**
 * \test 文字列が空の場合
 */
TEST_F (StringHelperTest, testJoin_empty) {
    std::vector<std::string> messages;
    EXPECT_EQ("", Helper::join(messages, "/"));
}

/**
 * \test １文字を１桁へ
 */
TEST_F (StringHelperTest, testreformatDidits_1DigitTo1Digit) {
    EXPECT_EQ("1", Helper::reformatDidits("1", 1));
}

/**
 * \test 0桁が指定された場合
 */
TEST_F (StringHelperTest, testreformatDidits_To0Digit) {
    EXPECT_EQ("", Helper::reformatDidits("1", 0));
}

/**
 * \test １文字を１0桁へ
 */
TEST_F (StringHelperTest, testreformatDidits_1DigitTo10Digit) {
    EXPECT_EQ("0000000001", Helper::reformatDidits("1", 10));
}

/**
 * \test 2文字を2桁へ
 */
TEST_F (StringHelperTest, testreformatDidits_2DigitTo2Digit) {
    EXPECT_EQ("12", Helper::reformatDidits("12", 2));
}

/**
 * \test 5文字を2桁へ
 */
TEST_F (StringHelperTest, testreformatDidits_5DigitTo2Digit) {
    EXPECT_EQ("IllegalFormat", Helper::reformatDidits("12345", 2));
}

/**
 * \test デリミタが一つ且つ前後に空白を含まない
 */
TEST_F (StringHelperTest, testSplit_singleDelimiterWithoutWhitespace) {
    std::string testString("Key=Value");
    std::string delimiter("=");
    std::vector<std::string> result = Helper::split(testString, delimiter);

    EXPECT_EQ(2, result.size());
    EXPECT_EQ("Key", result[0]);
    EXPECT_EQ("Value", result[1]);
}

/**
 * \test デリミタが複数且つ前後に空白を含まない
 */
TEST_F (StringHelperTest, testSplit_multipleDelimiterWithoutWhitespace) {
    std::string testString("Key=Value1=Value2=Value3");
    std::string delimiter("=");
    std::vector<std::string> result = Helper::split(testString, delimiter);

    EXPECT_EQ(4, result.size());
    EXPECT_EQ("Key", result[0]);
    EXPECT_EQ("Value1", result[1]);
    EXPECT_EQ("Value2", result[2]);
    EXPECT_EQ("Value3", result[3]);
}

/**
 * \test デリミタが一つ且つ前後に空白を含む
 */
TEST_F (StringHelperTest, testSplit_singleDelimiterWithWhitespace) {
    std::string testString("Key = Value");
    std::string delimiter(" = ");
    std::vector<std::string> result = Helper::split(testString, delimiter);

    EXPECT_EQ(2, result.size());
    EXPECT_EQ("Key", result[0]);
    EXPECT_EQ("Value", result[1]);
}

/**
 * \test デリミタが複数且つ前後に空白を含む
 */
TEST_F (StringHelperTest, testSplit_multipleDelimiterWithWhitespace) {
    std::string testString("Key = Value1 = Value2 = Value3");
    std::string delimiter(" = ");
    std::vector<std::string> result = Helper::split(testString, delimiter);

    EXPECT_EQ(4, result.size());
    EXPECT_EQ("Key", result[0]);
    EXPECT_EQ("Value1", result[1]);
    EXPECT_EQ("Value2", result[2]);
    EXPECT_EQ("Value3", result[3]);
}

/**
 * \test 1文字デリミタの前後の空白を無視する
 */
TEST_F (StringHelperTest, testSplit_ignoreWhiteSpaceAroundDelimiter) {
    std::string testString("Key = Value1 = Value2 = Value3");
    std::string delimiter("=");
    std::vector<std::string> result = Helper::split(testString, delimiter);

    EXPECT_EQ(4, result.size());
    EXPECT_EQ("Key", result[0]);
    EXPECT_EQ("Value1", result[1]);
    EXPECT_EQ("Value2", result[2]);
    EXPECT_EQ("Value3", result[3]);
}

/**
 * \test 1文字デリミタの前後の空白を無視する
 */
TEST_F (StringHelperTest, testSplit_ignoreMultiWhiteSpaceAroundDelimiter) {
    std::string testString("Key   =   Value1   =   Value2 = Value3");
    std::string delimiter("=");
    std::vector<std::string> result = Helper::split(testString, delimiter);

    EXPECT_EQ(4, result.size());
    EXPECT_EQ("Key", result[0]);
    EXPECT_EQ("Value1", result[1]);
    EXPECT_EQ("Value2", result[2]);
    EXPECT_EQ("Value3", result[3]);
}

/**
 * \test struct timespec型の現在日を文字列として返す
 */
TEST_F (StringHelperTest, testConvertDateFormatToString_20150901){
    TimeProviderMock* timeProviderMock = new TimeProviderMock();    // 2015/09/01 13:26:37固定
    struct timespec tm = timeProviderMock->GetCurrentDateTime();
    std::string result = Helper::convertDateFormatToString(tm, "@");

    EXPECT_EQ("2015@09@01", result);

    delete timeProviderMock;
}

/**
 * \test struct timespec型の現在時刻を文字列として返す
 */
TEST_F (StringHelperTest, testConvertTimeFormatToString_20150901){
    TimeProviderMock* timeProviderMock = new TimeProviderMock();    // 2015/09/01 13:26:37固定
    struct timespec tm = timeProviderMock->GetCurrentDateTime();
    std::string result = Helper::convertTimeFormatToString(tm);

    EXPECT_EQ("13:26:37.123456789", result);

    delete timeProviderMock;
}

/**
 * \test 現在日時を文字列として返す
 */
TEST_F (StringHelperTest, testGetCurrentDateTimeString_20150901){
    TimeProviderMock* timeProviderMock = new TimeProviderMock();    // 2015/09/01 13:26:37固定
    struct timespec tm = timeProviderMock->GetCurrentDateTime();
    std::string result = Helper::GetCurrentDateTimeString(tm);

    EXPECT_EQ("2015/09/01 13:26:37.123456789", result);

    delete timeProviderMock;
}

/**
 * \test 現在日を文字列として返す
 */
TEST_F (StringHelperTest, testGetCurrentDateString_20150901){
    TimeProviderMock* timeProviderMock = new TimeProviderMock();    // 2015/09/01 13:26:37固定
    struct timespec tm = timeProviderMock->GetCurrentDateTime();
    std::string result = Helper::GetCurrentDateString(tm);

    EXPECT_EQ("20150901", result);

    delete timeProviderMock;
}

/**
 * \test 現在時刻を文字列として返す
 */
TEST_F (StringHelperTest, testGetCurrentTimeString_20150901){
    TimeProviderMock* timeProviderMock = new TimeProviderMock();    // 2015/09/01 13:26:37固定
    struct timespec tm = timeProviderMock->GetCurrentDateTime();
    std::string result = Helper::GetCurrentTimeString(tm);

    EXPECT_EQ("132637", result);

    delete timeProviderMock;
}

/**
 * \test ファイル名と現在日を文字列として返す
 */
TEST_F (StringHelperTest, testMakeLogFileName_Write){
    //準備
    TimeProviderMock* timeProviderMock = new TimeProviderMock();    // 2015/09/01 13:26:37固定
    struct timespec tm = timeProviderMock->GetCurrentDateTime();
    std::string dummyFileName("Name");
    std::string result = Helper::MakeLogFileName(tm,dummyFileName);
    //比較
    EXPECT_EQ("Name_20150901.log", result);
    //後始末
    delete timeProviderMock;
}
