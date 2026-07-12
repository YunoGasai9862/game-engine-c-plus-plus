#pragma once

namespace dx3d
{
	class Logger final
	{
	public:
		enum class LogLevel
		{
			Info = 0,
			Warning = 1,
			Error = 2
		};

		//to avoid implicit conversions (Logger logger = LogLevel::Error) -> Creating Logger with error log level
		explicit Logger(LogLevel logLevel = LogLevel::Error);
		void log(LogLevel level, const char* message) const;

	private:
		LogLevel m_logLevel = LogLevel::Error;
	};
}
