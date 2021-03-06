#include <iostream>
#include <fstream>
#include "../../kitsune/audiofeatures.h"
#include "../../kitsune/audioclassifier.h"
#include "../../kitsune/debugutils/debugsingleton.h"
#include <string.h>
#include "pb_encode.h"
#include "../../kitsune/debugutils/base64.h"
using namespace std;

static std::string _label;


#define OUT_BUF_SIZE (100000)
static void serialize_buf(std::ofstream & ostream) {
    unsigned char buf[OUT_BUF_SIZE];
    pb_ostream_t output;
    size_t encodelength;
    std::string mytags = "";
    
    memset(buf,0,sizeof(buf));
    
    output = pb_ostream_from_buffer(buf, OUT_BUF_SIZE);
    
    encodelength = AudioClassifier_EncodeAudioFeatures(&output, NULL);
    AudioClassifier_ResetStorageBuffer();
    
    std::cout << "length is " << encodelength << std::endl;
    
    if (ostream.is_open()) {
        ostream << base64_encode(buf,encodelength) <<std::endl;
    }
}



int main(int argc, char * argv[]) {
    
    char bigbuf[1024*60];
    
    if (argc <= 2) {
        cerr << "Takes 2 inputs, 1) input file and 2) output file" << endl;
        cerr << "It is assumed that the input is mono, 16 bits per sample, in PCM format (i.e as raw as you can get)" << endl;
        return 0;
    }
    
    
    _label.clear();
    _label = "none";
    
    if (argc >= 4) {
        _label = argv[3];
    }
    
    std::ofstream dumpfile("bufdump.dat");

    
    ifstream inFile (argv[1], ios::in | ios::binary);
    std::cout << "Processing " << argv[1] << std::endl;
    //init output logging... tell it what its destination filename is
    DebugLogSingleton::Initialize_UsingFileStream(argv[2],_label);

    
    char buf[sizeof(int16_t) * AUDIO_FFT_SIZE];
    const short * samples = (const short *) buf;
    int64_t counter = 0;
    
    
    AudioFeatures_Init(AudioClassifier_DataCallback,NULL);
    AudioClassifier_Init(NULL);
    AudioClassifier_SetStorageBuffers(bigbuf,sizeof(bigbuf));
    
    
    do {
        //read
        inFile.read(buf,sizeof(buf));
        
        AudioFeatures_SetAudioData(samples,counter++);
        
        if (counter % 320 == 0) {
            serialize_buf(dumpfile);
        }
        
    } while (inFile);
    
    serialize_buf(dumpfile);
    
    dumpfile.close();

    return 0;
}
