/*! ********************************************************************************
 @file       TimeProviderMock.cpp
 @brief
 @attention  なし
 **********************************************************************************/
//--------------< インクルードファイル >-----------------
#include "TimeProviderMock.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

TimeProviderMock::TimeProviderMock() :
    m_numberOfGetCurrentTimeCalled(0)
{
}

TimeProviderMock::~TimeProviderMock() {
}

struct timespec TimeProviderMock::GetCurrentDateTime()
{
    struct timespec ts;

     ++m_numberOfGetCurrentTimeCalled;

     ts.tv_sec = 1441081597;        // 2015/09/01 13:26:37
     ts.tv_nsec = 123456789;

    return ts;
}

int TimeProviderMock::GetNumberOfGetCurrentTimeCalled() const {
    return m_numberOfGetCurrentTimeCalled;
}
