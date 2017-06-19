/*! ********************************************************************************
 @file       TimeProviderMock.h
 @brief
 @attention  なし
 **********************************************************************************/
#ifndef TIMEPROVIDERMOCK_H_
#define TIMEPROVIDERMOCK_H_

#include "TimeProvider.h"

/*! ******************************************************************************
 @class      TimeProviderMock
 @brief      TimeProviderを模擬する
 @note
 @attention  なし
 ********************************************************************************/
class TimeProviderMock: public TimeProvider {
public:
    TimeProviderMock();
    virtual ~TimeProviderMock();
    virtual struct timespec GetCurrentDateTime();
    int GetNumberOfGetCurrentTimeCalled() const;
private:
    int m_numberOfGetCurrentTimeCalled;

};

#endif /* TIMEPROVIDERMOCK_H_ */
