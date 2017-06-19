/*! ********************************************************************************
 @file       UtilitySpy.h
 @brief      Utilityのスパイクラス
 @attention  なし
 **********************************************************************************/

#ifndef UTILITYSPY_H_
#define UTILITYSPY_H_

//----------< インクルード・ファイル >------------------------------------------
#include "Utility.h"

//----------< クラスの前方宣言 >------------------------------------------------

//----------< マクロの宣言 >----------------------------------------------------

//----------< 型の宣言 >--------------------------------------------------------

namespace Helper
{

/*! ******************************************************************************
 @class      UtilitySpy
 @brief      Utilityのスパイクラス
 @note       Utilityに値を設定する
 @attention  なし
 ********************************************************************************/
class UtilitySpy: public Utility
{
public:
    UtilitySpy();
    virtual ~UtilitySpy();

    void SetLogger(Logger* logger){m_logger = logger;};
    void SetUtilityClient(LogClient* utilityClient){ m_UtilityClient = utilityClient;};
    void LogOutOfRange();
    void WriteLogMessage();

    std::string GetInformationMessage();
};

} /* namespace Helper */
#endif /* UTILITYSPY_H_ */
