#include "BinaryFileDaoTest.h"
#include <math.h>

BinaryFileDaoTest::BinaryFileDaoTest() {

}

BinaryFileDaoTest::~BinaryFileDaoTest() {

}

void BinaryFileDaoTest::SetUp() {
    sut = new BinaryFileDaoSpy();
}

void BinaryFileDaoTest::TearDown() {
    delete sut;
}


/*!*****************************************************************************
@brief          入力ファイルオープン
@note           入力用バイナリファイルを開く。
@param[in]      fileName 入力ファイル名 [-] (-)
@return         なし
@attention      なし
*******************************************************************************/
void BinaryFileDaoTest::OpenInFile(std::string fileName)
{
    m_FileIn.open(fileName.c_str(), std::ios::in|std::ios::binary);
}

/*!*****************************************************************************
@brief          入力ファイルサイズ
@note           バイナリファイルのサイズを取得する。
@param          なし
@return         int ファイルサイズ [byte] (1-)
@attention      なし
*******************************************************************************/
int BinaryFileDaoTest::GetInFileSizeByte()
{
    if(!m_FileIn){
        return -1;
    }

    m_FileIn.seekg (0, m_FileIn.end);
    return static_cast<int>(m_FileIn.tellg());
}

/*!*****************************************************************************
@brief          ファイル内容読み込み
@note           バイナリファイルの中身を読み込む。
@param[in]      data バイナリデータ [-] (-)
@param[in]      dataSizeByte データサイズ [byte] (1-)
@param[in]      dataIdx データ索引 [-] (-)
@return         なし
@attention      なし
*******************************************************************************/
void BinaryFileDaoTest::Read(void* data, int dataSizeByte, int dataIdx)
{
    //ポインタの位置を移動
    m_FileIn.seekg ( dataIdx*dataSizeByte , std::ios_base::beg);

    m_FileIn.read( ( char * ) data, dataSizeByte );
}

/*!*****************************************************************************
@brief          入力ファイルクローズ
@note           入力用バイナリファイルを閉じる。
@param          なし
@return         なし
@attention      なし
*******************************************************************************/
void BinaryFileDaoTest::CloseInFile()
{
    if (!m_FileIn) {
        return;
    }
    m_FileIn.close();
}


/*
 * \ test ダブル型の配列をバイナリデータとして読み書きする。
 */
TEST_F (BinaryFileDaoTest, test_DoubleArrayData) {

    BinaryFileDao dao;
    dao.OpenOutFile("testtest.log");

    double a[12];

    for(int i=0; i<12; i++) {
        a[i] = 1.0*double(i);
        dao.Write(&a[i], sizeof(double));
    }

    dao.CloseOutFile();


    OpenInFile("testtest.log");
    double b[12];

    for(int i=0; i<12; i++) {
        b[i] = 0.0;
    }

//    std::cout << "size = " << dao.GetInFileSizeByte() << std::endl;

    for(int i=0; i<12; i++) {
        Read(&b[i], sizeof(double), i);
    }

    CloseInFile();

    EXPECT_EQ(0, memcmp(a, b, sizeof(double)*12));

}
