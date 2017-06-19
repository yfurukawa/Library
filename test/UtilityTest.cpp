/*! ********************************************************************************
 @file       UtilityTest.cpp
 @brief      ユーティリティ機能（範囲チェック等）のテスト
 @attention  なし
 **********************************************************************************/

//--------------< インクルードファイル >-----------------
#include "UtilityTest.h"
#include "spy/UtilitySpy.h"
#include "mock/LoggerMock.h"
#include "LogClient.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

UtilityTest::UtilityTest() :
            sut(NULL)
{

}

UtilityTest::~UtilityTest()
{

}

void UtilityTest::SetUp() {
    sut = new Helper::Utility();
}

void UtilityTest::TearDown() {
    delete sut;
}


/**
 * \test 範囲内外判定にて整数値が最小値を下回るとき最小値を返す。
 */
TEST_F (UtilityTest, testlimitValue_IntUnderMin_Min) {
    int value(50);
    int min(60);
    int max(80);
    EXPECT_EQ(min, sut->LimitValue(value, min, max));
}

/**
 * \test 範囲内外判定にて整数値が範囲内のときそのまま返す。
 */
TEST_F (UtilityTest, testIsInRange_IntValueInRange_Value) {
    int value(70);
    int min(60);
    int max(80);
    EXPECT_EQ(value, sut->LimitValue(value, min, max));
}

/**
 * \test 範囲内外判定にて整数値が最大値を上回るとき最大値を返す。
 */
TEST_F (UtilityTest, testIsInRange_IntValueOverMax_Max) {
    int value(90);
    int min(60);
    int max(80);
    EXPECT_EQ(max, sut->LimitValue(value, min, max));
}

/**
 * \test 範囲内外判定にて小数値が最小値を下回るとき最小値を返す。
 */
TEST_F (UtilityTest, testIsInRange_DoubleValueUnderMin_Min) {
    double value(0.5);
    double min(0.6);
    double max(0.8);
    EXPECT_EQ(min, sut->LimitValue(value, min, max));
}

/**
 * \test 範囲内外判定にて小数値が範囲内のときそのまま返す。
 */
TEST_F (UtilityTest, testIsInRange_DoubleValueInRange_Value) {
    double value(0.7);
    double min(0.6);
    double max(0.8);
    EXPECT_EQ(value, sut->LimitValue(value, min, max));
}

/**
 * \test 範囲内外判定にて小数値が最大値を上回るとき最大値を返す。
 */
TEST_F (UtilityTest, testIsInRange_DoubleValueOverMax_Max) {
    double value(0.9);
    double min(0.6);
    double max(0.8);
    EXPECT_EQ(max, sut->LimitValue(value, min, max));
}

/**
 * \test 範囲内外判定にて小数値が範囲内のときそのまま返す。
 */
TEST_F (UtilityTest, testLimitValue_DoubleValueInRange_Value) {
    double value(0.7);
    double min(0.6);
    EXPECT_EQ(value, sut->LimitValue(value, min));
}

/**
 * \test 範囲内外判定にて小数値が最小値を下回るとき最小値を返す。
 */
TEST_F (UtilityTest, testLimitValue_DoubleValueOverMax_Min) {
    double value(0.5);
    double min(0.6);
    EXPECT_EQ(min, sut->LimitValue(value, min));
}

/**
 * \test 指定した値がゼロであることを確認する
 */
TEST_F (UtilityTest, testIsZeroDouble_JudgeZero) {

    double input(0.0);
    // 実行
    bool isZero = sut->IsZeroDouble(input);
    // 比較
    EXPECT_EQ(true, isZero);
}

/**
 * \test 指定した正の値がゼロでないことを確認する
 */
TEST_F (UtilityTest, testIsZeroDouble_JudgeNoZeroPlus) {

    double input(0.0000001);
    // 実行
    bool isZero = sut->IsZeroDouble(input);
    // 比較
    EXPECT_EQ(false, isZero);
}

/**
 * \test 指定した負の値がゼロでないことを確認する
 */
TEST_F (UtilityTest, testIsZeroDouble_JudgeNoZeroMinus) {

    double input(-0.0000001);
    // 実行
    bool isZero = sut->IsZeroDouble(input);
    // 比較
    EXPECT_EQ(false, isZero);
}

/**
 * \test 指定した正の値がゼロであることを確認する
 */
TEST_F (UtilityTest, testIsZeroDouble_JudgeZeroPlus) {

    double input(0.0000000009);
    // 実行
    bool isZero = sut->IsZeroDouble(input);
    // 比較
    EXPECT_EQ(true, isZero);
}

/**
 * \test 指定した負の値がゼロであることを確認する
 */
TEST_F (UtilityTest, testIsZeroDouble_JudgeZeroMinus) {

    double input(-0.0000000009);
    // 実行
    bool isZero = sut->IsZeroDouble(input);
    // 比較
    EXPECT_EQ(true, isZero);
}

/**
 * \test フォルダが存在するとき真を返す
 */
TEST_F (UtilityTest, testDoesDirExist_Existance) {
    bool result = sut->DoesDirExist("../src");
    // 比較
    EXPECT_EQ(true, result);
}

/**
 * \test フォルダが存在しないとき偽を返す
 */
TEST_F (UtilityTest, testDoesDirExist_NotExistance) {
    bool result = sut->DoesDirExist("./abcdefghijklnmop");
    // 比較
    EXPECT_EQ(false, result);
}

/**
 * \test フォルダを作成する
 */
TEST_F (UtilityTest, testMakeDir_Existance) {
    // abcフォルダが存在する場合、削除しておく
    rmdir("./abc");
    if(sut->DoesDirExist("./abc")){
        FAIL();
    }

    bool result = sut->MakeDir("./","abc");
    // 比較
    EXPECT_EQ(true, result);

    // 後始末
    rmdir("./abc");
}

/**
 * \test 範囲外メッセージを出力する
 */
TEST_F (UtilityTest, testLogOutOfRange_NormalCase) {
    // 準備
    Helper::UtilitySpy sutSpy;
    LoggerMock* loggerMock = new LoggerMock();
    LogClient* utilityClient = new LogClient();
    sutSpy.SetLogger(loggerMock);
    sutSpy.SetUtilityClient(utilityClient);

    // 実行
    sutSpy.LogOutOfRange();

    // 比較
    EXPECT_EQ(1, loggerMock->GetNumOpenOpuputDevice());
    EXPECT_EQ("ForTestString", loggerMock->GetLoggingMessage());
//    EXPECT_EQ(1, loggerMock->GetNumWriteContents());

    // 後始末
    delete utilityClient; // loggerMockはUtility内でdeleteされる
}

/**
 * \test 範囲外メッセージを出力しない。
 */
TEST_F (UtilityTest, testLogOutOfRange_AbnormalCase) {
    // 準備
    Helper::UtilitySpy* sutSpy = new Helper::UtilitySpy();
    LoggerMock* loggerMock = new LoggerMock();
    LogClient* utilityClient(NULL);
    sutSpy->SetLogger(loggerMock);
    sutSpy->SetUtilityClient(utilityClient);

    // 実行
    sutSpy->LogOutOfRange();

    // 比較
    EXPECT_EQ(0, loggerMock->GetNumOpenOpuputDevice());
    EXPECT_EQ("", loggerMock->GetLoggingMessage());
//    EXPECT_EQ(0, loggerMock->GetNumWriteContents());

    // 後始末
    delete sutSpy; // loggerMockはUtility内でdeleteされる
}

/**
 * \test loggerクラスのメッセージを出力するメソッドを呼び出す。
 */
TEST_F (UtilityTest, testWriteLogMessage_CallWriteContents) {
    // 準備
    Helper::UtilitySpy sutSpy;
    LoggerMock* loggerMock = new LoggerMock();
    LogClient* utilityClient = new LogClient();
    sutSpy.SetLogger(loggerMock);
    sutSpy.SetUtilityClient(utilityClient);

    // 実行
    sutSpy.WriteLogMessage();

    // 比較
    EXPECT_EQ(1, loggerMock->GetNumWriteContents());

    // 後始末
    delete utilityClient; // loggerMockはUtility内でdeleteされる
}

/**
 * \test degをラジアンに変換出来ることを確認する
 */
TEST_F (UtilityTest, testConvertDegToRad_ConvertSuccess) {

    // 実行
    double rad = sut->ConvertDegToRad(180.0);

    // 比較
    EXPECT_NEAR(M_PI, rad, 0.0001);
}

/**
 * \test degをラジアンに0度で変換出来ることを確認する
 */
TEST_F (UtilityTest, testConvertDegToRad_ConvertSuccessZero) {

    // 実行
    double rad = sut->ConvertDegToRad(0.0);
    // 比較
    EXPECT_NEAR(0.0, rad, 0.0001);
}

/**
 * \test degをラジアンにマイナス値で変換出来ることを確認する
 */
TEST_F (UtilityTest, testConvertDegToRad_ConvertSuccessMinus) {

    // 実行
    double rad = sut->ConvertDegToRad(-180.0);
    // 比較
    EXPECT_NEAR(-M_PI, rad, 0.0001);
}

/**
 * \test degをラジアンに360度で変換出来ることを確認する
 */
TEST_F (UtilityTest, testConvertDegToRad_ConvertSuccess360) {

    // 実行
    double rad = sut->ConvertDegToRad(360.0);
    // 比較
    EXPECT_NEAR(M_PI * 2.0, rad, 0.0001);
}

/**
 * \test 原点緯度が0のときX軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateXRangePerSec_CalculateXRangeWhenCenterLatitudeIsZero) {
    double CenterLatitude(0.0);
    double expectXRange(30.71215);

    EXPECT_NEAR(expectXRange, sut->CalculateXRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度がπ/4のときX軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateXRangePerSec_CalculateXRangeWhenCenterLatitudeIsAQuarterOfAPi) {
    double CenterLatitude(M_PI/4.0);
    double expectXRange(30.86653);

    EXPECT_NEAR(expectXRange, sut->CalculateXRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度が-π/4のときX軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateXRangePerSec_CalculateXRangeWhenCenterLatitudeIsMinusAQuarterOfAPi) {
    double CenterLatitude(-M_PI/4.0);
    double expectXRange(30.86653);

    EXPECT_NEAR(expectXRange, sut->CalculateXRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度が-π/2のときX軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateXRangePerSec_CalculateXRangeWhenCenterLatitudeIsMinusAHalfOfAPi) {
    double CenterLatitude(-M_PI/2.0);
    double expectXRange(31.02221);

    EXPECT_NEAR(expectXRange, sut->CalculateXRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度が0のときY軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateYRangePerSec_CalculateYRangeWhenCenterLatitudeIsZero) {
    double CenterLatitude(0.0);
    double expectYRange(30.91851);

    EXPECT_NEAR(expectYRange, sut->CalculateYRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度がπ/4のときY軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateYRangePerSec_CalculateYRangeWhenCenterLatitudeIsAQuarterOfAPi) {
    double CenterLatitude(M_PI/4.0);
    double expectYRange(21.89926);

    EXPECT_NEAR(expectYRange, sut->CalculateYRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度が-π/4のときY軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateYRangePerSec_CalculateYRangeWhenCenterLatitudeIsMinusAQuarterOfAPi) {
    double CenterLatitude(-M_PI/4.0);
    double expectYRange(21.89926);

    EXPECT_NEAR(expectYRange, sut->CalculateYRangePerSec(CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度がπ/2のときY軸方向距離が算出されることを確認する
 */
TEST_F (UtilityTest, testCalculateYRangePerSec_CalculateYRangeWhenCenterLatitudeIsMinusAHalfOfAPi) {
    double CenterLatitude(M_PI/2.0);
    double expectYRange(1.9*pow(10.0, -15.0));

    EXPECT_NEAR(expectYRange, sut->CalculateYRangePerSec(CenterLatitude), 0.0000000000000001);
}

/**
 * \test 機体緯度と原点緯度が等しいとき0を返すことを確認する。
 */
TEST_F (UtilityTest, testCalculateDeltaX_ReturnZero) {
    double Latitude(M_PI/2.0);
    double CenterLatitude(M_PI/2.0);
    double expectReturn(0.0);

    EXPECT_NEAR(expectReturn, sut->CalculateDeltaX(Latitude, CenterLatitude), 0.0001);
}

/**
 * \test 機体緯度が原点緯度より大きいときその差を返すことを確認する。
 */
TEST_F (UtilityTest, testCalculateDeltaX_ReturnDifferenceWhenLongitudeIsLarger) {
    double Latitude(M_PI);
    double CenterLatitude(M_PI/2.0);
    double expectReturn(M_PI/2.0);

    EXPECT_NEAR(expectReturn, sut->CalculateDeltaX(Latitude, CenterLatitude), 0.00001);
}

/**
 * \test 原点緯度が機体緯度より大きいときその差を返すことを確認する。
 */
TEST_F (UtilityTest, testCalculateDeltaX_ReturnDifferenceWhenCenterLongitudeIsLarger) {
    double Latitude(M_PI/2.0);
    double CenterLatitude(M_PI);
    double expectReturn(-M_PI/2.0);

    EXPECT_NEAR(expectReturn, sut->CalculateDeltaX(Latitude, CenterLatitude), 0.00001);
}

/**
 * \test 機体経度と原点経度が等しいとき0を返すことを確認する。
 */
TEST_F (UtilityTest, testCalculateDeltaY_ReturnZero) {
    double Longitude(M_PI/2.0);
    double CenterLongitude(M_PI/2.0);
    double expectReturn(0.0);

    EXPECT_NEAR(expectReturn, sut->CalculateDeltaY(Longitude, CenterLongitude), 0.0001);
}

/**
 * \test 機体経度が原点経度より大きいときその差を返すことを確認する。
 */
TEST_F (UtilityTest, testCalculateDeltaY_ReturnDifferenceWhenLongitudeIsLarger) {
    double Longitude(M_PI/2.0);
    double CenterLongitude(M_PI/4.0);
    double expectReturn(M_PI/4.0);

    EXPECT_NEAR(expectReturn, sut->CalculateDeltaY(Longitude, CenterLongitude), 0.0001);
}

/**
 * \test 原点経度が機体経度より大きいときその差を返すことを確認する。
 */
TEST_F (UtilityTest, testCalculateDeltaY_ReturnDifferenceWhenCenterLongitudeIsLarger) {
    double Longitude(M_PI/4.0);
    double CenterLongitude(M_PI/2.0);
    double expectReturn(-M_PI/4.0);

    EXPECT_NEAR(expectReturn, sut->CalculateDeltaY(Longitude, CenterLongitude), 0.0001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-πのときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIsMinus180_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI);
    double CenterLongitude(0.0);
    double expectReturn(22370210.179622);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-3π/4のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIsMinus135_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI*3/4);
    double CenterLongitude(0.0);
    double expectReturn(18022480.683017);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-π/2のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIsMinus90_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(14119824.979865);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-π/4のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIsMinus45_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI/4);
    double CenterLongitude(0.0);
    double expectReturn(11140253.406337);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/4、経度が-π/2のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIsMinus90_LatitudeIsMinus45) {
    double Latitude(-M_PI/4);
    double CenterLatitude(0.0);
    double Longitude(-M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(11185105.089811);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 緯度経度、原点緯度経度がすべて0のときのXY平面距離が0となることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_AllParameterIsZero) {
    double Latitude(0.0);
    double CenterLatitude(0.0);
    double Longitude(0.0);
    double CenterLongitude(0.0);
    double expectReturn(0.0);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度がπ/4のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIs45_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI/4);
    double CenterLongitude(0.0);
    double expectReturn(11140253.406337);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度がπ/2のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIs90_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(14119824.979865);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が3π/4のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIs135_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI*3/4);
    double CenterLongitude(0.0);
    double expectReturn(18022480.683017);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度がπ/4のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIs45_LatitudeIs45) {
    double Latitude(M_PI/4);
    double CenterLatitude(0.0);
    double Longitude(M_PI/4);
    double CenterLongitude(0.0);
    double expectReturn(7059912.489933);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度がπ/2のときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIs90_LatitudeIs45) {
    double Latitude(M_PI/4);
    double CenterLatitude(0.0);
    double Longitude(M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(11185105.089811);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/2、経度がπのときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI);
    double CenterLongitude(0.0);
    double expectReturn(22370210.179622);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度がπ/4、原点経度が3π/4で緯度がπ/2、経度がπのときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_CenterLongitudeIs135_CenterLatitudeIs45_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(M_PI/4);
    double Longitude(M_PI);
    double CenterLongitude(M_PI*3/4);
    double expectReturn(6131054.026042);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度が-π/4、原点経度が-3π/4で緯度がπ/2、経度がπのときのXY平面距離が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYRangeFromCenter_CenterLongitudeIsMinus135_CenterLatitudeIsMinus45_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(-M_PI/4);
    double Longitude(M_PI);
    double CenterLongitude(-M_PI*3/4);
    double expectReturn(29012926.415749);

    EXPECT_NEAR(expectReturn, sut->CalculateXYRangeFromCenter(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}


/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-πのときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIsMinus180_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI);
    double CenterLongitude(0.0);
    double expectReturn(-2.03177062);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-3π/4のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIsMinus135_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI*3/4);
    double CenterLongitude(0.0);
    double expectReturn(-2.15571212);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-π/2のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIsMinus90_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(-2.35284614);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-π/4のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIsMinus45_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(-M_PI/4);
    double CenterLongitude(0.0);
    double expectReturn(-2.67526097);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/4、経度が-π/2のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIsMinus90_LatitudeIsMinus45) {
    double Latitude(-M_PI/4);
    double CenterLatitude(0.0);
    double Longitude(-M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(-2.03177062);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度がπ/4のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIs45_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI/4);
    double CenterLongitude(0.0);
    double expectReturn(2.675260971);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度がπ/2のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIs90_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(2.352846142);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度がπ3/4のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIs135_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI*3/4);
    double CenterLongitude(0.0);
    double expectReturn(2.155712121);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 緯度経度、原点緯度経度がすべて0のときのXY方向方位角が0となることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_AllParameterIsZero) {
    double Latitude(0.0);
    double CenterLatitude(0.0);
    double Longitude(0.0);
    double CenterLongitude(0.0);
    double expectReturn(0.0);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.00000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度がπ/4のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIs45_LatitudeIs45) {
    double Latitude(M_PI/4);
    double CenterLatitude(0.0);
    double Longitude(M_PI/4);
    double CenterLongitude(0.0);
    double expectReturn(0.788746511);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度がπ/2のときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIs90_LatitudeIs45) {
    double Latitude(M_PI/4);
    double CenterLatitude(0.0);
    double Longitude(M_PI/2);
    double CenterLongitude(0.0);
    double expectReturn(1.109822029);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/2、経度がπのときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(0.0);
    double Longitude(M_PI);
    double CenterLongitude(0.0);
    double expectReturn(1.109822029);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000000001);
}

/**
 * \test 原点緯度がπ/4、原点経度が3π/4で緯度がπ/2、経度がπのときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_CenterLongitudeIs135_CenterLatitudeIs45_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(M_PI/4);
    double Longitude(M_PI);
    double CenterLongitude(M_PI*3/4);
    double expectReturn(0.617061671);

    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度が-π/4、原点経度が-3π/4で緯度がπ/2、経度がπのときのXY方向方位角が返ることを確認する。
 */
TEST_F (UtilityTest, testCalculateXYBearing_CenterLongitudeIsMinus135_CenterLatitudeIsMinus45_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(-M_PI/4);
    double Longitude(M_PI);
    double CenterLongitude(-M_PI*3/4);
    double expectReturn(1.02739533);



    EXPECT_NEAR(expectReturn, sut->CalculateXYBearing(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-πのときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeMinusIs180_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double Longitude(-M_PI);
    double expectX(-9950737.432767);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度経度が0のときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeIs0_LatitudeIs0) {
    double Latitude(0.0);
    double Longitude(0.0);
    double expectX(0.0);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/2、経度がπのときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double Longitude(M_PI);
    double expectX(9950737.432767);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度が-π/3のときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeIsMinus60_LatitudeIs45) {
    double Latitude(M_PI/4);
    double Longitude(-M_PI/3);
    double expectX(4975368.716384);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/6、経度が-3π/4のときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeIsMinus135_LatitudeIsMinus30) {
    double Latitude(-M_PI/6);
    double Longitude(-M_PI*3/4);
    double expectX(-3316912.477589);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度が3π/4のときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeIs45_LatitudeIs135) {
    double Latitude(M_PI/4);
    double Longitude(M_PI*3/4);
    double expectX(4975368.716384);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/4、経度がπ/3のときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_LongitudeIsMinus45_LatitudeIs60) {
    double Latitude(-M_PI/4);
    double Longitude(M_PI/3);
    double expectX(-4975368.716384);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度-π/3、原点経度-π/4で緯度がπ/2、経度がπのときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_CenterLongitudeIsMinus45_CenterLatitudeIsMinus60_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(-60.0);
    double Longitude(M_PI);
    double CenterLongitude(-45.0);
    double expectX(16709874.149222);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度-π/6、原点経度-π/6で緯度がπ/2、経度がπのときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_CenterLongitudeIsMinus30_CenterLatitudeIsMinus30_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(-30.0);
    double Longitude(M_PI);
    double CenterLongitude(-30.0);
    double expectX(13300926.770400);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度π/3、原点経度π/3で緯度がπ/2、経度がπのときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_CenterLongitudeIs60_CenterLatitudeIs60_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(60.0);
    double Longitude(M_PI);
    double CenterLongitude(60.0);
    double expectX(3341974.829844);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度π/4、原点経度2π/3で緯度がπ/2、経度がπのときのX座標を確認する。
 */
TEST_F (UtilityTest, testCalculateX_CalculateX_CenterLongitudeIs120_CenterLatitudeIs45_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(45.0);
    double Longitude(M_PI);
    double CenterLongitude(120.0);
    double expectX(5000378.612756);

    EXPECT_NEAR(expectX, sut->CalculateX(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/2、経度が-πのときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeMinusIs180_LatitudeIsMinus90) {
    double Latitude(-M_PI/2);
    double Longitude(-M_PI);
    double expectY(-20035197.229491);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度経度が0のときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeIs0_LatitudeIs0) {
    double Latitude(0.0);
    double Longitude(0.0);
    double expectY(0.0);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/2、経度がπのときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double Longitude(M_PI);
    double expectY(20035197.229491);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度が-π/3のときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeIsMinus60_LatitudeIs45) {
    double Latitude(M_PI/4);
    double Longitude(-M_PI/3);
    double expectX(-6678399.076497);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/6、経度が-3π/4のときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeIsMinus135_LatitudeIsMinus30) {
    double Latitude(-M_PI/6);
    double Longitude(-M_PI*3/4);
    double expectX(-15026397.922118);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度がπ/4、経度が3π/4のときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeIs45_LatitudeIs135) {
    double Latitude(M_PI/4);
    double Longitude(M_PI*3/4);
    double expectX(15026397.922118);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度経度が0で緯度が-π/4、経度がπ/3のときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_LongitudeIsMinus45_LatitudeIs60) {
    double Latitude(-M_PI/4);
    double Longitude(M_PI/3);
    double expectX(6678399.076497);
    double CenterLatitude(0.0);
    double CenterLongitude(0.0);

    EXPECT_NEAR(expectX, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度-π/3、原点経度-π/4で緯度がπ/2、経度がπのときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_CenterLongitudeIsMinus45_CenterLatitudeIsMinus60_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(-60.0);
    double Longitude(M_PI);
    double CenterLongitude(-45.0);
    double expectY(12553457.605749);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度-π/6、原点経度-π/6で緯度がπ/2、経度がπのときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_CenterLongitudeIsMinus30_CenterLatitudeIsMinus30_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(-30.0);
    double Longitude(M_PI);
    double CenterLongitude(-30.0);
    double expectY(20259731.079094);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度π/3、原点経度π/3で緯度がπ/2、経度がπのときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_CenterLongitudeIs60_CenterLatitudeIs60_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(60.0);
    double Longitude(M_PI);
    double CenterLongitude(60.0);
    double expectY(6695177.389733);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 原点緯度π/4、原点経度2π/3で緯度がπ/2、経度がπのときのY座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_CenterLongitudeIs120_CenterLatitudeIs45_LongitudeIs180_LatitudeIs90) {
    double Latitude(M_PI/2);
    double CenterLatitude(45.0);
    double Longitude(M_PI);
    double CenterLongitude(120.0);
    double expectY(4730240.717264);

    EXPECT_NEAR(expectY, sut->CalculateY(Latitude, Longitude, CenterLatitude, CenterLongitude), 0.000001);
}

/**
 * \test 高度が負のときのZ座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_AltitudeIsNegative) {
    double Altitude(-123.4);
    double expectZ(123.4);

    EXPECT_NEAR(expectZ, sut->CalculateZ(Altitude), 0.001);
}

/**
 * \test 高度が0のときのZ座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_AltitudeIsZero) {
    double Altitude(-123.4);
    double expectZ(123.4);

    EXPECT_NEAR(expectZ, sut->CalculateZ(Altitude), 0.001);
}

/**
 * \test 高度が正のときのZ座標を確認する。
 */
TEST_F (UtilityTest, testCalculateY_CalculateY_AltitudeIsPositive) {
    double Altitude(432.1);
    double expectZ(-432.1);

    EXPECT_NEAR(expectZ, sut->CalculateZ(Altitude), 0.001);
}
