# SameWav (WIP)
CLI for determining if two .wav files have identical sets of sample frames. For CI, Unit Tests, and anything that requires two identical sets of .wav data.

## Usage
On Windows:  
```./builds/SameWav.exe <wav file 0> <wav file 1> [invert exit code]```

or on Mac:  
```./builds/SameWav.app <wav file 0> <wav file 1> [invert exit code]```

## Notes
- `[invert exit code]` may be anything. If it exists, SameWav.exe will exit with 1 given same wav files.

- If the .exe or .app causes a "Permission Denied" error, you may have to run "chmod +x" first. For example on Mac, run `chmod +x ./builds/SameWav.app` before running SameWav.app.