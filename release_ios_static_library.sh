#!/bin/bash

PLUGIN="gameanalytics"

# Compile Plugin
./generate_ios_static_library.sh release $1
./generate_ios_static_library.sh release_debug $1
mv ./bin/${PLUGIN}.release_debug.a ./bin/${PLUGIN}.debug.a

# Move to release folder

rm -rf ./bin/release
mkdir ./bin/release

# Move Plugin
mv ./bin/${PLUGIN}.{release,debug}.a ./bin/release
cp ./bin/release/* ./ios/lib
