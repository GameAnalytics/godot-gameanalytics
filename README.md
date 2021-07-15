# GameAnalytics

Official GameAnalytics SDK wrapper for NativeLib. Supported platforms: iOS, Android, MacOS.

## Installation

Add [NativeLib-UI Addon](https://godotengine.org/asset-library/asset/824) into your project. Then find `GameAnalytics` in the list of available plugins and press `Install` button.

Don't forget to enable your platforms (iOS/Android/OSX) before plugin installation.

## Usage

This plugin contain gd-wrapper `gameanalytics` which will be automatically added to your autoloading list. So you can call it everywhere in your gd code.

## API

- initGA()
- addBusinessEvent(params: Dictionary)
- addResourceEvent(params: Dictionary)
- addProgressionEvent(params: Dictionary)
- addDesignEvent(params: Dictionary)
- addErrorEvent(params: Dictionary)
- isRemoteConfigsReady() -> bool
- getRemoteConfigsContentAsString() -> String
- getRemoteConfigsValueAsString(key: String, defval: String = '') -> String

Changelog
---------
<!--(CHANGELOG_TOP)-->
**1.3.1**
* small fixes

**1.3.0**
* added distribution via nativelib for android, ios and osx

