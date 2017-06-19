/*! ********************************************************************************
 @file       BinaryFileDao.h
 @brief      バイナリファイルアクセス処理
 @attention  なし
 **********************************************************************************/

#ifndef BINARYFILEDAO_H_
#define BINARYFILEDAO_H_

//----------< インクルード・ファイル >------------------------------------------
#include <iostream>
#include <fstream>
//----------< クラスの前方宣言 >------------------------------------------------

//----------< マクロの宣言 >----------------------------------------------------

//----------< 型の宣言 >--------------------------------------------------------

/*! ******************************************************************************
 @class      BinaryFileDao
 @brief      バイナリファイルアクセス処理
 @note       なし
 @attention  なし
 @see        4.4.5
 ********************************************************************************/
class BinaryFileDao
{
public:
    BinaryFileDao();
    virtual ~BinaryFileDao();

    virtual void OpenOutFile(std::string fileName);
    virtual void Write(void* data, int dataSizeByte);
    virtual void CloseOutFile();

private:
    std::ofstream m_FileOut; //!< バイナリデータ出力ファイル

};

#endif /* BINARYFILEDAO_H_ */
