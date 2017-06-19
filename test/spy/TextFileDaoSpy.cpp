/*! ********************************************************************************
 @file       TextFileDaoSpy.cpp
 @brief
 @attention
 **********************************************************************************/
//--------------< インクルードファイル >-----------------
#include "TextFileDaoSpy.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

TextFileDaoSpy::TextFileDaoSpy() {
}

TextFileDaoSpy::~TextFileDaoSpy() {
}

std::string TextFileDaoSpy::GetOutputFileName() const {
    return m_outputFileName;
}

std::string TextFileDaoSpy::GetContentsBuffer() const {
    return m_contentsBuffer;
}

bool TextFileDaoSpy::isOpenedInputStream() const {
    return inputStream_.is_open();
}
