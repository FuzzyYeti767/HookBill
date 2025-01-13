#include <iostream>    // cout.rdbuf
#include "Logger.h"
#include<spdlog/spdlog.h>
HookBill::Logger::Logger(Logger::Severity severity, bool useConsole) : minLevel(severity), outStream("Trace.log")
{
	spdlog::set_level(static_cast<spdlog::level::level_enum>(severity));
	//spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
	if (useConsole == true) {
		outStream.set_rdbuf(std::cout.rdbuf());
	}
}

HookBill::Logger::~Logger() {
	outStream.flush();
	outStream.close();
}

void HookBill::Logger::LogError(std::string text)
{
	spdlog::error(text);
}

void HookBill::Logger::LogEvent(std::string text)
{
	spdlog::info(text);
}

void HookBill::Logger::LogDebug(std::string text)
{
	spdlog::debug(text);
}

void HookBill::Logger::LogVerbose(std::string text)
{
	spdlog::trace(text);
}






