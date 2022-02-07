# SameWav
CLI for checking if two .wav files have identical sets of sample frames. For CI, Unit Tests, and anything that requires checking two sets of .wav data. 

## Windows (PowerShell)
Setup
```powershell
Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted
.\updateSub.ps1
```
Usage
```powershell
.\builds\SameWav.exe <wav file 0> <wav file 1>
```

## Mac (Bash)
Setup
```bash
./updateSub.sh
```
Usage
```bash
./builds/SameWav.app <wav file 0> <wav file 1>
```

## Output
- Error logs go to stdout
- Exit code is always 0