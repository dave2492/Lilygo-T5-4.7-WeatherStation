#ifndef DEBUG_H
#define DEBUG_H

// Set to 1 to enable debug output over the Serial monitor, 0 to disable it.
// TODO: once file-based logging is added, route these to a log file instead.
#define DEBUG_ENABLED 0

#if DEBUG_ENABLED
  #define DBG_INIT(...)    Serial.begin(__VA_ARGS__)
  #define DBG_END()        Serial.end()
  #define DBG_PRINT(...)   Serial.print(__VA_ARGS__)
  #define DBG_PRINTLN(...) Serial.println(__VA_ARGS__)
  #define DBG_PRINTF(...)  Serial.printf(__VA_ARGS__)
#else
  #define DBG_INIT(...)
  #define DBG_END()
  #define DBG_PRINT(...)
  #define DBG_PRINTLN(...)
  #define DBG_PRINTF(...)
#endif

#endif // DEBUG_H
