# Helicopter labs

The working files are collected here in one version:

- `common/`: shared initialization scripts.
- `lab_1/` to `lab_4/`: scripts, Simulink models, and measurements for each lab.
- `lab_1/data/`: all six lab 1 measurement files.
- `dokumentasjon/`: supporting documents.
- `arkiv/`: historical files; use the models in the lab folders for current work.

## Update on 2026-11-12

Merged `lab_new/` into this folder and removed the duplicate incoming folder.
The incoming `lab_2/heli_q8_lab2.slx` and
`lab_2/LQR_q3_10_elevation_rate_focus.mat` replace the previous working copies.
Those previous copies are preserved in `arkiv/lab_2_before_update_2026-11-12/`.

Identical lab 1 measurements were consolidated under `lab_1/data/`.
`lab_1/plot_data.m` now loads its measurement relative to the script location.
Generated Simulink/QUARC build files and caches were excluded from the merge.
