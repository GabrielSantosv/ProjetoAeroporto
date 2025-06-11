# Sistema de Gerenciamento de Aeroportos

Este é um sistema de gerenciamento de aeroportos desenvolvido em C que permite gerenciar aeroportos, voos e encontrar rotas entre diferentes aeroportos.

## 📋 Pré-requisitos

Para executar este programa, você precisa ter instalado:

- GCC (GNU Compiler Collection) ou outro compilador C
- Sistema operacional compatível com C (Windows, Linux ou macOS)

### Instalação do GCC

#### Windows
1. Instale o MinGW (Minimalist GNU for Windows):
   - Baixe o instalador do MinGW em: https://sourceforge.net/projects/mingw/
   - Durante a instalação, selecione o pacote `mingw32-base` e `mingw32-gcc-g++`
   - Adicione o caminho `C:\MinGW\bin` às variáveis de ambiente do sistema

#### Linux
```bash
sudo apt-get update
sudo apt-get install build-essential
```

#### macOS
```bash
xcode-select --install
```

## 🚀 Como Executar

1. Clone ou baixe este repositório
2. Abra o terminal na pasta do projeto
3. Compile o programa:
```bash
gcc aeroporto.c -o aeroporto
```
4. Execute o programa:
```bash
# Windows
.\aeroporto

# Linux/macOS
./aeroporto
```

## ✨ Funcionalidades

### 1. Gerenciamento de Aeroportos
- Adicionar novos aeroportos ao sistema
- Cada aeroporto é identificado por uma sigla de 3 letras (ex: GRU, GIG, CNF)
- Limite de 100 aeroportos no sistema

### 2. Gerenciamento de Voos
- Registrar novos voos entre aeroportos
- Excluir voos existentes
- Visualizar todos os voos partindo de um aeroporto específico

### 3. Busca de Rotas
- Encontrar todas as rotas possíveis entre dois aeroportos
- Utiliza algoritmo de busca em profundidade
- Mostra todas as conexões possíveis

## 🎮 Como Usar

O sistema possui um menu interativo com as seguintes opções:

1. **Adicionar aeroporto**
   - Digite a sigla do aeroporto (ex: CNF)

2. **Registrar voo**
   - Digite o código do voo (número)
   - Digite a sigla do aeroporto de partida
   - Digite a sigla do aeroporto de chegada

3. **Excluir voo**
   - Digite o código do voo que deseja excluir

4. **Mostrar voos de um aeroporto**
   - Digite a sigla do aeroporto para ver todos os voos que partem dele

5. **Encontrar rotas entre aeroportos**
   - Digite a sigla do aeroporto de origem
   - Digite a sigla do aeroporto de destino

## 🏗️ Estrutura do Código

- `codigosAero`: Array que armazena as siglas dos aeroportos
- `voos`: Matriz que armazena as conexões entre aeroportos
- `totalCadastrados`: Contador de aeroportos cadastrados

## 🔍 Exemplo de Uso

1. Adicionar um novo aeroporto:
```
Selecione: 1
Sigla do aeroporto: REC
```

2. Registrar um voo:
```
Selecione: 2
Código do voo: 101
Partida: GRU
Chegada: GIG
```

3. Verificar voos de um aeroporto:
```
Selecione: 4
Sigla do aeroporto de origem: GRU
```

## ⚠️ Limitações

- Máximo de 100 aeroportos
- Siglas de aeroportos limitadas a 3 caracteres
- Não suporta voos com escalas múltiplas`Várias Paradas`

## 🤝 Contribuindo

Sinta-se à vontade para contribuir com o projeto através de:
1. Fork do projeto
2. Criação de uma branch para sua feature (`git checkout -b feature/AmazingFeature`)
3. Commit das suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abertura de um Pull Request
