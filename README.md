# Cuda
Multi-Core Programming CUDA about AES encryption

# AES Implementation with CUDA

## Overview
This project is an implementation of the **Advanced Encryption Standard (AES)** algorithm using **CUDA** to leverage GPU acceleration for faster encryption. By parallelizing computations, this implementation significantly improves performance compared to a CPU-based approach.

This project supports **AES-128, AES-192, and AES-256** encryption and includes a **random file generator** to create test files.

## Features
- AES encryption using CUDA for parallel execution
- Supports **128-bit, 192-bit, and 256-bit AES key sizes**
- Key expansion implemented with Rcon transformations
- Optimized memory management for GPU processing
- Random file generator to create test input files

## Prerequisites
Before running the project, ensure that you have the following installed:

- **CUDA Toolkit** (latest version recommended)
- **NVIDIA GPU** with CUDA support
- **C++ Compiler** (such as g++)

## Installation
Clone this repository and navigate to the project directory:

```bash
git clone https://github.com/yourusername/aes-cuda.git
cd aes-cuda
```

## Compilation
To compile the CUDA AES implementation, use the following command:

```bash
nvcc -o aes_cuda aes_cuda.cu
```

To compile the random file generator:

```bash
gcc -o random_file_generator random_file_generator.c
```

## Usage

### Random File Generator
To generate a random file of a specified size:

```bash
./random_file_generator <size_in_MB>
```

Example:
```bash
./random_file_generator 10
```
This creates a file named `random_bytes.txt` with **10MB** of random data.

### AES Encryption
To run the AES encryption program:

```bash
./aes_cuda <input_file> <key_file> <output_file>
```

Where:
- `<input_file>` is the file to be encrypted.
- `<key_file>` contains the AES key (128, 192, or 256 bits).
- `<output_file>` is the resulting encrypted file.

#### Example
Encrypt a file:
```bash
./aes_cuda random_bytes.txt key.txt encrypted.bin
```

## Implementation Details
- **Key Expansion:** The AES key schedule expands the key using Rcon transformations and S-box substitutions.
- **Parallel Execution:** Each AES block is processed in parallel using CUDA threads.
- **Padding:** If the input file is not a multiple of 16 bytes, zero-padding is applied.

## Performance
This implementation demonstrates a significant speed-up over traditional CPU-based AES encryption by utilizing CUDA’s parallel computing capabilities. Benchmarks will depend on the GPU model used.

## Contributing
Contributions are welcome! If you find issues or have suggestions for improvement, feel free to open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See `LICENSE` for more details.

