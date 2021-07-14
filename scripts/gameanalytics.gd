extends Node

var _ga = null

func _ready():
    if(Engine.has_singleton("GameAnalytics")):
        _ga = Engine.get_singleton("GameAnalytics")
    if _ga != null:
        var isDebug = OS.is_debug_build()
        _ga.setEnabledInfoLog(isDebug)
        _ga.setEnabledVerboseLog(isDebug)

        if ProjectSettings.has_setting('GameAnalytics/CustomDimensions01'):
            var d = ProjectSettings.get_setting('GameAnalytics/CustomDimensions01')
            if d != null and d != '':
                var dims = d.split(',')
                _ga.configureAvailableCustomDimensions01(dims)
        if ProjectSettings.has_setting('GameAnalytics/CustomDimensions02'):
            var d = ProjectSettings.get_setting('GameAnalytics/CustomDimensions02')
            if d != null and d != '':
                var dims = d.split(',')
                _ga.configureAvailableCustomDimensions02(dims)
        if ProjectSettings.has_setting('GameAnalytics/CustomDimensions03'):
            var d = ProjectSettings.get_setting('GameAnalytics/CustomDimensions03')
            if d != null and d != '':
                var dims = d.split(',')
                _ga.configureAvailableCustomDimensions03(dims)
        if ProjectSettings.has_setting('GameAnalytics/ResourceCurrencies'):
            var c = ProjectSettings.get_setting('GameAnalytics/ResourceCurrencies')
            if c != null and c != '':
                var curs = c.split(',')
                _ga.configureAvailableResourceCurrencies(curs)
        if ProjectSettings.has_setting('GameAnalytics/ResourceItemTypes'):
            var t = ProjectSettings.get_setting('GameAnalytics/ResourceItemTypes')
            if t != null and t != '':
                var types = t.split(',')
                _ga.configureAvailableResourceItemTypes(types)
        _ga.configureAutoDetectAppVersion(true)

func initGA() -> void:
    var gameKeySettingKey = "GameAnalytics/" + OS.get_name() + "GAME_KEY"
    var secretKeySettingKey = "GameAnalytics/" + OS.get_name() + "SECRET_KEY"
    if ProjectSettings.has_setting(gameKeySettingKey) and ProjectSettings.has_setting(secretKeySettingKey):
        var gk = ProjectSettings.get_setting(gameKeySettingKey)
        var sk = ProjectSettings.get_setting(secretKeySettingKey)
        init(gk, sk)
    else:
        push_error('Project settings have no keys for GameAnalytics!')

func init(game_key: String, secret_key: String) -> void:
    if _ga != null:
        _ga.init(game_key, secret_key)
        print('GameAnalytics inited!')

func addBusinessEvent(params: Dictionary) -> void:
    if _ga != null:
        _ga.addBusinessEvent(params)

func addResourceEvent(params: Dictionary) -> void:
    if _ga != null:
        _ga.addResourceEvent(params)

func addProgressionEvent(params: Dictionary) -> void:
    if _ga != null:
        _ga.addProgressionEvent(params)

func addDesignEvent(params: Dictionary) -> void:
    if _ga != null:
        _ga.addDesignEvent(params)

func addErrorEvent(params: Dictionary) -> void:
    if _ga != null:
        _ga.addErrorEvent(params)

func isRemoteConfigsReady() -> bool:
    if _ga != null:
        return _ga.isRemoteConfigsReady()
    else:
        return false

func getRemoteConfigsContentAsString() -> String:
    if _ga != null:
        return _ga.getRemoteConfigsContentAsString()
    else:
        return ''

func getRemoteConfigsValueAsString(key: String, defval: String = '') -> String:
    if _ga != null:
        return _ga.getRemoteConfigsValueAsString({'key': key, 'defaultValue': defval})
    else:
        return defval

func _notification(what):
    if what == MainLoop.NOTIFICATION_WM_QUIT_REQUEST:
        if _ga != null:
            _ga.onQuit()
