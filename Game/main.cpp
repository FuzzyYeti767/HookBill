#include<test.h>
#include<Logger.h>
int main()
{
	HookBill::Logger logger(HookBill::Logger::Severity::Verbose,true);
	logger.LogVerbose("sex\n");
	logger.LogEvent("sex\n");
	
	logger.LogError("sex\n");
	
	logger.LogDebug("sex\n");
	
}