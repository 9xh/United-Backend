#pragma once

#include <iostream>
#include <Windows.h>
#include "settings.h"

namespace Colors
{
    int cyan = 3;
    int lightRed = 12;
    int green = 10;
    int defaultGray = 7;
}

template <typename T>
bool checkType(T msg, std::string type) // I know theres probably a function for this but idk how to code
{
    if (type == typeid(type).name()) return true;
    return false;
}

class Logs
{
public:
    static void nl() { std::cout << std::endl; }

    template <typename T>
    static void Log(T msg, int color = Colors::defaultGray, bool bNl = true, bool rainbowLog = false)
    {
        if (rainbowLog)
        {
            //bool t = RainbowLog(msg);
            //if(t) if(bNl) nl();
            return;
        }
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
        std::cout << msg;
        if (bNl) nl();
    }

    template <typename T>
    static void DebugLog(T msg, int color = Colors::defaultGray, bool bNl = true, bool rainbowLog = false)
    {
        if (!PROD) Log(msg, color, bNl, rainbowLog);
    }

    static bool RainbowLog(std::string msg) // TODO: Add support for const char etc.
    {
        /*if (!checkType(msg, "string"))
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, Colors::lightRed);
            std::cout << "[ERROR] ";
            SetConsoleTextAttribute(hConsole, Colors::defaultGray);
            std::cout << "Type was not string!";
            return false;
        } */
        int msgIndex = 0;
        for (int k = 1; k < msg.length() + 1; k++)
        {
            if (msgIndex == msg.length() + 1)
            {
                nl();
                return true;
            }
            Log(msg[msgIndex], k, false);
            msgIndex++;
            if (k == 15) k = 1;
        }
        return true;
    }
};

namespace Conversions
{
    
}