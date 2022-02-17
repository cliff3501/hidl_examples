#!/bin/bash

set -e

if [ ! -d $ANDROID_BUILD_TOP/hardware/interfaces/demo ] ; then
 echo "Where is demo/interfaces?";
 exit 1;
fi

if [ ! -d $ANDROID_BUILD_TOP/system/libhidl/transport ] ; then
 echo "Where is system/libhidl/transport?"
 exit 1;
fi

PACKAGE=android.hardware.demo@1.0
LOC=$ANDROID_BUILD_TOP/hardware/interfaces/demo/1.0/default/
options="-randroid.hardware:hardware/interfaces -randroid.hidl:system/libhidl/transport"

hidl-gen -o $LOC -Lc++-impl $options $PACKAGE

hidl-gen -o $LOC -Landroidbp-impl $options $PACKAGE

echo done!
