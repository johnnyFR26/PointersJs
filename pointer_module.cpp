#include <napi.h>
#include <unordered_map>
#include <iostream>

// Um mapa para armazenar ponteiros (simulando o comportamento para fins de rastreamento)
std::unordered_map<std::string, void*> pointerRegistry;

Napi::String ConvertToPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2 || !info[0].IsString() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Esperado: (nome, valor)").ThrowAsJavaScriptException();
        return Napi::String::New(env, "Erro");
    }

    std::string varName = info[0].As<Napi::String>();
    int* ptr = new int(info[1].As<Napi::Number>().Int32Value());
    pointerRegistry[varName] = static_cast<void*>(ptr);

    std::ostringstream result;
    result << "Ponteiro criado para " << varName << " com endereço " << ptr;
    return Napi::String::New(env, result.str());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("convertToPointer", Napi::Function::New(env, ConvertToPointer));
    return exports;
}

NODE_API_MODULE(pointer_module, Init)