# SameWav (WIP)
CLI for determining if two .wav files have identical sets of sample frames. For CI, Unit Tests, and anything that requires two identical sets of .wav data.

## Usage
```./SameWav.exe <wav file 0> <wav file 1> [invert exit code]```

`[invert exit code]` may be anything. If it exists, SameWav.exe will exit with 1 given same wav files.
