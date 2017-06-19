/*! ********************************************************************************
 @file       TextFileDaoSpy.h
 @brief      TextFileDaoの中を覗き見る
 @attention  なし
 **********************************************************************************/
#ifndef TEXTFILEDAOSPY_H_
#define TEXTFILEDAOSPY_H_

#include "TextFileDao.h"

/*! ******************************************************************************
 @class      TextFileDaoSpy
 @brief      TextFileDaoの中を覗き見る
 @note
 @attention  なし
 ********************************************************************************/
class TextFileDaoSpy: public TextFileDao {
public:
    TextFileDaoSpy();
    virtual ~TextFileDaoSpy();
    std::string GetOutputFileName() const;
    std::string GetContentsBuffer() const;
    bool isOpenedInputStream() const;
};

#endif /* TEXTFILEDAOSPY_H_ */
