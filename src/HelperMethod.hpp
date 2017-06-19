/*
 *  Created on: 2015/07/30
 *      Author: CE122548
 */

#ifndef SRC_HELPERMETHOD_H_
#define SRC_HELPERMETHOD_H_

#include <iostream>

namespace Helper {

template <typename T> T deleteInstance( T instance );
template <typename T> bool hasInstance( const T instance );

/*!*****************************************************************************
@brief          インスタンスを削除する
@note           本メソッドは、インスタンスの削除時に使用する。
                  削除対象のインスタンスが既に削除済みの場合、何もしない。
                  削除されていなければインスタンスを削除する。
@param[in]      instance 削除対象インスタンス
@return         instanceのポインタ（基本、NULLが返される）
@attention      なし
@see            N/A
*******************************************************************************/
template <typename T>
T deleteInstance( T instance )
{
	if( Helper::hasInstance( instance ) )
	{
		delete instance;
		instance = NULL;
	}
	return instance;
};

/*!*****************************************************************************
@brief          配列のインスタンスを削除する
@note           本メソッドは、配列のインスタンスの削除時に使用する。
                  削除対象のインスタンスが既に削除済みの場合、何もしない。
                  削除されていなければインスタンスを削除する。
@param[in]      instance 削除対象インスタンス
@return         instanceのポインタ（基本、NULLが返される）
@attention      なし
*******************************************************************************/
template <typename T>
T deleteArrayInstance( T instance )
{
    if( Helper::hasInstance( instance ) )
    {
        delete[] instance;
        instance = NULL;
    }
    return instance;
};

/*!*****************************************************************************
@brief          ポインタがインスタンスを持っているか判定する。
@note           N/A
@param[in]　　　 instance 判定対象インスタンス
@return         判定結果（true : 持っている　　false : もっていない)
@attention      なし
*******************************************************************************/
template <typename T>
bool hasInstance( const T instance )
{
	return instance != NULL;
};

}

#endif /* SRC_HELPERMETHOD_H_ */
