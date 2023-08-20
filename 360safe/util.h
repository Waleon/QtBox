/*
	工具类

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/


#ifndef UTIL_H
#define UTIL_H

#include <QSettings>
#include <QFontMetrics>
#include "common.h"

class Util
{

public:

	static bool writeInit(QString path, QString user_key, QString user_value);
	static bool readInit(QString path, QString user_key, QString &user_value);
	static bool updateText(QString text, int max_width, QString &elided_text);
	static QString getSkinName();

};

#endif
