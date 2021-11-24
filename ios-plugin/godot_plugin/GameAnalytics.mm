#import <Foundation/Foundation.h>
#include "GameAnalytics.h"
#include "GameAnalyticsCpp.h"
#include "core/engine.h"
#define VERSION "godot 2.2.1"

GameAnalytics *GameAnalytics::instance = NULL;

GameAnalytics::GameAnalytics()
{
    ERR_FAIL_COND(instance != NULL); //<< SUCCESS!!! FIRST
    instance = this;
}

GameAnalytics *GameAnalytics::get_singleton()
{
    return instance;
}

GameAnalytics::~GameAnalytics()
{
    if (instance == this)
    {
        instance = NULL;
   }
}

void GameAnalytics::_init()
{
}

void GameAnalytics::configureAvailableCustomDimensions01(const PoolStringArray &customDimensions)
{
    GameAnalyticsCpp::configureAvailableCustomDimensions01(customDimensions);
}

void GameAnalytics::configureAvailableCustomDimensions02(const PoolStringArray &customDimensions)
{
    GameAnalyticsCpp::configureAvailableCustomDimensions02(customDimensions);
}

void GameAnalytics::configureAvailableCustomDimensions03(const PoolStringArray &customDimensions)
{
    GameAnalyticsCpp::configureAvailableCustomDimensions03(customDimensions);
}

void GameAnalytics::configureAvailableResourceCurrencies(const PoolStringArray &resourceCurrencies)
{
    GameAnalyticsCpp::configureAvailableResourceCurrencies(resourceCurrencies);
}

void GameAnalytics::configureAvailableResourceItemTypes(const PoolStringArray &resourceItemTypes)
{
    GameAnalyticsCpp::configureAvailableResourceItemTypes(resourceItemTypes);
}

void GameAnalytics::configureBuild(const String &build)
{
    GameAnalyticsCpp::configureBuild(build.utf8().get_data());
}

void GameAnalytics::configureAutoDetectAppVersion(bool flag)
{
    GameAnalyticsCpp::configureAutoDetectAppVersion(flag);
}

void GameAnalytics::configureUserId(const String &userId)
{
    GameAnalyticsCpp::configureUserId(userId.utf8().get_data());
}

void GameAnalytics::configureSdkGameEngineVersion(const String &version)
{
    GameAnalyticsCpp::configureSdkGameEngineVersion(version.utf8().get_data());
}

void GameAnalytics::configureGameEngineVersion(const String &version)
{
    GameAnalyticsCpp::configureGameEngineVersion(version.utf8().get_data());
}

void GameAnalytics::init(const String &gameKey, const String &secretKey)
{
    NSLog(@"Game key: %s", gameKey.utf8().get_data());
    NSLog(@"Secret key: %s", secretKey.utf8().get_data());
    Dictionary versionInfo = Engine::get_singleton()->get_version_info();
    String major = versionInfo["major"];
    String minor = versionInfo["minor"];
    String patch = versionInfo["patch"];
    String engineVersion = "godot " + major + "." + minor + "." + patch;
    GameAnalyticsCpp::configureGameEngineVersion(engineVersion.utf8().get_data());
    GameAnalyticsCpp::configureSdkGameEngineVersion(VERSION);
    GameAnalyticsCpp::initialize(gameKey.utf8().get_data(), secretKey.utf8().get_data());
}

void GameAnalytics::addBusinessEvent(const Dictionary &options)
{
    String currency = "";
    int amount = 0;
    String itemType = "";
    String itemId = "";
    String cartType = "";
    String receipt = "";
    bool autoFetchReceipt = false;
    String fields = "{}";

    Array keys = options.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        String key = keys[i];

        if(key == "currency")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                currency = v;
            }
        }
        else if(key == "amount")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::INT)
            {
                amount = v;
            }
        }
        else if(key == "itemType")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                itemType = v;
            }
        }
        else if(key == "itemId")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                itemId = v;
            }
        }
        else if(key == "cartType")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                cartType = v;
            }
        }
        else if(key == "receipt")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                receipt = v;
            }
        }
        else if(key == "autoFetchReceipt")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::BOOL)
            {
                autoFetchReceipt = v;
            }
        }
        else if (key == "customFields")
        {
            const Variant *v = options.getptr(key);
            if (v != NULL && v->get_type() == Variant::Type::STRING)
            {
                fields = *v;
            }
        }
    }
    if(autoFetchReceipt)
    {
        GameAnalyticsCpp::addBusinessEventAndAutoFetchReceipt(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), fields.utf8().get_data());
    }
    else
    {
        GameAnalyticsCpp::addBusinessEvent(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), receipt.utf8().get_data(), fields.utf8().get_data());
    }
}

void GameAnalytics::addResourceEvent(const Dictionary &options)
{
    int flowType = 0;
    String currency = "";
    float amount = 0;
    String itemType = "";
    String itemId = "";
    String fields = "{}";

    Array keys = options.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        String key = keys[i];

        if(key == "flowType")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                String s = v;
                if(s == "Source")
                {
                    flowType = 1;
                }
                else if(s == "Sink")
                {
                    flowType = 2;
                }
            }
        }
        else if(key == "currency")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                currency = v;
            }
        }
        else if(key == "amount")
        {
            const Variant& v = options[key];
            if((v.get_type() == Variant::Type::INT || v.get_type() == Variant::Type::REAL))
            {
                amount = v;
            }
        }
        else if(key == "itemType")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                itemType = v;
            }
        }
        else if(key == "itemId")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                itemId = v;
            }
        }
        else if (key == "customFields")
        {
            const Variant *v = options.getptr(key);
            if (v != NULL && v->get_type() == Variant::Type::STRING)
            {
                fields = *v;
            }
        }
    }
    GameAnalyticsCpp::addResourceEvent(flowType, currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), fields.utf8().get_data());
}

void GameAnalytics::addProgressionEvent(const Dictionary &options)
{
    int progressionStatus = 0;
    String progression01 = "";
    String progression02 = "";
    String progression03 = "";
    int score = 0;
    bool sendScore = false;
    String fields = "{}";

    Array keys = options.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        String key = keys[i];

        if(key == "progressionStatus")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                String s = v;
                if(s == "Start")
                {
                    progressionStatus = 1;
                }
                else if(s == "Complete")
                {
                    progressionStatus = 2;
                }
                else if(s == "Fail")
                {
                    progressionStatus = 3;
                }
            }
        }
        else if(key == "progression01")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                progression01 = v;
            }
        }
        else if(key == "progression02")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                progression02 = v;
            }
        }
        else if(key == "progression03")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                progression03 = v;
            }
        }
        else if(key == "score")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::INT)
            {
                score = v;
                sendScore = true;
            }
        }
        else if (key == "customFields")
        {
            const Variant *v = options.getptr(key);
            if (v != NULL && v->get_type() == Variant::Type::STRING)
            {
                fields = *v;
            }
        }
    }
    if(sendScore)
    {
        GameAnalyticsCpp::addProgressionEventWithScore(progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), score, fields.utf8().get_data());
    }
    else
    {
        GameAnalyticsCpp::addProgressionEvent(progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), fields.utf8().get_data());
    }
}

void GameAnalytics::addDesignEvent(const Dictionary &options)
{
    String eventId = "";
    float value = 0;
    bool sendValue = false;
    String fields = "{}";

    Array keys = options.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        String key = keys[i];

        if(key == "eventId")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                eventId = v;
            }
        }
        else if(key == "value")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::INT || v.get_type() == Variant::Type::REAL)
            {
                value = v;
                sendValue = true;
            }
        }
        else if (key == "customFields")
        {
            const Variant *v = options.getptr(key);
            if (v != NULL && v->get_type() == Variant::Type::STRING)
            {
                fields = *v;
            }
        }
    }
    if(sendValue)
    {
        GameAnalyticsCpp::addDesignEventWithValue(eventId.utf8().get_data(), value, fields.utf8().get_data());
    }
    else
    {
        GameAnalyticsCpp::addDesignEvent(eventId.utf8().get_data(), fields.utf8().get_data());
    }
}

void GameAnalytics::addErrorEvent(const Dictionary &options)
{
    int severity = 0;
    String message = "";
    String fields = "{}";

    Array keys = options.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        String key = keys[i];

        if(key == "severity")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                String s = v;
                if(s == "Debug")
                {
                    severity = 1;
                }
                else if(s == "Info")
                {
                    severity = 2;
                }
                else if(s == "Warning")
                {
                    severity = 3;
                }
                else if(s == "Error")
                {
                    severity = 4;
                }
                else if(s == "Critical")
                {
                    severity = 5;
                }
            }
        }
        else if(key == "message")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                message = v;
            }
        }
        else if (key == "customFields")
        {
            const Variant *v = options.getptr(key);
            if (v != NULL && v->get_type() == Variant::Type::STRING)
            {
                fields = *v;
            }
        }
    }
    GameAnalyticsCpp::addErrorEvent(severity, message.utf8().get_data(), fields.utf8().get_data());
}

void GameAnalytics::setEnabledInfoLog(bool flag)
{
    GameAnalyticsCpp::setEnabledInfoLog(flag);
}

void GameAnalytics::setEnabledVerboseLog(bool flag)
{
    GameAnalyticsCpp::setEnabledVerboseLog(flag);
}

void GameAnalytics::setEnabledManualSessionHandling(bool flag)
{
    GameAnalyticsCpp::setEnabledManualSessionHandling(flag);
}

void GameAnalytics::setEnabledErrorReporting(bool flag)
{
    GameAnalyticsCpp::setEnabledErrorReporting(flag);
}

void GameAnalytics::setEnabledEventSubmission(bool flag)
{
    GameAnalyticsCpp::setEnabledEventSubmission(flag);
}

void GameAnalytics::setCustomDimension01(const String &dimension)
{
    GameAnalyticsCpp::setCustomDimension01(dimension.utf8().get_data());
}

void GameAnalytics::setCustomDimension02(const String &dimension)
{
    GameAnalyticsCpp::setCustomDimension02(dimension.utf8().get_data());
}

void GameAnalytics::setCustomDimension03(const String &dimension)
{
    GameAnalyticsCpp::setCustomDimension03(dimension.utf8().get_data());
}

void GameAnalytics::startSession()
{
    GameAnalyticsCpp::startSession();
}

void GameAnalytics::endSession()
{
    GameAnalyticsCpp::endSession();
}

void GameAnalytics::onQuit()
{
    // Do nothing
}

String GameAnalytics::getRemoteConfigsValueAsString(const Dictionary &options)
{
    String k = "";
    String defaultValue = "";
    bool useDefaultValue = false;
    Array keys = options.keys();
    for (int i = 0; i < keys.size(); ++i)
    {
        String key = keys[i];

        if(key == "key")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                k = v;
            }
        }
        else if(key == "defaultValue")
        {
            const Variant& v = options[key];
            if(v.get_type() == Variant::Type::STRING)
            {
                defaultValue = v;
                useDefaultValue = true;
            }
        }
    }
    if(useDefaultValue)
    {
        return GameAnalyticsCpp::getRemoteConfigsValueAsString(k.utf8().get_data(), defaultValue.utf8().get_data());
    }
    else
    {
        return GameAnalyticsCpp::getRemoteConfigsValueAsString(k.utf8().get_data());
    }
}

bool GameAnalytics::isRemoteConfigsReady()
{
    return GameAnalyticsCpp::isRemoteConfigsReady();
}

String GameAnalytics::getRemoteConfigsContentAsString()
{
    return GameAnalyticsCpp::getRemoteConfigsContentAsString();
}

void GameAnalytics::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("configureAvailableCustomDimensions01", "customDimensions"), &GameAnalytics::configureAvailableCustomDimensions01);
    ClassDB::bind_method(D_METHOD("configureAvailableCustomDimensions02", "customDimensions"), &GameAnalytics::configureAvailableCustomDimensions02);
    ClassDB::bind_method(D_METHOD("configureAvailableCustomDimensions03", "customDimensions"), &GameAnalytics::configureAvailableCustomDimensions03);

    ClassDB::bind_method(D_METHOD("configureAvailableResourceCurrencies", "resourceCurrencies"), &GameAnalytics::configureAvailableResourceCurrencies);
    ClassDB::bind_method(D_METHOD("configureAvailableResourceItemTypes", "resourceItemTypes"), &GameAnalytics::configureAvailableResourceItemTypes);

    ClassDB::bind_method(D_METHOD("configureBuild", "build"), &GameAnalytics::configureBuild);
    ClassDB::bind_method(D_METHOD("configureAutoDetectAppVersion", "flag"), &GameAnalytics::configureAutoDetectAppVersion);
    ClassDB::bind_method(D_METHOD("configureUserId", "userId"), &GameAnalytics::configureUserId);

    ClassDB::bind_method(D_METHOD("init", "gameKey", "secretKey"), &GameAnalytics::init);

    ClassDB::bind_method(D_METHOD("addBusinessEvent", "options"), &GameAnalytics::addBusinessEvent);
    ClassDB::bind_method(D_METHOD("addResourceEvent", "options"), &GameAnalytics::addResourceEvent);
    ClassDB::bind_method(D_METHOD("addProgressionEvent", "options"), &GameAnalytics::addProgressionEvent);
    ClassDB::bind_method(D_METHOD("addDesignEvent", "options"), &GameAnalytics::addDesignEvent);
    ClassDB::bind_method(D_METHOD("addErrorEvent", "options"), &GameAnalytics::addErrorEvent);

    ClassDB::bind_method(D_METHOD("setEnabledInfoLog", "flag"), &GameAnalytics::setEnabledInfoLog);
    ClassDB::bind_method(D_METHOD("setEnabledVerboseLog", "flag"), &GameAnalytics::setEnabledVerboseLog);
    ClassDB::bind_method(D_METHOD("setEnabledManualSessionHandling", "flag"), &GameAnalytics::setEnabledManualSessionHandling);
    ClassDB::bind_method(D_METHOD("setEnabledErrorReporting", "flag"), &GameAnalytics::setEnabledErrorReporting);
    ClassDB::bind_method(D_METHOD("setEnabledEventSubmission", "flag"), &GameAnalytics::setEnabledEventSubmission);

    ClassDB::bind_method(D_METHOD("setCustomDimension01", "dimension"), &GameAnalytics::setCustomDimension01);
    ClassDB::bind_method(D_METHOD("setCustomDimension02", "dimension"), &GameAnalytics::setCustomDimension02);
    ClassDB::bind_method(D_METHOD("setCustomDimension03", "dimension"), &GameAnalytics::setCustomDimension03);

    ClassDB::bind_method(D_METHOD("startSession"), &GameAnalytics::startSession);
    ClassDB::bind_method(D_METHOD("endSession"), &GameAnalytics::endSession);
    ClassDB::bind_method(D_METHOD("onQuit"), &GameAnalytics::onQuit);

    ClassDB::bind_method(D_METHOD("getRemoteConfigsValueAsString", "options"), &GameAnalytics::getRemoteConfigsValueAsString);
    ClassDB::bind_method(D_METHOD("isRemoteConfigsReady"), &GameAnalytics::isRemoteConfigsReady);
    ClassDB::bind_method(D_METHOD("getRemoteConfigsContentAsString"), &GameAnalytics::getRemoteConfigsContentAsString);
}





NSDictionary *convertFromDictionary(const Dictionary& dict)
{
    NSMutableDictionary *result = [NSMutableDictionary new];
    for(int i=0; i<dict.keys().size(); i++) {
        Variant key = dict.keys()[i];
        Variant val = dict[key];
        if(key.get_type() == Variant::STRING) {
            String skey = key;
            NSString *strKey = [NSString stringWithUTF8String:skey.utf8().get_data()];
            if(val.get_type() == Variant::INT) {
                int i = (int)val;
                result[strKey] = @(i);
            } else if(val.get_type() == Variant::REAL) {
                double d = (double)val;
                result[strKey] = @(d);
            } else if(val.get_type() == Variant::STRING) {
                String sval = val;
                NSString *s = [NSString stringWithUTF8String:sval.utf8().get_data()];
                result[strKey] = s;
            } else if(val.get_type() == Variant::BOOL) {
                BOOL b = (bool)val;
                result[strKey] = @(b);
            } else if(val.get_type() == Variant::DICTIONARY) {
                NSDictionary *d = convertFromDictionary((Dictionary)val);
                result[strKey] = d;
            } else {
                ERR_PRINT("Unexpected type as dictionary value");
            }
        } else {
            ERR_PRINT("Non string key in Dictionary");
        }
    }
    return result;
}
