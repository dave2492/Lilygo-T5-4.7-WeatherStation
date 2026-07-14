#ifndef USER_CONFIG_H
#define USER_CONFIG_H

// Per-device settings (WiFi credentials, location, timezone) loaded at boot from
// /user_config.json on the LittleFS partition, via LoadUserConfig() in
// OWM_EPD47.cpp. See data/user_config.example.json for the expected format and
// field descriptions - flash your own copy with 'pio run -t uploadfs'.
//
// These used to be compiled-in constants (see git history); they're String/int
// here (not const) because they're populated at runtime instead.
String ssid;
String password;
String apikey;
String City;
String Latitude;
String Longitude;
String Language;
String Hemisphere;
String Units;
String Timezone;
String ntpServer;
int    gmtOffset_sec;
int    daylightOffset_sec;

bool LoadUserConfig();

#endif
