#include <fftw3.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{    
    int W = atoi(argv[1]);
    int H = atoi(argv[2]);
    
    float *input = new float[W * H];
    int value = 0;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            input[i * W + j] = value++;
            cout << input[i * W + j] << "\t";
        }
        cout << endl;
    }

    fftwf_complex *output = (fftwf_complex *)fftwf_malloc(W * H * sizeof(fftwf_complex));
    fftwf_plan p = fftwf_plan_dft_r2c_2d(H, W, input, output, FFTW_ESTIMATE);
    fftwf_execute(p);

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cout << output[i * W + j][0] << "+" << output[i * W + j][1] << "j\t\t";
        }
        cout << endl;
    }

    return 0;
}