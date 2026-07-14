# user_config.json

Per-device settings (WiFi credentials, location, timezone) are no longer compiled into the firmware. Instead they're read at boot from `user_config.json` on the device's LittleFS partition.

To set up a device:

1. Copy `data/user_config.example.json` to `data/user_config.json`.
2. Fill in your own values (see field reference below).
3. Flash it to the device's filesystem partition: `pio run -t uploadfs`
4. Flash the firmware as usual: `pio run -t upload`

Alternatively, a web application such as ESPCONNECT may be used to retrieve the existing user_config.json file and upload a modified copy.  See this repo's README.md file for more information.

`data/user_config.json` is gitignored — it holds real credentials, so it's never committed. `data/user_config.example.json` (placeholder values) is the tracked template.

If the file is missing, unreadable, or missing `ssid` or `apikey`, the device shows an error on the e-paper display and retries on the next scheduled wake rather than proceeding with empty settings.

## Field reference

| Field | Type | Description |
|---|---|---|
| `ssid` | string | Your WiFi network name. |
| `password` | string | Your WiFi password. |
| `apikey` | string | Your OpenWeatherMap API key. Sign up for a free developer account at https://openweathermap.org/ |
| `City` | string | Your home city, used only for the on-screen label. |
| `Latitude` | string | Latitude of your location in decimal degrees. |
| `Longitude` | string | Longitude of your location in decimal degrees. |
| `Language` | string | Weather description language code. OWM only translates the description text, nothing else. Examples: German (`DE`), Arabic (`AR`), Czech (`CZ`), English (`EN`), Greek (`EL`), Persian/Farsi (`FA`), Galician (`GL`), Hungarian (`HU`), Japanese (`JA`), Korean (`KR`), Latvian (`LA`), Lithuanian (`LT`), Macedonian (`MK`), Slovak (`SK`), Slovenian (`SL`), Vietnamese (`VI`). |
| `Hemisphere` | string | `"north"` or `"south"` — affects moon-phase/seasonal display logic. |
| `Units` | string | `"M"` for Metric or `"I"` for Imperial. |
| `Timezone` | string | POSIX TZ string for your local timezone, including DST rules. Full list: https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv |
| `ntpServer` | string | NTP server to sync time from. Pick one close to you, or use a regional pool, e.g. `0.europe.pool.ntp.org` (EU), `0.north-america.pool.ntp.org` (US). See https://www.ntppool.org/en/ |
| `gmtOffset_sec` | number | Standard-time offset from GMT, in seconds. E.g. UK is `0`, US Eastern is `-18000`, most of Australia is `28800`. |
| `daylightOffset_sec` | number | Additional DST offset, in seconds, on top of `gmtOffset_sec`. Most commonly `3600` (1 hour); some regions use `7200` (2h), `1800` (30m), or `19800` (5.5h). |

### Example timezone strings

| Region | `Timezone` value |
|---|---|
| Most of Europe | `MET-1METDST,M3.5.0/01,M10.5.0/02` |
| Central Europe | `CET-1CEST,M3.5.0,M10.5.0/3` |
| EST (USA) | `EST5EDT,M3.2.0,M11.1.0` |
| CST (USA) | `CST6CDT,M3.2.0,M11.1.0` |
| MST (USA) | `MST7MDT,M4.1.0,M10.5.0` |
| Auckland | `NZST-12NZDT,M9.5.0,M4.1.0/3` |
| Asia (EET) | `EET-2EEST,M3.5.5/0,M10.5.5/0` |
| Australia (ACST) | `ACST-9:30ACDT,M10.1.0,M4.1.0/3` |
