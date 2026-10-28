# Devlog

## 2026-10-27 — Debounce without blocking

- Button used `sleep_ms(250)` to debounce. Tested: with a 500 ms block in
  breathe mode, quick taps got lost because the pin wasn't read during sleep.
- Rewrote debounce: save the time whenever the pin changes, and only trust it
  after it's steady for 50 ms. No sleeping.
- Learned: raw reading (bounces) vs trusted state (only changes when steady).
- Tested: quick taps, hold + release, fast tapping. All pass.
- Next: make `ledBreathe` non-blocking.
