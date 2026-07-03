# Revisons

1.1 TBD
```

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
Add littlfs support
Migrate to stored config
Add ESPCONNECT.md how-to
Write to log instead of serial monitor
Modify DBG_PRINT macros to support debug levels set in stored config
Modify README.md to be decscriptive of ths fork
Add critical error message writes to display
Modify NTP sync to compensate for drift when setting sleep duration
Rain / Snow precipitation as different bar fill (port from viktormail.ha)
Add ...

```