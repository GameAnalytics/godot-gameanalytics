
#import <Foundation/Foundation.h>
#import "godot_plugin.h"
#import "GameAnalytics.h"
#import "core/engine.h"

static GameAnalytics* GAPtr = NULL;

void register_gameanalytics_types()
{
    ClassDB::register_class<GameAnalytics>();
    GAPtr = memnew(GameAnalytics);
    Engine::get_singleton()->add_singleton(Engine::Singleton("GameAnalytics", GameAnalytics::get_singleton()));
}

void unregister_gameanalytics_types()
{
    memdelete(GAPtr);
}
