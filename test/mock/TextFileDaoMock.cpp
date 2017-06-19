/*! ********************************************************************************
 @file       TextFileDaoMock.cpp
 @brief
 @attention  なし
 **********************************************************************************/
//--------------< インクルードファイル >-----------------
#include "TextFileDaoMock.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

TextFileDaoMock::TextFileDaoMock() :
    m_numberOfOutputCalled(0),
    m_outputContents(""),
    m_numberOfOpenDeviceCalled(0),
    m_deviceName(""),
    m_writeCalled(false)
{
}

TextFileDaoMock::~TextFileDaoMock() {
}

void TextFileDaoMock::openOutputDevice(std::string device)
{
    m_deviceName = device;
}

void TextFileDaoMock::output(std::string& outputContents)
{
    ++m_numberOfOutputCalled;
    m_outputContents = outputContents;
}

int TextFileDaoMock::GetNumberOfGetCurrentTimeCalled() const {
    return m_numberOfOutputCalled;
}

std::string TextFileDaoMock::GetOutputContents() const {
    return m_outputContents;
}

int TextFileDaoMock::GetNumberOfOpenDeviceCalled() const {
    return m_numberOfOpenDeviceCalled;
}

void TextFileDaoMock::writeContents()
{
    m_writeCalled = true;
}

std::string TextFileDaoMock::GetDeviceName() const
{
    return m_deviceName;
}

bool TextFileDaoMock::isWriteCalled() const
{
    return m_writeCalled;
}
