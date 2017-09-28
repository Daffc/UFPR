#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    FILE *arquivo;

    char            riff_tag[5],
                    wave_tag[5],
                    form_tag[5],
                    data_tag[5];
    
    int             riff_size,
                    fmt_size,
                    audio_format,
                    num_channels,
                    sample_rate,
                    byte_rate,
                    block_align,
                    bits_per_sample,
                    data_size,
                    samples_channel;

    if(argc > 1)
    {       
        if(strcmp("-i",argv[1]) != 0)
        {
            printf("Parâmetro não identificado.\n");
            exit(1); 
        }

        arquivo = fopen(argv[2], "r");
    }

    else
    {
        arquivo = stdin;
    }

    if(!arquivo)
    {
        perror("Erro ao abrir arquivo.");
        exit(1);
    }

    fread(riff_tag, sizeof(char), 4, arquivo);
    fread(&riff_size, sizeof(int), 1, arquivo);        
    fread(wave_tag, sizeof(char), 4, arquivo);
    fread(form_tag, sizeof(char), 4, arquivo);
    fread(&fmt_size, sizeof(int), 1, arquivo);
    fread(&audio_format, sizeof(char), 2, arquivo);
    fread(&num_channels, sizeof(char), 2, arquivo);
    fread(&sample_rate, sizeof(int), 1, arquivo);
    fread(&byte_rate, sizeof(int), 1, arquivo);
    fread(&block_align, sizeof(char), 2, arquivo);
    fread(&bits_per_sample, sizeof(char), 2, arquivo);
    fread(data_tag, sizeof(char), 4, arquivo);
    fread(&data_size, sizeof(int), 1, arquivo);

    samples_channel = data_size / block_align;

    riff_tag[4] = 0;
    wave_tag[4] = 0;
    form_tag[4] = 0;
    data_tag[4] = 0;

    printf("riff tag        : \"%s\" \n", riff_tag);
    printf("riff size       : %d \n", riff_size );
    printf("wave tag        : \"%s\" \n", wave_tag);
    printf("form tag        : \"%s\" \n", form_tag);
    printf("fmt_size        : %d \n", fmt_size);
    printf("audio_format    : %d \n", audio_format);
    printf("num_channels    : %d \n", num_channels);
    printf("sample_rate     : %d \n", sample_rate);
    printf("byte_rate       : %d \n", byte_rate);
    printf("block_align     : %d \n", block_align);
    printf("bits_per_sample : %d \n", bits_per_sample);
    printf("data tag        : \"%s\" \n", data_tag); 
    printf("data size       : %d \n", data_size);
    printf("samples/channel : %d \n", samples_channel);

    fclose(arquivo);
}