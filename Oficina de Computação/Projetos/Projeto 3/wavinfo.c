#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "audio-open.h"

int main (int argc, char *argv[])
{      
    Music_header        cabecalho;          

    if(argc > 1)
    {       
        if(strcmp("-i",argv[1]) != 0)
        {
            printf("Parâmetro não identificado.\n");
            exit(1); 
        }

        //Envia caminho do arquivo que será aberto.
        audio_load(argv[2], &cabecalho);
    }
    
    else
    {
        audio_load("", &cabecalho);
    }
    
    printf("riff tag        : \"%s\" \n", cabecalho.riff_tag);
    printf("riff size       : %d \n", cabecalho.riff_size );
    printf("wave tag        : \"%s\" \n", cabecalho.wave_tag);
    printf("form tag        : \"%s\" \n", cabecalho.form_tag);
    printf("fmt_size        : %d \n", cabecalho.fmt_size);
    printf("audio_format    : %d \n", cabecalho.audio_format);
    printf("num_channels    : %d \n", cabecalho.num_channels);
    printf("sample_rate     : %d \n", cabecalho.sample_rate);
    printf("byte_rate       : %d \n", cabecalho.byte_rate);
    printf("block_align     : %d \n", cabecalho.block_align);
    printf("bits_per_sample : %d \n", cabecalho.bits_per_sample);
    printf("data tag        : \"%s\" \n", cabecalho.data_tag); 
    printf("data size       : %d \n", cabecalho.data_size);
    printf("samples/channel : %d \n", cabecalho.samples_channel);

    printf("%lu", sizeof(cabecalho.DATA));
}