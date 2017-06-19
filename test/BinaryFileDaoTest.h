#ifndef BINARYFILEDAOTEST_H_
#define BINARYFILEDAOTEST_H_

#include <gtest/gtest.h>
#include "BinaryFileDao.h"
#include "spy/BinaryFileDaoSpy.h"
#include <fstream>

class BinaryFileDaoTest : public ::testing::Test {
protected:
    BinaryFileDaoSpy* sut;
    void SetUp();
    void TearDown();

    void OpenInFile(std::string fileName);
    int GetInFileSizeByte();
    void Read(void* data, int dataSizeByte, int dataIdx);
    void CloseInFile();
public:
    BinaryFileDaoTest();
    virtual ~BinaryFileDaoTest();

    std::ifstream m_FileIn; //!< バイナリデータ入力ファイル
};

#endif
