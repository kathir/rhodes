
#include "ruby.h"

static VALUE rb_mParent;
static VALUE rb_mSystem;

VALUE rb_s_System_getPlatform(int argc, VALUE *argv);
VALUE rb_s_System_getHasCamera(int argc, VALUE *argv);
VALUE rb_s_System_getScreenWidth(int argc, VALUE *argv);
VALUE rb_s_System_getScreenHeight(int argc, VALUE *argv);
VALUE rb_s_System_getRealScreenWidth(int argc, VALUE *argv);
VALUE rb_s_System_getRealScreenHeight(int argc, VALUE *argv);
VALUE rb_s_System_getScreenOrientation(int argc, VALUE *argv);
VALUE rb_s_System_getPpiX(int argc, VALUE *argv);
VALUE rb_s_System_getPpiY(int argc, VALUE *argv);
VALUE rb_s_System_getPhoneNumber(int argc, VALUE *argv);
VALUE rb_s_System_getDeviceOwnerEmail(int argc, VALUE *argv);
VALUE rb_s_System_getDeviceOwnerName(int argc, VALUE *argv);
VALUE rb_s_System_getDevicePushId(int argc, VALUE *argv);
VALUE rb_s_System_getPhoneId(int argc, VALUE *argv);
VALUE rb_s_System_getDeviceName(int argc, VALUE *argv);
VALUE rb_s_System_getOsVersion(int argc, VALUE *argv);
VALUE rb_s_System_getLocale(int argc, VALUE *argv);
VALUE rb_s_System_getCountry(int argc, VALUE *argv);
VALUE rb_s_System_getIsEmulator(int argc, VALUE *argv);
VALUE rb_s_System_getHasCalendar(int argc, VALUE *argv);
VALUE rb_s_System_getIsMotorolaDevice(int argc, VALUE *argv);
VALUE rb_s_System_getOemInfo(int argc, VALUE *argv);
VALUE rb_s_System_getUuid(int argc, VALUE *argv);
VALUE rb_s_System_getApplicationIconBadge(int argc, VALUE *argv);
VALUE rb_s_System_setApplicationIconBadge(int argc, VALUE *argv);
VALUE rb_s_System_getHttpProxyURI(int argc, VALUE *argv);
VALUE rb_s_System_setHttpProxyURI(int argc, VALUE *argv);
VALUE rb_s_System_getLockWindowSize(int argc, VALUE *argv);
VALUE rb_s_System_setLockWindowSize(int argc, VALUE *argv);
VALUE rb_s_System_getShowKeyboard(int argc, VALUE *argv);
VALUE rb_s_System_setShowKeyboard(int argc, VALUE *argv);
VALUE rb_s_System_getFullScreen(int argc, VALUE *argv);
VALUE rb_s_System_setFullScreen(int argc, VALUE *argv);
VALUE rb_s_System_getLocalServerPort(int argc, VALUE *argv);
VALUE rb_s_System_setLocalServerPort(int argc, VALUE *argv);
VALUE rb_s_System_getFreeServerPort(int argc, VALUE *argv);
VALUE rb_s_System_getScreenAutoRotate(int argc, VALUE *argv);
VALUE rb_s_System_setScreenAutoRotate(int argc, VALUE *argv);
VALUE rb_s_System_getHasTouchscreen(int argc, VALUE *argv);
VALUE rb_s_System_getSecurityTokenNotPassed(int argc, VALUE *argv);
VALUE rb_s_System_getWebviewFramework(int argc, VALUE *argv);
VALUE rb_s_System_getScreenSleeping(int argc, VALUE *argv);
VALUE rb_s_System_setScreenSleeping(int argc, VALUE *argv);
VALUE rb_s_System_getHasNetwork(int argc, VALUE *argv);
VALUE rb_s_System_getHasWifiNetwork(int argc, VALUE *argv);
VALUE rb_s_System_getHasCellNetwork(int argc, VALUE *argv);
VALUE rb_s_System_getHasSqlite(int argc, VALUE *argv);
VALUE rb_s_System_applicationInstall(int argc, VALUE *argv);
VALUE rb_s_System_isApplicationInstalled(int argc, VALUE *argv);
VALUE rb_s_System_applicationUninstall(int argc, VALUE *argv);
VALUE rb_s_System_getStartParams(int argc, VALUE *argv);
VALUE rb_s_System_openUrl(int argc, VALUE *argv);
VALUE rb_s_System_unzipFile(int argc, VALUE *argv);
VALUE rb_s_System_zipFile(int argc, VALUE *argv);
VALUE rb_s_System_zipFiles(int argc, VALUE *argv);
VALUE rb_s_System_setRegistrySetting(int argc, VALUE *argv);
VALUE rb_s_System_getRegistrySetting(int argc, VALUE *argv);
VALUE rb_s_System_setWindowFrame(int argc, VALUE *argv);
VALUE rb_s_System_setWindowPosition(int argc, VALUE *argv);
VALUE rb_s_System_setWindowSize(int argc, VALUE *argv);
VALUE rb_s_System_bringToFront(int argc, VALUE *argv);
VALUE rb_s_System_replaceCurrentBundle(int argc, VALUE *argv);
VALUE rb_s_System_deleteFolder(int argc, VALUE *argv);
VALUE rb_s_System_setDoNotBackupAttribute(int argc, VALUE *argv);
VALUE rb_s_System_isBlobAttr(int argc, VALUE *argv);
VALUE rb_s_System_updateBlobAttribs(int argc, VALUE *argv);
VALUE rb_s_System_get_locale(int argc, VALUE *argv);
VALUE rb_s_System_set_locale(int argc, VALUE *argv);
VALUE rb_s_System_setPushNotification(int argc, VALUE *argv);
VALUE rb_s_System_setScreenRotationNotification(int argc, VALUE *argv);
VALUE rb_s_System_exit(int argc, VALUE *argv);
VALUE rb_s_System_set_sleeping(int argc, VALUE *argv);
VALUE rb_s_System_startTimer(int argc, VALUE *argv);
VALUE rb_s_System_stopTimer(int argc, VALUE *argv);
VALUE rb_s_System_setNetworkStatusNotify(int argc, VALUE *argv);
VALUE rb_s_System_clearNetworkStatusNotify(int argc, VALUE *argv);
VALUE rb_s_System_set_http_proxy_url(int argc, VALUE *argv);
VALUE rb_s_System_unset_http_proxy(int argc, VALUE *argv);
VALUE rb_s_System_set_application_icon_badge(int argc, VALUE *argv);
VALUE rb_s_System_runApplication(int argc, VALUE *argv);
VALUE rb_s_System_getProperty(int argc, VALUE *argv);
VALUE rb_s_System_getProperties(int argc, VALUE *argv);
VALUE rb_s_System_getAllProperties(int argc, VALUE *argv);
VALUE rb_s_System_setProperty(int argc, VALUE *argv);
VALUE rb_s_System_setProperties(int argc, VALUE *argv);
VALUE rb_s_System_clearAllProperties(int argc, VALUE *argv);




VALUE getRuby_System_Module(){ return rb_mSystem; }



void Init_RubyAPI_System(void)
{

    VALUE tmpParent = Qnil;
    rb_mParent = rb_define_module("Rho");
    

	rb_mSystem = rb_define_class_under(rb_mParent, "System", rb_cObject);

    //Constructor should be not available
	//rb_define_alloc_func(rb_cBarcode1, rb_barcode1_allocate);
    //rb_undef_alloc_func(rb_mSystem);

    rb_define_singleton_method(rb_mSystem, "platform", rb_s_System_getPlatform, -1);
    rb_define_singleton_method(rb_mSystem, "hasCamera", rb_s_System_getHasCamera, -1);
    rb_define_singleton_method(rb_mSystem, "screenWidth", rb_s_System_getScreenWidth, -1);
    rb_define_singleton_method(rb_mSystem, "screenHeight", rb_s_System_getScreenHeight, -1);
    rb_define_singleton_method(rb_mSystem, "realScreenWidth", rb_s_System_getRealScreenWidth, -1);
    rb_define_singleton_method(rb_mSystem, "realScreenHeight", rb_s_System_getRealScreenHeight, -1);
    rb_define_singleton_method(rb_mSystem, "screenOrientation", rb_s_System_getScreenOrientation, -1);
    rb_define_singleton_method(rb_mSystem, "ppiX", rb_s_System_getPpiX, -1);
    rb_define_singleton_method(rb_mSystem, "ppiY", rb_s_System_getPpiY, -1);
    rb_define_singleton_method(rb_mSystem, "phoneNumber", rb_s_System_getPhoneNumber, -1);
    rb_define_singleton_method(rb_mSystem, "deviceOwnerEmail", rb_s_System_getDeviceOwnerEmail, -1);
    rb_define_singleton_method(rb_mSystem, "deviceOwnerName", rb_s_System_getDeviceOwnerName, -1);
    rb_define_singleton_method(rb_mSystem, "devicePushId", rb_s_System_getDevicePushId, -1);
    rb_define_singleton_method(rb_mSystem, "phoneId", rb_s_System_getPhoneId, -1);
    rb_define_singleton_method(rb_mSystem, "deviceName", rb_s_System_getDeviceName, -1);
    rb_define_singleton_method(rb_mSystem, "osVersion", rb_s_System_getOsVersion, -1);
    rb_define_singleton_method(rb_mSystem, "locale", rb_s_System_getLocale, -1);
    rb_define_singleton_method(rb_mSystem, "country", rb_s_System_getCountry, -1);
    rb_define_singleton_method(rb_mSystem, "isEmulator", rb_s_System_getIsEmulator, -1);
    rb_define_singleton_method(rb_mSystem, "hasCalendar", rb_s_System_getHasCalendar, -1);
    rb_define_singleton_method(rb_mSystem, "isMotorolaDevice", rb_s_System_getIsMotorolaDevice, -1);
    rb_define_singleton_method(rb_mSystem, "oemInfo", rb_s_System_getOemInfo, -1);
    rb_define_singleton_method(rb_mSystem, "uuid", rb_s_System_getUuid, -1);
    rb_define_singleton_method(rb_mSystem, "applicationIconBadge", rb_s_System_getApplicationIconBadge, -1);
    rb_define_singleton_method(rb_mSystem, "applicationIconBadge=", rb_s_System_setApplicationIconBadge, -1);
    rb_define_singleton_method(rb_mSystem, "httpProxyURI", rb_s_System_getHttpProxyURI, -1);
    rb_define_singleton_method(rb_mSystem, "httpProxyURI=", rb_s_System_setHttpProxyURI, -1);
    rb_define_singleton_method(rb_mSystem, "lockWindowSize", rb_s_System_getLockWindowSize, -1);
    rb_define_singleton_method(rb_mSystem, "lockWindowSize=", rb_s_System_setLockWindowSize, -1);
    rb_define_singleton_method(rb_mSystem, "showKeyboard", rb_s_System_getShowKeyboard, -1);
    rb_define_singleton_method(rb_mSystem, "showKeyboard=", rb_s_System_setShowKeyboard, -1);
    rb_define_singleton_method(rb_mSystem, "fullScreen", rb_s_System_getFullScreen, -1);
    rb_define_singleton_method(rb_mSystem, "fullScreen=", rb_s_System_setFullScreen, -1);
    rb_define_singleton_method(rb_mSystem, "localServerPort", rb_s_System_getLocalServerPort, -1);
    rb_define_singleton_method(rb_mSystem, "localServerPort=", rb_s_System_setLocalServerPort, -1);
    rb_define_singleton_method(rb_mSystem, "freeServerPort", rb_s_System_getFreeServerPort, -1);
    rb_define_singleton_method(rb_mSystem, "screenAutoRotate", rb_s_System_getScreenAutoRotate, -1);
    rb_define_singleton_method(rb_mSystem, "screenAutoRotate=", rb_s_System_setScreenAutoRotate, -1);
    rb_define_singleton_method(rb_mSystem, "hasTouchscreen", rb_s_System_getHasTouchscreen, -1);
    rb_define_singleton_method(rb_mSystem, "securityTokenNotPassed", rb_s_System_getSecurityTokenNotPassed, -1);
    rb_define_singleton_method(rb_mSystem, "webviewFramework", rb_s_System_getWebviewFramework, -1);
    rb_define_singleton_method(rb_mSystem, "screenSleeping", rb_s_System_getScreenSleeping, -1);
    rb_define_singleton_method(rb_mSystem, "screenSleeping=", rb_s_System_setScreenSleeping, -1);
    rb_define_singleton_method(rb_mSystem, "hasNetwork", rb_s_System_getHasNetwork, -1);
    rb_define_singleton_method(rb_mSystem, "hasWifiNetwork", rb_s_System_getHasWifiNetwork, -1);
    rb_define_singleton_method(rb_mSystem, "hasCellNetwork", rb_s_System_getHasCellNetwork, -1);
    rb_define_singleton_method(rb_mSystem, "hasSqlite", rb_s_System_getHasSqlite, -1);
    rb_define_singleton_method(rb_mSystem, "applicationInstall", rb_s_System_applicationInstall, -1);
    rb_define_singleton_method(rb_mSystem, "isApplicationInstalled", rb_s_System_isApplicationInstalled, -1);
    rb_define_singleton_method(rb_mSystem, "applicationUninstall", rb_s_System_applicationUninstall, -1);
    rb_define_singleton_method(rb_mSystem, "getStartParams", rb_s_System_getStartParams, -1);
    rb_define_singleton_method(rb_mSystem, "openUrl", rb_s_System_openUrl, -1);
    rb_define_singleton_method(rb_mSystem, "unzipFile", rb_s_System_unzipFile, -1);
    rb_define_singleton_method(rb_mSystem, "zipFile", rb_s_System_zipFile, -1);
    rb_define_singleton_method(rb_mSystem, "zipFiles", rb_s_System_zipFiles, -1);
    rb_define_singleton_method(rb_mSystem, "setRegistrySetting", rb_s_System_setRegistrySetting, -1);
    rb_define_singleton_method(rb_mSystem, "getRegistrySetting", rb_s_System_getRegistrySetting, -1);
    rb_define_singleton_method(rb_mSystem, "setWindowFrame", rb_s_System_setWindowFrame, -1);
    rb_define_singleton_method(rb_mSystem, "setWindowPosition", rb_s_System_setWindowPosition, -1);
    rb_define_singleton_method(rb_mSystem, "setWindowSize", rb_s_System_setWindowSize, -1);
    rb_define_singleton_method(rb_mSystem, "bringToFront", rb_s_System_bringToFront, -1);
    rb_define_singleton_method(rb_mSystem, "replaceCurrentBundle", rb_s_System_replaceCurrentBundle, -1);
    rb_define_singleton_method(rb_mSystem, "deleteFolder", rb_s_System_deleteFolder, -1);
    rb_define_singleton_method(rb_mSystem, "setDoNotBackupAttribute", rb_s_System_setDoNotBackupAttribute, -1);
    rb_define_singleton_method(rb_mSystem, "isBlobAttr", rb_s_System_isBlobAttr, -1);
    rb_define_singleton_method(rb_mSystem, "updateBlobAttribs", rb_s_System_updateBlobAttribs, -1);
    rb_define_singleton_method(rb_mSystem, "get_locale", rb_s_System_get_locale, -1);
    rb_define_singleton_method(rb_mSystem, "set_locale", rb_s_System_set_locale, -1);
    rb_define_singleton_method(rb_mSystem, "setPushNotification", rb_s_System_setPushNotification, -1);
    rb_define_singleton_method(rb_mSystem, "setScreenRotationNotification", rb_s_System_setScreenRotationNotification, -1);
    rb_define_singleton_method(rb_mSystem, "exit", rb_s_System_exit, -1);
    rb_define_singleton_method(rb_mSystem, "set_sleeping", rb_s_System_set_sleeping, -1);
    rb_define_singleton_method(rb_mSystem, "startTimer", rb_s_System_startTimer, -1);
    rb_define_singleton_method(rb_mSystem, "stopTimer", rb_s_System_stopTimer, -1);
    rb_define_singleton_method(rb_mSystem, "setNetworkStatusNotify", rb_s_System_setNetworkStatusNotify, -1);
    rb_define_singleton_method(rb_mSystem, "clearNetworkStatusNotify", rb_s_System_clearNetworkStatusNotify, -1);
    rb_define_singleton_method(rb_mSystem, "set_http_proxy_url", rb_s_System_set_http_proxy_url, -1);
    rb_define_singleton_method(rb_mSystem, "unset_http_proxy", rb_s_System_unset_http_proxy, -1);
    rb_define_singleton_method(rb_mSystem, "set_application_icon_badge", rb_s_System_set_application_icon_badge, -1);
    rb_define_singleton_method(rb_mSystem, "runApplication", rb_s_System_runApplication, -1);
    rb_define_singleton_method(rb_mSystem, "getProperty", rb_s_System_getProperty, -1);
    rb_define_singleton_method(rb_mSystem, "getProperties", rb_s_System_getProperties, -1);
    rb_define_singleton_method(rb_mSystem, "getAllProperties", rb_s_System_getAllProperties, -1);
    rb_define_singleton_method(rb_mSystem, "setProperty", rb_s_System_setProperty, -1);
    rb_define_singleton_method(rb_mSystem, "setProperties", rb_s_System_setProperties, -1);
    rb_define_singleton_method(rb_mSystem, "clearAllProperties", rb_s_System_clearAllProperties, -1);





    rb_const_set(rb_mSystem, rb_intern("PLATFORM_WM_CE"), rb_str_new2("WINDOWS") );
    rb_const_set(rb_mSystem, rb_intern("PLATFORM_ANDROID"), rb_str_new2("ANDROID") );
    rb_const_set(rb_mSystem, rb_intern("PLATFORM_IOS"), rb_str_new2("APPLE") );
    rb_const_set(rb_mSystem, rb_intern("PLATFORM_WP8"), rb_str_new2("WP8") );
    rb_const_set(rb_mSystem, rb_intern("PLATFORM_WINDOWS_DESKTOP"), rb_str_new2("WINDOWS_DESKTOP") );
    rb_const_set(rb_mSystem, rb_intern("SCREEN_PORTRAIT"), rb_str_new2("portrait") );
    rb_const_set(rb_mSystem, rb_intern("SCREEN_LANDSCAPE"), rb_str_new2("landscape") );

    rb_define_alias(rb_singleton_class(rb_mSystem), "get_property", "getProperty");
    rb_define_alias(rb_singleton_class(rb_mSystem), "run_app", "runApplication");
    rb_define_alias(rb_singleton_class(rb_mSystem), "app_install", "applicationInstall");
    rb_define_alias(rb_singleton_class(rb_mSystem), "app_installed?", "isApplicationInstalled");
    rb_define_alias(rb_singleton_class(rb_mSystem), "app_uninstall", "applicationUninstall");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_camera", "hasCamera");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_width", "screenWidth");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_height", "screenHeight");
    rb_define_alias(rb_singleton_class(rb_mSystem), "real_screen_width", "realScreenWidth");
    rb_define_alias(rb_singleton_class(rb_mSystem), "real_screen_height", "realScreenHeight");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_orientation", "screenOrientation");
    rb_define_alias(rb_singleton_class(rb_mSystem), "ppi_x", "ppiX");
    rb_define_alias(rb_singleton_class(rb_mSystem), "ppi_y", "ppiY");
    rb_define_alias(rb_singleton_class(rb_mSystem), "phone_number", "phoneNumber");
    rb_define_alias(rb_singleton_class(rb_mSystem), "device_owner_email", "deviceOwnerEmail");
    rb_define_alias(rb_singleton_class(rb_mSystem), "device_owner_name", "deviceOwnerName");
    rb_define_alias(rb_singleton_class(rb_mSystem), "device_push_id", "devicePushId");
    rb_define_alias(rb_singleton_class(rb_mSystem), "phone_id", "phoneId");
    rb_define_alias(rb_singleton_class(rb_mSystem), "device_name", "deviceName");
    rb_define_alias(rb_singleton_class(rb_mSystem), "os_version", "osVersion");
    rb_define_alias(rb_singleton_class(rb_mSystem), "is_emulator", "isEmulator");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_calendar", "hasCalendar");
    rb_define_alias(rb_singleton_class(rb_mSystem), "is_motorola_device", "isMotorolaDevice");
    rb_define_alias(rb_singleton_class(rb_mSystem), "oem_info", "oemInfo");
    rb_define_alias(rb_singleton_class(rb_mSystem), "application_icon_badge", "applicationIconBadge");
    rb_define_alias(rb_singleton_class(rb_mSystem), "application_icon_badge=", "applicationIconBadge=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "http_proxy_uri", "httpProxyURI");
    rb_define_alias(rb_singleton_class(rb_mSystem), "http_proxy_uri=", "httpProxyURI=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "lock_window_size", "lockWindowSize");
    rb_define_alias(rb_singleton_class(rb_mSystem), "lock_window_size=", "lockWindowSize=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "show_keyboard", "showKeyboard");
    rb_define_alias(rb_singleton_class(rb_mSystem), "show_keyboard=", "showKeyboard=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "full_screen", "fullScreen");
    rb_define_alias(rb_singleton_class(rb_mSystem), "full_screen=", "fullScreen=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "local_server_port", "localServerPort");
    rb_define_alias(rb_singleton_class(rb_mSystem), "local_server_port=", "localServerPort=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "free_server_port", "freeServerPort");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_auto_rotate", "screenAutoRotate");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_auto_rotate=", "screenAutoRotate=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_touchscreen", "hasTouchscreen");
    rb_define_alias(rb_singleton_class(rb_mSystem), "security_token_not_passed", "securityTokenNotPassed");
    rb_define_alias(rb_singleton_class(rb_mSystem), "webview_framework", "webviewFramework");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_sleeping", "screenSleeping");
    rb_define_alias(rb_singleton_class(rb_mSystem), "screen_sleeping=", "screenSleeping=");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_network", "hasNetwork");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_wifi_network", "hasWifiNetwork");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_cell_network", "hasCellNetwork");
    rb_define_alias(rb_singleton_class(rb_mSystem), "has_sqlite", "hasSqlite");
    rb_define_alias(rb_singleton_class(rb_mSystem), "application_install", "applicationInstall");
    rb_define_alias(rb_singleton_class(rb_mSystem), "is_application_installed", "isApplicationInstalled");
    rb_define_alias(rb_singleton_class(rb_mSystem), "application_uninstall", "applicationUninstall");
    rb_define_alias(rb_singleton_class(rb_mSystem), "get_start_params", "getStartParams");
    rb_define_alias(rb_singleton_class(rb_mSystem), "open_url", "openUrl");
    rb_define_alias(rb_singleton_class(rb_mSystem), "unzip_file", "unzipFile");
    rb_define_alias(rb_singleton_class(rb_mSystem), "zip_file", "zipFile");
    rb_define_alias(rb_singleton_class(rb_mSystem), "zip_files", "zipFiles");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_registry_setting", "setRegistrySetting");
    rb_define_alias(rb_singleton_class(rb_mSystem), "get_registry_setting", "getRegistrySetting");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_window_frame", "setWindowFrame");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_window_position", "setWindowPosition");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_window_size", "setWindowSize");
    rb_define_alias(rb_singleton_class(rb_mSystem), "bring_to_front", "bringToFront");
    rb_define_alias(rb_singleton_class(rb_mSystem), "replace_current_bundle", "replaceCurrentBundle");
    rb_define_alias(rb_singleton_class(rb_mSystem), "delete_folder", "deleteFolder");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_do_not_backup_attribute", "setDoNotBackupAttribute");
    rb_define_alias(rb_singleton_class(rb_mSystem), "is_blob_attr", "isBlobAttr");
    rb_define_alias(rb_singleton_class(rb_mSystem), "update_blob_attribs", "updateBlobAttribs");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_push_notification", "setPushNotification");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_screen_rotation_notification", "setScreenRotationNotification");
    rb_define_alias(rb_singleton_class(rb_mSystem), "start_timer", "startTimer");
    rb_define_alias(rb_singleton_class(rb_mSystem), "stop_timer", "stopTimer");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_network_status_notify", "setNetworkStatusNotify");
    rb_define_alias(rb_singleton_class(rb_mSystem), "clear_network_status_notify", "clearNetworkStatusNotify");
    rb_define_alias(rb_singleton_class(rb_mSystem), "run_application", "runApplication");
    rb_define_alias(rb_singleton_class(rb_mSystem), "get_property", "getProperty");
    rb_define_alias(rb_singleton_class(rb_mSystem), "get_properties", "getProperties");
    rb_define_alias(rb_singleton_class(rb_mSystem), "get_all_properties", "getAllProperties");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_property", "setProperty");
    rb_define_alias(rb_singleton_class(rb_mSystem), "set_properties", "setProperties");
    rb_define_alias(rb_singleton_class(rb_mSystem), "clear_all_properties", "clearAllProperties");

//TODO: support module aliases
    rb_const_set(rb_mKernel, rb_intern("System"), rb_mSystem );
}

