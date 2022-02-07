/** GNU GPLv3 License

    Copyright (C) 2021 ZheDeng
    TheZheDeng@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
    
    if (file0.getBitDepth() != file1.getBitDepth())
    {
        cout << "ERROR SameWav (" + path0 + ", " + path1 + "): BitDepth mismatch" << endl;
        return false;
    }
    if (file0.getSampleRate() != file1.getSampleRate())
    {
        cout << "ERROR SameWav (" + path0 + ", " + path1 + "): SampleRate mismatch" << endl;
        return false;
    }
    if (file0.getNumSamplesPerChannel() != file1.getNumSamplesPerChannel())
    {
        cout << "ERROR SameWav (" + path0 + ", " + path1 + "): NumSamplesPerChannel mismatch" << endl;
        return false;
    }
    if (file0.getNumChannels() != file1.getNumChannels())
    {
        cout << "ERROR SameWav (" + path0 + ", " + path1 + "): NumChannels mismatch" << endl;
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
                cout << "ERROR SameWav (" + path0 + ", " + path1 + "): First sample mismatch at frame " << j << ", channel " << i << "; ";
            }
        }
    }    

    if (!same)
        cout << "Peak levels (dB) are " << gainTodB (peak0) << ", " << gainTodB (peak1) << endl;

    return same;
}   

int main (int argc, char* argv[]) 
{
    if (argc != 3)
    {
        #if defined (__APPLE__)
            cerr << "Usage: ./SameWave.app wav0 wav1" << endl;
        #elif defined (_WIN64)
            cerr << "Usage: .\\SameWav.exe wav0 wav1" << endl;
        #endif

        return 1;
    }

    sameWav(argv[1], argv[2]);

    return 0;
}