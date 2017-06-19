/*!*****************************************************************************
@file           TimeProvider.h
@brief          日付や時刻を提供
@attention      なし
*******************************************************************************/
#ifndef TIMEPROVIDER_H_
#define TIMEPROVIDER_H_

//----------< インクルード・ファイル >------------------------------------------
#include <ctime>
#include <vector>
#include <string>

//----------< クラスの前方宣言 >------------------------------------------------

//----------< マクロの宣言 >----------------------------------------------------

//----------< 型の宣言 >--------------------------------------------------------

/*!*****************************************************************************
@class          TimeProvider
@brief          日付や時刻を提供
@note           Logger用に日付や時刻を提供する。
@attention      なし
@see            4.4.5
*******************************************************************************/
class TimeProvider {
public:
    TimeProvider();
    virtual ~TimeProvider();
    virtual struct timespec GetCurrentDateTime();

protected:

private:
    explicit TimeProvider(const TimeProvider& theTimeProvider);
    TimeProvider& operator=(const TimeProvider& theTimeProvider);
};

#endif  // TIMEPROVIDER_H_
