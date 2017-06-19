/*! ********************************************************************************
 @file       TextFileDaoTest.cpp
 @brief      TextFileDaoをテストする
 @attention  なし
 **********************************************************************************/
//--------------< インクルードファイル >-----------------
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "TextFileDaoTest.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

TextFileDaoTest::TextFileDaoTest() :
    sut(NULL)
{
}

TextFileDaoTest::~TextFileDaoTest() {
}


void TextFileDaoTest::SetUp() {
    sut = new TextFileDaoSpy();
}

void TextFileDaoTest::TearDown() {
    delete sut;
}

std::string TextFileDaoTest::readFileContents(std::string readFileName) {
    std::ifstream inputStream_;
    std::string readData("");

    try {
        inputStream_.exceptions( std::ios::failbit | std::ios::badbit);
        inputStream_.open(readFileName.c_str(), std::ios::in );

        if(inputStream_.is_open()) {
            std::string line("");
            while( !getline(inputStream_, line).eof() ){
                readData += line;
                readData += "\n";
            }
            return readData;
        }
        else {
            std::string exceptionMessage("File is not opened.");
            throw exceptionMessage;
            return "";
        }
    }
    catch(std::string e) {
        std::cout << e << std::endl;
    }
    catch(...) {
        if(inputStream_.eof()) {
            return readData;
        }
        else {
            std::string message("");
            message += readFileName + " is NOT exists.";
            ADD_FAILURE() << message;
            return "";
        }
    }
    return "";
}

/**
 * \test 出力先のファイル名が設定されることを確認する
 */
TEST_F (TextFileDaoTest, testOpenOutputDevice) {
    std::string expectPath("Path/To/File.txt");
    sut->openOutputDevice(expectPath);
    EXPECT_EQ(expectPath, sut->GetOutputFileName());
}

/**
 * \test 出力用バッファにコンテンツが格納されることを確認する（1行）
 */
TEST_F (TextFileDaoTest, testOutput_1Line) {
    std::string outputContents("First Line");
    sut->output(outputContents);
    EXPECT_EQ("First Line", sut->GetContentsBuffer());
}

/**
 * \test 出力用バッファにコンテンツが格納されることを確認する（複数行）
 */
TEST_F (TextFileDaoTest, testOutput_MultiLine) {
    std::string outputContents("");
    outputContents += "First Line\n";
    outputContents += "Second Line\n";
    outputContents += "Third Line\n";

    sut->output(outputContents);
    EXPECT_EQ("First Line\nSecond Line\nThird Line\n", sut->GetContentsBuffer());
}

/**
 * \test 出力用バッファにコンテンツが格納されることを確認する（複数回出力）
 */
TEST_F (TextFileDaoTest, testOutput_MultiTimes) {
    std::string outputContents("");
    outputContents = "First Time\n";
    sut->output(outputContents);
    outputContents = "Second Time\n";
    sut->output(outputContents);
    outputContents = "Third Time\n";
    sut->output(outputContents);

    EXPECT_EQ("First Time\nSecond Time\nThird Time\n", sut->GetContentsBuffer());
}

/**
 * \test ファイルにバッファの内容が出力されることを確認する（1行）
 */
TEST_F (TextFileDaoTest, testWriteContents_singleLine) {
    std::string fileName("TextFileDaoTest.txt");
    remove(fileName.c_str());

    std::string outputContents("");
    outputContents = "First Line\n";
    sut->output(outputContents);
    sut->openOutputDevice(fileName);

    sut->writeContents();

    EXPECT_EQ("First Line\n", readFileContents(fileName));
}

/**
 * \test ファイルにバッファの内容が出力されることを確認する（複数行）
 */
TEST_F (TextFileDaoTest, testWriteContents_multiline) {
    std::string fileName("TextFileDaoTest.txt");
    remove(fileName.c_str());

    std::string outputContents("");
    outputContents += "First Line\n";
    outputContents += "Second Line\n";
    outputContents += "Third Line\n";
    sut->output(outputContents);
    sut->openOutputDevice(fileName);

    sut->writeContents();

    EXPECT_EQ("First Line\nSecond Line\nThird Line\n", readFileContents(fileName));

}

/**
 * \test ファイルへの書き込みが2回連続で行われた場合、内容が重複しないことを確認する
 */
TEST_F (TextFileDaoTest, testWriteContents_twice) {
    std::string fileName("TextFileDaoTest.txt");
    remove(fileName.c_str());

    std::string outputContents("");
    outputContents += "First Line\n";
    outputContents += "Second Line\n";
    outputContents += "Third Line\n";
    sut->output(outputContents);
    sut->openOutputDevice(fileName);

    sut->writeContents();
    sut->writeContents();

    EXPECT_EQ("First Line\nSecond Line\nThird Line\n", readFileContents(fileName));

}

/**
 * \test 指定された読み込みファイルが存在しない場合に例外がスローされることを確認する
 */
TEST_F(TextFileDaoTest, testOpenInputter_catchExceptionWhenOpenFileInputDueToFileNOTExsist) {
    EXPECT_THROW( sut->openInputter("NotExsitFile"), std::ios::failure);
}

/**
 * \test 指定された読み込みファイルが存在する場合に例外がスローされないことを確認する
 */
TEST_F(TextFileDaoTest, testOpenInputter_notCatchExceptionWhenOpenFileDueToInputFileExsist) {
    EXPECT_NO_THROW( sut->openInputter("TextFileDao.cpp") );
}

/**
 * \test 読み込み元ファイルが存在することがチェックできることを確認する
 */
TEST_F(TextFileDaoTest, testIsExists_getTrueWhenTargetFileExsist) {
    EXPECT_TRUE(sut->isExist("TextFileDao.cpp"));
    EXPECT_FALSE(sut->isOpenedInputStream());
}

/**
 * \test 読み込み元ファイルが存在しないことがチェックできることを確認する
 */
TEST_F(TextFileDaoTest, getFalseWhenTargetFileIsNOTExsist) {
    EXPECT_FALSE(sut->isExist("NoExsistFile"));
    EXPECT_FALSE(sut->isOpenedInputStream());
}

/**
 * \test ファイルの内容が1行読み込めることを確認する
 */
TEST_F(TextFileDaoTest, testReadData_singleLine) {
    std::string testFile("test.txt");
    std::string testString("Test String.");
    prepareTestingFile(testFile, testString);

    sut->openInputter(testFile);
    try {
        EXPECT_EQ(testString, sut->readData());
    }
    catch(const std::ios::failure& e) {
        std::cout << e.what() << std::endl;
        FAIL();
    }
    catch(const std::string& e) {
        std::cout << e << std::endl;
        FAIL();
    }
}

/**
 * \test ファイルの内容が複数行読み込めることを確認する
 */
TEST_F(TextFileDaoTest, testReadData_MultiLines) {
    std::string testFile("test.txt");
    std::string testString1stLine("1st Line");
    std::string testString2ndLine("2nd Line");
    prepareTestingFile(testFile, testString1stLine+"\n"+testString2ndLine);

    sut->openInputter(testFile);
    try {
        EXPECT_EQ(testString1stLine, sut->readData());
        EXPECT_EQ(testString2ndLine, sut->readData());
    }
    catch(const std::ios::failure& e) {
        std::cout << e.what() << std::endl;
        FAIL();
    }
    catch(const std::string& e) {
        std::cout << e << std::endl;
        FAIL();
    }
}


/**
 * \test ファイルの内容が複数行読み込めることを確認する
 */
TEST_F(TextFileDaoTest, testReadData_MultiLinesOverContents) {
    std::string testFile("test.txt");
    std::string testString1stLine("1st Line");
    std::string testString2ndLine("2nd Line");
    prepareTestingFile(testFile, testString1stLine+"\n"+testString2ndLine);

    sut->openInputter(testFile);
    try {
        EXPECT_EQ(testString1stLine, sut->readData());
        EXPECT_EQ(testString2ndLine, sut->readData());
        EXPECT_EQ("", sut->readData());
    }
    catch(const std::ios::failure& e) {
        if( strncmp(e.what(), "basic_ios::clear", sizeof(e.what())) == 0) {
            ;
        }
        else {
            FAIL();
        }
    }
    catch(const std::string& e) {
        std::cout << e << std::endl;
        FAIL();
    }
}

/**
 * \test 読み込みファイルオープン前に読み込もうとした場合に、例外がスローされることを確認する
 */
TEST_F(TextFileDaoTest, testReadData_catchExceptionWhenReadDataDueToFileIsNOTOpen) {
    EXPECT_THROW( sut->readData(), std::string);
}

/**
 * \test 読み込みファイルオープンされた後に読み込もうとした場合に、例外がスローされないことを確認する
 */
TEST_F(TextFileDaoTest, testReadData_notCatchExceptionWhenReadDataDueToFileIsOpened) {
    sut->openInputter("TextFileDao.cpp");
    EXPECT_NO_THROW( sut->readData());
}

/**
 * \test オープンされているファイルがクローズされることを確認する
 */
TEST_F(TextFileDaoTest, testCloseInputter) {
    sut->openInputter("TextFileDao.cpp");
    EXPECT_TRUE(sut->isOpenedInputStream());
    sut->closeInputter();
    EXPECT_FALSE(sut->isOpenedInputStream());
}

/**
 * \test オープンされていないファイルをクローズした場合に、例外がスローされることを確認する
 */
TEST_F(TextFileDaoTest, testCloseInputter_catchExceptionWhenCloseFileDueToFileHandlerWasClosed) {
    EXPECT_THROW( sut->closeInputter(), std::string);
}

/**
 * \test オープンされているファイルをクローズした場合に、例外がスローされないことを確認する
 */
TEST_F(TextFileDaoTest, testCloseInputter_notCatchExceptionWhenCloseFile) {
    sut->openInputter("TextFileDao.cpp");
    EXPECT_NO_THROW( sut->closeInputter());
}


/////////////////////////////////////////////////////////////
void TextFileDaoTest::prepareTestingFile(std::string fileName, std::string contents) {
    std::ofstream ofs(fileName.c_str());
    ofs << contents << std::endl;
}
