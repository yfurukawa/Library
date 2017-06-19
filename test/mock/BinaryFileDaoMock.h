/*! ********************************************************************************
 @file       BinaryFileDaoMock.h
 @brief      BinaryFiledaoMockクラスの定義ファイル
 @attention  なし
 **********************************************************************************/

#ifndef BINARYFILEDAOMOCK_H_
#define BINARYFILEDAOMOCK_H_

//----------< インクルード・ファイル >------------------------------------------
#include "BinaryFileDao.h"

//----------< クラスの前方宣言 >------------------------------------------------

//----------< マクロの宣言 >----------------------------------------------------

//----------< 型の宣言 >--------------------------------------------------------

/*! ******************************************************************************
 @class      BinaryFileDaoMock
 @brief      BinaryFileDaoMockのモッククラス
 @note       BinaryFileDaoを模擬する。
 @attention  なし
 ********************************************************************************/
class BinaryFileDaoMock: public BinaryFileDao
{
public:
    BinaryFileDaoMock();
    virtual ~BinaryFileDaoMock();

    void OpenOutFile(std::string fileName);
    void Write(void* data, int dataSizeByte);
    void CloseOutFile();

//    void OpenInFile(std::string fileName);
//    int GetInFileSizeByte();
//    void Read(void* data, int dataSizeByte, int dataIdx);
//    void CloseInFile();


    int GetNumOpenOutFile_CmnInfo(){ return numOpenOutFile_CmnInfo;};
    int GetNumOpenOutFile_ScenarioInfo(){ return numOpenOutFile_ScenarioInfo;};
    int GetNumOpenOutFile_FormationInfo(){ return numOpenOutFile_FormationInfo;};
    int GetNumOpenOutFile_DlStatus(){ return numOpenOutFile_DlStatus;};
    int GetNumOpenOutFile_PSnsTrackInfo(){ return numOpenOutFile_PSnsTrackInfo;};
    int GetNumOpenOutFile_PassiveIdTableIn(){ return numOpenOutFile_PassiveIdTableIn;};
    int GetNumOpenOutFile_ITrackInfo(){ return numOpenOutFile_ITrackInfo;};
    int GetNumOpenOutFile_SaCorInfo(){ return numOpenOutFile_SaCorInfo;};
    int GetNumOpenOutFile_PTrackInfo(){ return numOpenOutFile_PTrackInfo;};
    int GetNumOpenOutFile_PassiveIdTableOut(){ return numOpenOutFile_PassiveIdTableOut;};
    int GetNumOpenOutFile_TwoDimTrackInfo(){ return numOpenOutFile_TwoDimTrackInfo;};
    int GetNumOpenOutFile_PassiveIdTransitionInfo(){ return numOpenOutFile_PassiveIdTransitionInfo;};

    int GetNumWriteIsCalled(){ return numWriteIsCalled;};
    int GetNumCloseutFileCalled(){ return numCloseOutFileIsCalled;};
    void ResetMembers();

private:
    int numOpenOutFile_CmnInfo;             // 共通情報 呼び出し回数
    int numOpenOutFile_ScenarioInfo;        // シナリオ情報 呼び出し回数
    int numOpenOutFile_FormationInfo;       // 編隊情報 呼び出し回数
    int numOpenOutFile_DlStatus;            // データリンク・ステータス 呼び出し回数
    int numOpenOutFile_PSnsTrackInfo;       // パッシブセンサ航跡情報 呼び出し回数
    int numOpenOutFile_PassiveIdTableIn;    // パッシブ航跡ID対応表 呼び出し回数
    int numOpenOutFile_ITrackInfo;          // 統合航跡情報 呼び出し回数
    int numOpenOutFile_SaCorInfo;           // SA相関情報 呼び出し回数
    int numOpenOutFile_PTrackInfo;          // パッシブ航跡情報 呼び出し回数
    int numOpenOutFile_PassiveIdTableOut;   // パッシブ航跡ID対応表 呼び出し回数
    int numOpenOutFile_TwoDimTrackInfo; //二次元航跡情報 呼び出し回数
    int numOpenOutFile_PassiveIdTransitionInfo; //パッシブID遷移情報 呼び出し回数
    int numWriteIsCalled;               // 書き込み（トータル）　呼び出し回数
    int numCloseOutFileIsCalled;        // クローズ（トータル）　呼び出し回数
};

#endif /* BINARYFILEDAOMOCK_H_ */
