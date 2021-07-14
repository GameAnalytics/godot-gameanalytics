#!/bin/bash

# Compile static libraries
PLUGIN='gameanalytics'

# ARM64 Device
scons target=$1 arch=arm64 version=$2
# ARM7 Device
scons target=$1 arch=armv7 version=$2
# x86_64 Simulator
scons target=$1 arch=x86_64 simulator=yes version=$2

# Creating a fat libraries for device and simulator
# lib<plugin>.<arch>-<simulator|iphone>.<release|debug|release_debug>.a
lipo -create "./bin/lib${PLUGIN}.x86_64-simulator.$1.a" \
    "./bin/lib${PLUGIN}.armv7-iphone.$1.a" \
    "./bin/lib${PLUGIN}.arm64-iphone.$1.a" \
    -output "./bin/${PLUGIN}.$1.a"
