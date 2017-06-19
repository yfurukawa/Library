/*! ********************************************************************************
 @file       UtilitySpy.cpp
 @brief      UtilitySpyクラスの実装ファイル
 @attention  なし
 **********************************************************************************/

//--------------< インクルードファイル >-----------------
#include "UtilitySpy.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

namespace Helper
{

UtilitySpy::UtilitySpy()
{

}

UtilitySpy::~UtilitySpy()
{

}

void UtilitySpy::LogOutOfRange()
{
    Utility::LogOutOfRange();
}

void UtilitySpy::WriteLogMessage()
{
    Utility::WriteLogMessage();
}

std::string UtilitySpy::GetInformationMessage()
{
    return "ForTestString";
}
} /* namespace Helper */
