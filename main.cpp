#include "AudioFile/AudioFile.h"
#include <iostream>
#include <math.h>

using namespace std;

double gainTodB (double x)
{
    return 20.0 * log10 (x);
}

bool sameWav (string path0, string path1)
{
    AudioFile<double> file0, file1;
    file0.load(path0);
    file1.load(path1);
    
    if (file0.getSampleRate() != file1.getSampleRate())
    {
        cout << "SameWav (" + path0 + ", " + path1 + "): SampleRate mismatch" << endl;
        return false;
    }
    if (file0.getNumSamplesPerChannel() != file1.getNumSamplesPerChannel())
    {
        cout << "SameWav (" + path0 + ", " + path1 + "): NumSamplesPerChannel mismatch" << endl;
        return false;
    }
    if (file0.getNumChannels() != file1.getNumChannels())
    {
        cout << "SameWav (" + path0 + ", " + path1 + "): NumChannels mismatch" << endl;
        return false;
    }


    double peak0, peak1;
    bool same = true;

    for (int i = 0; i < file0.getNumChannels(); ++i)
    {
        for (int j = 0; j < file0.getNumSamplesPerChannel(); ++j)
        {
            peak0 = max (abs(file0.samples[i][j]), peak0);
            peak1 = max (abs(file1.samples[i][j]), peak1);

            if (file0.samples[i][j] != file1.samples[i][j] && same)
            {
                same = false;
                cout << "SameWav (" + path0 + ", " + path1 + "): First sample mismatch at frame " << j << ", channel " << i << "; ";
            }
        }
    }    

    if (!same)
        cout << "Peak levels (dB) are " << gainTodB (peak0) << ", " << gainTodB (peak1) << endl;

    return same;
}   

int main (int argc, char* argv[]) {
    if (argc  < 3 || argc > 4)
    {
        cout << "Usage: ./SameWave.exe <wav file 0> <wav file 1>\n";
        return 1;
    }

    sameWav(argv[1], argv[2]);

    return 0;
}