#include <fftw3.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{    
    int W = atoi(argv[1]);
    
    // float *input = new float[W * H];
    float *input = new float[W];
    int value = 0;
    for(int i = 0; i < W; i++)
    {
        input[i] = value++;
    }

    fftwf_complex *output = (fftwf_complex *)fftwf_malloc(W * sizeof(fftwf_complex));
    // fftwf_plan p = fftwf_plan_dft_c2c_2d(H, W, input, output, FFTW_ESTIMATE);
    fftwf_plan p = fftwf_plan_dft_r2c_1d(W, input, output, FFTW_ESTIMATE);
    fftwf_execute(p);

    for(int i = 0; i < W; i++)
    {
        cout << output[i][0] << "+" << output[i][1] << "j\t\t";
        cout << endl;
    }

    return 0;
}