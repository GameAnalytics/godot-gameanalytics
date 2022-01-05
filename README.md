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
**2.2.2**
* added error events to be sent for invalid custom event fields used
* added optional mergeFields argument to event methods to merge with global custom fields instead of overwrite them

**2.2.1**
* fixed missing custom event fields for when trying to fix missing session end events

**2.2.0**
* added global custom event fields function to allow to add custom fields to events sent automatically by the SDK

**2.1.1**
* added functionality to force a new user in a/b testing without having to uninstall app first, simply use custom user id function to set a new user id which hasn't been used yet

**2.1.0**
* added custom event fields feature

**2.1.0**
* added custom event fields feature

**2.0.0**
* Changed user identifier logic in preparation for Google changes to GAID. User id for a new install is now a randomised GUID. Existing installs that update SDK will continue using previous identifier logic. It is recommended to update as soon as possible to reduce impact on calculated metrics.

**1.3.6**
* small fix

**1.3.5**
* republished plugin on NativeLib due to malformed urls

**1.3.4**
* ios nativelib fixes

**1.3.3**
* fixed ios nativelib errors

**1.3.1**
* small fixes

**1.3.0**
* added distribution via nativelib for android, ios and osx

