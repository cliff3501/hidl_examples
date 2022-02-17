#define LOG_TAG "my_demo.hardware.led@1.0-service"

#include <log/log.h>
#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include <my_demo/hardware/led/1.0/ILed.h>
#include "Led.h"

using my_demo::hardware::led::V1_0::ILed;
using my_demo::hardware::led::V1_0::implementation::Led;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;
using android::status_t;

int main(int, char* [])
{
	configureRpcThreadpool(1, true);
	ALOGD("prepare for my_demo.hardware.led@1.0-service");
	sp<ILed> led = new Led();
	const status_t status = led->registerAsService();
	if (status != ::android::OK)
	{
		ALOGE("Can't register service of Led");
		return 1;
	}
	
	joinRpcThreadpool();
	return 1;
}
