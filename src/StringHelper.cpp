/*! ********************************************************************************
@file       StringHelper.cpp
@brief      文字列操作をするヘルパーメソッド
@attention  なし
**********************************************************************************/
//--------------< インクルードファイル >-----------------
#include <sstream>
#include "StringHelper.h"
#include "TimeProvider.h"

//--------------< ローカルなマクロの宣言 >-----------------

//--------------< ローカルな型／変数の宣言 >-----------------^

namespace Helper {

/*!*****************************************************************************
@brief          整数を文字列に変換
@note           整数を文字列に変換する。
@param[in]      val 変換対象の整数 [-] (0-)
@return         std::string	変換後の文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string itoa(int val) {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

/*!*****************************************************************************
@brief          浮動小数を文字列に変換
@note           浮動小数を文字列に変換する。
@param[in]      val 変換対象の浮動小数 [-] (0.0-)
@return         std::string 変換後の文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string dtoa(double val) {
    std::stringstream ss;
    //ss.precision(10);
    ss << val;
    return ss.str();
}

/*!*****************************************************************************
@brief          0が頭に入った数字を返す
@note           日付や時刻の2桁フォーマットに対応するため、0を頭に挿入する。
@param[in]      numberString 変換元文字列 [-] (-)
@param[in]      numberOfDigits 必要桁数 [-] (0-)
@return         std::string	現在日時を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string reformatDidits(std::string numberString, unsigned int numberOfDigits) {
    if( numberOfDigits == 0) {
        return "";
    }
    else if( numberString.size() > numberOfDigits ) {
        return "IllegalFormat";
    }
    else if( numberString.size() == numberOfDigits ) {
        return numberString;
    }
    else {
        std::string zero;
        zero.assign(numberOfDigits, '0');
        zero += numberString;
        return zero.substr(zero.size()-numberOfDigits, numberOfDigits);
    }
}

/*!*****************************************************************************
@brief          文字列を結合
@note           vectorコンテナに格納されている文字列をデリミタ文字列で結合する
@param[in]      message 結合対象文字列 [-] (-)
@param[in]      delimiter 結合する文字列 [-] (-)
@return         std::string	結合後の文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string join(std::vector<std::string> messages, std::string delimiter) {

    if(messages.empty())
        return "";

    std::string joinedString("");

    for(std::vector<std::string>::iterator itr = messages.begin(); itr != messages.end(); ++itr) {
        joinedString += *itr;
        joinedString += delimiter;
    }
    //size_t position = joinedString.find_last_of(delimiter);
    size_t position = joinedString.rfind(delimiter);
    joinedString.erase(position);

    return joinedString;
}

/*!*****************************************************************************
@brief          文字列の分離処理
@note           文字列を区切り文字毎に分離してvectorコンテナに格納する
@param[in]      targetString	切り出し元の文字列 [-] (-)
@param[in]      delimiter		区切り文字 [-] (-)
@return         std::vector<std::string>	分離後の文字列を格納 [-] (-)
@attention      なし
*******************************************************************************/
std::vector<std::string> split(std::string targetString, std::string delimiter)
{
    std::vector<std::string> result;
    size_t current(0);
    size_t found(0);
    size_t delimiterLength(delimiter.size());

    while((found = targetString.find(delimiter, current)) != std::string::npos){
        result.push_back(HelperPrivate::eraseSpace(std::string(targetString, current, found - current)));
        current = found + delimiterLength;
     }
    result.push_back(HelperPrivate::eraseSpace(std::string(targetString, current, targetString.size() - current)));

    return result;
}

/*!*****************************************************************************
@brief          struct timespec型の現在日を文字列として返す
@note           struct timespec型の現在日を文字列として返す。
@param[in]      tm          現在日時 [-] (-)
@param[in]      delimiter   年・月・日を仕切る文字列 [-] (-)
@return         std::string 現在日を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string convertDateFormatToString(struct timespec tm, std::string delimiter) {
    const int DIGITS(2);
    std::vector<std::string> dateString;
    struct tm* date;
    time_t now;

    now = tm.tv_sec;
    date = localtime(&now);
    dateString.push_back(Helper::itoa(date->tm_year+1900));
    dateString.push_back(Helper::reformatDidits(Helper::itoa(date->tm_mon+1), DIGITS));
    dateString.push_back(Helper::reformatDidits(Helper::itoa(date->tm_mday), DIGITS));

    return Helper::join(dateString, delimiter);
}

/*!*****************************************************************************
@brief          struct timespec型の現在時刻を文字列として返す
@note           struct timespec型の現在時刻を文字列として返す
@param[in]      tm    現在日時 [-] (-)
@return         std::string 現在時刻を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string convertTimeFormatToString(struct timespec tm) {
    const int DIGITS(2);
    const int NANO_SECOND_DIGITS(9);
    std::vector<std::string> timeString;
    struct tm* date;
    time_t now;

    now = tm.tv_sec;
    date = localtime(&now);
    timeString.push_back(Helper::reformatDidits(Helper::itoa(date->tm_hour), DIGITS));
    timeString.push_back(Helper::reformatDidits(Helper::itoa(date->tm_min), DIGITS));
    timeString.push_back(Helper::reformatDidits(Helper::itoa(date->tm_sec), DIGITS) + "."
            + Helper::reformatDidits(Helper::itoa(tm.tv_nsec), NANO_SECOND_DIGITS));

    return Helper::join(timeString, ":");
}

/*!*****************************************************************************
@brief          現在日時を文字列として返す
@note           現在日時を、"YYYY/MM/DD HH:MM:SS.nsec"のフォーマットで返す。
@param[in]      tm    現在日時 [-] (-)
@return         std::string 現在日時を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string GetCurrentDateTimeString(struct timespec tm) {

    return (convertDateFormatToString(tm, "/") + " " + convertTimeFormatToString(tm));
}

/*!*****************************************************************************
@brief          現在日を文字列として返す
@note           現在日を、"YYYYMMDD"のフォーマットで返す。
@param[in]      tm    現在日時 [-] (-)
@return         std::string 現在日を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string GetCurrentDateString(struct timespec tm) {

    return convertDateFormatToString(tm, "");
}

/*!*****************************************************************************
@brief          現在時刻を文字列として返す
@note           現在時刻を、"HHMMSS"のフォーマットで返す。
@param[in]      tm    現在日時 [-] (-)
@return         std::string 現在時刻を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string GetCurrentTimeString(struct timespec tm) {

    const int DIGITS(2);
    std::string timeString;
    struct tm* date;
    time_t now;

    now = tm.tv_sec;
    date = localtime(&now);
    timeString += Helper::reformatDidits(Helper::itoa(date->tm_hour), DIGITS);
    timeString += Helper::reformatDidits(Helper::itoa(date->tm_min), DIGITS);
    timeString += Helper::reformatDidits(Helper::itoa(date->tm_sec), DIGITS);


    return timeString;
}
/*!*****************************************************************************
@brief          ログファイル名を作成して返す
@note           現在日を、"YYYYMMDD"のフォーマットで返す。
@param[in]      tm    現在日 [-] (-)
@param[in]      device    ファイル名の基本となる部分 [-] (-)
@return         std::string 現在時刻とファイル名を表す文字列 [-] (-)
@attention      なし
*******************************************************************************/
std::string MakeLogFileName(struct timespec tm, std::string device) {
   std::string fileName(device);
   fileName += "_";
   fileName += Helper::GetCurrentDateString(tm);
   fileName += ".log";
   return fileName;
}

namespace HelperPrivate {
    std::string eraseSpace(std::string targetString) {
        if(targetString.empty()){
            return "";
        }

        size_t firstCharactor(targetString.find_first_not_of(" "));
        if( firstCharactor == std::string::npos )
            return "";
        std::string frontSpaceDelimitedString(targetString, firstCharactor, targetString.size()-firstCharactor);

        size_t latCharactor(frontSpaceDelimitedString.find_last_not_of(" "));
        if( latCharactor == std::string::npos )
                    return "";
        std::string endSpaceDelimitedString(frontSpaceDelimitedString, 0, latCharactor+1);

        return endSpaceDelimitedString;
    }
}
}


