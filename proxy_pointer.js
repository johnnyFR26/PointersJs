export function PointerManager() {
    return new Proxy({}, {
      set(target, prop, value) {
        if (prop.startsWith('*')) {
          // Converta para ponteiro chamando o módulo C++
          target[prop] = convertToPointer(value); 
        } else {
          target[prop] = value;
        }
        return true;
      }
    });
  }
  