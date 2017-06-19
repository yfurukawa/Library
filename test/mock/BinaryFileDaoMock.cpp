/*! ********************************************************************************
 @file       BinaryFileDaoMock.cpp
 @brief      BinaryFileDaoMockクラスの実装ファイル
 @attention  なし
 **********************************************************************************/

//--------------< インクルードファイル >-----------------
#include "BinaryFileDaoMock.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

BinaryFileDaoMock::BinaryFileDaoMock():numOpenOutFile_CmnInfo(0),numOpenOutFile_ScenarioInfo(0),numOpenOutFile_FormationInfo(0),
numOpenOutFile_DlStatus(0),numOpenOutFile_PSnsTrackInfo(0),numOpenOutFile_PassiveIdTableIn(0),numOpenOutFile_ITrackInfo(0),numOpenOutFile_SaCorInfo(0),numOpenOutFile_PTrackInfo(0),
numOpenOutFile_PassiveIdTableOut(0),numOpenOutFile_TwoDimTrackInfo(0),numWriteIsCalled(0),numCloseOutFileIsCalled(0)
{

}

BinaryFileDaoMock::~BinaryFileDaoMock()
{

}

// 呼ばれた回数を記録
void BinaryFileDaoMock::OpenOutFile( std::string fileName )
{
    if(fileName.find("CMN_INFO.log")!=std::string::npos){
        numOpenOutFile_CmnInfo++;
    }else if(fileName.find("SCENARIO_INFO.log")!=std::string::npos){
        numOpenOutFile_ScenarioInfo++;
    }else if(fileName.find("FORMATION_INFO.log")!=std::string::npos){
        numOpenOutFile_FormationInfo++;
    }else if(fileName.find("DL_STATUS.log")!=std::string::npos){
        numOpenOutFile_DlStatus++;
    }else if(fileName.find("P_SNS_TRACK_INFO.log")!=std::string::npos){
        numOpenOutFile_PSnsTrackInfo++;
    }else if(fileName.find("SIM_PASSIVE_ID_TABLE.log")!=std::string::npos){
        numOpenOutFile_PassiveIdTableIn++;
    }else if(fileName.find("I_TRACK_INFO.log")!=std::string::npos){
        numOpenOutFile_ITrackInfo++;
    }else if(fileName.find("SA_COR_INFO.log")!=std::string::npos){
        numOpenOutFile_SaCorInfo++;
    }else if(fileName.find("P_TRACK_INFO.log")!=std::string::npos){
        numOpenOutFile_PTrackInfo++;
    }else if(fileName.find("IFC_PASSIVE_ID_TABLE.log")!=std::string::npos){
        numOpenOutFile_PassiveIdTableOut++;
    }else if(fileName.find("TWO_DIM_TRACK_INFO.log")!=std::string::npos){
        numOpenOutFile_TwoDimTrackInfo++;
    }else if(fileName.find("PASSIVE_ID_TRANSITION_INFO.log")!=std::string::npos){
        numOpenOutFile_PassiveIdTransitionInfo++;
    }else{
        // なにもしない
    }
}

// 呼ばれた回数を記録
void BinaryFileDaoMock::Write( void* data, int dataSizeByte )
{
    numWriteIsCalled++;
}

// 呼ばれた回数を記録
void BinaryFileDaoMock::CloseOutFile()
{
    numCloseOutFileIsCalled++;
}

// すべてのメンバをリセットする。
void BinaryFileDaoMock::ResetMembers()
{
    numOpenOutFile_CmnInfo = 0;
    numOpenOutFile_ScenarioInfo = 0;
    numOpenOutFile_FormationInfo = 0;
    numOpenOutFile_DlStatus = 0;
    numOpenOutFile_PSnsTrackInfo = 0;
    numOpenOutFile_PassiveIdTableIn = 0;
    numOpenOutFile_ITrackInfo = 0;
    numOpenOutFile_SaCorInfo = 0;
    numOpenOutFile_PTrackInfo = 0;
    numOpenOutFile_PassiveIdTableOut = 0;
    numOpenOutFile_TwoDimTrackInfo = 0;
    numOpenOutFile_PassiveIdTransitionInfo = 0;
    numWriteIsCalled = 0;
    numCloseOutFileIsCalled = 0;
}
