#include <fftw3.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout << "Usage: ./main W H \n";
        return 0;
    }
    int W = atoi(argv[1]);
    int H = atoi(argv[2]);

    ifstream input_f("input.bin", ios::binary | ios::in);
    float *input = new float[W * H];
    input_f.read((char *)input, W * H * 4);

    fftwf_complex *output = (fftwf_complex *)fftwf_malloc(W * H * sizeof(fftwf_complex));
    fftwf_plan p = fftwf_plan_dft_r2c_2d(H, W, input, output, FFTW_ESTIMATE);
    fftwf_execute(p);

    float *output_r = new float[W * H];
    float *output_i = new float[W * H];

    for(int i = 0; i < W * H; i++)
    {
        output_r[i] = output[i][0];
        output_i[i] = output[i][1];
    }

    ofstream output_r_f("output_fftw_r.bin", ios::binary | ios::out);
    output_r_f.write((char *)output_r, W * H * 4);
    output_r_f.close();

    ofstream output_i_f("output_fftw_i.bin", ios::binary | ios::out);
    output_i_f.write((char *)output_i, W * H * 4);
    output_i_f.close();
    
    return 0;
}