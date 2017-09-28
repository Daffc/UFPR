#ifndef _AUDIO_OPEN_
#define _AUDIO_OPEN_

typedef struct Music_header{

    char            riff_tag[5],
                    wave_tag[5],
                    form_tag[5],
                    data_tag[5];

    int             riff_size,
                    fmt_size,
                    sample_rate,
                    byte_rate,
                    data_size,
                    samples_channel;

    short           audio_format,
                    num_channels,
                    block_align,
                    bits_per_sample;

    void            *DATA;
} Music_header;

//Função para carregar informações do arquivo wave.
void audio_load(char *caminho, Music_header *wave);

#endif
