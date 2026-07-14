#include "debug.h"

#if DEBUG_ENABLED

namespace {
  const char DEBUG_LOG_PATH[] = "/debug.log";
  const size_t DEBUG_LOG_MAX_BYTES = 100 * 1024; // truncate and start fresh once exceeded
}

File DebugLogFile;
int DebugLevel = DBG_LEVEL_INFO; // default until LoadUserConfig() calls DebugSetLevel()

void DebugSetLevel(const String &levelName) {
  String s = levelName;
  s.toUpperCase();
  if (s == "ERROR")        DebugLevel = DBG_LEVEL_ERROR;
  else if (s == "VERBOSE") DebugLevel = DBG_LEVEL_VERBOSE;
  else                     DebugLevel = DBG_LEVEL_INFO; // covers "INFO" and missing/unrecognized values
}

void DebugLogInit() {
  if (!LittleFS.begin(false)) return; // filesystem not mounted/flashed - logging stays a no-op

  File existing = LittleFS.open(DEBUG_LOG_PATH, "r");
  if (existing) {
    bool tooBig = existing.size() > DEBUG_LOG_MAX_BYTES;
    existing.close();
    if (tooBig) LittleFS.remove(DEBUG_LOG_PATH);
  }

  DebugLogFile = LittleFS.open(DEBUG_LOG_PATH, "a");
}

void DebugLogEnd() {
  if (DebugLogFile) DebugLogFile.close();
}

#endif // DEBUG_ENABLED
