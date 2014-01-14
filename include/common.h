/*
	common.h

 	Midi Wavetable Processing library

    Copyright (C) Chris Ison 2001-2011
    Copyright (C) Bret Curtis 2013-2014

    This file is part of WildMIDI.

    WildMIDI is free software: you can redistribute and/or modify the player
    under the terms of the GNU General Public License and you can redistribute
    and/or modify the library under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation, either version 3 of
    the licenses, or(at your option) any later version.

    WildMIDI is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License and
    the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU General Public License and the
    GNU Lesser General Public License along with WildMIDI.  If not,  see
    <http://www.gnu.org/licenses/>.
*/

#ifndef __COMMON_H
#define __COMMON_H

#define SAMPLE_16BIT 0x01
#define SAMPLE_UNSIGNED 0x02
#define SAMPLE_LOOP 0x04
#define SAMPLE_PINGPONG 0x08
#define SAMPLE_REVERSE 0x10
#define SAMPLE_SUSTAIN 0x20
#define SAMPLE_ENVELOPE 0x40
#define SAMPLE_CLAMPED 0x80

#ifdef DEBUG_SAMPLES
#define SAMPLE_CONVERT_DEBUG(dx) printf("\r%s\n",dx)
#else
#define SAMPLE_CONVERT_DEBUG(dx)
#endif

// Guspat Envelope Rate Timings
// Row 1 = (4095.0/(x*(1.0/(1.6*14.0)))) / 1000000.0
// Row 2 = (4095.0/(x*((1.0/(1.6*14.0))/8.0)))) / 1000000.0
// Row 3 = (4095.0/(x*((1.0/(1.6*14.0))/64.0))) / 1000000.0
// Row 4 = (4095.0/(x*((1.0/(1.6*14.0))/512.0))) / 1000000.0
static float env_time_table[] = {
    0.0f, 0.091728000f, 0.045864000f, 0.030576000f, 0.022932000f, 0.018345600f, 0.015288000f, 0.013104000f, 0.011466000f, 0.010192000f, 0.009172800f, 0.008338909f, 0.007644000f, 0.007056000f, 0.006552000f, 0.006115200f, 0.005733000f, 0.005395765f, 0.005096000f, 0.004827789f, 0.004586400f, 0.004368000f, 0.004169455f, 0.003988174f, 0.003822000f, 0.003669120f, 0.003528000f, 0.003397333f, 0.003276000f, 0.003163034f, 0.003057600f, 0.002958968f, 0.002866500f, 0.002779636f, 0.002697882f, 0.002620800f, 0.002548000f, 0.002479135f, 0.002413895f, 0.002352000f, 0.002293200f, 0.002237268f, 0.002184000f, 0.002133209f, 0.002084727f, 0.002038400f, 0.001994087f, 0.001951660f, 0.001911000f, 0.001872000f, 0.001834560f, 0.001798588f, 0.001764000f, 0.001730717f, 0.001698667f, 0.001667782f, 0.001638000f, 0.001609263f, 0.001581517f, 0.001554712f, 0.001528800f, 0.001503738f, 0.001479484f, 0.001456000f,
    0.0f, 0.733824000f, 0.366912000f, 0.244608000f, 0.183456000f, 0.146764800f, 0.122304000f, 0.104832000f, 0.091728000f, 0.081536000f, 0.073382400f, 0.066711273f, 0.061152000f, 0.056448000f, 0.052416000f, 0.048921600f, 0.045864000f, 0.043166118f, 0.040768000f, 0.038622316f, 0.036691200f, 0.034944000f, 0.033355636f, 0.031905391f, 0.030576000f, 0.029352960f, 0.028224000f, 0.027178667f, 0.026208000f, 0.025304276f, 0.024460800f, 0.023671742f, 0.022932000f, 0.022237091f, 0.021583059f, 0.020966400f, 0.020384000f, 0.019833081f, 0.019311158f, 0.018816000f, 0.018345600f, 0.017898146f, 0.017472000f, 0.017065674f, 0.016677818f, 0.016307200f, 0.015952696f, 0.015613277f, 0.015288000f, 0.014976000f, 0.014676480f, 0.014388706f, 0.014112000f, 0.013845736f, 0.013589333f, 0.013342255f, 0.013104000f, 0.012874105f, 0.012652138f, 0.012437695f, 0.012230400f, 0.012029902f, 0.011835871f, 0.011648000f,
    0.0f, 5.870592000f, 2.935296000f, 1.956864000f, 1.467648000f, 1.174118400f, 0.978432000f, 0.838656000f, 0.733824000f, 0.652288000f, 0.587059200f, 0.533690182f, 0.489216000f, 0.451584000f, 0.419328000f, 0.391372800f, 0.366912000f, 0.345328941f, 0.326144000f, 0.308978526f, 0.293529600f, 0.279552000f, 0.266845091f, 0.255243130f, 0.244608000f, 0.234823680f, 0.225792000f, 0.217429333f, 0.209664000f, 0.202434207f, 0.195686400f, 0.189373935f, 0.183456000f, 0.177896727f, 0.172664471f, 0.167731200f, 0.163072000f, 0.158664649f, 0.154489263f, 0.150528000f, 0.146764800f, 0.143185171f, 0.139776000f, 0.136525395f, 0.133422545f, 0.130457600f, 0.127621565f, 0.124906213f, 0.122304000f, 0.119808000f, 0.117411840f, 0.115109647f, 0.112896000f, 0.110765887f, 0.108714667f, 0.106738036f, 0.104832000f, 0.102992842f, 0.101217103f, 0.099501559f, 0.097843200f, 0.096239213f, 0.094686968f, 0.093184000f,
    0.0f, 46.964736000f, 23.482368000f, 15.654912000f, 11.741184000f, 9.392947200f, 7.827456000f, 6.709248000f, 5.870592000f, 5.218304000f, 4.696473600f, 4.269521455f, 3.913728000f, 3.612672000f, 3.354624000f, 3.130982400f, 2.935296000f, 2.762631529f, 2.609152000f, 2.471828211f, 2.348236800f, 2.236416000f, 2.134760727f, 2.041945043f, 1.956864000f, 1.878589440f, 1.806336000f, 1.739434667f, 1.677312000f, 1.619473655f, 1.565491200f, 1.514991484f, 1.467648000f, 1.423173818f, 1.381315765f, 1.341849600f, 1.304576000f, 1.269317189f, 1.235914105f, 1.204224000f, 1.174118400f, 1.145481366f, 1.118208000f, 1.092203163f, 1.067380364f, 1.043660800f, 1.020972522f, 0.999249702f, 0.978432000f, 0.958464000f, 0.939294720f, 0.920877176f, 0.903168000f, 0.886127094f, 0.869717333f, 0.853904291f, 0.838656000f, 0.823942737f, 0.809736828f, 0.796012475f, 0.782745600f, 0.769913705f, 0.757495742f, 0.745472000f
};


extern unsigned short int WM_SampleRate;

struct _sample {
	unsigned long int data_length;
	unsigned long int loop_start;
	unsigned long int loop_end;
	unsigned long int loop_size;
	unsigned char loop_fraction;
	unsigned short int rate;
	unsigned long int freq_low;
	unsigned long int freq_high;
	unsigned long int freq_root;
	unsigned char modes;
	unsigned long int env_rate[7];
	unsigned long int env_target[7];
	unsigned long int inc_div;
	signed short *data;
	struct _sample *next;
};

struct _env {
	float time;
	float level;
	unsigned char set;
};

struct _patch {
	unsigned short patchid;
	unsigned char loaded;
	char *filename;
	signed short int amp;
	unsigned char keep;
	unsigned char remove;
	struct _env env[6];
	unsigned char note;
	unsigned long int inuse_count;
	struct _sample *first_sample;
	struct _patch *next;
};



#endif // __COMMON_H
