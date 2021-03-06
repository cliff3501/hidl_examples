// FIXME: your file license if you have one

#define LOG_TAG "my_demo.hardware.led@1.0-impl"
#include <log/log.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "Led.h"

namespace my_demo::hardware::led::V1_0::implementation {

static const char THE_DEVICE[]="/sys/class/gpio/gpio18/value";
// Methods from ::my_demo::hardware::led::V1_0::ILed follow.

Led::Led(){
	ALOGD("%s() +++++++", __func__);
}


Led::~Led(){
	ALOGD("%s() +++++++", __func__);
}


// Methods from ::my_demo::hardware::led::V1_0::ILed follow.
Return<int32_t> Led::control(uint32_t enable) {
    char ctrl_str;
	int ret = 0;
	ALOGD("%s() ++++++++ enable=%d", __func__, enable);
	
	int fd = open(THE_DEVICE, O_RDWR);
	if(fd < 0) {
		ALOGE("open: %s", strerror(errno));
		ret = -1;
		goto err_open;
	}
	
	if(enable)
		ctrl_str = '1';
	else
		ctrl_str = '0';
	
	ALOGD("ctrl_str='%c'", ctrl_str);
	ret = write(fd, &ctrl_str, 1);
	if(ret < 0){
		ALOGD("write: %s", strerror(errno));
		ret = -1;
		goto err_write;
	}
	close(fd);
	return 0;
	
err_write:
	close(fd);
err_open:
	return int32_t {ret};
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//ILed* HIDL_FETCH_ILed(const char* /* name */) {
    //return new Led();
//}
//
}  // namespace my_demo::hardware::led::implementation
