# Revisons

1.1 TBD
```
Replace serial calls with macros and set disabled initially
```

1.0 Initial Baseline Version - Jul 1, 2026
```
Added REVISIONS.md to document changes
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
Add ESPCONNECT.md how-to
Add littlfs support
Migrate to stored config
Write to log instead of serial monitor
Modify DBG_PRINT macros to support debug levels set in stored config
Modify README.md to be decscriptive of ths fork
Add critical error message writes to display
Modify NTP sync to compensate for drift when setting sleep duration
Rain / Snow precipitation as different bar fill (port from viktormail.ha)
Add ...

```