/**
	@file      Logger.h
	@brief     Logger class for logging messages to console and file.
	@details   Logger class provides methods to log messages with different severity levels.
			   It can log messages to both console and a file, depending on the configuration.
	@author    Cool Guy
	@date      17.06.2025
	@copyright © Cool Guy, 2025. All right reserved.
**/
#pragma once
#include <string>
#include <fstream>

namespace HookBill
{
	/**
		@class   Logger
		@brief   Logger class for logging messages to console and file.
		@details Logger class provides methods to log messages with different severity levels.
				 It can log messages to both console and a file,

	**/
	class Logger
	{
	public:
		/**
		 * @enum Severity
		 * @brief Enumeration for log severity levels.
		 */
		enum class Severity
		{
			Verbose,
			Debug,
			Event,
			Error
		};

		/**
		 @brief Logger object constructor
		 @param severity   - set Severity of log message
		 @param useConsole - if value is true use console else log message on txt file
		**/
		Logger(Severity severity, bool useConsole);

		/**
			@brief Logger object destructor
		**/
		~Logger();

		
		void LogError(std::string text);
		void LogEvent(std::string text);
		void LogDebug(std::string text);
		void LogVerbose(std::string text);

	private:
		std::ofstream outStream;
		Severity minLevel;
	};

}