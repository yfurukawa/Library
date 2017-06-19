/*! ********************************************************************************
 @file       TextFileDaoTest.h
 @brief      TextFileDaoをテストする
 @attention  なし
 **********************************************************************************/
#ifndef TEXTFILEDAOTEST_H_
#define TEXTFILEDAOTEST_H_

#include <gtest/gtest.h>
#include <string>
#include "spy/TextFileDaoSpy.h"

/*! ******************************************************************************
 @class      TextFileDaoTest
 @brief      TextFileDaoをテストする
 @note
 @attention  なし
 ********************************************************************************/
class TextFileDaoTest : public ::testing::Test  {
public:
    TextFileDaoTest();
    virtual ~TextFileDaoTest();

protected:
    TextFileDaoSpy* sut;
    void SetUp();
    void TearDown();
    std::string readFileContents(std::string readFileName);
    void prepareTestingFile( std::string fileName = "t.txt", std::string contents = "No contents");
};

#endif /* TEXTFILEDAOTEST_H_ */
