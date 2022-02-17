// FIXME: your file license if you have one

#pragma once

#include <my_demo/hardware/led/1.0/ILed.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace my_demo::hardware::led::V1_0::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Led : public V1_0::ILed {
    // Methods from ::android::hardware::led::V1_0::ILed follow.
	Led();
	~Led();
    Return<int32_t> control(uint32_t enable) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IDemo* HIDL_FETCH_IDemo(const char* name);

}  // namespace android::hardware::demo::implementation
