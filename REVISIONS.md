# Revisons

1.1 TBD
```
Added littleFS support
Migrated to stored config and added user_config.md document
Error message write to device display if cannot load / parse user_config.json

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
Write to logfile instead of serial monitor
Modify DBG_PRINT macros to support debug levels
Add limiter for debug log files, perhaps one per reset/wakeup and specifiy max number?
Add critical error message writes to device display
Add ESPCONNECT how-to for user as well as dev bin file build
Modify README.md to be descriptive of this fork
Modify RTC code to compensate for drift between NTP syncs
Rain / Snow precipitation as different bar fill (port from viktormail.ha)
Consider more descriptive icons (port from viktormail.ha?)
Document sucessful mods to fix 2024 device's wake from sleep as reset event
```
