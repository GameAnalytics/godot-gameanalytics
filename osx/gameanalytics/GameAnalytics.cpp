#include "GameAnalytics.h"
#include <Engine.hpp>

#if __EMSCRIPTEN__
#define WEB_PLATFORM
#include "api/javascript_eval.h"
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
#define IOS_PLATFORM
#include "ios/src/GameAnalyticsCpp.h"
#else
#define OSX_PLATFORM
#include "cpp/GameAnalytics.h"
#endif
#elif defined(_WIN32) || defined(WIN32)
#define WINDOWS_PLATFORM
#include "cpp/GameAnalytics.h"
#elif defined(__linux__) || defined(__unix__) || defined(__unix) || defined(unix)
#define LINUX_PLATFORM
#include "cpp/GameAnalytics.h"
#endif

#define VERSION "godot 2.3.5"

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

void GameAnalytics::configureAvailableCustomDimensions01(const PoolStringArray &customDimensions)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureAvailableCustomDimensions01(customDimensions);
#elif defined(WEB_PLATFORM)
    String arrayString = "";
    if (customDimensions.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < customDimensions.size(); ++i)
        {
            String entry = customDimensions.read()[i];
            if (i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureAvailableCustomDimensions01(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    String arrayString = "";

    if(customDimensions.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < customDimensions.size(); ++i)
        {
            String entry = customDimensions.read()[i];
            if(i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    gameanalytics::GameAnalytics::configureAvailableCustomDimensions01(arrayString.utf8().get_data());
#endif
}

void GameAnalytics::configureAvailableCustomDimensions02(const PoolStringArray &customDimensions)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureAvailableCustomDimensions02(customDimensions);
#elif defined(WEB_PLATFORM)
    String arrayString = "";
    if (customDimensions.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < customDimensions.size(); ++i)
        {
            String entry = customDimensions.read()[i];
            if (i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureAvailableCustomDimensions02(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    String arrayString = "";

    if(customDimensions.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < customDimensions.size(); ++i)
        {
            String entry = customDimensions.read()[i];
            if(i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    gameanalytics::GameAnalytics::configureAvailableCustomDimensions02(arrayString.utf8().get_data());
#endif
}

void GameAnalytics::configureAvailableCustomDimensions03(const PoolStringArray &customDimensions)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureAvailableCustomDimensions03(customDimensions);
#elif defined(WEB_PLATFORM)
    String arrayString = "";
    if (customDimensions.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < customDimensions.size(); ++i)
        {
            String entry = customDimensions.read()[i];
            if (i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureAvailableCustomDimensions03(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    String arrayString = "";

    if(customDimensions.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < customDimensions.size(); ++i)
        {
            String entry = customDimensions.read()[i];
            if(i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    gameanalytics::GameAnalytics::configureAvailableCustomDimensions03(arrayString.utf8().get_data());
#endif
}

void GameAnalytics::configureAvailableResourceCurrencies(const PoolStringArray &resourceCurrencies)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureAvailableResourceCurrencies(resourceCurrencies);
#elif defined(WEB_PLATFORM)
    String arrayString = "";
    if (resourceCurrencies.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < resourceCurrencies.size(); ++i)
        {
            String entry = resourceCurrencies.read()[i];
            if (i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureAvailableResourceCurrencies(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    String arrayString = "";

    if(resourceCurrencies.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < resourceCurrencies.size(); ++i)
        {
            String entry = resourceCurrencies.read()[i];
            if(i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    gameanalytics::GameAnalytics::configureAvailableResourceCurrencies(arrayString.utf8().get_data());
#endif
}

void GameAnalytics::configureAvailableResourceItemTypes(const PoolStringArray &resourceItemTypes)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureAvailableResourceItemTypes(resourceItemTypes);
#elif defined(WEB_PLATFORM)
    String arrayString = "";
    if (resourceItemTypes.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < resourceItemTypes.size(); ++i)
        {
            String entry = resourceItemTypes.read()[i];
            if (i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureAvailableResourceItemTypes(JSON.parse('" + arrayString + "'))");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    String arrayString = "";

    if(resourceItemTypes.size() > 0)
    {
        arrayString += "[\"";
        for (int i = 0; i < resourceItemTypes.size(); ++i)
        {
            String entry = resourceItemTypes.read()[i];
            if(i > 0)
            {
                arrayString += "\",\"";
            }
            arrayString += entry;
        }
        arrayString += "\"]";
    }
    else
    {
        arrayString = "[]";
    }
    gameanalytics::GameAnalytics::configureAvailableResourceItemTypes(arrayString.utf8().get_data());
#endif
}

void GameAnalytics::configureBuild(const String &build)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureBuild(build.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureBuild('" + build + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::configureBuild(build.utf8().get_data());
#endif
}

void GameAnalytics::configureAutoDetectAppVersion(bool flag)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureAutoDetectAppVersion(flag);
#elif defined(WEB_PLATFORM)
    // TODO: add implementation
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    // Do nothing
#endif
}

void GameAnalytics::configureUserId(const String &userId)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureUserId(userId.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureBuild('" + userId + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::configureUserId(userId.utf8().get_data());
#endif
}

void GameAnalytics::configureSdkGameEngineVersion(const String &version)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureSdkGameEngineVersion(version.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureSdkGameEngineVersion('" + version + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::configureSdkGameEngineVersion(version.utf8().get_data());
#endif
}

void GameAnalytics::configureGameEngineVersion(const String &version)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureGameEngineVersion(version.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.configureGameEngineVersion('" + version + "')");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::configureGameEngineVersion(version.utf8().get_data());
#endif
}

void GameAnalytics::init(const String &gameKey, const String &secretKey)
{
    Dictionary versionInfo = Engine::get_singleton()->get_version_info();
    String major = versionInfo["major"];
    String minor = versionInfo["minor"];
    String patch = versionInfo["patch"];
    String engineVersion = "godot " + major + "." + minor + "." + patch;
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::configureGameEngineVersion(engineVersion.utf8().get_data());
    GameAnalyticsCpp::configureSdkGameEngineVersion(VERSION);
    GameAnalyticsCpp::initialize(gameKey.utf8().get_data(), secretKey.utf8().get_data());
#elif defined(WEB_PLATFORM)
    configureGameEngineVersion(engineVersion);
    configureSdkGameEngineVersion(VERSION);
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.initialize('%s', '%s')", gameKey, secretKey));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::configureGameEngineVersion(engineVersion.utf8().get_data());
    gameanalytics::GameAnalytics::configureSdkGameEngineVersion(VERSION);
    gameanalytics::GameAnalytics::initialize(gameKey.utf8().get_data(), secretKey.utf8().get_data());
#endif
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
#if defined(IOS_PLATFORM)
    if(autoFetchReceipt)
    {
        GameAnalyticsCpp::addBusinessEventAndAutoFetchReceipt(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), fields.utf8().get_data());
    }
    else
    {
        GameAnalyticsCpp::addBusinessEvent(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), receipt.utf8().get_data(), fields.utf8().get_data());
    }
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addBusinessEvent('%s', %d, '%s', '%s', '%s', JSON.parse('%s'))", currency, amount, itemType, itemId, cartType, fields));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::addBusinessEvent(currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), cartType.utf8().get_data(), fields.utf8().get_data());
#endif
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
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::addResourceEvent(flowType, currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), fields.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addResourceEvent(%d, '%s', %f, '%s', '%s', JSON.parse('%s'))", flowType, currency, amount, itemType, itemId, fields));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::addResourceEvent((gameanalytics::EGAResourceFlowType)flowType, currency.utf8().get_data(), amount, itemType.utf8().get_data(), itemId.utf8().get_data(), fields.utf8().get_data());
#endif
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
#if defined(IOS_PLATFORM)
    if(sendScore)
    {
        GameAnalyticsCpp::addProgressionEventWithScore(progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), score, fields.utf8().get_data());
    }
    else
    {
        GameAnalyticsCpp::addProgressionEvent(progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), fields.utf8().get_data());
    }
#elif defined(WEB_PLATFORM)
    if (sendScore)
    {
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addProgressionEvent(%d, '%s', '%s', '%s', %d, JSON.parse('%s'))", progressionStatus, progression01, progression02, progression03, score, fields));
    }
    else
    {
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addProgressionEvent(%d, '%s', '%s', '%s', JSON.parse('%s'))", progressionStatus, progression01, progression02, progression03, fields));
    }
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    if(sendScore)
    {
        gameanalytics::GameAnalytics::addProgressionEvent((gameanalytics::EGAProgressionStatus)progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), score, fields.utf8().get_data());
    }
    else
    {
        gameanalytics::GameAnalytics::addProgressionEvent((gameanalytics::EGAProgressionStatus)progressionStatus, progression01.utf8().get_data(), progression02.utf8().get_data(), progression03.utf8().get_data(), fields.utf8().get_data());
    }
#endif
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
            if((v.get_type() == Variant::Type::INT || v.get_type() == Variant::Type::REAL))
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
#if defined(IOS_PLATFORM)
    if(sendValue)
    {
        GameAnalyticsCpp::addDesignEvent(eventId.utf8().get_data(), value, fields.utf8().get_data());
    }
    else
    {
        GameAnalyticsCpp::addDesignEvent(eventId.utf8().get_data(), fields.utf8().get_data());
    }
#elif defined(WEB_PLATFORM)
    if (sendValue)
    {
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addDesignEvent('%s', %f, JSON.parse('%s'))", eventId, value, fields));
    }
    else
    {
        JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addDesignEvent('%s', JSON.parse('%s'))", eventId, fields));
    }
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    if(sendValue)
    {
        gameanalytics::GameAnalytics::addDesignEvent(eventId.utf8().get_data(), value, fields.utf8().get_data());
    }
    else
    {
        gameanalytics::GameAnalytics::addDesignEvent(eventId.utf8().get_data(), fields.utf8().get_data());
    }
#endif
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
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::addErrorEvent(severity, message.utf8().get_data(), fields.utf8().get_data()));
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.addErrorEvent(%d, '%s', JSON.parse('%s'))", severity, message, fields));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::addErrorEvent((gameanalytics::EGAErrorSeverity)severity, message.utf8().get_data(), fields.utf8().get_data()));
#endif
}

void GameAnalytics::setEnabledInfoLog(bool flag)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setEnabledInfoLog(flag);
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setEnabledInfoLog(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setEnabledInfoLog(flag);
#endif
}

void GameAnalytics::setEnabledVerboseLog(bool flag)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setEnabledVerboseLog(flag);
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setEnabledVerboseLog(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setEnabledVerboseLog(flag);
#endif
}

void GameAnalytics::setEnabledManualSessionHandling(bool flag)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setEnabledManualSessionHandling(flag);
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setEnabledManualSessionHandling(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setEnabledManualSessionHandling(flag);
#endif
}

void GameAnalytics::setEnabledErrorReporting(bool flag)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setEnabledErrorReporting(flag);
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setEnabledErrorReporting(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setEnabledErrorReporting(flag);
#endif
}

void GameAnalytics::setEnabledEventSubmission(bool flag)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setEnabledEventSubmission(flag);
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setEnabledEventSubmission(%s)", flag ? "true" : "false"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setEnabledEventSubmission(flag);
#endif
}

void GameAnalytics::setCustomDimension01(const String &dimension)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setCustomDimension01(dimension.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setCustomDimension01('%s')", dimension));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setCustomDimension01(dimension.utf8().get_data());
#endif
}

void GameAnalytics::setCustomDimension02(const String &dimension)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setCustomDimension02(dimension.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setCustomDimension02('%s')", dimension));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setCustomDimension02(dimension.utf8().get_data());
#endif
}

void GameAnalytics::setCustomDimension03(const String &dimension)
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::setCustomDimension03(dimension.utf8().get_data());
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.setCustomDimension03('%s')", dimension));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::setCustomDimension03(dimension.utf8().get_data());
#endif
}

void GameAnalytics::startSession()
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::startSession();
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.startSession()");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    // Do nothing
#endif
}

void GameAnalytics::endSession()
{
#if defined(IOS_PLATFORM)
    GameAnalyticsCpp::endSession();
#elif defined(WEB_PLATFORM)
    JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.endSession()");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    // Do nothing
#endif
}

void GameAnalytics::onQuit()
{
#if defined(IOS_PLATFORM)
    // Do nothing
#elif defined(WEB_PLATFORM)
    // Do nothing
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    gameanalytics::GameAnalytics::onQuit();
#endif
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
#if defined(IOS_PLATFORM)
    if(useDefaultValue)
    {
        return GameAnalyticsCpp::getRemoteConfigsValueAsString(k.utf8().get_data(), defaultValue.utf8().get_data());
    }
    else
    {
        return GameAnalyticsCpp::getRemoteConfigsValueAsString(k.utf8().get_data());
    }
#elif defined(WEB_PLATFORM)
    if (useDefaultValue)
    {
        return String(JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.getRemoteConfigsValueAsString('%s', '%s')", k, defaultValue)));
    }
    else
    {
        return String(JavaScript::get_singleton()->eval(vformat("gameanalytics.GameAnalytics.getRemoteConfigsValueAsString('%s')", k)));
    }
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    if(useDefaultValue)
    {
        return String(gameanalytics::GameAnalytics::getRemoteConfigsValueAsString(k.utf8().get_data(), defaultValue.utf8().get_data()).data());
    }
    else
    {
        return String(gameanalytics::GameAnalytics::getRemoteConfigsValueAsString(k.utf8().get_data()).data());
    }
#endif
}

bool GameAnalytics::isRemoteConfigsReady()
{
#if defined(IOS_PLATFORM)
    return GameAnalyticsCpp::isRemoteConfigsReady();
#elif defined(WEB_PLATFORM)
    return JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.isRemoteConfigsReady()");
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    return gameanalytics::GameAnalytics::isRemoteConfigsReady();
#endif
}

String GameAnalytics::getRemoteConfigsContentAsString()
{
#if defined(IOS_PLATFORM)
    return GameAnalyticsCpp::getRemoteConfigsContentAsString();
#elif defined(WEB_PLATFORM)
    return String(JavaScript::get_singleton()->eval("gameanalytics.GameAnalytics.getRemoteConfigsContentAsString()"));
#elif defined(OSX_PLATFORM) || defined(WINDOWS_PLATFORM) || defined(LINUX_PLATFORM)
    return String(gameanalytics::GameAnalytics::getRemoteConfigsContentAsString().data());
#endif
}

void GameAnalytics::_register_methods()
{
    register_method("configureAvailableCustomDimensions01", &GameAnalytics::configureAvailableCustomDimensions01);
    register_method("configureAvailableCustomDimensions02", &GameAnalytics::configureAvailableCustomDimensions02);
    register_method("configureAvailableCustomDimensions03", &GameAnalytics::configureAvailableCustomDimensions03);

    register_method("configureAvailableResourceCurrencies", &GameAnalytics::configureAvailableResourceCurrencies);
    register_method("configureAvailableResourceItemTypes", &GameAnalytics::configureAvailableResourceItemTypes);

    register_method("configureBuild", &GameAnalytics::configureBuild);
    register_method("configureAutoDetectAppVersion", &GameAnalytics::configureAutoDetectAppVersion);
    register_method("configureUserId", &GameAnalytics::configureUserId);

    register_method("init", &GameAnalytics::init);

    register_method("addBusinessEvent", &GameAnalytics::addBusinessEvent);
    register_method("addResourceEvent", &GameAnalytics::addResourceEvent);
    register_method("addProgressionEvent", &GameAnalytics::addProgressionEvent);
    register_method("addDesignEvent", &GameAnalytics::addDesignEvent);
    register_method("addErrorEvent", &GameAnalytics::addErrorEvent);

    register_method("setEnabledInfoLog", &GameAnalytics::setEnabledInfoLog);
    register_method("setEnabledVerboseLog", &GameAnalytics::setEnabledVerboseLog);
    register_method("setEnabledManualSessionHandling", &GameAnalytics::setEnabledManualSessionHandling);
    register_method("setEnabledErrorReporting", &GameAnalytics::setEnabledErrorReporting);
    register_method("setEnabledEventSubmission", &GameAnalytics::setEnabledEventSubmission);

    register_method("setCustomDimension01", &GameAnalytics::setCustomDimension01);
    register_method("setCustomDimension02", &GameAnalytics::setCustomDimension02);
    register_method("setCustomDimension03", &GameAnalytics::setCustomDimension03);

    register_method("startSession", &GameAnalytics::startSession);
    register_method("endSession", &GameAnalytics::endSession);
    register_method("onQuit", &GameAnalytics::onQuit);

    register_method("getRemoteConfigsValueAsString", &GameAnalytics::getRemoteConfigsValueAsString);
    register_method("isRemoteConfigsReady", &GameAnalytics::isRemoteConfigsReady);
    register_method("getRemoteConfigsContentAsString", &GameAnalytics::getRemoteConfigsContentAsString);
}
