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
Modified RTC / NTP code to compensate for drift between NTP syncs

(TEMP - to be removed when the S3 wakeup problem is completely verified as fixed.) 
Add an Error level message if NTP is done from a RESET, with the new time included.
So I can know how often a 'RESET' occurs on wake from deep sleep.
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
Note that the S3 connects with the jtag port and the dev board connects over serial port.
Remove redundant config file entries gmtOffset_sec and daylightOffset_sec.
(The timestamp string actually contains all the necessary information.)
Consider putting back the serial print capability if Log is disabled.
(The older dev boards do serial monitor OK)
Document the fix for the S3 wakeup problem.
Simply add a 470uf cap from pin 2 of the ESP32-S3 to GND.  I used a low ESR 16v cap.
Add ESPCONNECT how-to for user as well as dev bin file build
Good tip is to hold the boot button down untill you finish connecting in ESPCONNECT. 
Modify README.md to be descriptive of this fork
Rain / Snow precipitation as different bar fill (port from viktormail.ha)
Consider more descriptive icons (port from viktormail.ha)
Consider moving to onecall for openweathermap (single round trip)
Log error messages should include date string if available (esp if logging errors only)
Add critical error message writes to device display

And then:
Look into occasional json incomplete input errors and http timeouts (maybe just server problems)
Replace the flat size-cap truncation on /debug.log with proper rotation
Reduce flash wear from /debug.log - it's written every wake (every 30 min
while awake), so consider write batching, a longer size cap, or an option
to disable logging once the board is stable.
```
