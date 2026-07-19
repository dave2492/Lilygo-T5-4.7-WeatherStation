# Revisons

1.1 TBD
```
Added littleFS support
Migrated to stored config and added user_config.md document
Error message write to device display if cannot load / parse user_config.json
DBG_* macros now write to /debug.log on LittleFS instead of Serial, with a
basic size cap (cleared and restarted once the log exceeds ~100KB)
Added debug levels (ERROR/INFO/VERBOSE) via DBG_PRINT*E/V macros
Added DebugLevel field in user_config.json, defaults to INFO
Noisy per-field JSON dumps in DecodeWeather() moved to VERBOSE
Real failure messages moved to ERROR level and are always logged

```

1.0 Initial Baseline Version - Jul 1, 2026
```
Added REVISIONS.md to document changes
Replaced serial calls with macros and set the default to disable serial printing (for now)
Use JsonDocument instead of deprecated DynamicJsonDocument
Converted from INO to CPP
Added WiFi connect retry 
New Battery SOC Calculation
Change NTP sync to once per day (always if reset)
Overnight single sleep period
Main loop restructure
```

TODO
```
Consider removing the NTP skips unless the S3 wakeup problems can be fixed
Replace the flat size-cap truncation on /debug.log with proper rotation -
perhaps one file per reset/wakeup and a max file count?
Reduce flash wear from /debug.log - it's written every wake (every 30 min
while awake), so consider write batching, a longer size cap, or an option
to disable logging once the board is stable
Add critical error message writes to device display
Add ESPCONNECT how-to for user as well as dev bin file build
Modify README.md to be descriptive of this fork
Modify RTC code to compensate for drift between NTP syncs (or just NTP sync every wake)
Rain / Snow precipitation as different bar fill (port from viktormail.ha)
Consider more descriptive icons (port from viktormail.ha?)
Consider moving to onecall for openweathermap (single round trip)
Document sucessful mods to fix 2024 device's wake from sleep as reset event
```
