# JavaScript Pointer Runtime

A custom JavaScript runtime that introduces support for pointers, enabling low-level memory manipulation in JavaScript.

## 🚀 Features
- **Pointer Support**: Use pointers in JavaScript for direct memory access.
- **Memory Management**: Allocate and deallocate memory manually.
- **Performance Optimization**: Optimized execution for high-performance applications.
- **C-Like Behavior**: Brings manual memory handling closer to languages like C.

## 🛠 Installation

```sh
npm install -g js-pointer-runtime
```

## 📖 Usage

```js
import { malloc, free, deref, set } from 'js-pointer-runtime';

// Allocate memory for an integer
const ptr = malloc(4);

// Set value at allocated memory
set(ptr, 42);

// Retrieve value from memory
console.log(deref(ptr)); // 42

// Free allocated memory
free(ptr);
```

## 📜 API Reference

### `malloc(size: number): Pointer`
Allocates memory of given size in bytes and returns a pointer.

### `free(pointer: Pointer): void`
Frees allocated memory.

### `set(pointer: Pointer, value: any): void`
Sets a value at the memory location pointed to by `pointer`.

### `deref(pointer: Pointer): any`
Retrieves the value stored at the memory location pointed to by `pointer`.

## 🛡️ Security Considerations
- Manual memory management introduces risks like memory leaks and segmentation faults.
- Avoid accessing freed memory.

## 🤝 Contributing
Contributions are welcome! Please open an issue or submit a pull request.

## 📜 License
MIT License

