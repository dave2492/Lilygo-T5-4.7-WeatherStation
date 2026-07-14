#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>
#include <LittleFS.h>

// Set to 1 to enable debug logging to /debug.log on the LittleFS partition, 0 to disable it.
#define DEBUG_ENABLED 1

// Verbosity tiers, low to high. Runtime-selected (not compile-time) via the
// "DebugLevel" field in user_config.json - see DBG_SET_LEVEL below.
#define DBG_LEVEL_ERROR   0
#define DBG_LEVEL_INFO    1
#define DBG_LEVEL_VERBOSE 2

#if DEBUG_ENABLED
  // Defined in debug.cpp. DebugLogInit() mounts LittleFS and opens the log file
  // for append (truncating it first if it's grown past the size cap);
  // DebugLogEnd() flushes and closes it - always call this before deep sleep.
  extern File DebugLogFile;
  void DebugLogInit();
  void DebugLogEnd();

  // DebugLevel defaults to DBG_LEVEL_INFO and stays there until LoadUserConfig()
  // parses user_config.json and calls DBG_SET_LEVEL - so the handful of DBG_PRINT*
  // calls in InitialiseSystem(), which run before the config file is read, always
  // log at INFO regardless of what's configured.
  extern int DebugLevel;
  void DebugSetLevel(const String &levelName);
  #define DBG_SET_LEVEL(levelName) DebugSetLevel(levelName)

  // All writes are guarded by DebugLogFile's bool operator, so a failed mount
  // (e.g. filesystem never flashed) silently disables logging instead of crashing.
  #define DBG_INIT(...)    DebugLogInit()
  #define DBG_END()        DebugLogEnd()

  // Default tier - status/flow info you'd normally want to see.
  #define DBG_PRINT(...)   do { if (DebugLevel >= DBG_LEVEL_INFO && DebugLogFile) DebugLogFile.print(__VA_ARGS__);   } while (0)
  #define DBG_PRINTLN(...) do { if (DebugLevel >= DBG_LEVEL_INFO && DebugLogFile) DebugLogFile.println(__VA_ARGS__); } while (0)
  #define DBG_PRINTF(...)  do { if (DebugLevel >= DBG_LEVEL_INFO && DebugLogFile) DebugLogFile.printf(__VA_ARGS__);  } while (0)

  // Verbose tier - noisy/rarely-useful detail, e.g. per-field JSON dumps.
  #define DBG_PRINTV(...)   do { if (DebugLevel >= DBG_LEVEL_VERBOSE && DebugLogFile) DebugLogFile.print(__VA_ARGS__);   } while (0)
  #define DBG_PRINTLNV(...) do { if (DebugLevel >= DBG_LEVEL_VERBOSE && DebugLogFile) DebugLogFile.println(__VA_ARGS__); } while (0)
  #define DBG_PRINTFV(...)  do { if (DebugLevel >= DBG_LEVEL_VERBOSE && DebugLogFile) DebugLogFile.printf(__VA_ARGS__);  } while (0)

  // Error tier - always logged regardless of configured level.
  #define DBG_PRINTE(...)   do { if (DebugLogFile) DebugLogFile.print(__VA_ARGS__);   } while (0)
  #define DBG_PRINTLNE(...) do { if (DebugLogFile) DebugLogFile.println(__VA_ARGS__); } while (0)
  #define DBG_PRINTFE(...)  do { if (DebugLogFile) DebugLogFile.printf(__VA_ARGS__);  } while (0)
#else
  #define DBG_SET_LEVEL(...)
  #define DBG_INIT(...)
  #define DBG_END()
  #define DBG_PRINT(...)
  #define DBG_PRINTLN(...)
  #define DBG_PRINTF(...)
  #define DBG_PRINTV(...)
  #define DBG_PRINTLNV(...)
  #define DBG_PRINTFV(...)
  #define DBG_PRINTE(...)
  #define DBG_PRINTLNE(...)
  #define DBG_PRINTFE(...)
#endif

#endif // DEBUG_H
