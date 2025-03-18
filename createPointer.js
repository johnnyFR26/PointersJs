const vars = PointerManager();

// Cria um ponteiro para um número
vars['*myVar'] = 42; // Criará um ponteiro no C++
console.log(vars['*myVar']); // Mostra o ponteiro no console

// Adiciona uma variável normal
vars['normalVar'] = 100; // Não será convertido em ponteiro
console.log(vars['normalVar']); // Saída: 100