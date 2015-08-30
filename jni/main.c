#include <android/log.h>
#include <sys/prctl.h>

#define LOG_INFO (3)
#define LOGTAG "CrashAndBurn"

__attribute__((constructor)) void bootstrap() {

	__android_log_print(LOG_INFO, LOGTAG, "Making process dumpable");
	int res = prctl(PR_SET_DUMPABLE, 1, 0, 0, 0);
	__android_log_print(LOG_INFO, LOGTAG, "Result: %d", res);	

}
