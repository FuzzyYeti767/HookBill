#include<string>
#include<fstream>
namespace HookBill
{
	class Logger
	{
	public:
		enum class Severity
		{
			Verbose,
			Debug,
			Event,
			Error
		};
		Logger(Severity severity, bool useConsole);
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