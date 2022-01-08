# SameWav (WIP)
CLI for checking if two .wav files have identical sets of sample frames. For CI, Unit Tests, and anything that requires checking two sets of .wav data. NOTE: The program always returns exit code 0, so by default it is used for logging.

## Usage
On Windows:  
```./builds/SameWav.exe <wav file 0> <wav file 1>```

or on Mac:  
```./builds/SameWav.app <wav file 0> <wav file 1>```

## Notes
If the .exe or .app causes a "Permission Denied" error, you may have to run "chmod +x" first. For example on Mac, run `chmod +x ./builds/SameWav.app` before running SameWav.app.