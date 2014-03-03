//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef SYSLOG_HPP
#define SYSLOG_HPP

#include <iostream>
#include <QDateTime>
#include <QStringList>

enum BottieLogType
{
    BottieLogType_Normal,
    BottieLogType_Error,
    BottieLogType_Debug,
    BottieLogType_Warn
};

//! Line of log
class BottieLog_Line
{
    public:
        BottieLog_Line(BottieLog_Line *line);
        BottieLog_Line(const BottieLog_Line &line);
        BottieLog_Line(QString text, QString date);
        QString Text;
        QString Date;
        BottieLogType Type;
};

//! Provides a logging to various places
class Syslog
{
    public:
        //! Write text to terminal as well as ring log
        /*!
             * \param Message Message to log
             */
        static void Log(QString Message, BottieLogType Type = BottieLogType_Normal);
        static void ErrorLog(QString Message);
        static void WarningLog(QString Message);
        //! This log is only shown if verbosity is same or larger than requested verbosity
        static void DebugLog(QString Message, unsigned int Verbosity = 1);
};

#endif // SYSLOG_HPP
