/*! ********************************************************************************
 @file       BinaryFileDao.cpp
 @brief      バイナリファイルアクセス処理
 @attention  なし
 **********************************************************************************/

//--------------< インクルードファイル >-----------------
#include <cstring>
#include "BinaryFileDao.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

/*!*****************************************************************************
@brief          コンストラクタ
@note           クラスを構築する。
@param          なし
@return         なし
@attention      なし
*******************************************************************************/
BinaryFileDao::BinaryFileDao()
{

}

/*!*****************************************************************************
@brief          デストラクタ
@note           クラスを破棄する。
@param          なし
@return         なし
@attention      なし
*******************************************************************************/
BinaryFileDao::~BinaryFileDao()
{

}

/*!*****************************************************************************
@brief          出力ファイルオープン
@note           バイナリデータを出力するファイルを開く。
@param[in]      fileName 出力ファイル名 [-] (-)
@return         なし
@attention      なし
*******************************************************************************/
void BinaryFileDao::OpenOutFile(std::string fileName)
{
    m_FileOut.open(fileName.c_str(), std::ios::out|std::ios::binary|std::ios::trunc);
}

/*!*****************************************************************************
@brief          ファイル書き込み
@note           ファイルにバイナリデータを書き込む。
@param[in]      data 書き込みデータ [-] (-)
@param[in]      dataSizeByte データサイズ [byte] (1-)
@return         なし
@attention      なし
*******************************************************************************/
void BinaryFileDao::Write(void* data, int dataSizeByte)
{
    if (!m_FileOut) {
        return;
    }

    m_FileOut.write(( char * ) data, dataSizeByte );
}

/*!*****************************************************************************
@brief          出力ファイルクローズ
@note           バイナリデータを出力したファイルを閉じる。
@param          なし
@return         なし
@attention      なし
*******************************************************************************/
void BinaryFileDao::CloseOutFile()
{
    if (!m_FileOut) {
        return;
    }
    m_FileOut.close();
}
