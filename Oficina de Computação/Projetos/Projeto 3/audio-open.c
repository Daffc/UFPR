#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "audio-open.h"

void audio_load(char caminho[], Music_header *wave)
{
    FILE            *arquivo;

    if(caminho[0] != 0)
    {
        arquivo = fopen (caminho, "r");

        if(!arquivo)
        {
            perror("Erro ao abrir arquivo.");
            exit(1);
        }
    }

    else
    {
        arquivo = stdin;
    }

    fread((*wave).riff_tag, sizeof(char), 4, arquivo);
    fread(&(*wave).riff_size, sizeof(int), 1, arquivo);        
    fread((*wave).wave_tag, sizeof(char), 4, arquivo);
    fread((*wave).form_tag, sizeof(char), 4, arquivo);
    fread(&(*wave).fmt_size, sizeof(int), 1, arquivo);
    fread(&(*wave).audio_format, sizeof(short), 1, arquivo);
    fread(&(*wave).num_channels, sizeof(short), 1, arquivo);
    fread(&(*wave).sample_rate, sizeof(int), 1, arquivo);
    fread(&(*wave).byte_rate, sizeof(int), 1, arquivo);
    fread(&(*wave).block_align, sizeof(short), 1, arquivo);
    fread(&(*wave).bits_per_sample, sizeof(short), 1, arquivo);
    fread((*wave).data_tag, sizeof(char), 4, arquivo);
    fread(&(*wave).data_size, sizeof(int), 1, arquivo);

    (*wave).samples_channel = (*wave).data_size / (*wave).block_align;

    (*wave).riff_tag[4] = 0;
    (*wave).wave_tag[4] = 0;
    (*wave).form_tag[4] = 0;
    (*wave).data_tag[4] = 0;

    (*wave).DATA = malloc((*wave).data_size);

    fread((*wave).DATA, (*wave).data_size, 1, arquivo);

    fclose(arquivo);
}
