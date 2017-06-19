/*!*****************************************************************************
@file			TextFileDao.cpp
@brief			テキストファイルにアクセスする
@attention		なし
*******************************************************************************/
//----------< インクルードファイル >--------------------------------------------
#include "TextFileDao.h"

//----------< ローカルなマクロの宣言 >------------------------------------------

//----------< ローカルな型／変数の宣言 >----------------------------------------

/*!*****************************************************************************
@brief			コンストラクタ
@note			クラスを構築する。
@param			なし
@return		なし
@attention		なし
*******************************************************************************/
TextFileDao::TextFileDao() :
    m_outputFileName(""),
    m_contentsBuffer("")
{
}

/*!*****************************************************************************
@brief			コピーコンストラクタ
@note			クラスを複製する。
@param[in]		theTextFileDao	コピー元のインスタンス[-] (-)
@return		なし
@attention		なし
*******************************************************************************/
TextFileDao::TextFileDao(const TextFileDao& theTextFileDao) :
    m_outputFileName(theTextFileDao.m_outputFileName),
    m_contentsBuffer(theTextFileDao.m_contentsBuffer)
{
}
/*!*****************************************************************************
@brief          代入演算子
@note           インスタンスの代入を行う。
@param[in]      theTextFileDao  コピー元のインスタンス [-] (-)
@return         this 自分自身のポインタ
@attention      なし
*******************************************************************************/
TextFileDao& TextFileDao::operator =(const TextFileDao& theTextFileDao)
{
    m_outputFileName = theTextFileDao.m_outputFileName;
    m_contentsBuffer = theTextFileDao.m_contentsBuffer;
    return *this;
}
/*!*****************************************************************************
@brief			デストラクタ
@note			クラスを破棄する。
@param			なし
@return		なし
@attention		なし
*******************************************************************************/
TextFileDao::~TextFileDao(){
}

/*!*****************************************************************************
@brief          出力先ファイル名をセット
@note			  出力先ファイル名をセットする
@param[in]      device 出力先ファイル名 [-] (-)
@return         なし
@attention      ファイル名をセットするのみで実際にファイルをオープンする訳ではない。
*******************************************************************************/
void TextFileDao::openOutputDevice(std::string device) {
    m_outputFileName = device;
}

/*!*****************************************************************************
@brief          バッファに蓄積されたテキストをファイルに書き込む
@note			  バッファに蓄積されたテキストをファイルに書き込む処理をする。
@param          なし
@return         なし
@attention      なし
*******************************************************************************/
void TextFileDao::writeContents() {
    std::ofstream outFile(m_outputFileName.c_str(), std::ios::out | std::ios::app);
    outFile << m_contentsBuffer;
    m_contentsBuffer = "";
}

/*!*****************************************************************************
@brief          デバイスに書き込むコンテンツをバッファに出力
@note			  デバイスに書き込むコンテンツをバッファに出力する。
@param[in]      outputContents 出力内容 [-] (-)
@return         なし
@attention      なし
*******************************************************************************/
void TextFileDao::output( std::string& outputContents) {
    m_contentsBuffer += outputContents;
}

/*!*****************************************************************************
@brief          読み込み用ファイルをオープン
@note			  読み込み用ファイルをオープンする。
@param[in]      name 読み込み元のファイル名 [-] (-)
@return         なし
@attention      読み込みファイルがない場合は、basic_ios::clear例外がスローされる
*******************************************************************************/
void TextFileDao::openInputter(std::string name) {
    inputStream_.exceptions( std::ios::failbit | std::ios::badbit);
    inputStream_.open(name.c_str(), std::ios::in );
}

/*!*****************************************************************************
@brief          読み込み用ファイルをクローズ
@note			  読み込み用ファイルをクローズする。
@param          なし
@return         なし
@attention      既にクローズされていた場合、メッセージがスローされる
*******************************************************************************/
void TextFileDao::closeInputter() {
    if(inputStream_.is_open()) {
        inputStream_.close();
    }
    else {
        std::string exceptionMessage("File Handler is already closed.");
        throw exceptionMessage;
    }
}

/*!*****************************************************************************
@brief          ファイルから1行読み込む
@note			  ファイルから1行を読み込む処理をする。
@param          なし
@return         std::string	読み込んだ文字列 [-] (-)
@attention      読み込みファイルがオープンされていない場合は、メッセージがスローされる
@attention      eofファイルまで読み込むとbasic_ios::clear例外がスローされるので適切に
処理する必要がある
*******************************************************************************/
std::string TextFileDao::readData() {
    if(inputStream_.is_open()) {
        std::string readData;
        getline(inputStream_, readData);
        return readData;
    }
    else {
        std::string exceptionMessage("File is not opened.");
        throw exceptionMessage;
        return "";
    }
}

/*!*****************************************************************************
@brief          読み込みファイルの有無を確認
@note			  読み込みファイルの有無を確認する
@param[in]      name 読み込み元のファイル名 [-] (-)
@return         bool 確認結果 [-] (true : 存在する　　false : 存在しない)
@attention      なし
*******************************************************************************/
bool TextFileDao::isExist(std::string name) {
    try {
        this->openInputter( name );
        inputStream_.close();
        return true;
    }
    catch (...) {
        return false;
    }
    return false;
}

