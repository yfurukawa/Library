/*!*****************************************************************************
@file			TextFileDao.h
@brief			テキストファイルにアクセスする
@attention		なし
*******************************************************************************/
#ifndef TEXTFILEDAO_H
#define TEXTFILEDAO_H

//----------< インクルード・ファイル >------------------------------------------
#include <string>
#include <fstream>
#include <iostream>
#include "IOutputter.h"
#include "IInputter.h"

//----------< クラスの前方宣言 >------------------------------------------------

//----------< マクロの宣言 >----------------------------------------------------

//----------< 型の宣言 >--------------------------------------------------------

/*!*****************************************************************************
@class			TextFileDao
@brief			テキストファイルにアクセスする
@note			設定条件のアクセス方法を知っている。
@attention		なし
@see          4.4.5
*******************************************************************************/
class TextFileDao : public IOutputter, public IInputter
{

public:
	TextFileDao();
	virtual ~TextFileDao();
    virtual void openOutputDevice(std::string device);
    virtual void output( std::string& outputContents);
    virtual void writeContents();

    virtual void openInputter( std::string name );
    virtual void closeInputter();
    virtual std::string readData();
    virtual bool isExist ( std::string name );

protected:
    std::string m_outputFileName; //!< 出力ファイル名
    std::string m_contentsBuffer;//!< 出力コンテンツ格納用バッファ
    std::ifstream inputStream_; //!< 入力ファイルストリーム

private:
	explicit TextFileDao(const TextFileDao& theTextFileDao);
	TextFileDao& operator=(const TextFileDao& theTextFileDao);

};
#endif // TEXTFILEDAO_H
