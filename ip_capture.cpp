#include <napi.h>
#include <pcap.h>
#include <iostream>
#include <sstream>

Napi::String CapturePackets(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_if_t *all_devices, *device;

    // Encontra dispositivos disponíveis
    if (pcap_findalldevs(&all_devices, error_buffer) == -1) {
        return Napi::String::New(env, "Erro ao encontrar dispositivos.");
    }

    device = all_devices;
    if (!device) {
        return Napi::String::New(env, "Nenhum dispositivo disponível.");
    }

    std::ostringstream result;
    result << "Capturando no dispositivo: " << device->name << "\n";

    // Abrir dispositivo para captura
    pcap_t *handle = pcap_open_live(device->name, 65536, 1, 0, error_buffer);
    if (handle == nullptr) {
        return Napi::String::New(env, "Erro ao abrir dispositivo.");
    }

    const u_char *buffer;
    struct pcap_pkthdr header;

    for (int i = 0; i < 5; ++i) { // Exemplo: capturar 5 pacotes
        buffer = pcap_next(handle, &header);
        if (buffer == nullptr) continue; // Ignorar pacotes inválidos
        result << "Pacote capturado: " << header.len << " bytes\n";
    }

    pcap_close(handle);
    return Napi::String::New(env, result.str());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("capturePackets", Napi::Function::New(env, CapturePackets));
    return exports;
}

NODE_API_MODULE(ip_capture, Init)