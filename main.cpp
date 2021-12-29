#include "AudioFile/AudioFile.h"
#include <iostream>

using namespace std;

bool sameWav (string path0, string path1)
{
    AudioFile<double> file0, file1;
    file0.load(path0);
    file1.load(path1);
    
    if (file0.getSampleRate() != file1.getSampleRate())
    {
        cout << "SameWav: SampleRate mismatch\n";
        return false;
    }
    if (file0.getNumSamplesPerChannel() != file1.getNumSamplesPerChannel())
    {
        cout << "SameWav: NumSamplesPerChannel mismatch\n";
        return false;
    }
    if (file0.getNumChannels() != file1.getNumChannels())
    {
        cout << "SameWav: NumChannels mismatch\n";
        return false;
    }

    for (int i = 0; i < file0.getNumChannels(); ++i)
    {
        for (int j = 0; j < file0.getNumSamplesPerChannel(); ++j)
        {
            if (file0.samples[i][j] != file1.samples[i][j])
            {
                cout << "SameWav: Sample mismatch\n";
                return false;
            }
        }
    }    

    return true;
}   

int main (int argc, char* argv[]) {
    if (argc  < 3 || argc > 4)
    {
        cout << "Usage: ./SameWave.exe <wav file 0> <wav file 1> [invert exit code]\n";
        return 1;
    }

    if (!sameWav(argv[1], argv[2]))
        return (argc == 3 ? 1 : 0);

    return (argc == 3 ? 0 : 1);
}