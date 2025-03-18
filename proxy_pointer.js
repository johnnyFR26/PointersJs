const pointerModule = require('./build/Release/pointer_module');

// Função para converter valores para ponteiros no C++
function convertToPointer(name, value) {
  return pointerModule.convertToPointer(name, value);
}

// Gerenciador de ponteiros
function PointerManager() {
  return new Proxy({}, {
    // Intercepta atribuições a propriedades do objeto
    set(target, prop, value) {
      if (prop.startsWith('*')) {
        // Cria o ponteiro chamando o módulo em C++
        const pointerInfo = convertToPointer(prop, value);
        console.log(pointerInfo); // Exibe o resultado do módulo
        target[prop] = pointerInfo; // Armazena a referência no objeto
      } else {
        target[prop] = value; // Variáveis normais
      }
      return true;
    },
    // Intercepta acessos a propriedades do objeto
    get(target, prop) {
      return target[prop]; // Retorna a referência do ponteiro ou valor normal
    }
  });
}
