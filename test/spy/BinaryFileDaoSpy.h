/*! ********************************************************************************
 @file       BinaryFileDaoSpy.h
 @brief      BinaryFileDaoSpyクラスの定義ファイル
 @attention  なし
 **********************************************************************************/
#ifndef BINARYFILEDAOSPY_H_
#define BINARYFILEDAOSPY_H_

#include "BinaryFileDao.h"

/*! ******************************************************************************
 @class      BinaryFileDaoSpy
 @brief      BinaryFileDaoのスパイクラス
 @note       BinaryFileDaoSpyの中を覗き見る。
 @attention  なし
 ********************************************************************************/
class BinaryFileDaoSpy: public BinaryFileDao {
public:
    BinaryFileDaoSpy();
    virtual ~BinaryFileDaoSpy();


//    std::ofstream GetFileOut(){return m_FileOut;};
//    std::ifstream GetFileIn(){return m_FileIn;};
};

#endif /* BINARYFILEDAOSPY_H_ */
