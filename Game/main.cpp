#include<test.h>
#include<Logger.h>
int main()
{
	HookBill::Logger logger(HookBill::Logger::Severity::Debug,true);
	logger.LogVerbose("verbose sex\n");
	logger.LogDebug("debug sex\n");
	logger.LogEvent("event sex\n");
	
	logger.LogError("error sex\n");
	
	
	
}