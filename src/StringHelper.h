/*! ********************************************************************************
@file       StringHelper.h
@brief      文字列操作をするヘルパーメソッド
@attention  なし
**********************************************************************************/
#ifndef STRINGHELPER_H_
#define STRINGHELPER_H_

#include <string>
#include <vector>


namespace Helper {
std::string itoa(int val);
std::string dtoa(double val);
std::string join(std::vector<std::string> messages, std::string delimiter);
std::string reformatDidits(std::string numberString, unsigned int numberOfDigits);
std::vector<std::string> split(std::string targetString, std::string delimiter);
std::string convertDateFormatToString(struct timespec tm, std::string delimiter);
std::string convertTimeFormatToString(struct timespec tm);
std::string GetCurrentDateTimeString(struct timespec tm);
std::string GetCurrentDateString(struct timespec tm);
std::string GetCurrentTimeString(struct timespec tm);
std::string MakeLogFileName(struct timespec tm, std::string device);

namespace HelperPrivate {
    std::string eraseSpace(std::string targetString);
}
}

#endif /* STRINGHELPER_H_ */
