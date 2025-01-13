#include<test.h>
#include<Logger.h>
#include"window.h"
int main()
{
	HookBill::Logger logger(HookBill::Logger::Severity::Debug,true);
	logger.LogVerbose("Hello \n");
	logger.LogDebug("Mother\n");
	logger.LogEvent("event se\n");
	
	logger.LogError("error sex\n");
	
	HookBill::create_window();
	
}