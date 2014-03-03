//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "syslog.hpp"

void Syslog::Log(QString Message, BottieLogType Type)
{
    QString d = QDateTime::currentDateTime().toString();
    QString message = d + "   " + Message;
    if (Type == BottieLogType_Error)
    {
        std::cerr << message.toStdString() << std::endl;
    } else
    {
        std::cout << message.toStdString() << std::endl;
    }
}

void Syslog::ErrorLog(QString Message)
{
    Log("ERROR: " + Message, BottieLogType_Error);
}

void Syslog::WarningLog(QString Message)
{
    Log("WARNING: " + Message, BottieLogType_Warn);
}

void Syslog::DebugLog(QString Message, unsigned int Verbosity)
{
    Log("DEBUG[" + QString::number(Verbosity) + "]: " + Message, BottieLogType_Debug);
}
