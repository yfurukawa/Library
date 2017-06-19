/*! ********************************************************************************
 @file       TextFileDaoMock.h
 @brief
 @attention  なし
 **********************************************************************************/
#ifndef TEXTFILEDAOMOCK_H_
#define TEXTFILEDAOMOCK_H_

#include <string>
#include "IOutputter.h"

/*! ******************************************************************************
 @class      TextFileDaoMock
 @brief      模擬TextFileDao
 @note       TextFileDaoの模擬をする
 @attention  なし
 ********************************************************************************/
class TextFileDaoMock: public IOutputter {
public:
    TextFileDaoMock();
    virtual ~TextFileDaoMock();
    virtual void openOutputDevice(std::string device);
    virtual void output(std::string& outputContents);
    virtual void writeContents();
    int GetNumberOfGetCurrentTimeCalled() const;
    std::string GetOutputContents() const;
    int GetNumberOfOpenDeviceCalled() const;
    std::string GetDeviceName() const;
    bool isWriteCalled() const;

private:
    int m_numberOfOutputCalled;
    std::string m_outputContents;
    int m_numberOfOpenDeviceCalled;
    std::string m_deviceName;
    bool m_writeCalled;
};

#endif /* TEXTFILEDAOMOCK_H_ */
